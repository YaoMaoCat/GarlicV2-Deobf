
  void* sub_18001a7d0(int32_t* arg1, int64_t* arg2, int64_t arg3, int64_t* arg4, int32_t* arg5, char arg6, int32_t arg7, int32_t arg8)

{
    void var_138;
    int64_t rax_1 = __security_cookie ^ &var_138;
    int64_t* r14 = arg2;
    int32_t* rbp = arg1;
    int64_t var_d0 = arg3;
    int64_t rsi = arg3;
    int32_t rax_2 = sub_180019fb0(arg5, arg4);
    int32_t var_d8 = rax_2;
    int32_t rbx = rax_2;
    int64_t* var_c8;
    sub_180018960(r14, arg4, arg5, &var_c8);
    
    if (rbx <= __GetUnwindTryBlock(r14, arg4, arg5))
    {
        int32_t rax_4 = __GetUnwindTryBlock(r14, arg4, arg5);
        rbx = rax_4;
        var_d8 = rax_4;
    }
    else
    {
        __SetState(&var_c8, arg4, arg5, rbx);
        __FrameHandler3::SetUnwindTryBlock(r14, arg4, arg5, rbx);
    }
    
    if (rbx >= 0xffffffff && rbx < arg5[1])
    {
        int128_t var_70;
        void* result;
        
        if (*rbp != 0xe06d7363 || rbp[6] != 4 || rbp[8] - 0x19930520 > 2 || *(rbp + 0x30))
        {
        label_18001a97e:
            int64_t var_98_1 = arg4[1];
            int32_t* var_a0 = arg5;
            
            if (*rbp == 0xe06d7363 && rbp[6] == 4 && rbp[8] - 0x19930520 <= 2)
            {
                int32_t var_110;
                int64_t* var_100;
                void var_a8;
                
                if (arg5[3] > 0)
                {
                    var_110 = arg7;
                    int64_t* var_90;
                    sub_180018a90(&var_90, &var_a0, rbx, arg4, arg5);
                    int32_t var_88;
                    int32_t r8_5 = var_88;
                    int64_t* r9_4 = var_90;
                    var_c8 = r9_4;
                    int32_t var_d4_1 = r8_5;
                    int32_t var_78;
                    
                    while (r8_5 < var_78)
                    {
                        int64_t rax_22 = r9_4[1];
                        int64_t rdx_9 = *(*r9_4 + 0x10) + r8_5 * 0x14;
                        int32_t rcx_11 = *(rdx_9 + rax_22);
                        
                        if (rcx_11 <= rbx && rbx <= *(rdx_9 + rax_22 + 4))
                        {
                            int32_t rcx_12 = *(rdx_9 + rax_22 + 8);
                            uint64_t r14_1 = 0;
                            int32_t r12_1 = *(rdx_9 + rax_22 + 0xc);
                            int64_t rdx_11 = *(rdx_9 + rax_22 + 0x10) + arg4[1];
                            int64_t var_b0_1 = rdx_11;
                            
                            if (!r12_1)
                            {
                            label_18001abbe:
                                r14 = arg2;
                            }
                            else
                            {
                                while (true)
                                {
                                    uint64_t rcx_13 = r14_1 * 5;
                                    var_70 = *(rdx_11 + (rcx_13 << 2));
                                    int32_t var_60_1 = *(rdx_11 + (rcx_13 << 2) + 0x10);
                                    int32_t* rsi_2 =
                                        *(*(rbp + 0x30) + 0xc) + _GetThrowImageBase() + 4;
                                    int32_t rbx_3 =
                                        *(_GetThrowImageBase() + *(*(rbp + 0x30) + 0xc));
                                    
                                    if (rbx_3 > 0)
                                    {
                                        while (true)
                                        {
                                            char* rdi_2 = *rsi_2 + _GetThrowImageBase();
                                            
                                            if (sub_18001b900(&var_70, rdi_2, *(rbp + 0x30)))
                                            {
                                                r14 = arg2;
                                                int64_t* rax_31 =
                                                    sub_180018960(r14, arg4, arg5, &var_a8);
                                                
                                                if (rdi_2)
                                                    sub_18001a650(rbp, rax_31, &var_70, rdi_2);
                                                
                                                char var_e8_1 = arg6;
                                                int64_t* var_f0_1 = arg4;
                                                var_100 = rcx_12;
                                                var_110 = arg5;
                                                sub_180018d40(r14, rbp, var_d0, rax_31, 
                                                    _GetImageBase() + *(&var_70 + 0xc), var_110, 
                                                    rcx_11, var_100, &var_70);
                                                r8_5 = var_d4_1;
                                                r9_4 = var_c8;
                                                rbx = var_d8;
                                                break;
                                            }
                                            
                                            rbx_3 -= 1;
                                            rsi_2 = &rsi_2[1];
                                            
                                            if (rbx_3 <= 0)
                                                goto label_18001aaf0;
                                        }
                                        
                                        break;
                                    }
                                    
                                label_18001aaf0:
                                    r14_1 = r14_1 + 1;
                                    
                                    if (r14_1 == r12_1)
                                    {
                                        r8_5 = var_d4_1;
                                        rbx = var_d8;
                                        r9_4 = var_c8;
                                        goto label_18001abbe;
                                    }
                                    
                                    rdx_11 = var_b0_1;
                                }
                            }
                        }
                        
                        r8_5 += 1;
                        var_d4_1 = r8_5;
                    }
                }
                
                if ((*arg5 & 0x1fffffff) >= 0x19930521)
                {
                    int64_t rbx_5 = arg5[8];
                    int64_t rax_36;
                    
                    if (rbx_5)
                        rax_36 = _GetImageBase();
                    
                    if (rbx_5 && rax_36 != -(rbx_5))
                    {
                    label_18001ac22:
                        
                        if (arg5[9] & 4)
                        {
                            *(sub_180019c40() + 0x20) = rbp;
                            *(sub_180019c40() + 0x28) = var_d0;
                            sub_180020b48();
                            /* no return */
                        }
                        
                        int64_t rbx_6 = arg5[8];
                        int32_t* rdx_17;
                        
                        if (!rbx_6)
                            rdx_17 = nullptr;
                        else
                            rdx_17 = rbx_6 + _GetImageBase();
                        
                        if (!sub_18001cec0(rbp, rdx_17))
                        {
                            char var_e8_2 = arg6;
                            int64_t* var_f0_2 = arg4;
                            var_100 = 0xffffffff;
                            var_110 = arg5;
                            sub_180018d40(r14, rbp, var_d0, 
                                sub_180018960(r14, arg4, arg5, &var_a8), 0, var_110, 0xffffffff, 
                                var_100, 0);
                        }
                    }
                    else if (arg5[9] & 4 && !sub_180018770(arg4, arg5))
                        goto label_18001ac22;
                }
                
                goto label_18001acec;
            }
            
            if (arg5[3] <= 0)
                goto label_18001acec;
            
            if (!arg6)
            {
                sub_18001b330(rbp, r14, rsi, arg4, arg5, rbx, arg7, arg8);
            label_18001acec:
                result = sub_180019c40();
                
                if (!*(result + 0x38))
                {
                    __security_check_cookie(rax_1 ^ &var_138);
                    return result;
                }
            }
        }
        else
        {
            result = sub_180019c40();
            
            if (!*(result + 0x20))
            {
                __security_check_cookie(rax_1 ^ &var_138);
                return result;
            }
            
            rbp = *(sub_180019c40() + 0x20);
            rsi = *(sub_180019c40() + 0x28);
            var_d0 = rsi;
            _SetThrowImageBase(*(rbp + 0x38));
            
            if (rbp
                && (*rbp != 0xe06d7363 || rbp[6] != 4 || rbp[8] - 0x19930520 > 2 || *(rbp + 0x30)))
            {
                if (*(sub_180019c40() + 0x38))
                {
                    int32_t* rbx_1 = *(sub_180019c40() + 0x38);
                    *(sub_180019c40() + 0x38) = 0;
                    
                    if (!sub_18001cec0(rbp, rbx_1))
                    {
                        char rax_15;
                        int64_t rdx_6;
                        rax_15 = sub_18001cfd0(rbx_1);
                        
                        if (!rax_15)
                        {
                            sub_180020b48();
                            /* no return */
                        }
                        
                        rdx_6 = 1;
                        sub_180019930(rbp);
                        sub_18001c190(&var_70);
                        sub_180019520(&var_70, &data_180045520);
                        /* no return */
                    }
                    
                    rbx = var_d8;
                }
                
                goto label_18001a97e;
            }
        }
    }
    
    abort();
    /* no return */
}

