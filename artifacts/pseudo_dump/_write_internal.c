
🌐  uint64_t _write_internal(int32_t arg1, int16_t* arg2, int32_t arg3, int64_t* arg4)

{
    int32_t arg_8 = arg1;
    int64_t rsi = arg1;
    
    if (rsi != 0xfffffffe)
    {
        int32_t rax_2;
        
        if (arg1 < 0 || rsi >= data_180047c40)
            rax_2 = 0;
        else
            rax_2 = 1;
        
        if (rax_2)
        {
            int64_t r15_2 = rsi >> 6;
            uint64_t r12_1 = (rsi & 0x3f) * 9;
            
            if (*((&data_180047840)[r15_2] + (r12_1 << 3) + 0x38) & 1)
            {
                __acrt_lowio_unlock_fh(rsi);
                int32_t r14_1 = -1;
                
                if (*((&data_180047840)[r15_2] + (r12_1 << 3) + 0x38) & 1)
                    r14_1 = sub_18002b280(rsi, arg2, arg3, arg4);
                else
                {
                    arg4[6] = 1;
                    *(arg4 + 0x2c) = 9;
                    arg4[7] = 1;
                    *(arg4 + 0x34) = 0;
                }
                
                sub_1800292dc(rsi);
                return r14_1;
            }
        }
        
        arg4[7] = 1;
        *(arg4 + 0x34) = 0;
        arg4[6] = 1;
        *(arg4 + 0x2c) = 9;
        _invalid_parameter_internal(0, 0, 0, 0, 0, arg4);
    }
    else
    {
        arg4[7] = 1;
        *(arg4 + 0x34) = 0;
        arg4[6] = 1;
        *(arg4 + 0x2c) = 9;
    }
    
    return 0xffffffff;
}

