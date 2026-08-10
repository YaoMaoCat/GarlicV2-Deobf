/* garlic_injector.c — 大蒜's injection wrapper (not in SakuraTools).
 *
 * This is the approximate C reconstruction of what
 * data/GarlicInjector.exe does that is NOT covered by injector/cli.c.
 *
 * Differences from SakuraTools injector/cli.c:
 *
 *   1. CLI            — <pkg-path> --auth-nonce <hex16> --auth-token <hex16>
 *                        instead of <dll-path>
 *   2. FNV-1a verify   — GarlicAuth_Verify(nonce, token) before injection
 *   3. Decrypt         — PBKDF2 + AES-GCM decrypt of .pkg (see decrypt_pkg.py)
 *   4. Auth block      — Build 24B {GARLICAU, nonce, token} and inject it
 *                        into the target BEFORE the DLL
 *   5. Remote auth     — Pass pAuthBuf as lpParameter to CreateRemoteThread,
 *                        which becomes DllMain's lpReserved
 *
 * The decryption step (#3) is implemented through the separate
 * pkg_decrypt module; if the decryptor is not yet ported to C, the
 * simplest workaround is to run artifacts/decrypt_pkg.py first and
 * pass the resulting DLL straight to this injector.
 */

#include "garlic_auth.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#include <iphlpapi.h>
#include <winsock2.h>
#include <stdio.h>
#include <string.h>

/* Provided by injector/Inject.c (SakuraTools). */
BOOL DoInject(DWORD pid, const char *dllPath, char *msg, int msgMax);

/* Decrypt .pkg → plaintext DLL buffer (caller must HeapFree).
 * Returns NULL on failure; *outSize is set to the plaintext length. */
static void *DecryptPkgFile(const char *pkgPath, DWORD *outSize,
                            char *errMsg, int errMax);

/* ------------------------------------------------------------------ */

static int usage(const char *argv0)
{
    fprintf(stderr,
            "usage: %s <pkg-path> --auth-nonce <16-hex-chars>"
            " --auth-token <16-hex-chars>\n",
            argv0);
    return 2;
}

/* ---- 布吉岛 (Buji Island) window finder — same as cli.c ---- */

typedef struct { DWORD pid; ULONGLONG created; } ProcChoice;

static BOOL IsJavaProcess(DWORD pid)
{
    BOOL found = FALSE;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return FALSE;
    PROCESSENTRY32 e = { sizeof(e) };
    if (Process32First(snap, &e)) {
        do {
            if (e.th32ProcessID == pid) {
                found = (_stricmp(e.szExeFile, "java.exe") == 0 ||
                         _stricmp(e.szExeFile, "javaw.exe") == 0);
                break;
            }
        } while (Process32Next(snap, &e));
    }
    CloseHandle(snap);
    return found;
}

static BOOL CALLBACK FindBujiWindow(HWND wnd, LPARAM param)
{
    ProcChoice *choice = (ProcChoice *)param;
    if (!IsWindowVisible(wnd)) return TRUE;
    wchar_t title[512];
    if (GetWindowTextW(wnd, title, 512) <= 0) return TRUE;
    /*
     * "布吉岛" = U+5E03 U+5409 U+5C9B
     */
    static const wchar_t buji[] = { 0x5E03, 0x5409, 0x5C9B, 0 };
    if (!wcsstr(title, buji)) return TRUE;
    DWORD pid = 0;
    GetWindowThreadProcessId(wnd, &pid);
    if (!pid || !IsJavaProcess(pid)) return TRUE;
    FILETIME ct, _, __, ___;
    HANDLE hp = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!hp) return TRUE;
    ULONGLONG t = 0;
    if (GetProcessTimes(hp, &ct, &_, &__, &___)) {
        ULARGE_INTEGER u; u.LowPart = ct.dwLowDateTime;
        u.HighPart = ct.dwHighDateTime; t = u.QuadPart;
    }
    CloseHandle(hp);
    if (!choice->pid || t > choice->created) {
        choice->pid = pid; choice->created = t;
    }
    return TRUE;
}

