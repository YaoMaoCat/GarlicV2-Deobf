
  void* common_assert_to_message_box_build_string<char>(int32_t* arg1, int64_t* arg2, int64_t arg3, int64_t* arg4, char* arg5, char arg6, int32_t arg7, int32_t arg8)

{
    void var_1a8;
    int64_t rax_1 = __security_cookie ^ &var_1a8;
    char* r15 = arg5;
    int64_t rbx = arg3;
    int32_t* r14 = arg1;
    int64_t var_140 = rbx;
    char* var_130 = r15;
    int32_t rax_2 = sub_18001ce10(arg2, arg4, r15);
    int32_t rsi = rax_2;
    
    if (rax_2 >= 0xffffffff)
    {
        int64_t rcx_1 = *(r15 + 8);
        uint32_t rax_5;
        
        if (!rcx_1)
            rax_5 = 0;
        else
        {
            char* r8_2 = arg4[1] + rcx_1;
            uint64_t rcx_3 = *r8_2 & 0xf;
            rax_5 = *(r8_2 - *(rcx_3 + 0x180038880) - 4) >> *(rcx_3 + 0x180038890);
        }
        
        if (rsi < rax_5)
        {
            int32_t* var_118;
            void* result;
            
            if (*r14 != 0xe06d7363 || r14[6] != 4 || r14[8] - 0x19930520 > 2 || *(r14 + 0x30))
            {
            label_18001af1d:
                int32_t var_78;
                sub_18001c060(&var_78, r15, arg4[1]);
                
                if (*r14 == 0xe06d7363 && r14[6] == 4 && r14[8] - 0x19930520 <= 2)
                {
                    if (var_78 > 0)
                    {
                        int32_t var_180_1 = arg7;
                        char* var_188_1 = r15;
                        sub_180018bc0(&var_118, &var_78, rsi);
                        int32_t var_110;
                        int32_t rdi_1 = var_110;
                        int32_t* rbx_2 = var_118;
                        int32_t* var_128_1 = rbx_2;
                        int32_t var_148_1 = rdi_1;
                        int32_t var_100;
                        
                        while (rdi_1 < var_100)
                        {
                            int32_t rax_20 = rbx_2[6];
                            
                            if (rax_20 <= rsi && rsi <= rbx_2[7])
                            {
                                int32_t rax_21 = rbx_2[8];
                                int32_t r15_1 = 0;
                                int64_t r8_6 = rbx_2[9];
                                int128_t zmm0_1 = {0};
                                void* rdx_5 = arg4[1];
                                int32_t* rax_22 = arg4[2];
                                int64_t var_c0_1;
                                __builtin_memset(&var_c0_1, 0, 0x11);
                                int32_t var_80_1 = *rax_22;
                                int32_t var_ac_1 = 0;
                                int64_t var_a4_1 = 0;
                                void* var_88_1 = rdx_5;
                                uint32_t var_c8;
                                uint32_t r12_1;
                                
                                if (!r8_6)
                                {
                                    r12_1 = 0;
                                    var_c8 = 0;
                                }
                                else
                                {
                                    uint64_t r8_8 = *(rdx_5 + r8_6) & 0xf;
                                    void* rdx_7 = rdx_5 - *(r8_8 + 0x180038880) + r8_6;
                                    void* var_c0_2 = rdx_7;
                                    void* var_b8_1 = rdx_7;
                                    var_c8 = *(rdx_7 - 4) >> *(r8_8 + 0x180038890);
                                    sub_18001c630(&var_c8);
                                    r12_1 = var_c8;
                                }
                                
                                if (!r12_1)
                                {
                                label_18001b10e:
                                    r15 = var_130;
                                }
                                else
                                {
                                    while (true)
                                    {
                                        char var_b0;
                                        char var_f0 = var_b0;
                                        int16_t var_af;
                                        int16_t var_ef_1 = var_af;
                                        char var_ad;
                                        char var_ed_1 = var_ad;
                                        int32_t var_ec_1 = var_ac_1;
                                        int32_t var_a8;
                                        int32_t var_e8_1 = var_a8;
                                        int32_t var_e4_1 = var_a4_1;
                                        int32_t var_9c;
                                        int32_t var_dc_1 = var_9c;
                                        int64_t var_d8_1 = zmm0_1;
                                        int64_t var_d0_1 = *(&zmm0_1 + 8);
                                        int32_t* rsi_2 =
                                            *(*(r14 + 0x30) + 0xc) + _GetThrowImageBase() + 4;
                                        int32_t rbx_4 =
                                            *(_GetThrowImageBase() + *(*(r14 + 0x30) + 0xc));
                                        
                                        if (rbx_4 > 0)
                                        {
                                            while (true)
                                            {
                                                char* rdi_3 = *rsi_2 + _GetThrowImageBase();
                                                
                                                if (sub_18001ba30(&var_f0, rdi_3, *(r14 + 0x30)))
                                                {
                                                    r15 = var_130;
                                                    void var_f8;
                                                    int64_t* rax_52 =
                                                        __FrameHandler4::GetEstablisherFrame(arg2, 
                                                        arg4, r15, &var_f8);
                                                    
                                                    if (rdi_3)
                                                        sub_18001a710(r14, rax_52, &var_f0, rdi_3);
                                                    
                                                    char var_158_1 = arg6;
                                                    void* var_170;
                                                    var_170 = rax_21;
                                                    var_180_1 = r15;
                                                    sub_180018e70(arg2, r14, var_140, rax_52, 
                                                        _GetImageBase() + *(&var_a4_1 + 4), 
                                                        var_180_1, rax_20, var_170, &var_f0, arg4);
                                                    rbx_2 = var_128_1;
                                                    rsi = rax_2;
                                                    rdi_1 = var_148_1;
                                                    break;
                                                }
                                                
                                                rbx_4 -= 1;
                                                rsi_2 = &rsi_2[1];
                                                
                                                if (rbx_4 <= 0)
                                                    goto label_18001b0f1;
                                            }
                                            
                                            break;
                                        }
                                        
                                    label_18001b0f1:
                                        sub_18001c630(&var_c8);
                                        r15_1 += 1;
                                        
                                        if (r15_1 == r12_1)
                                        {
                                            rbx_2 = var_128_1;
                                            rsi = rax_2;
                                            rdi_1 = var_148_1;
                                            goto label_18001b10e;
                                        }
                                    }
                                }
                            }
                            
                            char* r10_1 = *(rbx_2 + 8);
                            rdi_1 += 1;
                            var_148_1 = rdi_1;
                            uint64_t rcx_17 = *r10_1 & 0xf;
                            int64_t r9_1 = *(rcx_17 + 0x180038880);
                            char rcx_18 = *(rcx_17 + 0x180038890);
                            char* rdx_10 = r10_1 - r9_1;
                            int32_t rax_43 = *(rdx_10 - 4);
                            *(rbx_2 + 8) = rdx_10;
                            rbx_2[6] = rax_43 >> rcx_18;
                            uint64_t rcx_20 = *rdx_10 & 0xf;
                            int64_t r8_10 = *(rcx_20 + 0x180038880);
                            char* rdx_13 = r10_1 - r8_10 - r9_1;
                            rbx_2[7] = *(rdx_13 - 4) >> *(rcx_20 + 0x180038890);
                            *(rbx_2 + 8) = rdx_13;
                            uint64_t rcx_23 = *rdx_13 & 0xf;
                            int32_t* r10_4 = r10_1 - *(rcx_23 + 0x180038880) - r8_10 - r9_1;
                            rbx_2[8] = r10_4[-1] >> *(rcx_23 + 0x180038890);
                            *(rbx_2 + 8) = r10_4;
                            int32_t rcx_25 = *r10_4;
                            *(rbx_2 + 8) = &r10_4[1];
                            rbx_2[9] = rcx_25;
                        }
                    }
                    
                    if (*r15 & 0x40 && !sub_1800187e0(arg4, r15))
                    {
                        *(sub_180019c40() + 0x20) = r14;
                        *(sub_180019c40() + 0x28) = var_140;
                        sub_180020b48();
                        /* no return */
                    }
                    
                    goto label_18001b2b7;
                }
                
                if (var_78 <= 0)
                    goto label_18001b2b7;
                
                if (!arg6)
                {
                    sub_18001b590(r14, arg2, rbx, arg4, r15, rsi, arg7, arg8);
                label_18001b2b7:
                    result = sub_180019c40();
                    
                    if (!*(result + 0x38))
                    {
                        __security_check_cookie(rax_1 ^ &var_1a8);
                        return result;
                    }
                }
            }
            else
            {
                result = sub_180019c40();
                
                if (!*(result + 0x20))
                {
                    __security_check_cookie(rax_1 ^ &var_1a8);
                    return result;
                }
                
                r14 = *(sub_180019c40() + 0x20);
                rbx = *(sub_180019c40() + 0x28);
                var_140 = rbx;
                _SetThrowImageBase(*(r14 + 0x38));
                
                if (r14 &&
                    (*r14 != 0xe06d7363 || r14[6] != 4 || r14[8] - 0x19930520 > 2 || *(r14 + 0x30)))
                {
                    if (*(sub_180019c40() + 0x38))
                    {
                        int32_t* rbx_1 = *(sub_180019c40() + 0x38);
                        *(sub_180019c40() + 0x38) = 0;
                        
                        if (!sub_18001cec0(r14, rbx_1))
                        {
                            char rax_16;
                            int64_t rdx_2;
                            rax_16 = sub_18001cfd0(rbx_1);
                            
                            if (!rax_16)
                            {
                                sub_180020b48();
                                /* no return */
                            }
                            
                            rdx_2 = 1;
                            sub_180019930(r14);
                            sub_18001c190(&var_118);
                            sub_180019520(&var_118, &data_180045520);
                            /* no return */
                        }
                        
                        rbx = var_140;
                    }
                    
                    goto label_18001af1d;
                }
            }
        }
    }
    
    abort();
    /* no return */
}

