
🌐  int64_t _mbtowc_internal(int16_t* arg1, char* arg2, int64_t arg3, int64_t* arg4)

{
    char* rsi = arg2;
    
    if (!arg2 || !arg3)
        data_180047800 = 0;
    else
    {
        if (*arg2)
        {
            if (!arg4[5])
                __crt_cached_ptd_host::update_locale_slow(arg4);
            
            int64_t* rdx = arg4[3];
            uint32_t r10_1 = *(rdx + 0xc);
            int32_t result;
            
            if (r10_1 != 0xfde9)
            {
                if (!rdx[0x27])
                {
                    if (arg1)
                        *arg1 = *rsi;
                    
                    return 1;
                }
                
                if (*(*rdx + (*rsi << 1)) >= 0)
                {
                    int32_t rax_7;
                    rax_7 = arg1;
                    int32_t var_10_2 = rax_7;
                    int16_t* var_18_3 = arg1;
                    
                    if (__acrt_MultiByteToWideChar(r10_1, MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, 
                            rsi, 1))
                        return 1;
                }
                else
                {
                    uint64_t r9 = rdx[1];
                    int32_t rax_4;
                    
                    if (r9 > 1 && arg3 >= r9)
                    {
                        int32_t rax_3;
                        rax_3 = arg1;
                        int32_t var_10_1 = rax_3;
                        int16_t* var_18_2 = arg1;
                        rax_4 = __acrt_MultiByteToWideChar(r10_1, 
                            MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, rsi, r9);
                    }
                    
                    if (r9 > 1 && arg3 >= r9 && rax_4)
                        return *(arg4[3] + 8);
                    
                    if (arg3 >= *(arg4[3] + 8) && rsi[1])
                        return *(arg4[3] + 8);
                }
                
                arg4[6] = 1;
                result = -1;
                *(arg4 + 0x2c) = 0x2a;
            }
            else
            {
                result = sub_180022c2c(arg1, rsi, arg3, &data_180047800, arg4);
                
                if (result < 0)
                    return -1;
            }
            
            return result;
        }
        
        if (arg1)
            *arg1 = 0;
    }
    
    return 0;
}