static DWORD WaitForBujiProcess(void)
{
    fprintf(stdout,
            "waiting for a visible Java window containing"
            " U+5E03 U+5409 U+5C9B...\n");
    fflush(stdout);
    for (;;) {
        ProcChoice c = { 0, 0 };
        EnumWindows(FindBujiWindow, (LPARAM)&c);
        if (c.pid) return c.pid;
        Sleep(50);
    }
}

/* ---- auth-block injection into remote process ---- */

/* Write the 24-byte auth block into the target at pAuthBuf,
 * then CreateRemoteThread → ReflectiveLoader with pAuthBuf as
 * the lpParameter.  This is the equivalent of
 * sub_140001750 + sub_140001bf0 combined, minus the encrypt layer. */
static BOOL InjectDllWithAuth(HANDLE hProc, const void *dllBuf,
                              DWORD dllSize, const uint64_t authBlock[3],
                              char *msg, int msgMax)
{
    /* step 1 — write the 24-byte auth block into the target */
    LPVOID pAuthBuf = VirtualAllocEx(hProc, NULL, GARLIC_AUTH_BLOCK_SIZE,
                                     MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!pAuthBuf) {
        snprintf(msg, msgMax, "VirtualAllocEx(auth) failed: %lu",
                 GetLastError());
        return FALSE;
    }
    SIZE_T nw = 0;
    if (!WriteProcessMemory(hProc, pAuthBuf, authBlock,
                            GARLIC_AUTH_BLOCK_SIZE, &nw) ||
        nw != GARLIC_AUTH_BLOCK_SIZE) {
        snprintf(msg, msgMax, "WriteProcessMemory(auth) failed: %lu",
                 GetLastError());
        VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
        return FALSE;
    }

    /* step 2 — find the ReflectiveLoader export inside the DLL image */
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)dllBuf;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
        snprintf(msg, msgMax, "not a valid PE image (bad MZ)");
        VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
        return FALSE;
    }
    PIMAGE_NT_HEADERS nt =
        (PIMAGE_NT_HEADERS)((UINT_PTR)dllBuf + dos->e_lfanew);
    if (nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR64_MAGIC) {
        snprintf(msg, msgMax, "not a 64-bit PE");
        VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
        return FALSE;
    }
    DWORD expRVA = nt->OptionalHeader
                       .DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT]
                       .VirtualAddress;
    PIMAGE_EXPORT_DIRECTORY exp =
        (PIMAGE_EXPORT_DIRECTORY)((UINT_PTR)dllBuf + expRVA);
    DWORD *names = (DWORD *)((UINT_PTR)dllBuf + exp->AddressOfNames);
    WORD  *ords  = (WORD *)((UINT_PTR)dllBuf + exp->AddressOfNameOrdinals);
    DWORD *funcs = (DWORD *)((UINT_PTR)dllBuf + exp->AddressOfFunctions);
    DWORD loaderRVA = 0;
    for (DWORD i = 0; i < exp->NumberOfNames; ++i) {
        const char *n = (const char *)((UINT_PTR)dllBuf + names[i]);
        if (strcmp(n, "ReflectiveLoader") == 0) {
            loaderRVA = funcs[ords[i]]; break;
        }
    }
    if (!loaderRVA) {
        snprintf(msg, msgMax, "ReflectiveLoader export not found");
        VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
        return FALSE;
    }

    /* step 3 — copy the DLL into the target */
    LPVOID remoteDll = VirtualAllocEx(hProc, NULL, dllSize,
                                      MEM_COMMIT | MEM_RESERVE,
                                      PAGE_EXECUTE_READWRITE);
    if (!remoteDll) {
        snprintf(msg, msgMax, "VirtualAllocEx(dll) failed: %lu",
                 GetLastError());
        VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
        return FALSE;
    }
    if (!WriteProcessMemory(hProc, remoteDll, dllBuf, dllSize, &nw) ||
        nw != dllSize) {
        snprintf(msg, msgMax, "WriteProcessMemory(dll) failed: %lu",
                 GetLastError());
        VirtualFreeEx(hProc, remoteDll, 0, MEM_RELEASE);
        VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
        return FALSE;
    }

    /* step 4 — launch the remote ReflectiveLoader with pAuthBuf */
    LPTHREAD_START_ROUTINE entry =
        (LPTHREAD_START_ROUTINE)((UINT_PTR)remoteDll + loaderRVA);
    HANDLE hThread = CreateRemoteThread(hProc, NULL, 1024 * 1024,
                                        entry, pAuthBuf, 0, NULL);
    if (!hThread) {
        snprintf(msg, msgMax, "CreateRemoteThread failed: %lu",
                 GetLastError());
        VirtualFreeEx(hProc, remoteDll, 0, MEM_RELEASE);
        VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
        return FALSE;
    }
    WaitForSingleObject(hThread, INFINITE);
    DWORD exitCode = 0;
    GetExitCodeThread(hThread, &exitCode);
    CloseHandle(hThread);

    /* cleanup — we keep the DLL region (it's now in use), but
     * free the auth block (it was read-once by the loader) */
    VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);

    if (exitCode == 0) {
        snprintf(msg, msgMax, "ReflectiveLoader returned 0 "
                              "(DllMain auth check failed?)");
        return FALSE;
    }
    snprintf(msg, msgMax, "injected OK into PID %lu",
             (unsigned long)GetProcessId(hProc));
    return TRUE;
}

