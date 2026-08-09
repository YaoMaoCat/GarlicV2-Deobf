# B-side Server

This file documents the full life-cycle of the **B-side Netty
server** that the proxy boots inside the injected JVM, and the way
it accepts a second Minecraft client and relays its bytes into A's
session.

The B-side server is the most visible end of the proxy. From a
player's perspective:

* A launches Minecraft normally. The proxy is injected by the
  launcher, the proxy splices `channelActive` so A's connection is
  captured, and a Netty listener is brought up on `0.0.0.0:25565`
  inside A's JVM.
* B runs `Minecraft → Multiplayer → Add Server → 127.0.0.1:25565`
  (or `<lan-ip-of-A>:25565`). B connects normally; the proxy
  multiplexes B into A's existing server connection.

## 1. End-to-end call chain

```
InstallBServer(env)                                           ← b_server.cpp
└── new NioEventLoopGroup()
└── new ServerBootstrap()
└── new InetSocketAddress("0.0.0.0", 0x63DD)                   ← 25565
└── bootstrap
        .group(elg)
        .channel(NioServerSocketChannel.class)
        .childHandler(<ChannelInitializer from InstallServerChannelInit>)
        .bind(addr).sync()
└── log "BServer: bound 0.0.0.0:25565 (all interfaces, LAN-wide)"

(per accepted connection) ServerChannelInit.initChannel(ch)      ← sub_18000ec70
└── ch.config().setTcpNoDelay(true)
└── ch.pipeline()
       └── (re)configure pipeline serialization
       └── strip or keep `bundler`/`unbundler` based on BundlerInfo availability
       └── pipeline.addLast("bside", bsideHandler)
└── state = AwaitHandshake
```

The dump function for the bootstrap is `sub_18000f010.c`. The dump
function for the per-connection `initChannel` is `sub_18000ec70.c`.

## 2. `sub_18000f010.c` — server bootstrap

Each `(*(*env + N))(env, ...)` call is one of:

| vtable offset | JNI method |
|---------------|------------|
| `+0x28` | `DefineClass` |
| `+0x108` | `GetMethodID` |
| `+0xb8` | `DeleteLocalRef` |
| `+0x538` | `NewStringUTF` |
| `+0xf8` | `CallObjectMethod` |
| `+0x720` | `ExceptionCheck` |
| `+0x88` | `ExceptionDescribe` |
| `+0xb0` | `DeleteGlobalRef` |

The full flow (decompiled):

```c
elg      = DefineClass(env, mcLoader, "io.netty.channel.nio.NioEventLoopGroup",
                                          "Lio/netty/channel/nio/NioEventLoopGroup;");
bootstrap= DefineClass(env, mcLoader, "io.netty.bootstrap.ServerBootstrap",
                                          "Lio/netty/bootstrap/ServerBootstrap;");
ch_class = DefineClass(env, mcLoader, "io.netty.channel.socket.nio.NioServerSocketChannel",
                                          "Lio/netty/channel/socket/nio/NioServerSocketChannel;");
addr     = FindClass(env, "java/net/InetSocketAddress");

elg_obj       = NewObjectA(env, elg);                 // new NioEventLoopGroup()
bootstrap_obj = NewObjectA(env, bootstrap);            // new ServerBootstrap()

addr_obj = NewObjectA(env, addr,
                      NewStringUTF(env, "0.0.0.0"),
                      jint(0x63DD));                    // new InetSocketAddress("0.0.0.0", 25565)

bootstrap_obj.group(elg)
             .channel(NioServerSocketChannel.class)
             .childHandler(<init from InstallServerChannelInit>)
             .bind(addr)
             .sync();
log("BServer: bound 0.0.0.0:25565 (all interfaces, LAN-wide)");
```

`0x63DD = 25565` is hard-coded as an immediate argument in the
`bootstrap.bind(addr, 0x63DD)` call. The match with
`proxy/launcher.ps1:10`'s `$ProxyPort = 25565` and the
`b_server.cpp:1206` literal `(jint)25565` is exact.

## 3. `sub_180012180.c` — ServerChannelInit

`InstallServerChannelInit` builds the class that handles the **first
Netty handler inserted into every B-side channel**:

* It extends `io.netty.channel.ChannelInitializer<Channel>` (string
  literal at offset 0x23).
* The class is placed in a **randomly-generated package** via
  `random_name.cpp::GenerateRandomPackageName()` — see `random_name.md`.
* The class name is `g_simple = GenerateRandomClassName(2, 3)`,
  also randomly generated.
* The synthetic class overrides `initChannel(Channel)` (signature
  `(Lio/netty/channel/Channel;)V`), and the override is bound via
  `RegisterNatives` to `sub_18000ec70`.

So when a TCP connection arrives on port 25565, Netty fires
`initChannel(ch)` on the proxy's randomly-named subclass of
`ChannelInitializer`. Control then jumps to `sub_18000ec70` (the
`initChannel` native).

## 4. `sub_18000ec70.c` — per-connection setup

For each incoming B-side channel `ch`:

```c
log("BServer: initChannel for incoming ch=%p", ch);

ch.config().setTcpNoDelay(true);                       // disable Nagle
pipeline = ch.pipeline();                              // get the pipeline

configure_serialization(pipeline, ...);               // JSON / ByteString modes
remove_or_keep_bundler(pipeline);                      // strip if BundlerInfo is gone

pipeline.addLast("bside", bsideHandler);               // <-- the relay handler

state = AwaitHandshake;                                // (in data_180046688)
log("  B channel captured, state=AwaitHandshake");
```

