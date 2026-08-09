
🌐  int64_t _Query_perf_frequency()

{
    int64_t result = data_180047598;
    
    if (!result)
    {
        int64_t frequency;
        QueryPerformanceFrequency(&frequency);
        result = frequency;
        data_180047598 = result;
    }
    
    return result;
}

