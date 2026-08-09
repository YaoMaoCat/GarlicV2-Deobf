# Analysis: Decrypted Proxy DLL

`artifacts/GarlicProxy.dll` is the result of running `artifacts/decrypt_pkg.py`
against `artifacts/GarlicProxy.pkg`. This file documents the binary's
internal structure, the bytecode-level hook into
`net.minecraft.network.Connection`, and the B-side relay server.

## 1. Image layout

* **Image base:** `0x180000000` (standard for `cl /GL`-built DLLs).
* **Exports:** `ReflectiveLoader` only (the entry point used by the
  reflective injector in `data/GarlicInjector.exe`).
* **Imports:** KERNEL32 only — `FlsAlloc/Free/GetValue/SetValue`,
  `InitializeCriticalSectionEx`. Everything else is resolved at
  runtime through `JavaVM*` / `JNIEnv*` vtables, JVMTI vtable
  pointers (`g_jvmti`), or `GetProcAddress`-style lookups against
  loaded Netty / `java.*` classes via JNI.

* **No static imports of `ws2_32` / `wininet` / `winhttp` etc.** —
  the B-side Netty server runs inside the injected JVM and uses the
  JVM's own networking stack rather than calling Winsock directly.

## 2. Top-level initialization

The DLL's only exported symbol is `ReflectiveLoader`. When the
injector's `CreateRemoteThread` lands on it, control flow is:

```
ReflectiveLoader (sub_180001050 in decrypted, reflective_loader's classic body)
└── finds MZ header in self by walking the return-address chain
    └── sub_180001050a: ResolveReflectiveLoader imports from KERNEL32
        └── copies itself into the freshly mapped RX region and jumps in

DLLMain-equivalent in reflective body (sub_180001740, "ProxyInitWorker"):
└── prints "ProxyInitWorker: attaching to JVM as daemon"
    JavaVM_AttachCurrentThreadAsDaemon → env (vtable +0x38)
    poll every 500ms for the MC class loader to load
        sub_18000adb0: InstallHookBridge(env)             (trampolines.cpp)
        sub_18000b770: InstallRelayHandler(env)           (relay_handler.cpp)
        sub_18000d7f0: InstallConnectionHook(env)         (connection_hook.cpp)
        sub_18000ea20: InstallBServer(env)                (b_server.cpp)
        (optionally) sub_18000dac0: queue a render-thread blocker
    finally: JavaVM_DetachCurrentThread
```

The four `Install*` calls correspond 1:1 to the C++ functions in
`native/`. The function-level mapping between the PseudoC dump and
the C++ source is documented in §3 of `README.md`.

## 3. HookBridge: a JVMTI `RetransformClasses`-free trampoline

`trampolines.cpp::InstallHookBridge` defines a synthetic Java class
inside the target JVM (no Minecraft code needed yet) with:

* A static method `onChannelActive(Object self, Object ctx)`.
* A static method `onChannelRead(Object self, Object msg)`.
* A static method `onWrite(Object self, Object ctx, Object msg, Object promise)`.

These are loaded via `DefineClass` on the runtime class loader, then
`RegisterNatives` binds them to native C++ callbacks in the DLL.

The corresponding PseudoC dump function is `sub_18000adb0.c`. The
compiled binary emits exactly the same JNI signatures found in the
source:

```
(Ljava/lang/Object;Ljava/lang/Object;)V                onChannelActive
(Ljava/lang/Object;Ljava/lang/Object;)V                onChannelRead
(Ljava/lang/Object;Ljava/lang/Object;
 Ljava/lang/Object;Ljava/lang/Object;)V                onWrite
```

The native implementations of those (`NativeHookBridge_onChannelActive`,
`NativeHookBridge_onChannelRead`, `NativeHookBridge_onWrite`) live in
the same compilation unit and forward to RelayHandler.

## 4. The `Connection` class hook (the actual AOP)

`connection_hook.cpp::InstallConnectionHook` does the bytecode splice
on `net.minecraft.network.Connection`. Looking at the decompiled dump
function `sub_18000d7f0.c`, the high-level flow is:

```
InstallConnectionHook(env):
    if (data_180046030 == 0) return 0;     // g_hook must already be valid

    // 1) JVMTI capabilities
    jvmti->GetCapabilities(&caps);                 // +0x468
    caps.can_retransform_classes = 1;
    caps.can_generate_all_class_hook_events = 1;
    jvmti->AddCapabilities(&caps);                 // [+0x468]

    // 2) Hook callbacks
    cb.ClassFileLoadHook = sub_18000d360;          // +0x3c8
    jvmti->SetEventCallbacks(&cb, sizeof(cb));     // [+0x3c8]

    // 3) Enable the event
    jvmti->SetEventNotificationMode(JVMTI_ENABLE,
                                    JVMTI_EVENT_CLASS_FILE_LOAD_HOOK,
                                    nullptr);       // +0x36

    // 4) Retransform every already-loaded class named Connection
    jvmti->GetLoadedClasses(&n, &classes);          // +0x268
    for each class:
        jvmti->GetClassSignature(class, &sig, NULL);  // +0x178
        if (strcmp(sig, "Lnet/minecraft/network/Connection;") == 0)
            jvmti->RetransformClasses(1, &class);  // +0x4b8
            ++retransformed;
        jvmti->Deallocate(sig);

    jvmti->Deallocate(classes);
    return 1;
```

The `ClassFileLoadHook` callback (`sub_18000d360.c`) is invoked by
the JVM every time the `net.minecraft.network.Connection` class is
(re-)loaded. Inside that callback:

