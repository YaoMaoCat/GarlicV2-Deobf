
🌐  uint64_t _fclose_internal(int32_t* arg1, int64_t* arg2)

{
    int32_t* arg_8 = arg1;
    
    if (arg1)
    {
        if (!(arg1[5] >> 0xc & 1))
        {
            sub_180020d3c(arg1);
            int32_t rax_4 = _fclose_nolock_internal(arg1, arg2);
            sub_180020d48(arg1);
            return rax_4;
        }
        
        __acrt_stdio_free_stream(arg1);
    }
    else
    {
        arg2[6] = 1;
        *(arg2 + 0x2c) = 0x16;
        int64_t var_18;
        _invalid_parameter_internal(arg1, 0, 0, 0, var_18 & arg1, arg2);
    }
    
    return 0xffffffff;
}

