
🌐  int64_t __vcrt_uninitialize_critical()

{
    __vcrt_uninitialize_ptd();
    int64_t result;
    result = 1;
    return result;
}

