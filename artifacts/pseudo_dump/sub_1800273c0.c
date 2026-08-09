
  uint64_t sub_1800273c0(int32_t* arg1, int32_t* arg2)

{
    int32_t r10 = *arg1;
    
    if (r10)
    {
        int32_t rdi_1 = *arg2;
        
        if (rdi_1)
        {
            uint64_t r10_1 = r10 - 1;
            uint64_t rbp_1 = rdi_1 - 1;
            
            if (!rbp_1)
            {
                uint64_t r12_1 = arg2[1];
                void var_214;
                
                if (r12_1 == 1)
                {
                    int32_t rbx_1 = arg1[1];
                    *arg1 = 0;
                    int32_t var_218_1 = 0;
                    memcpy_s(&arg1[1], 0x1cc, &var_214, nullptr);
                    return rbx_1;
                }
                
                uint64_t rax_1;
                int32_t rbp_2;
                
                if (r10_1)
                {
                    uint64_t rdi_2 = 0;
                    int64_t r14_1 = 0;
                    
                    while (r10_1 != 0xffffffff)
                    {
                        uint64_t rax_3 = arg1[r10_1 + 1];
                        int64_t rdx_1 = 0;
                        r10_1 = r10_1 - 1;
                        int64_t rax_4 = rax_3 | r14_1 << 0x20;
                        int32_t temp2_2 = r12_1;
                        r14_1 = COMBINE(rdx_1, rax_4) % temp2_2;
                        rdi_2 = (rdi_2 << 0x20) + COMBINE(rdx_1, rax_4) / temp2_2;
                    }
                    
                    int32_t var_218_3 = 0;
                    *arg1 = 0;
                    memcpy_s(&arg1[1], 0x1cc, &var_214, nullptr);
                    arg1[1] = r14_1;
                    uint32_t rcx_5 = r14_1 >> 0x20;
                    rax_1 = rdi_2;
                    arg1[2] = rcx_5;
                    rbp_2 = rcx_5;
                    *arg1 = rbp_2 + 1;
                }
                else
                {
                    int32_t rbx_2 = arg1[1];
                    *arg1 = 0;
                    int32_t var_218_2 = 0;
                    memcpy_s(&arg1[1], 0x1cc, &var_214, nullptr);
                    int32_t temp2_1 = r12_1;
                    uint32_t temp1_1 = COMBINE(0, rbx_2) % temp2_1;
                    rax_1 = COMBINE(0, rbx_2) / temp2_1;
                    arg1[1] = temp1_1;
                    rbp_2 = temp1_1;
                    *arg1 = rbp_2;
                }
                return rax_1;
            }
            
            if (rbp_1 <= r10_1)
            {
                int64_t rdx_3 = r10_1;
                int32_t r8_5 = r10_1 - rbp_1;
                int32_t r9_1 = r10_1;
                int64_t rbx_3 = r8_5;
                
                if (rdx_3 < rbx_3)
                {
                label_180027548:
                    r8_5 += 1;
                }
                else
                {
                    int32_t* rcx_7 = &arg1[1 + rdx_3];
                    
                    while (*(arg2 - (rbx_3 << 2) - arg1 + rcx_7) == *rcx_7)
                    {
                        r9_1 -= 1;
                        rdx_3 -= 1;
                        rcx_7 -= 4;
                        
                        if (rdx_3 < rbx_3)
                            goto label_180027548_1;
                    }
                    
                    if (arg2[r9_1 - r8_5 + 1] < arg1[r9_1 + 1])
                    {
                    label_180027548_1:
                        r8_5 += 1;
                    }
                }
                
                if (r8_5)
                {
                    int32_t r9_2 = arg2[rbp_1 + 1];
                    int32_t r11_4 = arg2[rdi_1 - 2 + 1];
                    uint64_t rflags_1;
                    int32_t temp0_3;
                    temp0_3 = _bit_scan_reverse(r9_2);
                    int32_t arg_18 = r11_4;
                    int32_t arg_8 = 0;
                    int32_t rbx_4 = 0x20;
                    arg_8 = 0;
                    int32_t r14_3 = 0;
                    char rcx_10 = rbx_4;
                    int32_t r11_5 = r11_4 << rcx_10;
                    arg_18 = r11_5;
                    
                    if (rdi_1 > 2)
                        arg_18 = r11_5 | arg2[rdi_1 - 3 + 1] >> r14_3;
                    
                    int32_t r12_2 = r8_5 - 1;
                    uint64_t var_228_1 = 0;
                    uint64_t r11_7 = 0;
                    
                    if (r12_2 >= 0)
                    {
                        char rax_19 = r14_3;
                        uint64_t rax_20 = r11_4 >> r14_3 | r9_2 << rcx_10;
                        uint64_t r13_1 = r12_2 + rdi_1;
                        int32_t temp7_1;
                        
                        do
                        {
                            int32_t rdx_7;
                            
                            if (r13_1 > r10_1)
                                rdx_7 = 0;
                            else
                                rdx_7 = arg1[r13_1 + 1];
                            
                            uint64_t r11_8 = arg1[r13_1 - 2 + 1];
                            uint64_t var_238_1 = arg1[r13_1 - 1 + 1];
                            *(&var_238_1 + 4) = rdx_7;
                            uint64_t r8_8;
                            
                            if (!rbx_4)
                                r8_8 = var_238_1;
                            else
                            {
                                char rcx_14 = rbx_4;
                                r8_8 = r11_8 >> rax_19 | var_238_1 << rcx_14;
                                r11_8 = r11_8 << rcx_14;
                                
                                if (r13_1 >= 3)
                                    r11_8 = r11_8 | arg1[r13_1 - 3 + 1] >> r14_3;
                            }
                            
                            int64_t r9_4 = COMBINE(0, r8_8) / rax_20;
                            uint64_t r8_9 = COMBINE(0, r8_8) % rax_20;
                            
                            if (r9_4 > 0xffffffff)
                            {
                                int64_t rax_32 = -0xffffffff + r9_4;
                                r9_4 = 0xffffffff;
                                r8_9 += rax_32 * rax_20;
                            }
                            
                            if (r8_9 <= 0xffffffff)
                            {
                                uint64_t rdx_11 = arg_18;
                                int64_t i = rdx_11 * r9_4;
                                
                                while (i > (r8_9 << 0x20 | r11_8))
                                {
                                    r9_4 -= 1;
                                    i -= rdx_11;
                                    r8_9 += rax_20;
                                    
                                    if (r8_9 > 0xffffffff)
                                        break;
                                }
                                
                                r14_3 = arg_8;
                            }
                            
                            if (r9_4)
                            {
                                uint64_t r10_2 = 0;
                                int32_t r11_9 = 0;
                                
                                if (rdi_1)
                                {
                                    int32_t* r14_6 = &arg2[1];
                                    
                                    do
                                    {
                                        uint64_t rax_35 = *r14_6;
                                        r14_6 = &r14_6[1];
                                        int64_t r10_3 = r10_2 + rax_35 * r9_4;
                                        uint64_t rax_37 = r11_9 + r12_2;
                                        int32_t r8_10 = r10_3;
                                        uint64_t r10_4 = r10_3 >> 0x20;
                                        int32_t rax_38 = arg1[rax_37 + 1];
                                        r10_2 = r10_4 + 1;
                                        
                                        if (rax_38 >= r8_10)
                                            r10_2 = r10_4;
                                        
                                        r11_9 += 1;
                                        arg1[rax_37 + 1] = rax_38 - r8_10;
                                    } while (r11_9 < rdi_1);
                                    
                                    r14_3 = arg_8;
                                }
                                
                                int32_t* r11_11 = &arg2[1];
                                
                                if (rdx_7 < r10_2)
                                {
                                    int32_t r10_5 = 0;
                                    
                                    if (rdi_1)
                                    {
                                        uint64_t r8_11 = 0;
                                        
                                        do
                                        {
                                            uint64_t rcx_21 = *r11_11;
                                            void* rdx_13 = &arg1[r10_5 + r12_2];
                                            r10_5 += 1;
                                            r11_11 = &r11_11[1];
                                            uint64_t r8_13 = r8_11 + *(rdx_13 + 4) + rcx_21;
                                            *(rdx_13 + 4) = r8_13;
                                            r8_11 = r8_13 >> 0x20;
                                        } while (r10_5 < rdi_1);
                                    }
                                    
                                    r9_4 -= 1;
                                }
                                
                                r10_1 = r13_1 - 1;
                            }
                            
                            r13_1 = r13_1 - 1;
                            r11_7 = (var_228_1 << 0x20) + r9_4;
                            temp7_1 = r12_2;
                            r12_2 -= 1;
                            var_228_1 = r11_7;
                        } while (temp7_1 - 1 >= 0);
                    }
                    
                    int32_t i_3 = r10_1 + 1;
                    int32_t i_1 = i_3;
                    
                    if (i_3 < *arg1)
                    {
                        do
                        {
                            uint64_t i_2 = i_1;
                            i_1 += 1;
                            arg1[i_2 + 1] = 0;
                        } while (i_1 < *arg1);
                    }
                    
                    *arg1 = i_3;
                    
                    if (i_3)
                    {
                        uint64_t rdx_14;
                        
                        do
                        {
                            rdx_14 = i_3 - 1;
                            i_3 = rdx_14;
                            
                            if (arg1[rdx_14 + 1])
                                break;
                            
                            *arg1 = rdx_14;
                        } while (rdx_14);
                    }
                    
                    return r11_7;
                }
            }
        }
    }
    
    return 0;
}

