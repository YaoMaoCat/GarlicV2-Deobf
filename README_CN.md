# GarlicV2-Deobf

> **English version: [README.md](README.md)**

> **本仓库不是原创项目。**
>
> 本仓库内所有 C / C++ / PowerShell / CMake 文件（即 `injector/`、
> `mindll/`、`native/`、`proxy/`、`scripts/`、`tests/`、`CMakeLists.txt`
> 的全部内容）**都是来自**
> [GzSakura1338/SakuraTools](https://github.com/GzSakura1338/SakuraTools)
> 的源码（即"Garlic" / "GarlicV2" Minecraft JVMTI 代理工具链）。
> 唯一的例外是 `native/loader.cpp`：为了与二进制一致，GarlicV2 的维护者在
> `DllMain` 里加了一个 FNV-1a 内部鉴权（约 35 行；详见
> [`analysis/dll_vs_native.md`](analysis/dll_vs_native.md)）。
> 其他内容放在这里**仅仅**是为了让读者能验证：从 `artifacts/GarlicProxy.pkg`
> 中恢复出来的 DLL 与其所声称的源码一致。
>
> 本仓库**真正新增的内容**：
>
> - `analysis/` — 完整逆向分析笔记（launcher、injector、Themida、代理 DLL、BServer、鉴权、DLL vs native 差异）。
> - `artifacts/GarlicProxy.pkg` —— 发布时随 launcher 一起分发的加密包。
> - `artifacts/GarlicProxy.dll` —— 解密得到的 DLL。
> - `artifacts/decrypt_pkg.py`  —— 解密脚本。
> - `artifacts/pseudo_dump/`    —— DLL 的 PseudoC 反编译器 dump，
>   仅作为额外验证。
>
> **请不要把本仓库当作原创作品。** 代理、launcher、反射注入器与构建系统
> 的全部功劳都归 SakuraTools 的作者所有。下方 §1 中记录的包格式与解密密钥，
> 是从公开发布的 `unpacked_GarlicNELauncherV2.exe` /
> `data/GarlicInjector.exe` 中逆向得到的，仅用于互操作性分析。

本仓库目录：

| 路径 | 作用 |
|------|------|
| `injector/` | 反射式 DLL 注入器（`reflective_injector.exe`）。**（SakuraTools 源码，未改动。）** |
| `mindll/`   | 用于测试的最小反射式 DLL 示例。**（SakuraTools 源码，未改动。）** |
| `native/`   | Minecraft JVMTI 代理本体。**（SakuraTools 源码；`loader.cpp` DllMain 有修改——加入了 FNV-1a 验证器以与二进制一致。）** |
| `proxy/launcher.ps1` | 用户侧的 launcher / 注入器 UI。**（SakuraTools 源码，未改动。）** |
| `tests/`    | 构建期的 Java / C++ 自测。**（SakuraTools 源码，未改动。）** |
| `scripts/`  | 构建 + 注入辅助脚本。**（SakuraTools 源码，未改动。）** |
| `analysis/` | **本仓库新增。** 完整逆向分析笔记（launcher、injector、Themida、代理 DLL、BServer、鉴权机制、DLL vs native 差异分析）。 |
| `artifacts/` | **本仓库新增。** 解密出的二进制、加密包、解密脚本、PseudoC dump。 |
| `artifacts/decrypt_pkg.py` | **唯一新增的代码。** 单文件 Python 解密器；其他都是文档 / dump 产物。 |

---

## 1. 从 `GarlicProxy.pkg` 还原 `GarlicProxy.dll`

launcher（`data/GarlicInjector.exe`）会读取 `GarlicProxy.pkg`、在内存中解密，
然后用反射式加载把得到的 DLL 注入到目标 Java 进程里。这个包的格式未文档化，
密钥又被硬编码进 injector，所以不解构 injector 的话 `.pkg` 本身是不透明的。

我们还原了它的格式并用纯 Python 重新实现了对应解密器。
从 `data/GarlicProxy.pkg` 还原 DLL：

```
python artifacts/decrypt_pkg.py
# 在当前目录下写出 GarlicProxy.dll（301 056 字节）
```

已在随 `unpacked_GarlicNELauncherV2.exe` 一起分发的 `data/GarlicProxy.pkg`
（字符串 `"GarlicBridge-V2-20260809"`）上验证通过。

### 1.1 包头布局（100 字节，小端）

```
偏移   长度  含义
0x00    8    Magic ASCII 字符串 "GNP2PKG!"
0x08    4    格式版本（必须为 2）
0x0C    4    头大小（必须为 0x64 == 100）
0x10    8    密文长度 N（LE）
0x18   16    PBKDF2 salt
0x28   12    AES-GCM nonce
0x34   32    保留 / 辅助头字段（被 AAD 覆盖）
0x54   16    AES-GCM tag
0x64    N    AES-GCM 密文（明文 = Windows x64 PE DLL）
```

injector 做的合法性校验：

```
file_size == N + 100
b"GNP2PKG!" == header[0:8]
2            == *(uint32_t*)&header[0x08]
0x64         == *(uint32_t*)&header[0x0C]
N            == *(uint64_t*)&header[0x10]
N > 0
```

### 1.2 密钥派生

injector 用一个硬编码的 PBKDF2 密码（32 字节，在
`unpacked_GarlicInjector.exe` 中的文件相对偏移 `0x19_880`）：

```
4d 8a 16 c3 57 91 e2 2f 6b d4 09 7e a5 38 f1 64
b2 0c 73 de 41 9f 25 88 fa 56 1b c9 34 67 ad 02
```

密钥派生：

```
key = PBKDF2-HMAC-SHA256(
        password = 上面那 32 字节常量,
        salt     = header[0x18 : 0x28],     # 16 字节
        iter     = 75 000,                  # 0x124F8
        dklen    = 32)
```

对应算法：

```
BCryptOpenAlgorithmProvider(&alg, "SHA256", nullptr, BCRYPT_ALG_HANDLE_HMAC_FLAG)
BCryptDeriveKeyPBKDF2(alg, password, 32, salt, 16, 75 000, key_out, 32, 0)
```

### 1.3 解密负载（AES-256-GCM）

```
BCryptOpenAlgorithmProvider(&alg, "AES", nullptr, 0)
BCryptSetProperty(alg, "ChainingMode", "ChainingModeGCM", 32, 0)
BCryptGenerateSymmetricKey(alg, &key, obj, obj_len, key, 32, 0)
BCryptDecrypt(
    key,
    plaintext      = header + 0x64,
    plaintext_len  = N,
    paddingInfo    = {
        cbSize        = 0x58,
        dwInfoVersion = 1,
        pbNonce       = header + 0x28, cbNonce = 12,
        pbAuthData    = header + 0x00, cbAuthData = 0x54,    # 84 字节
        pbTag         = header + 0x54, cbTag    = 16,
    },
    IV  = nullptr, cbIV = 0,
    out  = heap(N), out_len = N,
    result_len, flags = 0)
```

`AAD` 覆盖**头部的 84 字节**（magic + 版本 + 长度 + salt + nonce）。
GCM tag 紧接着占用 16 字节。再往后第一个字节才是密文。

解密后 injector 还会做这些校验：

* GCM tag（由 `BCryptDecrypt` 自己处理）；
* `memcmp(SHA-256(plaintext), header[0x34:0x54], 32) == 0`；
* 明文前两字节是 `"MZ"`。

任何一项不满足都会拒收，launcher 以非零退出码结束。

### 1.4 `auth-nonce` / `auth-token`（会话鉴权）

`GarlicInjector.exe` 的调用形式是：

```
GarlicInjector.exe <pkg-path> --auth-nonce <16-位十六进制> --auth-token <16-位十六进制>
```

launcher 每次启动都会现场生成 nonce 和 token：

```
bridge_seed = FNV1a-64("GarlicBridge-V2-20260809", seed = 0x14650fb0739d0383)
nonce       = QueryPerformanceCounter()
                ^ (GetTickCount64() << 0x11)
                ^ (GetCurrentProcessId()  << 0x20)
                ^ &QueryPerformanceCounter
token       = FNV1a-64(nonce, seed = bridge_seed, finish = "GARLICAU" XOR)
```

injector 收到的 24 字节 "auth 块"是：

```
arg3[0] = 0x4741524c49434155     // "GARLICAU"
arg3[1] = nonce（8 字节 LE）
arg3[2] = token（8 字节 LE）
```

injector 用同一个 FNV-1a 算法从 `arg3[1]` 重新派生出 `token'`，只有
`token' == arg3[2]` 才放行。通过鉴权门之后，
**`sub_140001000` / `sub_140001750` / `sub_1400021e0` 是唯一会接触包数据的
函数，它们都不消费 `arg3`**——PBKDF2 密码就是那个硬编码的 32 字节常量。
也就是说：

> **会话期的 `auth-nonce` / `auth-token` 只是防篡改门，根本没参与密钥派生。
> 任何拿到硬编码 PBKDF2 密码的人都能绕过 launcher 直接解密包。**

这正是 `artifacts/decrypt_pkg.py` 所做的。

### 1.5 参考解密器（Python）

```python
import hashlib
from cryptography.hazmat.primitives.ciphers.aead import AESGCM

PWD = bytes.fromhex(
    "4d8a16c35791e22f6bd4097ea538f164b20c73de419f2588fa561bc93467ad02")

def decrypt(pkg_path):
    d = open(pkg_path, "rb").read()
    assert d[:8] == b"GNP2PKG!"
    n        = int.from_bytes(d[0x10:0x18], "little")
    salt     = d[0x18:0x28]
    nonce    = d[0x28:0x34]
    aad      = d[0x00:0x54]
    tag      = d[0x54:0x64]
    ct       = d[0x64:0x64 + n]

    key = hashlib.pbkdf2_hmac("sha256", PWD, salt, 75_000, dklen=32)
    return AESGCM(key).decrypt(nonce, ct + tag, aad)
```

完整可运行的实现见 `artifacts/decrypt_pkg.py`。

---

## 2. 从源码构建代理

代理 DLL 由 `native/` 编译得到（CMake target `MinecraftProxy_msvc`）。
`artifacts/GarlicProxy.dll` 就是 `artifacts/GarlicProxy.pkg` 解密后的产物——
它就是这份源码编译出来的二进制。

```
cmake -S . -B build -G "Ninja"      # 或 "Visual Studio 17 2022"
cmake --build build --target MinecraftProxy_msvc --config Release
```

反射式注入器由 `injector/` 编译：

```
cmake --build build --target reflective_injector --config Release
```

launcher 是一个 PowerShell 脚本（`proxy/launcher.ps1`）；在构建机上运行，
等 MC 起来后选 *"Inject proxy (auto-wait for MC window)"*。

---

## 3. 关于 `artifacts/pseudo_dump/`

`artifacts/pseudo_dump/` 是 Binary Ninja 的 PseudoC 反编译器对
`artifacts/GarlicProxy.dll` 跑出来的结果（每个函数一个 .c 文件，共 828 个
文件，约 700 KB）。放在这里**只是为了**让任何人拿一个反编译器就能验证
DLL 和 `native/` 里 SakuraTools 源码的对应关系——它不能替代真正的源码，
也不会被维护。

SakuraTools 源码 与 dump 的交叉对应表：

| SakuraTools 源码（`native/` 内） | PseudoC dump 函数 | 对得上什么 |
|--------------------|------------------------|-------|
| `native/loader.cpp` | `sub_180001740.c`（"`ProxyInitWorker`"） | 1:1 控制流：`AttachCurrentThreadAsDaemon` → 轮询 MC `ClassLoader` → `InstallHookBridge` → `InstallRelayHandler` → `InstallConnectionHook` → `InstallBServer`。 |
| `native/relay_handler.cpp` | `sub_18000b770.c`（入口）+ `sub_18000c550.c`（handler 类）+ `sub_18000c2f0.c`（pipeline 安装） | 同样的 JNI 签名（`io/netty/channel/ChannelDuplexHandler`、`channelRead`、`write`），同样的错误日志字符串（`"InstallRelayHandler/DefineClass"`、`"/RegisterNatives"`、`"/ctor"`）。 |
| `native/connection_hook.cpp` | `sub_18000d7f0.c`（hook 安装）+ `sub_18000d360.c`（过滤）+ `sub_18000f390.c`（live hook） | 同样的 hook 类（`net/minecraft/network/Connection`），同样的常量（`ClassFileLoadHook`、`RetransformClasses`）。 |
| `native/b_server.cpp`     | `sub_18000f010.c`（server bootstrap） | 同样的常量（`io/netty/channel/nio/NioEventLoopGroup`、`…/socket/nio/NioServerSocketChannel`），同样的绑定日志（`"BServer: bound 0.0.0.0:25565 (all interfaces, LAN-wide)"`），同样的端口（`0x63dd`）。 |
| `native/trampolines.cpp`  | `sub_18000adb0.c` | 同样的 JNI 错误日志字符串（`"InstallHookBridge/GetStaticMethodID"`、`"/RegisterNatives"`、`"/DefineClass"`）。 |
| `native/env.cpp`          | `sub_18000adb0.c` 中的 helper | `AttachCurrentThreadAsDaemon`、JVMTI `GetAllThreads` / `GetThreadInfo`。 |

二进制里每一个有辨识度的字符串都能对应上，从而确认该二进制就是从
SakuraTools 源码树编译出来的。

---

## 4. 来源 / 归属声明

"Garlic" / "GarlicV2" Minecraft JVMTI 代理工具链是 **SakuraTools** 项目的工作成果：

* 仓库：<https://github.com/GzSakura1338/SakuraTools>
* 作者 / 维护者：**GzSakura1338**

本仓库中 `injector/`、`mindll/`、`native/`、`proxy/`、`scripts/`、`tests/`、
`CMakeLists.txt` 和原版 `.gitignore` 下的所有内容都是**来自 SakuraTools 的
逐字源码**。没有文件被修改过，这里没有写过一行源码。这些目录放在本仓库里
**纯粹是为了让读者确认 `artifacts/` 下的 DLL 与 SakuraTools 源码编译产物
一致。**

本仓库**真正新增**的内容只有：

* `artifacts/GarlicProxy.pkg`     —— 发布时随包的加密包。
* `artifacts/GarlicProxy.dll`     —— 用 `artifacts/decrypt_pkg.py` 解密出的 DLL。
* `artifacts/decrypt_pkg.py`      —— 一个 60 行的纯 Python 解密器（PBKDF2-HMAC-SHA256
  + AES-256-GCM），复现了 `data/GarlicInjector.exe` 里的解密逻辑。这是本仓库
  **唯一**不在 SakuraTools 里的代码。
* `artifacts/pseudo_dump/`        —— DLL 的 828 文件 PseudoC 反编译器 dump，仅作为
  额外验证用。
* `README.md`、`README_CN.md`、`LICENSE` —— 本文档。

如果你觉得这个代理、launcher 或反射注入器有价值，请把你的支持、bug 报告和 star
都投向原 SakuraTools 仓库。本仓库**不是**提交代理本身 issue 的地方。

### 4.1 那为什么还要发出来？

因为上游的包格式没有文档化，而任何想做到下面事情的人：

* 在不跑 launcher 的前提下验证 `data/GarlicProxy.pkg` 的内容；
* 从别的操作系统 / 工具链接入 launcher；
* 审计 injector 到底对 `MinecraftProxy.dll` 做了什么；

都需要把这个格式逆向出来。逆向并不简单（Themida VM、AES-GCM 带 header AAD、
基于 FNV-1a 的会话鉴权），结果能塞进一个 Python 文件里，就是
`artifacts/decrypt_pkg.py`。本仓库剩下的内容都是文档 / 验证材料。

**GarlicV2 的维护者（"大蒜" / Dev）此前曾因为本人指出 GarlicV2 工具链其实就是 SakuraTools，
而指控本人"散播病毒"，并把本人从项目群聊里踢出。** 本仓库并没有再分发任何新二进制，
只是指向 launcher 已经在分发的公开二进制，并展示怎么验证它和公开源码一致。任何关于再分发的
投诉应该去找 GarlicV2 维护者，而不是本仓库。

---

## 5. 本次新增的文件

```
artifacts/GarlicProxy.dll     -- 解密出的负载（MinecraftProxy.dll）
artifacts/GarlicProxy.pkg     -- 发布时的原始加密包
artifacts/decrypt_pkg.py      -- 单文件 Python 解密器
                                 （本仓库唯一新增的代码）
artifacts/pseudo_dump/        -- 由 Binary Ninja 对 artifacts/GarlicProxy.dll
                                 生成的 828 个 PseudoC 风格 .c 文件
README.md                     -- 本文件（英文版）
README_CN.md                  -- 本文件（中文版）
LICENSE                       -- MIT，仅覆盖真正新增的代码
```

`native/`、`injector/`、`mindll/`、`proxy/`、`scripts/`、`tests/`、
`CMakeLists.txt` 和原版 `.gitignore` 都跟 SakuraTools 上游版本一致，
原样保留以供读者确认 DLL 与上游源码一致。本仓库没有写过一行这种代码。

---

## 6. 许可证

本仓库以 **MIT 许可证**发布（见 `LICENSE`）。
`injector/`、`mindll/`、`native/`、`proxy/`、`scripts/`、`tests/` 中的 C / C++
源码是 SakuraTools 作者的成果，沿用他们发布时使用的许可证；上面的 MIT 声明
**只适用于本仓库真正新增的少量代码**（README、LICENSE、`artifacts/decrypt_pkg.py`）。

`injector/ReflectiveDLLInjection.h` 和 `native/ReflectiveLoader.c` 是
Stephen Fewer 的
[ReflectiveDLLInjection](https://github.com/stephenfewer/ReflectiveDLLInjection)
公有领域项目的派生作品，沿用原作者的公有领域声明。

`native/include/` 下的 `jni.h` / `jvmti.h` 是 Sun / Oracle 的受版权保护头文件
（Oracle Binary Code License），按原始许可证保留，未做修改。

---

## 7. 逆向分析笔记

launcher、injector 与解密出的代理 DLL 的详细逆向笔记见
[`analysis/`](analysis/INDEX.md)：

* [`analysis/decryption.md`](analysis/decryption.md) —— 包格式细节。
* [`analysis/auth.md`](analysis/auth.md) —— `auth-nonce` / `auth-token` 机制。
* [`analysis/launcher.md`](analysis/launcher.md) —— `unpacked_GarlicNELauncherV2.exe`。
* [`analysis/injector.md`](analysis/injector.md) —— `data/GarlicInjector.exe`。
* [`analysis/injector_diff.md`](analysis/injector_diff.md) —— **SakuraTools `injector/` 与 `data/GarlicInjector.exe` 的差异**。
* [`analysis/injector_chain.md`](analysis/injector_chain.md) —— **完整鉴权链：launcher → injector → DLL**（Mermaid 时序图 + 5 个胶水点）。
* [`analysis/themida.md`](analysis/themida.md) —— Themida 保护细节。
* [`analysis/proxy.md`](analysis/proxy.md) —— 解密出的 DLL。
* [`analysis/bserver.md`](analysis/bserver.md) —— B 端 Netty 服务器。
* [`analysis/random_name.md`](analysis/random_name.md) —— 合成类名生成。
* [`analysis/threat_model.md`](analysis/threat_model.md) —— 工具能做什么 / 不能做什么。
* [`analysis/verify/`](analysis/verify/) —— 构建+SHA-256 比对脚本。
* [`analysis/dll_vs_native.md`](analysis/dll_vs_native.md) —— **DLL 与 `native/` 的终极差异分析**；结论是大蒜在 `DllMain` 开头加了一个 FNV-1a 内部验证器（约 35 行新增代码；`native/` 其余部分与二进制逐字节一致）。