
  uint64_t sub_180029b20(char* arg1, int64_t arg2, void* arg3, void (* arg4)())

{
    void var_468;
    int64_t rax_1 = __security_cookie ^ &var_468;
    char* r13 = arg1;
    uint64_t result;
    
    if (arg1)
    {
        if (arg3 && arg4)
            goto label_180029b79;
        
        *sub_18002131c() = 0x16;
        result = _invalid_parameter_noinfo();
    }
    else if (!arg2 && arg3 && arg4)
    {
    label_180029b79:
        sub_18002c30c(arg4);
        int128_t var_438[0x1f];
        sub_18002de50(&var_438, 0, 0x1f0);
        int128_t var_248[0x1f];
        result = sub_18002de50(&var_248, 0, 0x1f0);
        
        if (arg2 >= 2)
        {
            char* r15_3 = (arg2 - 1) * arg3 + r13;
            int64_t rcx_3 = 0;
            int64_t var_448_1 = 0;
            
            while (true)
            {
                result = COMBINE(0, r15_3 - r13) / arg3;
                
                if (result + 1 > 8)
                {
                    void* rbx_5 = ((result + 1) >> 1) * arg3;
                    char* rdi_2 = rbx_5 + r13;
                    
                    if (arg4(r13, rdi_2) > 0)
                    {
                        void* i_12 = arg3;
                        char* r8 = rdi_2;
                        
                        if (r13 != rdi_2)
                        {
                            void* i;
                            
                            do
                            {
                                char* rdx_6 = r8 - rbx_5;
                                char rcx_8 = *rdx_6;
                                *rdx_6 = *r8;
                                *r8 = rcx_8;
                                r8 = &r8[1];
                                i = i_12;
                                i_12 -= 1;
                            } while (i != 1);
                        }
                    }
                    
                    if (arg4(r13, r15_3) > 0)
                    {
                        void* i_9 = arg3;
                        char* rdx_8 = r15_3;
                        
                        if (r13 != r15_3)
                        {
                            char* r9_1 = r13 - r15_3;
                            void* i_1;
                            
                            do
                            {
                                char rcx_10 = *(r9_1 + rdx_8);
                                *(r9_1 + rdx_8) = *rdx_8;
                                *rdx_8 = rcx_10;
                                rdx_8 = &rdx_8[1];
                                i_1 = i_9;
                                i_9 -= 1;
                            } while (i_1 != 1);
                        }
                    }
                    
                    if (arg4(rdi_2, r15_3) > 0)
                    {
                        void* i_10 = arg3;
                        char* rdx_10 = r15_3;
                        
                        if (rdi_2 != r15_3)
                        {
                            char* r9_3 = rdi_2 - r15_3;
                            void* i_2;
                            
                            do
                            {
                                char rcx_12 = *(r9_3 + rdx_10);
                                *(r9_3 + rdx_10) = *rdx_10;
                                *rdx_10 = rcx_12;
                                rdx_10 = &rdx_10[1];
                                i_2 = i_10;
                                i_10 -= 1;
                            } while (i_2 != 1);
                        }
                    }
                    
                    char* rbx_6 = r13;
                    char* rsi_2 = r15_3;
                    char* rbp_1;
                    
                    while (true)
                    {
                        if (rdi_2 > rbx_6)
                        {
                            while (true)
                            {
                                rbx_6 += arg3;
                                
                                if (rbx_6 >= rdi_2)
                                    break;
                                
                                if (arg4(rbx_6, rdi_2) > 0)
                                    goto label_180029d9b;
                            }
                        }
                        
                        int32_t i_3;
                        
                        do
                        {
                            rbx_6 += arg3;
                            
                            if (rbx_6 > r15_3)
                                break;
                            
                            i_3 = arg4(rbx_6, rdi_2);
                        } while (i_3 <= 0);
                    label_180029d9b:
                        int32_t i_4;
                        
                        do
                        {
                            rbp_1 = rsi_2;
                            rsi_2 -= arg3;
                            
                            if (rsi_2 <= rdi_2)
                                break;
                            
                            i_4 = arg4(rsi_2, rdi_2);
                        } while (i_4 > 0);
                        
                        if (rsi_2 < rbx_6)
                            break;
                        
                        void* i_11 = arg3;
                        char* rdx_14 = rsi_2;
                        
                        if (rsi_2 != rbx_6)
                        {
                            char* r9_5 = rbx_6 - rsi_2;
                            void* i_5;
                            
                            do
                            {
                                char rcx_16 = *(r9_5 + rdx_14);
                                *(r9_5 + rdx_14) = *rdx_14;
                                *rdx_14 = rcx_16;
                                rdx_14 = &rdx_14[1];
                                i_5 = i_11;
                                i_11 -= 1;
                            } while (i_5 != 1);
                        }
                        
                        char* rax_13 = rbx_6;
                        
                        if (rdi_2 != rsi_2)
                            rax_13 = rdi_2;
                        
                        rdi_2 = rax_13;
                    }
                    
                    if (rdi_2 < rbp_1)
                    {
                        while (true)
                        {
                            rbp_1 -= arg3;
                            
                            if (rbp_1 <= rdi_2)
                                break;
                            
                            if (arg4(rbp_1, rdi_2))
                                goto label_180029e15;
                        }
                    }
                    
                    int32_t i_6;
                    
                    do
                    {
                        rbp_1 -= arg3;
                        
                        if (rbp_1 <= r13)
                            break;
                        
                        i_6 = arg4(rbp_1, rdi_2);
                    } while (!i_6);
                label_180029e15:
                    result = rbp_1 - r13;
                    rcx_3 = var_448_1;
                    
                    if (result < r15_3 - rbx_6)
                    {
                        if (rbx_6 < r15_3)
                        {
                            *(&var_438 + (rcx_3 << 3)) = rbx_6;
                            *(&var_248 + (rcx_3 << 3)) = r15_3;
                            rcx_3 += 1;
                            var_448_1 = rcx_3;
                        }
                        
                        if (r13 < rbp_1)
                        {
                            r15_3 = rbp_1;
                            continue;
                        }
                    }
                    else
                    {
                        if (r13 < rbp_1)
                        {
                            *(&var_438 + (rcx_3 << 3)) = r13;
                            *(&var_248 + (rcx_3 << 3)) = rbp_1;
                            rcx_3 += 1;
                            var_448_1 = rcx_3;
                        }
                        
                        if (rbx_6 < r15_3)
                        {
                            r13 = rbx_6;
                            continue;
                        }
                    }
                }
                else if (r15_3 > r13)
                {
                    char* rsi_1 = arg3 + r13;
                    
                    do
                    {
                        char* rbx_2 = r13;
                        char* rdi_1 = rsi_1;
                        
                        if (rsi_1 <= r15_3)
                        {
                            do
                            {
                                result = arg4(rdi_1, rbx_2);
                                char* rcx_5 = rdi_1;
                                
                                if (result <= 0)
                                    rcx_5 = rbx_2;
                                
                                rdi_1 += arg3;
                                rbx_2 = rcx_5;
                            } while (rdi_1 <= r15_3);
                        }
                        
                        void* i_8 = arg3;
                        char* rdx_3 = r15_3;
                        
                        if (rbx_2 != r15_3)
                        {
                            char* rbx_3 = rbx_2 - r15_3;
                            void* i_7;
                            
                            do
                            {
                                result = *rdx_3;
                                char rcx_6 = *(rbx_3 + rdx_3);
                                *(rbx_3 + rdx_3) = result;
                                *rdx_3 = rcx_6;
                                rdx_3 = &rdx_3[1];
                                i_7 = i_8;
                                i_8 -= 1;
                            } while (i_7 != 1);
                        }
                        
                        r15_3 -= arg3;
                    } while (r15_3 > r13);
                    
                    rcx_3 = var_448_1;
                }
                
                int64_t temp3_1 = rcx_3;
                rcx_3 -= 1;
                var_448_1 = rcx_3;
                
                if (temp3_1 - 1 < 0)
                    break;
                
                r13 = *(&var_438 + (rcx_3 << 3));
                r15_3 = *(&var_248 + (rcx_3 << 3));
            }
        }
    }
    else
    {
        *sub_18002131c() = 0x16;
        result = _invalid_parameter_noinfo();
    }
    
    __security_check_cookie(rax_1 ^ &var_468);
    return result;
}