The bundler strip is conditional on the presence of `data_180046398`
and `data_180046390` (these are the `BundlerInfo` registry slots
populated by `InstallBServer` if the bundled-format codec is in
use). The exact condition reads:

```
if (data_180046398 == 0 || data_180046390 == 0)
    remove("bundler", "unbundler")
    log "  bundle handlers removed (no BundlerInfo)"
else
    log "  bundle handlers kept (BundlerInfo available)"
```

Netty's `BundlerInfo` is the registry that controls whether
`ChannelOutboundHandler`s get coalesced into a single flush. Stripping
the bundler when `BundlerInfo` is missing avoids a class-cast
exception when downstream handlers try to access it.

## 5. B-side handler and the actual byte relay

The "bside" handler installed at the end of step 4 is implemented in
`sub_180011c10.c` ("`io/netty/channel/ChannelInboundHandlerAdapter`").
That file defines a Netty `ChannelInboundHandlerAdapter` subclass
named by `random_name.cpp` and binds four native methods:

* `channelActive(ChannelHandlerContext)` — fires when the TCP
  connection completes the handshake; sends the proxy's
  "handshake ack" back to B (state → `Ready`).
* `channelInactive(ChannelHandlerContext)` — fires when B disconnects.
* `channelRead(ChannelHandlerContext, Object msg)` — the **byte
  relay**: every Netty `ByteBuf` that arrives from B is queued and
  forwarded into A's captured `Connection.channel().write(...)` via
  the hook bridge.
* `exceptionCaught(ChannelHandlerContext, Throwable cause)` — error
  sink that closes both sides.

In `sub_180011c10.c`:

```c
"io/netty/channel/ChannelInboundHandlerAdapter"   // superclass
"channelActive"    "(Lio/netty/channel/ChannelHandlerContext;)V"
"channelInactive"  "(Lio/netty/channel/ChannelHandlerContext;)V"
"channelRead"      "(Lio/netty/channel/ChannelHandlerContext;Ljava/lang/Object;)V"
```

The native implementations (`Native_*_onChannelActive`,
`Native_*_onChannelInactive`, `Native_*_onChannelRead`,
`Native_*_onExceptionCaught`) live in the same compilation unit.

## 6. Mid-session attach — when A is *already* in-game

If A is **already on a server** when the proxy is injected, the
proxy can't pre-hook the channel before Minecraft's own handshake.
Instead it goes through `sub_18000dac0.c` ("MAIN-GATE"):

1. Look up `net.minecraft.client.Minecraft` via the class loader.
2. Get `Minecraft.getInstance()`.
3. Get `Minecraft.execute(Runnable)`.
4. Build a `Runnable` (`sub_18000e9f0`) that:
   * walks `Minecraft.getConnection().getConnection().channel().pipeline()`
     (`sub_18000f390.c`),
   * finds the synthetic RelayHandler installed by the
     `ClassFileLoadHook` splice,
   * attaches the existing B-side session to that pipeline.

The reason for going through `Minecraft.execute()` is that **all
Netty pipeline mutation in Mojang's code happens on the GL/render
thread**, and `Minecraft.execute(Runnable)` is the only safe
cross-thread hook to get onto that thread.

If `data_180046040` (the "captured A connection" flag) is
non-zero, the runner logs:

```
"mid-session: captured A's live Connection + attached relay (A already in-game)"
```

Otherwise (the normal cold-boot case where the channelActive splice
fired during `Connection.channelActive(...)`) the runner logs nothing
and falls through to the natural proxy path.

## 7. `sub_180011440.c` — `[A-CLOSE]` handler

When A's netty connection to the remote server closes (A leaves the
game, the server kicks A, etc.), the `[A-CLOSE]` handler runs:

```c
ch = data_180046680;                     // cached A-side channel
if (ch == NULL) return;

conn = ch.pipeline().get(data_180046340);  // the A-side Connection
if (conn != NULL)
    conn.channel().close();             // tear down A's netty channel
    log("[A-CLOSE] A's netty channel to remote server closed directly");
data_180046680 = NULL;                  // clear cached A channel
```

Closing the A-side channel propagates through Netty to the bside
handler, which then closes B's TCP connection too. The full state
machine for A→B lifecycle is:

```
                AwaitHandshake
                     │
   (B connects)     │     (B disconnects)
        ▼           │           ▼
      Ready ◄───────┴────► B-closed
        │
        ▼
   (A leaves server)
        ▼
    A-closed → B-closed
```

## 8. What the B-side server does *not* do

* It does not speak the Minecraft protocol itself — it only relays
  bytes between B and A. All protocol parsing, entity tracking,
  inventory management, etc. happens in B's own Minecraft client.
* It does not authenticate B. Mojang's online-mode authentication
  is bypassed because A already has an authenticated session, and
  B "piggy-backs" on A's account by simply connecting to localhost
  on A's machine.
* It does not modify the wire protocol. There is no packet
  rewriting, no Mojang-telemetry scrubbing, no chunk-fix, no
  re-encryption. The byte stream from B is forwarded into A's
  session verbatim, and vice versa.

This makes the tool strictly **a LAN-bridge** between two Minecraft
clients on the same physical machine (or LAN): A and B both see
the same world, and B can join a server that A is on without
needing a second account.