/* ------------------------------------------------------------------ */

int main(int argc, char **argv)
{
    /* GarlicInjector.exe <pkg-path> --auth-nonce <h> --auth-token <h> */
    if (argc != 6)
        return usage(argv[0]);

    const char *pkgPath  = argv[1];
    const char *nonceStr = NULL;
    const char *tokenStr = NULL;

    for (int i = 2; i < argc; i += 2) {
        if (strcmp(argv[i], "--auth-nonce") == 0) nonceStr = argv[i+1];
        else if (strcmp(argv[i], "--auth-token") == 0) tokenStr = argv[i+1];
        else return usage(argv[0]);
    }
    if (!nonceStr || !tokenStr)
        return usage(argv[0]);

    /* ---- hex-decode & FNV-1a verify (大蒜's additions) ---- */
    uint64_t nonce = 0, token = 0;
    if (GarlicAuth_HexDecode(nonceStr, &nonce) != 0 ||
        GarlicAuth_HexDecode(tokenStr,  &token)  != 0) {
        fprintf(stderr, "[-] invalid hex in auth-nonce / auth-token\n");
        return 3;
    }
    uint64_t authBlock[3];
    GarlicAuth_BuildBlock(authBlock, nonce, token);
    if (!GarlicAuth_Verify(authBlock)) {
        fprintf(stderr, "[-] auth-nonce / auth-token mismatch\n");
        return 3;
    }
    /* ---- end of 大蒜's additions ---- */

    /* Find the MC PID (same as SakuraTools cli.c). */
    DWORD pid = WaitForBujiProcess();
    fprintf(stdout, "matched Buji Island Java window, PID %lu\n",
            (unsigned long)pid);

    /* Decrypt the .pkg (if the decryptor is not yet ported, this
     * function falls back to reading a plain DLL path). */
    DWORD dllSize = 0;
    char errBuf[4096] = { 0 };
    void *dllBuf = DecryptPkgFile(pkgPath, &dllSize, errBuf, sizeof(errBuf));
    if (!dllBuf) {
        fprintf(stderr, "%s\n", errBuf);
        return 1;
    }

    /* Acquire SeDebugPrivilege (same as SakuraTools Inject.c). */
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(),
                         TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        TOKEN_PRIVILEGES tp = { 0 };
        tp.PrivilegeCount = 1;
        tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        LookupPrivilegeValueA(NULL, SE_DEBUG_NAME,
                              &tp.Privileges[0].Luid);
        AdjustTokenPrivileges(hToken, FALSE, &tp, 0, NULL, NULL);
        CloseHandle(hToken);
    }

    HANDLE hProc = OpenProcess(
        PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION |
        PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
        FALSE, pid);
    if (!hProc) {
        fprintf(stderr, "OpenProcess(%lu) failed: %lu\n",
                (unsigned long)pid, GetLastError());
        HeapFree(GetProcessHeap(), 0, dllBuf);
        return 1;
    }

    char msg[4096] = { 0 };
    BOOL ok = InjectDllWithAuth(hProc, dllBuf, dllSize, authBlock,
                                msg, sizeof(msg));
    fprintf(stdout, "%s\n", msg);
    CloseHandle(hProc);
    HeapFree(GetProcessHeap(), 0, dllBuf);
    return ok ? 0 : 4;
}

