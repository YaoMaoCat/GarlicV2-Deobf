
  int64_t* sub_18002adc8(int64_t* arg1, int32_t arg2, char* arg3, int32_t arg4)

{
    __chkstk(0x1450);
    void var_1468;
    int64_t rax_1 = __security_cookie ^ &var_1468;
    int64_t r10 = arg2;
    void* rbp_1 = &arg3[arg4];
    char* rsi = arg3;
    HANDLE hFile = *((&data_180047840)[r10 >> 6] + (r10 & 0x3f) * 0x48 + 0x28);
    *arg1 = 0;
    arg1[1] = 0;
    
    if (arg3 < rbp_1)
    {
        do
        {
            uint8_t buffer[0x13ff];
            uint8_t (* rbx_1)[0x13ff] = &buffer;
            uint32_t rax_5;
            
            while (rsi < rbp_1)
            {
                rax_5 = *rsi;
                rsi = &rsi[1];
                
                if (rax_5 == 0xa)
                {
                    arg1[1] += 1;
                    *rbx_1 = 0xd;
                    rbx_1 = &(*rbx_1)[1];
                }
                
                *rbx_1 = rax_5;
                rbx_1 = &(*rbx_1)[1];
                void var_29;
                
                if (rbx_1 >= &var_29)
                    break;
            }
            
            uint32_t numberOfBytesWritten[0x4];
            numberOfBytesWritten[0] = 0;
            uint32_t nNumberOfBytesToWrite = rbx_1 - &buffer;
            
            if (!WriteFile(hFile, &buffer, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
            {
                *arg1 = GetLastError();
                break;
            }
            
            rax_5 = numberOfBytesWritten[0];
            *(arg1 + 4) += rax_5;
            
            if (rax_5 < nNumberOfBytesToWrite)
                break;
        } while (rsi < rbp_1);
    }
    
    __security_check_cookie(rax_1 ^ &var_1468);
    return arg1;
}

