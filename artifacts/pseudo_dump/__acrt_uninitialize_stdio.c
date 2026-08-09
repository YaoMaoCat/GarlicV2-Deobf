
🌐  int64_t __acrt_uninitialize_stdio()

{
    _flushall();
    sub_180026c98();
    
    for (int64_t* i = nullptr; i != 0x18; i = &i[1])
    {
        __acrt_stdio_free_buffer_nolock(*(i + data_1800477f0));
        DeleteCriticalSection(*(i + data_1800477f0) + 0x30);
    }
    
    int64_t result = _free_base(data_1800477f0);
    data_1800477f0 = 0;
    return result;
}