/* ---- Fallback decryptor (placeholder until full C port is ready) ----
 * In production GarlicInjector.exe this calls BCrypt* functions
 * (PBKDF2 + AES-GCM).  For now, if the path ends with .pkg we try
 * to exec decrypt_pkg.py via system(); if it ends with .dll we read
 * it directly (plain DLL mode). */

static void *DecryptPkgFile(const char *path, DWORD *outSize,
                            char *errMsg, int errMax)
{
    const char *ext = strrchr(path, '.');
    if (!ext) {
        snprintf(errMsg, errMax, "cannot determine file type: %s", path);
        return NULL;
    }
    int isPkg = (_stricmp(ext, ".pkg") == 0);

    if (!isPkg) {
        /* Plain DLL — just read it (same as SakuraTools Inject.c). */
        HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ,
                                   NULL, OPEN_EXISTING,
                                   FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            snprintf(errMsg, errMax, "CreateFileA(%s) failed: %lu",
                     path, GetLastError());
            return NULL;
        }
        DWORD sz = GetFileSize(hFile, NULL);
        if (sz == INVALID_FILE_SIZE || sz == 0) {
            snprintf(errMsg, errMax, "GetFileSize(%s) failed: %lu",
                     path, GetLastError());
            CloseHandle(hFile); return NULL;
        }
        void *buf = HeapAlloc(GetProcessHeap(), 0, sz);
        if (!buf) {
            snprintf(errMsg, errMax, "HeapAlloc(%lu) failed", (unsigned long)sz);
            CloseHandle(hFile); return NULL;
        }
        DWORD rd = 0;
        BOOL ok = ReadFile(hFile, buf, sz, &rd, NULL);
        CloseHandle(hFile);
        if (!ok || rd != sz) {
            HeapFree(GetProcessHeap(), 0, buf);
            snprintf(errMsg, errMax, "ReadFile(%s) failed: %lu",
                     path, GetLastError());
            return NULL;
        }
        *outSize = sz;
        return buf;
    } else {
        /* .pkg — run artifacts/decrypt_pkg.py and read the output.
         * In production GarlicInjector.exe this is replaced by BCrypt*
         * calls (PBKDF2 + AES-GCM); this fallback is for reference. */
        const char *outDll = "GarlicProxy_dll.tmp";
        char cmd[1024];
        snprintf(cmd, sizeof(cmd),
                 "python artifacts\\decrypt_pkg.py %s %s > NUL 2>&1",
                 path, outDll);
        int rc = system(cmd);
        if (rc != 0) {
            snprintf(errMsg, errMax,
                     "decrypt_pkg.py failed (rc=%d)", rc);
            return NULL;
        }
        /* Recurse to read the plain DLL we just wrote. */
        void *buf = DecryptPkgFile(outDll, outSize, errMsg, errMax);
        DeleteFileA(outDll);
        return buf;
    }
}