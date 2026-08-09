
  int128_t* sub_180011120(int128_t* arg1, int64_t* arg2, int64_t arg3)

{
    void var_a8;
    int64_t rax_1 = __security_cookie ^ &var_a8;
    int128_t* var_78 = arg1;
    
    if (!arg3 || !data_180047468)
    {
        *arg1 = {0};
        arg1[1] = 0;
        *(arg1 + 0x18) = 0xf;
        *arg1 = 0;
    }
    else
    {
        int64_t r8 = *arg2;
        int64_t rax_3 = (*(r8 + 0xf8))(arg2, arg3, r8);
        
        if (rax_3)
        {
            char* var_80 = nullptr;
            int64_t* rcx_1 = data_180047468;
            int32_t rax_5 = (*(*rcx_1 + 0x178))(rcx_1, rax_3, &var_80, 0);
            int64_t r8_2 = *arg2;
            (*(r8_2 + 0xb8))(arg2, rax_3, r8_2);
            
            if (rax_5)
                goto label_180011186;
            
            char* rdx_3 = var_80;
            
            if (!rdx_3)
                goto label_180011186;
            
            int128_t var_68 = {0};
            void* r8_3 = nullptr;
            void* var_58_1 = nullptr;
            int64_t rbx_2 = 0xf;
            int64_t var_50_1 = 0xf;
            var_68 = 0;
            
            if (*rdx_3 != 0x4c)
            {
                sub_18000bf60(&var_68, rdx_3);
                rdx_3 = var_80;
            }
            else
            {
                char* r12_2 = &rdx_3[1];
                
                if (*r12_2)
                {
                    int32_t* rsi_2 = var_68;
                    
                    do
                    {
                        char rax_6 = *r12_2;
                        
                        if (rax_6 == 0x3b)
                            break;
                        
                        char rcx_3 = rax_6;
                        
                        if (rax_6 == 0x2f)
                            rcx_3 = 0x2e;
                        
                        if (r8_3 >= rbx_2)
                        {
                            if (0x7fffffffffffffff - r8_3 < 1)
                            {
                                sub_180003aa0();
                                /* no return */
                            }
                            
                            int64_t r13_1 = rbx_2;
                            rbx_2 = (r8_3 + 1) | 0xf;
                            char* rdi_1;
                            uint64_t rcx_4;
                            
                            if (rbx_2 <= 0x7fffffffffffffff)
                            {
                                uint64_t rcx_6 = r13_1 >> 1;
                                
                                if (r13_1 > 0x7fffffffffffffff - rcx_6)
                                {
                                    rbx_2 = 0x7fffffffffffffff;
                                    rcx_4 = -0x7fffffffffffffd9;
                                    goto label_1800112f6;
                                }
                                
                                int64_t rax_12 = rcx_6 + r13_1;
                                
                                if (rbx_2 < rax_12)
                                    rbx_2 = rax_12;
                                
                                if (rbx_2 != -1)
                                {
                                    if (rbx_2 + 1 >= 0x1000)
                                    {
                                        rcx_4 = rbx_2 + 0x28;
                                        
                                        if (rcx_4 > rbx_2 + 1)
                                            goto label_1800112f6;
                                        
                                        stdext::threads::_Throw_lock_error();
                                        /* no return */
                                    }
                                    
                                    rdi_1 = sub_180016420(rbx_2 + 1);
                                }
                                else
                                    rdi_1 = nullptr;
                            }
                            else
                            {
                                rbx_2 = 0x7fffffffffffffff;
                                rcx_4 = -0x7fffffffffffffd9;
                            label_1800112f6:
                                int64_t rax_14 = sub_180016420(rcx_4);
                                
                                if (!rax_14)
                                    trap(0xd);
                                
                                rdi_1 = (rax_14 + 0x27) & 0xffffffffffffffe0;
                                *(rdi_1 - 8) = rax_14;
                            }
                            var_58_1 = r8_3 + 1;
                            var_50_1 = rbx_2;
                            int128_t* rcx_8 = rdi_1;
                            
                            if (r13_1 <= 0xf)
                            {
                                memcpy(rcx_8, &var_68, r8_3);
                                *(rdi_1 + r8_3) = rcx_3;
                                *(rdi_1 + r8_3 + 1) = 0;
                            }
                            else
                            {
                                memcpy(rcx_8, rsi_2, r8_3);
                                *(rdi_1 + r8_3) = rcx_3;
                                *(rdi_1 + r8_3 + 1) = 0;
                                
                                if (r13_1 + 1 < 0x1000)
                                    j_sub_180021340(rsi_2);
                                else
                                {
                                    int64_t rcx_9 = *(rsi_2 - 8);
                                    
                                    if (rsi_2 - rcx_9 - 8 > 0x1f)
                                        trap(0xd);
                                    
                                    j_sub_180021340(rcx_9);
                                }
                            }
                            
                            r8_3 += 1;
                            var_68 = rdi_1;
                            rsi_2 = rdi_1;
                        }
                        else
                        {
                            var_58_1 = r8_3 + 1;
                            int32_t* rax_8 = &var_68;
                            
                            if (rbx_2 > 0xf)
                                rax_8 = rsi_2;
                            
                            *(rax_8 + r8_3) = rcx_3;
                            *(rax_8 + r8_3 + 1) = 0;
                            rbx_2 = var_50_1;
                            r8_3 = var_58_1;
                            rsi_2 = var_68;
                        }
                        
                        r12_2 = &r12_2[1];
                    } while (*r12_2);
                    
                    rdx_3 = var_80;
                }
            }
            
            int64_t* rcx_13 = data_180047468;
            (*(*rcx_13 + 0x170))(rcx_13, rdx_3);
            *arg1 = var_68;
            arg1[1] = var_58_1;
        }
        else
        {
        label_180011186:
            *arg1 = {0};
            arg1[1] = 0;
            *(arg1 + 0x18) = 0xf;
            *arg1 = 0;
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_a8);
    return arg1;
}

