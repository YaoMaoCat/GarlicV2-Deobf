
  uint64_t sub_180017000()

{
    uint64_t __security_cookie_1 = __security_cookie;
    
    if (__security_cookie_1 != 0x2b992ddfa232)
    {
        uint64_t result = ~__security_cookie_1;
        data_180046840 = result;
        return result;
    }
    
    FILETIME systemTimeAsFileTime;
    __builtin_memset(&systemTimeAsFileTime, 0, 8);
    GetSystemTimeAsFileTime(&systemTimeAsFileTime);
    int64_t rax;
    rax = systemTimeAsFileTime.dwLowDateTime;
    *(&rax + 4) = systemTimeAsFileTime.dwHighDateTime;
    int64_t var_18 = rax;
    uint64_t rax_2 = GetCurrentThreadId();
    var_18 ^= rax_2;
    uint64_t rax_4 = GetCurrentProcessId();
    var_18 ^= rax_4;
    int64_t performanceCount;
    QueryPerformanceCounter(&performanceCount);
    int64_t performanceCount_1 = performanceCount;
    uint64_t rcx_7 =
        (performanceCount_1 << 0x20 ^ performanceCount_1 ^ var_18 ^ &var_18) & 0xffffffffffff;
    
    if (rcx_7 == 0x2b992ddfa232)
        rcx_7 = 0x2b992ddfa233;
    
    __security_cookie = rcx_7;
    data_180046840 = ~rcx_7;
    return 0x2b992ddfa233;
}

