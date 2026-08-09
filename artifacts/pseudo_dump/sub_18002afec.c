
  int64_t* sub_18002afec(int64_t* arg1, int32_t arg2, int16_t* arg3, int32_t arg4)

{
    __chkstk(0x1470);
    void var_1498;
    int64_t rax_1 = __security_cookie ^ &var_1498;
    int64_t r10 = arg2;
    void* r14_1 = arg4 + arg3;
    int16_t* rdi = arg3;
    HANDLE hFile = *((&data_180047840)[r10 >> 6] + (r10 & 0x3f) * 0x48 + 0x28);
    *arg1 = 0;
    arg1[1] = 0;
    
    if (arg3 < r14_1)
    {
        do
        {
            wchar16 var_1448[0x354];
            wchar16 (* r9)[0x354] = &var_1448;
            
            while (rdi < r14_1)
            {
                int16_t rax_5 = *rdi;
                rdi = &rdi[1];
                
                if (rax_5 == 0xa)
                {
                    *r9 = 0xd;
                    r9 = &(*r9)[1];
                }
                
                *r9 = rax_5;
                r9 = &(*r9)[1];
                void var_da0;
                
                if (r9 >= &var_da0)
                    break;
            }
            
            int64_t var_1460_1 = 0;
            int64_t var_1468_1 = 0;
            void var_d98;
            int32_t rax_6 = __acrt_WideCharToMultiByte(0xfde9, 0, &var_1448, (r9 - &var_1448) >> 1, 
                &var_d98, 0xd55);
            
            if (!rax_6)
            {
            label_18002b12f:
                *arg1 = GetLastError();
                break;
            }
            
            int32_t rsi_1 = 0;
            
            if (rax_6)
            {
                do
                {
                    uint32_t numberOfBytesWritten[0x4];
                    numberOfBytesWritten[0] = 0;
                    
                    if (!WriteFile(hFile, &var_d98 + rsi_1, rax_6 - rsi_1, &numberOfBytesWritten, 
                            nullptr))
                        goto label_18002b12f;
                    
                    rsi_1 += numberOfBytesWritten[0];
                } while (rsi_1 < rax_6);
            }
            
            *(arg1 + 4) = rdi - arg3;
        } while (rdi < r14_1);
    }
    
    __security_check_cookie(rax_1 ^ &var_1498);
    return arg1;
}

