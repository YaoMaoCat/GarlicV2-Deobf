
🌐  int64_t __crt_state_management::dual_state_global<void (__cdecl*)(wchar_t const* __ptr64, wchar_t const* __ptr64, wchar_t const* __ptr64, uint32_t, uint64_t)>::value(int64_t arg1, void* arg2)

{
    int64_t rbx = 0;
    
    if (*(arg2 + 0x10))
        rbx = *(arg2 + 8);
    else
    {
        enum WIN32_ERROR dwErrCode = GetLastError();
        *(arg2 + 8) = 0;
        *(arg2 + 0x10) = 1;
        SetLastError(dwErrCode);
    }
    
    return arg1 + (rbx << 3);
}

