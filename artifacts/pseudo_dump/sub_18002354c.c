
  int32_t* sub_18002354c()

{
    void startupInfo;
    sub_18002de50(&startupInfo, 0, 0x68);
    int32_t* result = GetStartupInfoW(&startupInfo);
    int16_t var_36;
    
    if (var_36)
    {
        int32_t* result_1;
        result = result_1;
        
        if (result)
        {
            char* rsi_1 = &result[1];
            uint64_t i_1 = 0x2000;
            int64_t* rbx_2 = &rsi_1[*result];
            
            if (*result < 0x2000)
                i_1 = *result;
            
            result = __acrt_lowio_ensure_fh_exists(i_1);
            
            if (i_1 > data_180047c40)
                i_1 = data_180047c40;
            
            if (i_1)
            {
                int64_t rbp_1 = 0;
                uint64_t i;
                
                do
                {
                    if (*rbx_2 != -1 && *rbx_2 != -2 && *rsi_1 & 1)
                    {
                        if (!(*rsi_1 & 8))
                            result = GetFileType(*rbx_2);
                        
                        if (*rsi_1 & 8 || result)
                        {
                            int64_t rcx_6 = (&data_180047840)[rbp_1 >> 6];
                            uint64_t rdx_1 = (rbp_1 & 0x3f) * 9;
                            *(rcx_6 + (rdx_1 << 3) + 0x28) = *rbx_2;
                            result = *rsi_1;
                            *(rcx_6 + (rdx_1 << 3) + 0x38) = result;
                        }
                    }
                    
                    rbp_1 += 1;
                    rsi_1 = &rsi_1[1];
                    rbx_2 = &rbx_2[1];
                    i = i_1;
                    i_1 -= 1;
                } while (i != 1);
            }
        }
    }
    
    return result;
}

