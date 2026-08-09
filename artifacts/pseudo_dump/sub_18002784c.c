
  uint64_t sub_18002784c(int64_t arg1, int32_t arg2, int32_t arg3, int32_t* arg4, char* arg5, int64_t arg6)

{
    void var_828;
    int64_t rax_1 = __security_cookie ^ &var_828;
    uint128_t zmm6 = arg1;
    int32_t var_7dc = arg3;
    int32_t var_7c0;
    fegetenv(&var_7c0);
    int32_t r15 = 1;
    char var_7b8;
    
    if ((var_7c0 & 0x1f) != 0x1f)
    {
        sub_18002b930(&var_7c0);
        var_7b8 = 1;
    }
    else
        var_7b8 = 0;
    
    *(arg4 + 8) = arg5;
    int64_t rdi = zmm6;
    int32_t rax_4 = 0x20;
    
    if (rdi < 0)
        rax_4 = 0x2d;
    
    int32_t var_7d8 = 0;
    *arg4 = rax_4;
    sub_18002b830(&var_7d8, 0, 0);
    int64_t rax_7 = rdi >> 0x34 & 0x7ff;
    char const* const r8;
    
    if (!rax_7)
    {
        if (0xfffffffffffff & rdi && !(var_7d8 & 0x1000000))
            goto label_1800279ee;
        
        arg4[1] = 0;
        r8 = &data_18003bbcc;
    label_1800279a4:
        
        if (sub_180020d70(arg5, arg6, r8))
        {
        label_180028ab5:
            int64_t var_808 = 0;
            _invoke_watson();
            /* no return */
        }
    }
    else if (rax_7 != 0x7ff)
    {
    label_1800279ee:
        int32_t var_7ec = 0;
        int32_t var_7cc_1 = 0x8001f;
        int64_t rdi_1 = rdi & 0x7fffffffffffffff;
        int32_t var_7d0;
        sub_18002b830(&var_7d0, 0, 0);
        sub_18002b830(&var_7ec, 0x8001f, var_7cc_1);
        double zmm0_1[0x2] = rdi_1;
        double rdx_2 = zmm0_1[0];
        var_7ec = arg2 + 1;
        uint64_t r8_3 = rdx_2 >> 0x34;
        int64_t rcx_8 = r8_3 & 0x7ff;
        int64_t rdi_4 = ((rdi_1 - rdi_1) & 0x10000000000000) + (rdx_2 & 0xfffffffffffff);
        int32_t r12_2 = 2 + 0xffffffff + 1 + (r8_3 & 0x7ff);
        int32_t rdx_4;
        double zmm0_3;
        zmm0_3 = sub_18002b990(log10(zmm0_1, zmm6));
        int32_t rcx_10 = zmm0_3;
        int32_t var_794 = rdi_4;
        int32_t rax_23 = (rcx_10 - 0x7fffffff) & 0xfffffffe;
        int32_t rax_24 = -(rax_23);
        uint32_t rdi_5 = rdi_4 >> 0x20;
        int32_t rax_26 = (rax_24 - rax_24) & rcx_10;
        uint32_t var_790_1 = rdi_5;
        uint64_t rax_28 = -(rdi_5);
        int32_t i_17 = -((rdx_4 - rdx_4)) + 1;
        int32_t i_10 = i_17;
        int32_t var_7e8_1;
        int32_t i_11;
        int32_t var_3f4;
        void* r9_1;
        int32_t i_2;
        
        if (r12_2 < 0x434)
        {
            if (r12_2 != 0x36)
            {
                rax_28 = 0;
                int32_t var_3f0_3 = 0x100000;
                var_3f4 = 0;
                int32_t var_3f8_5 = 2;
            }
            
            uint64_t rdi_11;
            
            if (r12_2 == 0x36 || !rdi_5)
            {
            label_180027e89:
                var_7e8_1 = 0;
                uint64_t rax_48 = (rax_28 - rax_28) & 4;
                uint64_t rflags_4;
                int32_t temp0_5;
                temp0_5 = __bsr_gprv_memv(*(&var_794 + rax_48));
                int32_t rax_50;
                
                rax_50 = !rax_48 ? 0 : temp0_5 + 1;
                
                int32_t r14_6;
                r14_6 = 0x20 - rax_50 < 1;
                i_2 = r14_6 + i_17;
                
                if (i_2 <= 0x73)
                {
                    int32_t rax_58 = i_2 - 1;
                    
                    if (rax_58 != 0xffffffff)
                    {
                        while (true)
                        {
                            uint64_t r10_6 = rax_58;
                            uint64_t r8_18 = rax_58 - 1;
                            int32_t r9_7;
                            
                            if (rax_58 >= i_17)
                                r9_7 = 0;
                            else
                                r9_7 = (&var_794)[r10_6];
                            
                            int32_t rcx_41;
                            
                            if (r8_18 >= i_17)
                                rcx_41 = 0;
                            else
                                rcx_41 = (&var_794)[r8_18];
                            
                            rax_58 = r8_18;
                            (&var_794)[r10_6] = rcx_41 >> 0x1f | (r9_7 * 2);
                            
                            if (r8_18 == 0xffffffff)
                                break;
                            
                            i_17 = i_10;
                        }
                    }
                }
                else
                    i_2 = 0;
                
                i_10 = i_2;
                rdi_11 = (0x435 - r12_2) >> 5;
                sub_18002de50(&var_3f4, 0, rdi_11 << 2);
                (&var_3f4)[rdi_11] = 1 << ((0x435 - r12_2) & 0x1f);
            }
            else
            {
                uint64_t r8_10 = 0;
                
                while (true)
                {
                    rax_28 = (&var_794)[r8_10];
                    
                    if ((&var_3f4)[r8_10] != rax_28)
                        goto label_180027e89;
                    
                    r8_10 = r8_10 + 1;
                    
                    if (r8_10 == 2)
                    {
                        var_7e8_1 = 0;
                        uint64_t rflags_3;
                        int32_t temp0_4;
                        temp0_4 = _bit_scan_reverse(rdi_5);
                        int32_t r14_5;
                        r14_5 = 0x20 < 2;
                        i_2 = r14_5 + i_17;
                        
                        if (i_2 <= 0x73)
                        {
                            int32_t rax_44 = i_2 - 1;
                            
                            if (rax_44 != 0xffffffff)
                            {
                                while (true)
                                {
                                    uint64_t r10_5 = rax_44;
                                    uint64_t r8_12 = rax_44 - 1;
                                    uint64_t r9_5;
                                    
                                    if (rax_44 >= i_17)
                                        r9_5 = 0;
                                    else
                                        r9_5 = (&var_794)[r10_5];
                                    
                                    int32_t rcx_28;
                                    
                                    if (r8_12 >= i_17)
                                        rcx_28 = 0;
                                    else
                                        rcx_28 = (&var_794)[r8_12];
                                    
                                    rax_44 = r8_12;
                                    (&var_794)[r10_5] = rcx_28 >> 0x1e | r9_5 << 2;
                                    
                                    if (r8_12 == 0xffffffff)
                                        break;
                                    
                                    i_17 = i_10;
                                }
                            }
                            
                            i_10 = i_2;
                        }
                        else
                        {
                            int32_t var_3f8_6 = 0;
                            i_10 = 0;
                            memcpy_s(&var_794, 0x1cc, &var_3f4, nullptr);
                            i_2 = i_10;
                        }
                        
                        rdi_11 = (0x436 - r12_2) >> 5;
                        sub_18002de50(&var_3f4, 0, rdi_11 << 2);
                        (&var_3f4)[rdi_11] = 1 << ((0x436 - r12_2) & 0x1f);
                        break;
                    }
                }
            }
            
            int32_t i_16 = rdi_11 + 1;
            r9_1 = i_16 << 2;
            i_11 = i_16;
            int32_t i_18 = i_16;
        }
        else
        {
            int32_t var_3f0_1 = 0x100000;
            var_3f4 = 0;
            int32_t var_3f8_1 = 2;
            
            if (!rdi_5)
            {
            label_180027c45:
                var_7e8_1 = 0;
                int32_t r11_4 = (r12_2 - 0x433) & 0x1f;
                uint32_t i = (r12_2 - 0x433) >> 5;
                int32_t rdi_8 = 1 << (0x20 - r11_4);
                uint64_t rflags_2;
                int32_t temp0_3;
                temp0_3 = __bsr_gprv_memv((&var_794)[i_17 - 1]);
                int32_t rcx_21;
                
                rcx_21 = rdi_8 == 1 ? 0 : temp0_3 + 1;
                
                if (i_17 + i <= 0x73)
                {
                    int32_t r14_3;
                    r14_3 = r11_4 > 0x20 - rcx_21;
                    i_2 = r14_3 + i_17 + i;
                }
                
                if (i_17 + i > 0x73 || i_2 > 0x73)
                {
                    int32_t var_3f8_4 = 0;
                    i_10 = 0;
                    memcpy_s(&var_794, 0x1cc, &var_3f4, nullptr);
                    i_2 = i_10;
                }
                else
                {
                    uint64_t r10_4 = i_2 - 1;
                    
                    if (r10_4 != i - 1)
                    {
                        while (true)
                        {
                            uint64_t rax_41 = r10_4 - i;
                            uint64_t rcx_23 = rax_41 - 1;
                            int32_t r9_2;
                            
                            if (rax_41 >= i_17)
                                r9_2 = 0;
                            else
                                r9_2 = (&var_794)[rax_41];
                            
                            int32_t rdx_11;
                            
                            if (rcx_23 >= i_17)
                                rdx_11 = 0;
                            else
                                rdx_11 = (&var_794)[rcx_23];
                            
                            (&var_794)[r10_4] = (rdx_11 & ~(rdi_8 - 1)) >> (0x20 - r11_4)
                                | (r9_2 & (rdi_8 - 1)) << r11_4;
                            r10_4 = r10_4 - 1;
                            
                            if (r10_4 == i - 1)
                                break;
                            
                            i_17 = i_10;
                        }
                        
                        r15 = 1;
                    }
                    
                    uint64_t rcx_26 = 0;
                    
                    if (i)
                    {
                        do
                        {
                            (&var_794)[rcx_26] = 0;
                            rcx_26 = rcx_26 + 1;
                        } while (rcx_26 != i);
                    }
                    
                    i_10 = i_2;
                }
                
                var_3f4 = 2;
            }
            else
            {
                uint64_t r8_5 = 0;
                
                while (true)
                {
                    if ((&var_3f4)[r8_5] != (&var_794)[r8_5])
                        goto label_180027c45;
                    
                    r8_5 = r8_5 + 1;
                    
                    if (r8_5 == 2)
                    {
                        var_7e8_1 = 0;
                        int32_t r11_2 = (r12_2 - 0x432) & 0x1f;
                        uint32_t i_1 = (r12_2 - 0x432) >> 5;
                        int32_t rdi_6 = 1 << (0x20 - r11_2);
                        uint64_t rflags_1;
                        int32_t temp0_2;
                        temp0_2 = __bsr_gprv_memv((&var_794)[i_17 - 1]);
                        int32_t rcx_13;
                        
                        rcx_13 = rdi_6 == 1 ? 0 : temp0_2 + 1;
                        
                        if (i_17 + i_1 <= 0x73)
                        {
                            int32_t r14_1;
                            r14_1 = r11_2 > 0x20 - rcx_13;
                            i_2 = r14_1 + i_17 + i_1;
                        }
                        
                        if (i_17 + i_1 > 0x73 || i_2 > 0x73)
                        {
                            int32_t var_3f8_2 = 0;
                            i_10 = 0;
                            memcpy_s(&var_794, 0x1cc, &var_3f4, nullptr);
                            i_2 = i_10;
                        }
                        else
                        {
                            uint64_t r9 = i_2 - 1;
                            
                            if (r9 != i_1 - 1)
                            {
                                while (true)
                                {
                                    uint64_t rax_35 = r9 - i_1;
                                    uint64_t rcx_15 = rax_35 - 1;
                                    int32_t r10_1;
                                    
                                    if (rax_35 >= i_17)
                                        r10_1 = 0;
                                    else
                                        r10_1 = (&var_794)[rax_35];
                                    
                                    int32_t rdx_7;
                                    
                                    if (rcx_15 >= i_17)
                                        rdx_7 = 0;
                                    else
                                        rdx_7 = (&var_794)[rcx_15];
                                    
                                    (&var_794)[r9] = (rdx_7 & ~(rdi_6 - 1)) >> (0x20 - r11_2)
                                        | (r10_1 & (rdi_6 - 1)) << r11_2;
                                    r9 = r9 - 1;
                                    
                                    if (r9 == i_1 - 1)
                                        break;
                                    
                                    i_17 = i_10;
                                }
                                
                                r15 = 1;
                            }
                            
                            uint64_t rcx_18 = 0;
                            
                            if (i_1)
                            {
                                do
                                {
                                    (&var_794)[rcx_18] = 0;
                                    rcx_18 = rcx_18 + 1;
                                } while (rcx_18 != i_1);
                            }
                            
                            i_10 = i_2;
                        }
                        
                        var_3f4 = 4;
                        break;
                    }
                }
            }
            
            int32_t var_3f0_2 = 0;
            r9_1 = 4;
            int32_t var_3f8_3 = 1;
            i_11 = 1;
        }
        
        int128_t var_5c4[0x1c];
        memcpy_s(&var_5c4, 0x1cc, &var_3f4, r9_1);
        int32_t rcx_36 = rax_26;
        int32_t i_4;
        int32_t var_224[0x73];
        
        if (rcx_36 < 0)
        {
            int32_t rcx_59 = -(rcx_36);
            uint32_t rax_75 = rcx_59 / 0xa;
            uint32_t var_7f0_1 = rax_75;
            
            if (rax_75)
            {
                while (true)
                {
                    uint32_t rcx_60 = rax_75;
                    
                    if (rax_75 > 0x26)
                        rcx_60 = 0x26;
                    
                    uint64_t rax_76 = rcx_60 - 1;
                    uint64_t rcx_61 = *((rax_76 << 2) + 0x18003bb12);
                    uint64_t rsi_11 = *((rax_76 << 2) + 0x18003bb13);
                    sub_18002de50(&var_3f4, 0, rcx_61 << 2);
                    memcpy(&(&var_3f4)[rcx_61], 
                        &data_18003b200 + (*((rax_76 << 2) + 0x18003bb10) << 2), rsi_11 << 2);
                    uint64_t i_15 = rsi_11 + rcx_61;
                    int32_t* rax_79;
                    uint32_t r8_30;
                    
                    if (i_15 <= 1)
                    {
                        rax_79 = var_3f4;
                        
                        if (!rax_79)
                        {
                        label_1800284d1:
                            i_2 = 0;
                            i_10 = i_2;
                            rax_79 = 1;
                        }
                        else if (rax_79 == 1 || !i_2)
                            rax_79 = 1;
                        else
                        {
                            r8_30 = 0;
                            uint64_t r9_11 = 0;
                            
                            do
                            {
                                void* rcx_66 = (&var_794)[r9_11] * rax_79 + r8_30;
                                (&var_794)[r9_11] = rcx_66;
                                r8_30 = rcx_66 >> 0x20;
                                r9_11 = r9_11 + 1;
                            } while (r9_11 != i_2);
                            
                        label_18002851b:
                            
                            if (!r8_30)
                            {
                                i_2 = i_10;
                                rax_79 = 1;
                            }
                            else if (i_10 >= 0x73)
                            {
                                i_2 = 0;
                                i_10 = 0;
                                rax_79 = 0;
                            }
                            else
                            {
                                (&var_794)[i_10] = r8_30;
                                i_2 = i_10 + 1;
                                i_10 = i_2;
                                rax_79 = 1;
                            }
                        }
                    }
                    else if (i_2 > 1)
                    {
                        bool c_9 = i_15 < i_2;
                        int32_t i_3 = i_2;
                        int32_t* rcx_71 = &var_3f4;
                        
                        if (!c_9)
                            rcx_71 = &var_794;
                        
                        if (c_9)
                            i_3 = i_15;
                        
                        int32_t* var_7b0_1 = rcx_71;
                        rax_79 = c_9;
                        int32_t i_8 = i_3;
                        int32_t* rdx_29 = &var_794;
                        
                        if (!c_9)
                            rdx_29 = &var_3f4;
                        
                        int32_t* var_7c8_2 = rdx_29;
                        
                        if (rax_79)
                            i_15 = i_2;
                        
                        i_2 = 0;
                        uint64_t r10_13 = 0;
                        int32_t i_13 = 0;
                        
                        if (i_3)
                        {
                            do
                            {
                                uint64_t rsi_13 = rcx_71[r10_13];
                                
                                if (rsi_13)
                                {
                                    uint32_t j_9 = 0;
                                    int32_t j = r10_13;
                                    
                                    if (i_15)
                                    {
                                        int32_t rdi_19 = -(r10_13);
                                        
                                        while (j != 0x73)
                                        {
                                            uint64_t j_7 = j;
                                            
                                            if (j == i_2)
                                            {
                                                var_224[j_7] = 0;
                                                i_13 = j + 1;
                                            }
                                            
                                            uint64_t rax_82 = j + rdi_19;
                                            j += 1;
                                            int64_t rdx_33 =
                                                rdx_29[rax_82] * rsi_13 + j_9 + var_224[j_7];
                                            var_224[j_7] = rdx_33;
                                            i_2 = i_13;
                                            j_9 = rdx_33 >> 0x20;
                                            
                                            if (j + rdi_19 == i_15)
                                                break;
                                            
                                            rdx_29 = var_7c8_2;
                                        }
                                        
                                        if (j_9)
                                        {
                                            uint32_t j_1;
                                            
                                            do
                                            {
                                                if (j == 0x73)
                                                    goto label_18002883e;
                                                
                                                uint64_t j_5 = j;
                                                
                                                if (j == i_2)
                                                {
                                                    var_224[j_5] = 0;
                                                    i_13 = j + 1;
                                                }
                                                
                                                j += 1;
                                                void* rcx_73 = var_224[j_5] + j_9;
                                                var_224[j_5] = rcx_73;
                                                i_2 = i_13;
                                                j_1 = rcx_73 >> 0x20;
                                                j_9 = j_1;
                                            } while (j_1);
                                        }
                                        
                                        i_3 = i_8;
                                    }
                                    
                                    if (j == 0x73)
                                        goto label_18002883e;
                                    
                                    rcx_71 = var_7b0_1;
                                    rdx_29 = var_7c8_2;
                                }
                                else if (r10_13 == i_2)
                                {
                                    var_224[r10_13] &= rsi_13;
                                    i_2 = r10_13 + 1;
                                    i_13 = i_2;
                                }
                                
                                r10_13 = r10_13 + 1;
                            } while (r10_13 != i_3);
                        }
                        
                        void* r8_36 = i_2 << 2;
                        i_10 = i_2;
                        
                        if (!r8_36)
                            rax_79 = 1;
                        else
                        {
                            int128_t* rcx_74 = &var_794;
                            
                            if (r8_36 > 0x1cc)
                            {
                                sub_18002de50(rcx_74, 0, 0x1cc);
                                *sub_18002131c() = 0x22;
                                _invalid_parameter_noinfo();
                            }
                            else
                                memcpy(rcx_74, &var_224, r8_36);
                            
                            i_2 = i_10;
                            rax_79 = 1;
                        }
                    }
                    else
                    {
                        uint64_t rbx_12 = var_794;
                        void* r8_33 = i_15 << 2;
                        i_2 = i_15;
                        i_10 = i_15;
                        
                        if (r8_33)
                        {
                            int128_t* rcx_67 = &var_794;
                            
                            if (r8_33 > 0x1cc)
                            {
                                sub_18002de50(rcx_67, 0, 0x1cc);
                                *sub_18002131c() = 0x22;
                                _invalid_parameter_noinfo();
                            }
                            else
                                memcpy(rcx_67, &var_3f4, r8_33);
                            
                            i_2 = i_10;
                        }
                        
                        if (!rbx_12)
                            goto label_1800284d1;
                        
                        if (rbx_12 != 1 && i_2)
                        {
                            r8_30 = 0;
                            uint64_t r9_12 = 0;
                            
                            do
                            {
                                void* rcx_70 = (&var_794)[r9_12] * rbx_12 + r8_30;
                                (&var_794)[r9_12] = rcx_70;
                                r8_30 = rcx_70 >> 0x20;
                                r9_12 = r9_12 + 1;
                            } while (r9_12 != i_2);
                            
                            goto label_18002851b;
                        }
                        
                        rax_79 = 1;
                    }
                    
                    if (!rax_79)
                        break;
                    
                    rax_75 = var_7f0_1 - rcx_60;
                    bool cond:11_1 = var_7f0_1 != rcx_60;
                    var_7f0_1 = rax_75;
                    
                    if (!cond:11_1)
                        goto label_1800287c9;
                }
                
                goto label_18002883e;
            }
            
        label_1800287c9:
            
            if (rcx_59 != rcx_59 / 0xa * 0xa)
            {
                int32_t rax_91 = *(((rcx_59 % 0xa - 1) << 2) + 0x18003bba8);
                
                if (!rax_91)
                {
                label_18002883e:
                    i_2 = 0;
                    i_10 = i_2;
                }
                else if (rax_91 != 1 && i_2)
                {
                    uint32_t r8_37 = 0;
                    uint64_t r9_13 = 0;
                    
                    do
                    {
                        int64_t rcx_78 = (&var_794)[r9_13] * rax_91 + r8_37;
                        (&var_794)[r9_13] = rcx_78;
                        r8_37 = rcx_78 >> 0x20;
                        r9_13 = r9_13 + 1;
                    } while (r9_13 != i_2);
                    
                    if (!r8_37)
                        i_2 = i_10;
                    else
                    {
                        if (i_10 >= 0x73)
                            goto label_18002883e;
                        
                        (&var_794)[i_10] = r8_37;
                        i_2 = i_10 + 1;
                        i_10 = i_2;
                    }
                }
            }
            
            i_4 = i_11;
        }
        else
        {
            i_4 = i_11;
            uint32_t rax_53 = rcx_36 / 0xa;
            uint32_t var_7f8_4 = rax_53;
            
            if (rax_53)
            {
                while (true)
                {
                    uint32_t rcx_37 = rax_53;
                    
                    if (rax_53 > 0x26)
                        rcx_37 = 0x26;
                    
                    uint64_t rax_54 = rcx_37 - 1;
                    uint64_t rcx_38 = *((rax_54 << 2) + 0x18003bb12);
                    uint64_t rsi_8 = *((rax_54 << 2) + 0x18003bb13);
                    sub_18002de50(&var_3f4, 0, rcx_38 << 2);
                    memcpy(&(&var_3f4)[rcx_38], 
                        &data_18003b200 + (*((rax_54 << 2) + 0x18003bb10) << 2), rsi_8 << 2);
                    uint64_t i_14 = rsi_8 + rcx_38;
                    int32_t* rax_57;
                    uint32_t r8_19;
                    
                    if (i_14 <= 1)
                    {
                        rax_57 = var_3f4;
                        
                        if (!rax_57)
                        {
                        label_180027ff1:
                            i_4 = 0;
                            i_11 = i_4;
                            rax_57 = 1;
                        }
                        else if (rax_57 == 1 || !i_4)
                            rax_57 = 1;
                        else
                        {
                            r8_19 = 0;
                            uint64_t r9_8 = 0;
                            
                            do
                            {
                                void* rcx_46 = *(&var_5c4 + (r9_8 << 2)) * rax_57 + r8_19;
                                *(&var_5c4 + (r9_8 << 2)) = rcx_46;
                                r8_19 = rcx_46 >> 0x20;
                                r9_8 = r9_8 + 1;
                            } while (r9_8 != i_4);
                            
                        label_180028093:
                            
                            if (!r8_19)
                            {
                                i_4 = i_11;
                                rax_57 = 1;
                            }
                            else if (i_11 >= 0x73)
                            {
                                i_4 = 0;
                                i_11 = 0;
                                rax_57 = 0;
                            }
                            else
                            {
                                *(&var_5c4 + (i_11 << 2)) = r8_19;
                                i_4 = i_11 + 1;
                                i_11 = i_4;
                                rax_57 = 1;
                            }
                        }
                    }
                    else if (i_4 > 1)
                    {
                        bool c_8 = i_14 < i_4;
                        int32_t i_5 = i_4;
                        int32_t* rcx_51 = &var_3f4;
                        
                        if (!c_8)
                            rcx_51 = &var_5c4;
                        
                        if (c_8)
                            i_5 = i_14;
                        
                        int32_t* var_7c8_1 = rcx_51;
                        rax_57 = c_8;
                        int32_t i_9 = i_5;
                        int128_t (* rdx_18)[0x1c] = &var_5c4;
                        
                        if (!c_8)
                            rdx_18 = &var_3f4;
                        
                        var_7e8_1 = rdx_18;
                        
                        if (rax_57)
                            i_14 = i_4;
                        
                        i_4 = 0;
                        uint64_t r10_9 = 0;
                        int32_t i_12 = 0;
                        
                        if (i_5)
                        {
                            do
                            {
                                uint64_t rsi_10 = rcx_51[r10_9];
                                
                                if (rsi_10)
                                {
                                    uint32_t j_8 = 0;
                                    int32_t j_2 = r10_9;
                                    
                                    if (i_14)
                                    {
                                        int32_t rdi_16 = -(r10_9);
                                        
                                        while (j_2 != 0x73)
                                        {
                                            uint64_t j_6 = j_2;
                                            
                                            if (j_2 == i_4)
                                            {
                                                var_224[j_6] = 0;
                                                i_12 = j_2 + 1;
                                            }
                                            
                                            uint64_t rax_62 = j_2 + rdi_16;
                                            j_2 += 1;
                                            int64_t rdx_22 = *(rdx_18 + (rax_62 << 2)) * rsi_10
                                                + var_224[j_6] + j_8;
                                            var_224[j_6] = rdx_22;
                                            i_4 = i_12;
                                            j_8 = rdx_22 >> 0x20;
                                            
                                            if (j_2 + rdi_16 == i_14)
                                                break;
                                            
                                            rdx_18 = var_7e8_1;
                                        }
                                        
                                        if (j_8)
                                        {
                                            uint32_t j_3;
                                            
                                            do
                                            {
                                                if (j_2 == 0x73)
                                                    goto label_180028416;
                                                
                                                uint64_t j_4 = j_2;
                                                
                                                if (j_2 == i_4)
                                                {
                                                    var_224[j_4] = 0;
                                                    i_12 = j_2 + 1;
                                                }
                                                
                                                j_2 += 1;
                                                void* rcx_53 = var_224[j_4] + j_8;
                                                var_224[j_4] = rcx_53;
                                                i_4 = i_12;
                                                j_3 = rcx_53 >> 0x20;
                                                j_8 = j_3;
                                            } while (j_3);
                                        }
                                        
                                        i_5 = i_9;
                                    }
                                    
                                    if (j_2 == 0x73)
                                        goto label_180028416;
                                    
                                    rcx_51 = var_7c8_1;
                                    rdx_18 = var_7e8_1;
                                }
                                else if (r10_9 == i_4)
                                {
                                    var_224[r10_9] &= rsi_10;
                                    i_4 = r10_9 + 1;
                                    i_12 = i_4;
                                }
                                
                                r10_9 = r10_9 + 1;
                            } while (r10_9 != i_5);
                        }
                        
                        void* r8_25 = i_4 << 2;
                        i_11 = i_4;
                        
                        if (!r8_25)
                            rax_57 = 1;
                        else
                        {
                            int128_t* rcx_54 = &var_5c4;
                            
                            if (r8_25 > 0x1cc)
                            {
                                sub_18002de50(rcx_54, 0, 0x1cc);
                                *sub_18002131c() = 0x22;
                                _invalid_parameter_noinfo();
                            }
                            else
                                memcpy(rcx_54, &var_224, r8_25);
                            
                            i_4 = i_11;
                            rax_57 = 1;
                        }
                    }
                    else
                    {
                        uint64_t rbx_10 = var_5c4[0];
                        void* r8_22 = i_14 << 2;
                        i_4 = i_14;
                        i_11 = i_14;
                        
                        if (r8_22)
                        {
                            int128_t* rcx_47 = &var_5c4;
                            
                            if (r8_22 > 0x1cc)
                            {
                                sub_18002de50(rcx_47, 0, 0x1cc);
                                *sub_18002131c() = 0x22;
                                _invalid_parameter_noinfo();
                            }
                            else
                                memcpy(rcx_47, &var_3f4, r8_22);
                            
                            i_4 = i_11;
                        }
                        
                        if (!rbx_10)
                            goto label_180027ff1;
                        
                        if (rbx_10 != 1 && i_4)
                        {
                            r8_19 = 0;
                            uint64_t r9_9 = 0;
                            
                            do
                            {
                                void* rcx_50 = *(&var_5c4 + (r9_9 << 2)) * rbx_10 + r8_19;
                                *(&var_5c4 + (r9_9 << 2)) = rcx_50;
                                r8_19 = rcx_50 >> 0x20;
                                r9_9 = r9_9 + 1;
                            } while (r9_9 != i_4);
                            
                            goto label_180028093;
                        }
                        
                        rax_57 = 1;
                    }
                    
                    if (!rax_57)
                        goto label_180028416;
                    
                    rax_53 = var_7f8_4 - rcx_37;
                    bool cond:12_1 = var_7f8_4 != rcx_37;
                    var_7f8_4 = rax_53;
                    
                    if (!cond:12_1)
                    {
                        rcx_36 = rax_26;
                        break;
                    }
                }
            }
            
            if (rcx_36 != rcx_36 / 0xa * 0xa)
            {
                int32_t rax_71 = *(((rcx_36 % 0xa - 1) << 2) + 0x18003bba8);
                
                if (!rax_71)
                {
                label_180028416:
                    i_4 = 0;
                    i_11 = i_4;
                }
                else if (rax_71 != 1 && i_4)
                {
                    uint32_t r8_26 = 0;
                    uint64_t r9_10 = 0;
                    
                    do
                    {
                        int64_t rcx_58 = *(&var_5c4 + (r9_10 << 2)) * rax_71 + r8_26;
                        *(&var_5c4 + (r9_10 << 2)) = rcx_58;
                        r8_26 = rcx_58 >> 0x20;
                        r9_10 = r9_10 + 1;
                    } while (r9_10 != i_4);
                    
                    if (!r8_26)
                        i_4 = i_11;
                    else
                    {
                        if (i_11 >= 0x73)
                            goto label_180028416;
                        
                        *(&var_5c4 + (i_11 << 2)) = r8_26;
                        i_4 = i_11 + 1;
                        i_11 = i_4;
                    }
                }
            }
        }
        char* rbx_13 = arg5;
        
        if (i_2)
        {
            uint32_t r8_39 = 0;
            uint64_t r9_14 = 0;
            
            do
            {
                uint64_t r8_40 = r8_39 + (&var_794)[r9_14] * 0xa;
                (&var_794)[r9_14] = r8_40;
                r9_14 = r9_14 + 1;
                r8_39 = r8_40 >> 0x20;
            } while (r9_14 != i_2);
            
            if (r8_39)
            {
                if (i_10 >= 0x73)
                    i_10 = 0;
                else
                {
                    (&var_794)[i_10] = r8_39;
                    i_10 += 1;
                }
            }
        }
        
        int32_t rax_97 = sub_1800273c0(&i_10, &i_11);
        int32_t r10_15 = rax_26;
        i_2 = 0x30;
        
        if (rax_97 == 0xa)
        {
            r10_15 += 1;
            *arg5 = 0x31;
            rbx_13 = &arg5[1];
            
            if (i_4)
            {
                uint32_t r8_41 = 0;
                uint64_t r9_15 = 0;
                
                do
                {
                    uint64_t r8_42 = r8_41 + *(&var_5c4 + (r9_15 << 2)) * 0xa;
                    *(&var_5c4 + (r9_15 << 2)) = r8_42;
                    r9_15 = r9_15 + 1;
                    r8_41 = r8_42 >> 0x20;
                } while (r9_15 != i_4);
                
                if (r8_41)
                {
                    if (i_11 >= 0x73)
                        i_11 = 0;
                    else
                    {
                        *(&var_5c4 + (i_11 << 2)) = r8_41;
                        i_11 += 1;
                    }
                }
            }
        }
        else if (rax_97)
        {
            rax_97 += 0x30;
            rbx_13 = &arg5[1];
            *arg5 = rax_97;
        }
        else
            r10_15 -= 1;
        
        arg4[1] = r10_15;
        int32_t rax_102 = var_7ec;
        
        if (r10_15 >= 0 && rax_102 <= 0x7fffffff && !var_7dc)
            rax_102 += r10_15;
        
        uint64_t rdi_20 = rax_102;
        
        if (arg6 - 1 < rdi_20)
            rdi_20 = arg6 - 1;
        
        void* rdi_21 = &arg5[rdi_20];
        char* rsi_14;
        rsi_14 = 0;
        int32_t i_6;
        
        if (rbx_13 == rdi_21)
        {
        label_180028a4c:
            i_6 = i_10;
        }
        else
        {
            while (true)
            {
                i_6 = i_10;
                
                if (!i_6)
                    break;
                
                uint32_t r8_43 = 0;
                uint64_t r10_16 = 0;
                
                do
                {
                    int64_t rcx_83 = (&var_794)[r10_16] * 0x3b9aca00 + r8_43;
                    (&var_794)[r10_16] = rcx_83;
                    r8_43 = rcx_83 >> 0x20;
                    r10_16 = r10_16 + 1;
                } while (r10_16 != i_6);
                
                if (r8_43)
                {
                    if (i_10 >= 0x73)
                        i_10 = 0;
                    else
                    {
                        (&var_794)[i_10] = r8_43;
                        i_10 += 1;
                    }
                }
                
                uint32_t r8_45 = sub_1800273c0(&i_10, &i_11);
                
                for (int32_t i_7 = 8; i_7 != 0xffffffff; i_7 -= 1)
                {
                    uint32_t rdx_40 = r8_45 / 0xa;
                    r8_45 -= rdx_40 * 0xa;
                    char rcx_85 = i_2 + r8_45;
                    r8_45 = rdx_40;
                    
                    if (rdi_21 - rbx_13 > i_7)
                        *(i_7 + rbx_13) = rcx_85;
                    else if (rcx_85 != 0x30)
                        rsi_14 = 1;
                }
                
                void* rax_112 = rdi_21 - rbx_13;
                
                if (rax_112 > 9)
                    rax_112 = 9;
                
                rbx_13 += rax_112;
                
                if (rbx_13 == rdi_21)
                    goto label_180028a4c;
            }
        }
        
        *rbx_13 = 0;
        
        if (i_6 || rsi_14)
            r15 = 0;
        
        var_7dc = 0;
        sub_18002b830(&var_7dc, var_7d0, var_7cc_1);
    }
    else
    {
        int64_t rax_9 = rdi & 0xfffffffffffff;
        int32_t rax_10;
        
        if (!rax_9)
            rax_10 = 1;
        else if (rdi >= 0 || rax_9 != 0x8000000000000)
            rax_10 = (~(rdi >> 0x33) & 1) | 2;
        else
            rax_10 = 4;
        
        arg4[1] = 1;
        
        if (rax_10 != 1)
        {
            if (rax_10 == 2)
            {
                r8 = "1#QNAN";
                goto label_1800279a4;
            }
            
            if (rax_10 == 3)
            {
                r8 = "1#SNAN";
                goto label_1800279a4;
            }
            
            if (rax_10 != 4)
                goto label_1800279ee;
            
            r8 = "1#IND";
            goto label_1800279a4;
        }
        
        if (sub_180020d70(arg5, arg6, "1#INF"))
            goto label_180028ab5;
        
        r15 = 0;
    }
    
    if (var_7b8)
        sub_18002b8c0(&var_7c0);
    
    __security_check_cookie(rax_1 ^ &var_828);
    return r15;
}

