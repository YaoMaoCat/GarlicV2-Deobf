
🌐  uint64_t _fclose_nolock_internal(int32_t* arg1, int64_t* arg2)

{
    if (!arg1)
    {
        arg2[6] = 1;
        *(arg2 + 0x2c) = 0x16;
        int64_t var_18;
        _invalid_parameter_internal(arg1, 0, 0, 0, var_18 & arg1, arg2);
        return 0xffffffff;
    }
    
    int32_t rsi_1 = -1;
    
    if (arg1[5] >> 0xd & 1)
    {
        rsi_1 = __acrt_stdio_flush_nolock(arg1, arg2);
        __acrt_stdio_free_buffer_nolock(arg1);
        
        if (_close_internal(_fileno(arg1), arg2) >= 0)
        {
            int64_t rcx_3 = *(arg1 + 0x28);
            
            if (rcx_3)
            {
                _free_base(rcx_3);
                *(arg1 + 0x28) = 0;
            }
        }
        else
            rsi_1 = -1;
    }
    
    __acrt_stdio_free_stream(arg1);
    return rsi_1;
}

