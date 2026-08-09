
  int64_t* sub_18002a934(int64_t* arg1, int32_t arg2, char* arg3, int32_t arg4, int64_t* arg5)

{
    int64_t var_60 = -2;
    void var_108;
    int64_t rax_1 = __security_cookie ^ &var_108;
    char* rsi = arg3;
    int64_t r14 = arg2;
    int64_t r13_1 = r14 >> 6;
    int64_t var_90 = r13_1;
    uint64_t r15 = (r14 & 0x3f) * 9;
    HANDLE hFile = *((&data_180047840)[r13_1] + (r15 << 3) + 0x28);
    void* r12_1 = &arg3[arg4];
    uint32_t rax_6 = GetConsoleOutputCP();
    int32_t rdi = 0;
    int64_t* r10 = arg5;
    
    if (!r10[5])
    {
        __crt_cached_ptd_host::update_locale_slow(r10);
        r10 = arg5;
    }
    
    int32_t rcx_2 = *(r10[3] + 0xc);
    int32_t var_9c = rcx_2;
    *arg1 = 0;
    arg1[1] = 0;
    
    if (arg3 < r12_1)
    {
        int64_t r11_2 = r14 >> 6;
        int64_t var_68_1 = r11_2;
        int32_t rdx = 0;
        
        while (true)
        {
            BOOL rax_7;
            rax_7 = *rsi;
            uint8_t buffer = rax_7;
            int32_t var_c4 = 0;
            int32_t r12_2 = 1;
            
            if (rcx_2 != 0xfde9)
            {
                int64_t r8_4 = (&data_180047840)[r13_1];
                rcx_2 = *(r8_4 + (r15 << 3) + 0x3d);
                char* rdx_8;
                int64_t r8_5;
                
                if (!(rcx_2 & 4))
                {
                    uint64_t r9_4 = *rsi;
                    
                    if (*(*r10[3] + (r9_4 << 1)) >= 0)
                    {
                        r8_5 = 1;
                        rdx_8 = rsi;
                        goto label_18002ac2e;
                    }
                    
                    if (&rsi[1] >= r12_1)
                    {
                        *(r8_4 + (r15 << 3) + 0x3e) = r9_4;
                        int64_t rax_25 = (&data_180047840)[r13_1];
                        *(rax_25 + (r15 << 3) + 0x3d) |= 4;
                        *(arg1 + 4) = rdx + 1;
                        break;
                    }
                    
                    if (_mbtowc_internal(&var_c4, rsi, 2, r10) == 0xffffffff)
                        break;
                    
                    rsi = &rsi[1];
                }
                else
                {
                    rax_7 = *(r8_4 + (r15 << 3) + 0x3e);
                    char var_50 = rax_7;
                    rax_7 = *rsi;
                    char var_4f_1 = rax_7;
                    rcx_2 &= 0xfb;
                    *(r8_4 + (r15 << 3) + 0x3d) = rcx_2;
                    r8_5 = 2;
                    rdx_8 = &var_50;
                label_18002ac2e:
                    
                    if (_mbtowc_internal(&var_c4, rdx_8, r8_5, r10) == 0xffffffff)
                        break;
                }
            }
            else
            {
                int32_t rdx_1 = 0;
                int64_t r14_1 = 0;
                char* rcx_4 = (r15 << 3) + 0x3e + (&data_180047840)[r11_2];
                
                while (*rcx_4)
                {
                    rdx_1 += 1;
                    r14_1 += 1;
                    rcx_4 = &rcx_4[1];
                    
                    if (r14_1 >= 5)
                        break;
                }
                
                uint32_t var_a8;
                
                if (r14_1 <= 0)
                {
                    int64_t r13_2 = *(*rsi + 0x180047130);
                    int32_t rcx_11 = r13_2 + 1;
                    void* i = r12_1 - rsi;
                    
                    if (rcx_11 > i)
                    {
                        if (i > 0)
                        {
                            char* r8_8 = nullptr;
                            
                            do
                            {
                                int64_t rax_18;
                                rax_18 = *(r8_8 + rsi);
                                r8_8[(r15 << 3) + (&data_180047840)[var_90] + 0x3e] = rax_18;
                                rdi += 1;
                                r8_8 = &r8_8[1];
                            } while (rdi < i);
                        }
                        
                        *(arg1 + 4) += i;
                        break;
                    }
                    
                    var_a8 = 0;
                    char* var_78 = rsi;
                    int32_t rax_19;
                    rax_19 = rcx_11 == 4;
                    
                    if (sub_180022c74(&var_c4, &var_78, rax_19 + 1, &var_a8, r10) == -1)
                        break;
                    
                    rsi = &rsi[r13_2];
                    r12_2 = rax_19 + 1;
                    r13_1 = var_90;
                }
                else
                {
                    int32_t r12_4 =
                        *(*((&data_180047840)[r13_1] + (r15 << 3) + 0x3e) + 0x180047130) + 1;
                    uint64_t rax_10 = r12_4 - rdx_1;
                    var_a8 = rax_10;
                    void* i_1 = r12_1 - rsi;
                    int64_t r9 = rax_10;
                    
                    if (r9 > i_1)
                    {
                        if (i_1 > 0)
                        {
                            char* rsi_1 = rsi - r14_1;
                            
                            do
                            {
                                rax_10 = rsi_1[r14_1];
                                *(r14_1 + (r15 << 3) + (&data_180047840)[r13_1] + 0x3e) = rax_10;
                                rdi += 1;
                                r14_1 += 1;
                            } while (rdi < i_1);
                        }
                        
                        *(arg1 + 4) += i_1;
                        break;
                    }
                    
                    int64_t rcx_6 = 0;
                    char* rdx_3 = (r15 << 3) + 0x3e + (&data_180047840)[r11_2];
                    void var_58;
                    
                    do
                    {
                        rax_10 = *rdx_3;
                        *(&var_58 + rcx_6) = rax_10;
                        rcx_6 += 1;
                        rdx_3 = &rdx_3[1];
                    } while (rcx_6 < r14_1);
                    
                    if (r9 > 0)
                    {
                        memcpy(&var_58 + r14_1, rsi, r9);
                        r10 = arg5;
                    }
                    
                    int64_t rdx_5 = 0;
                    
                    do
                    {
                        *(rdx_5 + (r15 << 3) + (&data_180047840)[r13_1] + 0x3e) = 0;
                        rdx_5 += 1;
                    } while (rdx_5 < r14_1);
                    
                    int64_t var_88 = 0;
                    void* var_80 = &var_58;
                    int32_t rax_12;
                    rax_12 = r12_4 == 4;
                    r12_2 = rax_12 + 1;
                    
                    if (sub_180022c74(&var_c4, &var_80, rax_12 + 1, &var_88, r10) == -1)
                        break;
                    
                    rsi = &rsi[var_a8 - 1];
                }
            }
            
            rsi = &rsi[1];
            int64_t var_d0_1 = 0;
            int64_t var_d8_1 = 0;
            uint8_t buffer_1;
            uint32_t nNumberOfBytesToWrite =
                __acrt_WideCharToMultiByte(rax_6, 0, &var_c4, r12_2, &buffer_1, 5);
            
            if (!nNumberOfBytesToWrite)
                break;
            
            uint32_t numberOfBytesWritten = 0;
            
            if (WriteFile(hFile, &buffer_1, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
            {
                rdx = arg1[1] - arg3 + rsi;
                *(arg1 + 4) = rdx;
                
                if (numberOfBytesWritten < nNumberOfBytesToWrite)
                    break;
                
                if (buffer != 0xa)
                {
                label_18002acf7:
                    
                    if (rsi >= r12_1)
                        break;
                    
                    r10 = arg5;
                    r11_2 = var_68_1;
                    rcx_2 = var_9c;
                    continue;
                }
                else
                {
                    buffer = 0xd;
                    
                    if (WriteFile(hFile, &buffer, 1, &numberOfBytesWritten, nullptr))
                    {
                        if (numberOfBytesWritten < 1)
                            break;
                        
                        arg1[1] += 1;
                        *(arg1 + 4) += 1;
                        rdx = *(arg1 + 4);
                        goto label_18002acf7;
                    }
                }
            }
            
            *arg1 = GetLastError();
            break;
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_108);
    return arg1;
}

