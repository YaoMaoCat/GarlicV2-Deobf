# Random-name generation

The proxy uses **synthesised, randomly-named Java classes** to avoid
having to ship any Mojang code in its DLL. Every injected class is
built at runtime with `DefineClass` and given a name drawn from a
96-word vocabulary chosen so the resulting dotted name looks like a
legitimate Netty or Mojang package prefix.

This file documents the algorithm, the vocabulary and the entropy
budget, then discusses what the random names are actually trying to
hide from.

## 1. Code

The whole generator is in `native/random_name.cpp` (117 lines,
compiled into the DLL — see `sub_180002e20.c` for the C runtime
helper and `sub_180003410.c` for the `std::string` plumbing that
survives the decompiler).

```cpp
namespace {
constexpr std::array<const char*, 96> kWords = {
    "Azure",   "Amber",   "Arcane",   "Aurora",   "Blaze",   "Bramble",
    "Bright",  "Cinder",  "Cipher",   "Cobalt",   "Comet",   "Crimson",
    ... 96 entries total, all fantasy-adjective nouns ...
};

std::mt19937_64 make_rng() {
    LARGE_INTEGER pc{};
    QueryPerformanceCounter(&pc);
    FILETIME ft{};
    GetSystemTimeAsFileTime(&ft);
    uint64_t seed =
        (uint64_t)pc.QuadPart ^
        ((uint64_t)ft.dwHighDateTime << 32 | ft.dwLowDateTime) ^
        ((uint64_t)GetCurrentProcessId() << 16) ^
        (uint64_t)GetCurrentThreadId();
    return std::mt19937_64(seed);
}
}  // namespace

std::string GenerateRandomClassName(int minWords = 2, int maxWords = 3) {
    if (minWords < 1) minWords = 1;
    if (maxWords < minWords) maxWords = minWords;
    std::mt19937_64 rng = make_rng();
    std::uniform_int_distribution<int> nDist(minWords, maxWords);
    std::uniform_int_distribution<size_t> wDist(0, kWords.size() - 1);
    int n = nDist(rng);
    std::string out;
    out.reserve(48);
    for (int i = 0; i < n; ++i) out += kWords[wDist(rng)];
    return out;
}

std::string GenerateRandomPackageName() {
    std::mt19937_64 rng = make_rng();
    std::uniform_int_distribution<int> depthDist(1, 3);
    std::uniform_int_distribution<size_t> wDist(0, kWords.size() - 1);
    int depth = depthDist(rng);
    std::string out;
    for (int i = 0; i < depth; ++i) {
        if (i > 0) out += "/";
        std::uniform_int_distribution<int> wordCountDist(1, 2);
        int wordCount = wordCountDist(rng);
        std::string firstWord = kWords[wDist(rng)];
        for (char& c : firstWord) c = std::tolower((unsigned char)c);
        out += firstWord;
        for (int j = 1; j < wordCount; ++j) out += kWords[wDist(rng)];
    }
    return out;
}
```

The class name is a run-together concatenation of `n` capitalised
words from `kWords`. The package name is `1..3` segments separated by
`/`, where the first word of each segment is lowercased and any
following words are run-on in their original capitalisation.

## 2. Examples (sampled by hand)

Possible class names (from the vocabulary):

```
AzureAmber            (2 words, 96*96 = 9 216 possibilities)
GlimmerRadiant        (2 words)
CinderPhoenixStorm    (3 words, 96^3 ≈ 884 736 possibilities)
VortexShadowLunar     (3 words)
```

Possible package names (first segment lowercased, run-on capitalised):

```
azure/Amber
cinder/Glimmer/Radiant
azure/AmberStorm
flux/VortexLunar
```

The full internal name (passed to `MakeInternalName`) is
`g_trampolinePackage + "/" + g_simple`, e.g.
`cinder/Glimmer/Radiant/VortexShadowLunar`.

## 3. Where each random name is used

| Synthetic class | Source call site | Purpose |
|-----------------|------------------|---------|
| `HookBridge` | `trampolines.cpp:65` (`InstallHookBridge`) | Static methods `onChannelActive` / `onChannelRead` / `onWrite` bound to native callbacks. |
| `g_relay.dotName` | `relay_handler.cpp:136` (`InstallRelayHandler`) | Netty `ChannelDuplexHandler` subclass with `channelRead` and `write` rebound. |
| `g_b.dotName` | `b_server.cpp:533,564,603` (`InstallBServer`) × 3 | Three independent Netty handlers — `ServerChannelInit`, the `bside` handler, and an internal helper. |
| (trampoline package prefix) | `random_name.cpp:113` | Common package for all of the above. |

The class loader used by `DefineClass` is the **Minecraft class
loader** (`mcLoader`), so these names live in a package rooted at
`g_trampolinePackage`, not in `io.netty.*` or `net.minecraft.*`.
That's the whole point — putting them in a Netty-shaped package
would invite collision with real Netty classes.

## 4. Seed entropy

`make_rng()` mixes four Windows-native entropy sources:

| Source | Bits |
|--------|------|
| `QueryPerformanceCounter` | typically 24–48 (depends on QPC frequency) |
| `GetSystemTimeAsFileTime` (100 ns ticks) | typically 32–48 (depends on uptime) |
| `GetCurrentProcessId` | typically 9–16 (Windows PIDs are 32-bit but small in practice) |
| `GetCurrentThreadId`   | typically 9–16 |

`mt19937_64` then expands this seed into a full 64-bit state.
Effective entropy is **at least ~80 bits** even on the most
pessimistic Windows machine, and the user gets a fresh random name
on every process start (`std::call_once` ensures the package name is
only generated once per process, but `make_rng()` is called fresh
each time, so successive processes get distinct sequences).

## 5. What the random names hide from

Two attack models:

1. **Human reviewer looking at the Minecraft process.** A JFR or
   `jcmd Thread.dump` will list the running threads and any
   `ChannelHandler` instances they have loaded. Names like
   `cinder/Glimmer/Radiant/VortexShadowLunar` look like they could be
   part of an internal Mojang package, so the human reading the dump
   doesn't immediately notice a third-party handler.
2. **Mojang's anti-cheat.** Mojang does not ship anti-cheat, but
   server-side plugins like NoCheat or Vulcan sometimes fingerprint
   unusual client-side classes loaded into the JVM. The random
   prefix is meant to dodge naive list-of-classes heuristics. (In
   practice this is not a serious threat model — anyone with `jcmd`
   can list all loaded classes regardless of their name.)

## 6. Limitations

* The name space is small (`96^n` with `n ≤ 3`, so at most ≈ 884 736
  classes per package). With deterministic `mt19937_64` from the
  same seed (e.g. same QPC tick + same PID + same TID), the name is
  reproducible. That does not matter for this proxy because each
  Minecraft process has its own QPC/PID/TID.
* The vocabulary is recognisable to humans: a Mojang engineer
  searching the JVM for "synthetic handlers added by foreign code"
  would find the random-name pattern trivially by sorting the class
  list by frequency.
* The proxy's `native/random_name.cpp` does not use any
  cryptographic-strength randomness. `mt19937_64` is fine for the
  obfuscation job, but if the goal were to defeat a host-side
  allow-list of class names, the entire approach would need to be
  replaced.