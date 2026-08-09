# Threat model and what this tool actually does

This file describes what `GarlicV2`/`SakuraTools` does in concrete
terms, what it does **not** do, and what the realistic risks are.

It is **not** a usage guide. There is no instructions in this repo
for hooking A's session — only the analysis files. If you are looking
for "how to use this", the upstream repo has that. This file is
about understanding the system.

## 1. What the proxy does, in one sentence

**It lets two Minecraft Java Edition clients on the same physical
machine (or LAN) share one server session, by injecting a JVMTI
agent into the first client (A), splicing a Netty pipeline hook into
`net.minecraft.network.Connection`, and relaying bytes from a second
client (B) into A's network connection.**

In other words: B "borrows" A's logged-in Minecraft account, with
A's consent (because A has to actively run the launcher / injector).
There is no account theft, no password sniffing, no protocol
exploit. A chooses to share its session, the tool just provides a
local LAN bridge.

## 2. Operational flow

```
+----------------+           +------------------------+         +----------------+
|  Player A       |          |  A's Minecraft JVM     |        |   MC server    |
| (Minecraft.exe) |          |  (java.exe)            |        |   (remote)     |
+-------+--------+          +-----------+------------+        +-------+--------+
        |                                |                           |
        | "Play Multiplayer → Join X"    |                           |
        +------------------------------->+  TLS to MC server          |
        |                                +-------------------------->+
        |                                |                           |
+-------+--------+                      |                           |
|  Player B       |                      |                           |
| (Minecraft.exe) |                      |                           |
+-------+--------+                      |                           |
        |                                |                           |
        | Launcher UI: "Inject proxy"    |                           |
        +------> Launcher.exe            |                           |
                  |                      |                           |
                  | CreateProcess        |                           |
                  v                      |                           |
            GarlicInjector.exe           |                           |
                  |                      |                           |
                  | OpenProcess+VirtualAllocEx+WriteProcessMemory+CreateRemoteThread
                  +--------------------->|                           |
                                         |                           |
                                         |  ReflectiveLoader()       |
                                         |     v                     |
                                         |  ProxyInitWorker:         |
                                         |   InstallHookBridge()     |
                                         |   InstallRelayHandler()   |
                                         |   InstallConnectionHook() |
                                         |   InstallBServer()        |
                                         |                           |
        B connects to 127.0.0.1:25565    |                           |
        +-------------------------------->|                           |
                                         |                           |
                                         |  Netty ServerChannelInit |
                                         |     v                     |
                                         |  bssideHandler.channelRead
                                         |     v                     |
                                         |  HookBridge.onChannelRead |
                                         |     v                     |
                                         |  A's Connection.channel().write()
                                         +------------------------->|
                                                                     |
B receives whatever A's server sees <------ (relay byte stream) <------+
```

What B sees is exactly what A would see from the same point of view.
Both clients control the same player character. If A presses W,
both clients see the character move forward. If B presses W,
**only B sees the local prediction** — the server only sees one
`PlayerPosition` packet (the one from whichever client won the
input race that frame). In practice this means **A and B cannot
both be in active control simultaneously**; whoever sends a packet
first owns that tick.

## 3. What the proxy does *not* do

* **It does not authenticate B.** Mojang's session is held by A.
  B simply "piggy-backs" on A's account by joining on `127.0.0.1`.
  B's offline-mode login (or any account) is irrelevant; the server
  only ever sees A's UUID.
* **It does not proxy B's traffic directly to the server.** All
  packets from B are filtered through A's local Netty pipeline
  before they hit the wire. So B cannot bypass A's anti-cheat
  hooks, cannot reach a different server, and cannot spoof a
  different account.
* **It does not bypass server-side anti-cheat.** Whatever the MC
  server's anti-cheat sees is the same view it has always seen:
  one player, controlled by a single account, sending Netty
  packets.
* **It does not crack Minecraft.** No Mojang server is contacted
  beyond what A would normally do. No Mojang credentials are
  stolen. No Mojang tokens are forged.
* **It does not modify disk content** of any Minecraft file. The
  JVMTI `ClassFileLoadHook` only patches classes in-memory at load
  time; nothing is written back to the JAR.
* **It does not persist across reboots.** It runs entirely inside
  A's JVM process. When A quits Minecraft, the proxy dies.

## 4. Realistic risks

The proxy's risk surface is small because it does not talk to the
network in any way that is novel from Minecraft's point of view:

1. **Account sharing against Mojang's terms of service.** Mojang
   explicitly forbids account sharing in the EULA. If A lets B
   play on A's account, both A and B are violating the EULA.
   Realistically, Mojang has never enforced this with bans; the
   worst case is account suspension if a player is reported.
2. **Local security boundary.** If B is on a different machine on
   the same LAN, B can connect to A's port 25565 over the LAN
   (the BServer binds `0.0.0.0:25565`, not `127.0.0.1`). This
   means **anyone on the LAN** can join A's game without A's
   knowledge, until A quits. Mitigation: firewall rule, or a
   one-line patch in `b_server.cpp` to bind `127.0.0.1` instead
   of `0.0.0.0`.
3. **Anti-cheat detection by the server.** Some servers (mostly
   large paid ones like Wynncraft or Hypixel) run aggressive
   client-side anti-cheats that fingerprint the JVM. None of
   these currently detect JVMTI agents; if one ever did, this
   proxy would be flagged. There is no known incident of this
   happening.
4. **Privilege on the host.** The injector calls
   `AdjustTokenPrivileges(SeDebugPrivilege)` so it can
   `OpenProcess(PROCESS_ALL_ACCESS)` on the Minecraft PID. This
   requires the launcher to already be running as a user with
   SeDebugPrivilege (admin by default, but any user on Windows
   can have it granted by a service). So **the launcher's
   privilege is the only standing requirement**; nothing else
   in the chain requires admin.
5. **Privacy / telemetry.** Mojang and Microsoft do not see this
   proxy's JVMTI hooks. They see exactly what A normally sends.
   No additional telemetry is exfiltrated.

## 5. Why "散播病毒" is the wrong characterisation

The GarlicV2 maintainer ("大蒜") has accused people of "spreading a
virus" for distributing this kind of analysis. That is incorrect:

* The proxy does not self-replicate. It runs in a single Minecraft
  process and dies with it.
* It does not modify Minecraft binaries. The `ClassFileLoadHook`
  splice lives only in-memory.
* It does not exfiltrate credentials. The PBKDF2 password it uses
  to decrypt its own DLL is a hard-coded constant, not a leaked
  Mojang credential.
* It is not detected by any major anti-virus product at the time of
  writing.

What it *does* do is share A's account with B without using
Mojang-provided mechanisms. That violates Mojang's EULA, but it
isn't a malware-style violation.

## 6. Summary

* **What the tool is:** a JVMTI-based LAN bridge between two
  Minecraft clients.
* **What it requires:** A's consent to run the launcher, A and B
  on the same machine or LAN, Mojang's online-mode session on A.
* **What it doesn't do:** crack, exfiltrate, self-replicate,
  persist, escalate privileges beyond what A already has.
* **What it is mistaken for:** a "virus" — incorrectly, by the
  GarlicV2 maintainer.