```
ClassFileLoadHook(jvmti, env, class_being_defined, name, ...) {
    if (name == NULL || strcmp(name, "net/minecraft/network/Connection") != 0)
        return;                                 // skip everything else

    if (!g_hook.valid())
        return;

    // 1) Parse the .class file (sub_180007650 → ClassFileEditor)
    ClassFileEditor ed(class_data, class_data_len);

    // 2) Add a method ref to HookBridge.onChannelActive
    u2 mref = ed.addMethodRef(g_hook.internalName,
                              "onChannelActive",
                              "(Ljava/lang/Object;Ljava/lang/Object;)V");

    // 3) Build the bytecode fragment we prepend:
    //    0x2A             aload_0                 (push `this`)
    //    0x2B             aload_1                 (push `ctx`)
    //    0xB8 hi lo       invokestatic #mref
    std::vector<u1> insertion = {0x2A, 0x2B, 0xB8, hi, lo};

    // 4) Splice it onto the front of channelActive()
    bool ok = ed.prependToMethodCode("channelActive",
                                     "(Lio/netty/channel/ChannelHandlerContext;)V",
                                     insertion);

    if (ok) {
        ed.serialize(buf);
        *new_class_data_len = buf.size();
        *new_class_data = jvmti->Allocate(buf.size());
        memcpy(*new_class_data, buf.data(), buf.size());
    }
}
```

So the bytecode that ends up being injected at the start of every
`Connection.channelActive(ChannelHandlerContext ctx)` is:

```
2A    aload_0           ; push this
2B    aload_1           ; push ctx
B8 hh ll               ; invokestatic HookBridge.onChannelActive:(Ljava/lang/Object;Ljava/lang/Object;)V
```

— exactly the 5-byte insertion from `connection_hook.cpp:44-48`, byte
for byte. Once this splice is in place, every time Minecraft spins up a
new `Connection`, the proxy DLL's native `onChannelActive` fires
before Minecraft's own code gets to read or write anything through the
channel.

## 5. RelayHandler

`relay_handler.cpp::InstallRelayHandler` runs **after** HookBridge,
and depends on the channelActive hook having just fired. Its job is
to:

1. `DefineClass` a synthetic Netty handler called by the dotted name
   `g_relay.dotName` (an obfuscated, randomly generated dotted name
   produced by `random_name.cpp`).
2. The synthetic handler extends
   `io/netty/channel/ChannelDuplexHandler` (see `kSuperInternal` in
   `relay_handler.cpp:18`).
3. `RegisterNatives` binds `channelRead` and `write` of that handler
   to native callbacks that forward into `g_relay`.

The corresponding PseudoC dump functions:

```
sub_18000b770.c    InstallRelayHandler entry
sub_18000c550.c    DefineClass + RegisterNatives for the synthetic handler
sub_18000c2f0.c    pipeline installation (last 5-stage harness for the B-side)
```

The synthetic handler never runs code that Netty itself executes; it
just exists so the JVM has JNI bindings that the bytecode splice can
indirect through. All real work happens in `Native_*` callbacks that
read/write through the original `Connection`'s channel.

## 6. ConnectionHook (post-AOP)

Once HookBridge and RelayHandler are installed, the
`ClassFileLoadHook`-spliced `Connection.channelActive` runs every
time a new connection is established. The native
`onChannelActive(this, ctx)` reads the original `ctx.channel()` and
registers the synthetic RelayHandler into the channel's pipeline so
that subsequent `channelRead` / `write` get proxied.

`sub_18000dac0.c` and `sub_18000dac0.c` (and friends) implement the
post-mid-session attach logic — when the B-side client is already
connected, the proxy tears down the existing `Connection`, replaces
its pipeline with the relay, and re-binds the channel. The source
for this lives in `connection_hook.cpp::InstallConnectionHook_post`
and the corresponding `sub_18000dac0.c`.

## 7. BServer

`b_server.cpp::InstallBServer` boots a Netty server inside the
injected JVM that listens on `0.0.0.0:25565` (`0x63DD`, big-endian).
The dump function `sub_18000f010.c` does:

1. Resolve `io.netty.channel.nio.NioEventLoopGroup`,
   `io.netty.channel.socket.nio.NioServerSocketChannel`, and
   `io.netty.bootstrap.ServerBootstrap` reflectively against the MC
   class loader.
2. Build a `ServerBootstrap`, attach a `ChannelInitializer<Channel>`
   that wraps the incoming channel with the synthetic RelayHandler.
3. Bind to port `0x63DD` (25565). The bootstrap's `bind(int)` returns
   a `ChannelFuture`; we call `.sync()` to block until the bind is
   actually live.
4. Print `"BServer: bound 0.0.0.0:25565 (all interfaces, LAN-wide)"`.

Any TCP client connecting to port 25565 from this point on lands
inside the JVM and is handled by the synthetic RelayHandler, which
relays bytes to the original `Connection`'s channel via the hook
bridge.

## 8. Other observations

* The DLL does **not** patch the network stack in any out-of-band way.
  All interception is via JVMTI `ClassFileLoadHook` + `RegisterNatives`
  against the Minecraft JVM itself; no Winsock LSP, no TDI filter, no
  Ndis hook.
* The DLL does **not** read or write `MinecraftProxy.log` directly.
  The `$LogPath` in `proxy/launcher.ps1` is read by the launcher for
  the user's convenience, not written by the proxy.
* The DLL holds no persistent state outside of three globals in
  `data_180046030` (`g_hook`), `data_180046090` (`g_relay`), and the
  various `data_18004606x` slots that hold the dotted-name strings
  for the synthetic classes.
* The DLL does not call `exit()`; it returns from `ReflectiveLoader`
  with `STATUS_SUCCESS` so the injector can `WaitForSingleObject`
  cleanly. The proxy continues running inside the injected JVM via
  the Netty threads, not via any thread the DLL itself owns.