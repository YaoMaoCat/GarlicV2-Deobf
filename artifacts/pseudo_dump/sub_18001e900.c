
  uint64_t sub_18001e900(int64_t* arg1)

{
    int64_t var_50 = -2;
    void var_88;
    uint64_t var_38 = __security_cookie ^ &var_88;
    int64_t* rbx = arg1;
    int32_t rdx = *(arg1 + 0x39);
    char rdi = 0x78;
    uint64_t result;
    
    if (rdx > 0x64)
    {
        if (rdx > 0x6f)
        {
            if (rdx == 0x70)
            {
                arg1[6] = 0x10;
                *(arg1 + 0x34) = 0xb;
            label_18001ea2a:
                rdx = 1;
            label_18001ea2c:
                result = sub_18001dd5c(arg1, rdx);
                goto label_18001ea31;
            }
            
            if (rdx == 0x73)
            {
            label_18001ea15:
                result = sub_18001f1d4(arg1);
                goto label_18001ea31;
            }
            
            if (rdx == 0x75)
                goto label_18001e9d8;
            
            if (rdx == 0x78)
            {
                rdx = 0;
                goto label_18001ea2c;
            }
            
            result = 0;
        }
        else
        {
            if (rdx == 0x6f)
            {
                int32_t rcx = arg1[5];
                
                if (rcx >> 5 & 1)
                    rbx[5] = rcx | 0x80;
                
                result = sub_18001d954(rbx, 0);
                goto label_18001ea31;
            }
            
            if (rdx == 0x65 || rdx == 0x66 || rdx == 0x67)
            {
            label_18001e96f:
                result = sub_18001edec(arg1);
                goto label_18001ea31;
            }
            
            if (rdx == 0x69)
                goto label_18001e9d2;
            
            if (rdx == 0x6e)
            {
                result = sub_18001f11c(arg1);
                goto label_18001ea31;
            }
            
            result = 0;
        }
    }
    else if (rdx == 0x64)
    {
    label_18001e9d2:
        arg1[5] |= 0x10;
    label_18001e9d8:
        result = sub_18001db58(arg1, 0);
    label_18001ea31:
        
        if (result)
        {
            if (!rbx[7])
            {
                int16_t var_48 = 0;
                char var_46_1 = 0;
                int64_t r8_1 = 0;
                int32_t rdx_10 = rbx[5];
                
                if (rdx_10 >> 4 & 1)
                {
                    if (rdx_10 >> 6 & 1)
                    {
                        var_48 = 0x2d;
                        r8_1 = 1;
                    }
                    else if (rbx[5] & 1)
                    {
                        var_48 = 0x2b;
                        r8_1 = 1;
                    }
                    else if (rdx_10 >> 1 & 1)
                    {
                        var_48 = 0x20;
                        r8_1 = 1;
                    }
                }
                
                arg1 = *(rbx + 0x39);
                char r9_1;
                
                if (&arg1[-0xb] & 0xdf || !(rdx_10 >> 5 & 1))
                    r9_1 = 0;
                else
                    r9_1 = 1;
                
                if (r9_1 || !((arg1 - 0x41) & 0xdf))
                {
                    *(&var_48 + r8_1) = 0x30;
                    
                    if (arg1 == 0x58 || arg1 == 0x41)
                        rdi = 0x58;
                    
                    *((&var_48 + 1) + r8_1) = rdi;
                    r8_1 += 2;
                }
                
                int32_t rsi_3 = *(rbx + 0x2c) - r8_1 - rbx[9];
                
                if (!(rdx_10 & 0xc))
                {
                    int32_t r9_2 = 0;
                    
                    if (rsi_3 > 0)
                    {
                        int32_t rdx_11 = rbx[4];
                        
                        do
                        {
                            void* rcx_3 = rbx[0x8c];
                            
                            if (*(rcx_3 + 0x10) != *(rcx_3 + 8))
                            {
                                rbx[4] = rdx_11 + 1;
                                *(rcx_3 + 0x10) += 1;
                                **rbx[0x8c] = 0x20;
                                int64_t* rax_16 = rbx[0x8c];
                                *rax_16 += 1;
                            }
                            else
                            {
                                int32_t rdx_12;
                                
                                if (!*(rcx_3 + 0x18))
                                    rdx_12 = -1;
                                else
                                    rdx_12 = rdx_11 + 1;
                                
                                rbx[4] = rdx_12;
                            }
                            
                            rdx_11 = rbx[4];
                            
                            if (rdx_11 == 0xffffffff)
                                break;
                            
                            r9_2 += 1;
                        } while (r9_2 < rsi_3);
                    }
                }
                
                int64_t var_68_1 = rbx[1];
                __crt_stdio_output::string_output_adapter<char>::write_string(&rbx[0x8c], &var_48, 
                    r8_1, &rbx[4]);
                int32_t rcx_6 = rbx[5];
                
                if (rcx_6 >> 3 & 1 && !(rcx_6 >> 2 & 1))
                {
                    int32_t r8_2 = 0;
                    
                    if (rsi_3 > 0)
                    {
                        int32_t rdx_14 = rbx[4];
                        
                        do
                        {
                            void* rcx_8 = rbx[0x8c];
                            
                            if (*(rcx_8 + 0x10) != *(rcx_8 + 8))
                            {
                                rbx[4] = rdx_14 + 1;
                                *(rcx_8 + 0x10) += 1;
                                **rbx[0x8c] = 0x30;
                                int64_t* rax_23 = rbx[0x8c];
                                *rax_23 += 1;
                            }
                            else
                            {
                                int32_t rdx_15;
                                
                                if (!*(rcx_8 + 0x18))
                                    rdx_15 = -1;
                                else
                                    rdx_15 = rdx_14 + 1;
                                
                                rbx[4] = rdx_15;
                            }
                            
                            rdx_14 = rbx[4];
                            
                            if (rdx_14 == 0xffffffff)
                                break;
                            
                            r8_2 += 1;
                        } while (r8_2 < rsi_3);
                    }
                }
                
                if (!*(rbx + 0x4c) || rbx[9] <= 0)
                {
                    int64_t var_68_5 = rbx[1];
                    __crt_stdio_output::string_output_adapter<char>::write_string(&rbx[0x8c], 
                        rbx[8], rbx[9], &rbx[4]);
                }
                else
                {
                    int64_t* r15_1 = rbx[1];
                    
                    if (!r15_1[5])
                        __crt_cached_ptd_host::update_locale_slow(r15_1);
                    
                    int16_t* r14_1 = rbx[8];
                    int32_t rcx_11 = rbx[9];
                    int32_t r15_2 = 0;
                    int64_t var_40;
                    
                    if (*(r15_1[3] + 0xc) == 0xfde9)
                    {
                        var_40 = 0;
                        
                        if (rcx_11)
                        {
                            while (true)
                            {
                                int16_t rdx_16 = *r14_1;
                                r14_1 = &r14_1[1];
                                result = __crt_mbstring::__c16rtomb_utf8(&var_48, rdx_16, &var_40, 
                                    rbx[1]);
                                
                                if (result == -1)
                                    break;
                                
                                int64_t var_68_2 = rbx[1];
                                __crt_stdio_output::string_output_adapter<char>::write_string(
                                    &rbx[0x8c], &var_48, result, &rbx[4]);
                                r15_2 += 1;
                                
                                if (r15_2 == rbx[9])
                                    goto label_18001ecd4;
                            }
                            
                            rbx[4] = 0xffffffff;
                        }
                    }
                    else if (rcx_11)
                    {
                        while (true)
                        {
                            var_48 = 0;
                            wchar16 r9_6 = *r14_1;
                            r14_1 = &r14_1[1];
                            
                            if (_wctomb_internal(&var_48, &var_40, 6, r9_6, rbx[1]))
                                break;
                            
                            int32_t r8_5 = var_48;
                            
                            if (!r8_5)
                                break;
                            
                            int64_t var_68_4 = rbx[1];
                            __crt_stdio_output::string_output_adapter<char>::write_string(
                                &rbx[0x8c], &var_40, r8_5, &rbx[4]);
                            r15_2 += 1;
                            
                            if (r15_2 == rbx[9])
                                goto label_18001ecd4;
                        }
                        
                        rbx[4] = 0xffffffff;
                    }
                }
                
            label_18001ecd4:
                int32_t rcx_17 = rbx[4];
                
                if (rcx_17 >= 0 && (rbx[5] >> 2) & 1)
                {
                    int32_t r9_9 = 0;
                    
                    if (rsi_3 > 0)
                    {
                        do
                        {
                            void* rdx_21 = rbx[0x8c];
                            
                            if (*(rdx_21 + 0x10) != *(rdx_21 + 8))
                            {
                                rbx[4] = rcx_17 + 1;
                                *(rdx_21 + 0x10) += 1;
                                **rbx[0x8c] = 0x20;
                                result = rbx[0x8c];
                                *result += 1;
                            }
                            else
                            {
                                int32_t rcx_18;
                                
                                if (!*(rdx_21 + 0x18))
                                    rcx_18 = -1;
                                else
                                    rcx_18 = rcx_17 + 1;
                                
                                rbx[4] = rcx_18;
                            }
                            
                            rcx_17 = rbx[4];
                            
                            if (rcx_17 == 0xffffffff)
                                break;
                            
                            r9_9 += 1;
                        } while (r9_9 < rsi_3);
                    }
                }
            }
            
            result = 1;
        }
        else
            result = 0;
    }
    else if (rdx > 0x53)
    {
        if (rdx == 0x58)
            goto label_18001ea2a;
        
        if (rdx == 0x5a)
        {
            result = sub_18001ed70(arg1);
            goto label_18001ea31;
        }
        
        if (rdx == 0x61)
            goto label_18001e96f;
        
        if (rdx == 0x63)
            goto label_18001e997;
        
        result = 0;
    }
    else
    {
        if (rdx == 0x53)
            goto label_18001ea15;
        
        if (rdx == 0x41)
            goto label_18001e96f;
        
        if (rdx == 0x43)
        {
        label_18001e997:
            result = sub_18001f048(arg1);
            goto label_18001ea31;
        }
        
        if (rdx == 0x45 || rdx == 0x46 || rdx == 0x47)
            goto label_18001e96f;
        
        result = 0;
    }
    
    __security_check_cookie(var_38 ^ &var_88);
    return result;
}

