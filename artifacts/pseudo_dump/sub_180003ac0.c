
  int32_t* sub_180003ac0(int32_t* arg1)

{
    int64_t performanceCount = 0;
    QueryPerformanceCounter(&performanceCount);
    FILETIME systemTimeAsFileTime;
    __builtin_memset(&systemTimeAsFileTime, 0, 8);
    GetSystemTimeAsFileTime(&systemTimeAsFileTime);
    int64_t rbx_2 = GetCurrentProcessId() << 0x10
        ^ (systemTimeAsFileTime.dwHighDateTime << 0x20 | systemTimeAsFileTime.dwLowDateTime)
        ^ performanceCount;
    int64_t rdx_1 = GetCurrentThreadId() ^ rbx_2;
    __builtin_strncpy(&arg1[0x4e2], "UUUUUUUU", 8);
    int64_t i = 1;
    *(arg1 + 8) = rdx_1;
    
    do
    {
        rdx_1 = (rdx_1 ^ rdx_1 >> 0x3e) * 0x5851f42d4c957f2d + i;
        *(arg1 + (i << 3) + 8) = rdx_1;
        i += 1;
    } while (i < 0x138);
    
    *arg1 = 0x138;
    return arg1;
}

