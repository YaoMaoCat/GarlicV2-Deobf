
🌐  int64_t __acrt_uninitialize(char arg1)

{
    if (!arg1)
        /* tailcall */
        return sub_1800265b8(&data_180039ad0, &data_180039bd0);
    
    if (data_1800477f0)
        _flushall();
    
    int64_t result;
    result = 1;
    return result;
}

