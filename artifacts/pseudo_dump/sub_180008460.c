
  void* sub_180008460(int64_t* arg1, char* arg2, int64_t arg3)

{
    void var_e8;
    int64_t rax_1 = __security_cookie ^ &var_e8;
    void* var_b0;
    
    if (arg3 - arg2 < 0xa)
    {
        sub_180004ba0(&var_b0, "class_edit: too short");
        sub_180019520(&var_b0, &data_180045388);
        /* no return */
    }
    
    uint32_t rcx_5 = ((arg2[1] | *arg2 << 8) << 8 | arg2[2]) << 8 | arg2[3];
    arg1[3] = rcx_5;
    
    if (rcx_5 != 0xcafebabe)
    {
        sub_180004ba0(&var_b0, "class_edit: bad magic");
        sub_180019520(&var_b0, &data_180045388);
        /* no return */
    }
    
    *(arg1 + 0x1c) = arg2[5] | arg2[4] << 8;
    *(arg1 + 0x1e) = arg2[7] | arg2[6] << 8;
    uint16_t rdi = arg2[9];
    uint16_t rsi = arg2[8];
    char* rdx = arg1[1];
    void* rcx_8 = *arg1;
    
    if (rcx_8 != rdx)
    {
        sub_180006d00(rcx_8, rdx);
        rdx = *arg1;
        arg1[1] = rdx;
    }
    
    char var_90 = 0;
    int64_t var_78 = 0;
    char var_70 = 0;
    int64_t rax_10;
    int64_t rcx_9;
    
    if (rdx == arg1[2])
    {
        sub_180006f80(arg1, rdx, &var_90);
        rax_10 = var_78;
        rcx_9 = {0};
    }
    else
    {
        *rdx = 0;
        rax_10 = 0;
        rcx_9 = 0;
        __builtin_memset(&rdx[8], 0, 0x19);
        arg1[1] += 0x28;
    }
    
    if (!rcx_9)
        goto label_1800085ab;
    
    if (rax_10 - rcx_9 < 0x1000)
        goto label_18000859c;
    
    int64_t rdx_1 = *(rcx_9 - 8);
    
    if (rcx_9 - rdx_1 - 8 <= 0x1f)
    {
        rcx_9 = rdx_1;
    label_18000859c:
        j_sub_180021340(rcx_9);
    label_1800085ab:
        uint16_t rcx_13 = rdi | rsi << 8;
        char* rbx_1 = &arg2[0xa];
        int32_t var_c4_1 = 1;
        
        if (1 < rcx_13)
        {
            while (true)
            {
                uint32_t rsi_1 = *rbx_1;
                char var_68;
                void* rdi_3;
                
                if (rsi_1 - 1 <= 0x13)
                    switch (rsi_1)
                    {
                        case 1:
                        {
                            rdi_3 = (rbx_1[2] | rbx_1[1] << 8) + 2;
                        label_180008627:
                            int64_t var_88_1 = {0};
                            int64_t var_78_1 = 0;
                            char var_70_1 = 0;
                            var_90 = rsi_1;
                            
                            if (rdi_3 > 0x7fffffffffffffff)
                            {
                                sub_1800052a0();
                                /* no return */
                            }
                            
                            int64_t r15_2;
                            
                            if (rdi_3 < 0x1000)
                            {
                                r15_2 = sub_180016420(rdi_3);
                            label_180008685:
                                var_88_1 = r15_2;
                                void* rax_20 = rdi_3 + r15_2;
                                memcpy(r15_2, &rbx_1[1], rdi_3);
                                void* r8_3 = rdi_3 + r15_2;
                                *(&var_88_1 + 8) = r8_3;
                                bool rax_21 = rsi_1 - 5 <= 1;
                                char* rdx_4 = arg1[1];
                                int64_t rsi_2;
                                void* r13_1;
                                
                                if (rdx_4 == arg1[2])
                                {
                                    sub_180006f80(arg1, rdx_4, &var_90);
                                    r13_1 = rax_20;
                                    rsi_2 = var_88_1;
                                }
                                else
                                {
                                    *rdx_4 = rsi_1;
                                    r13_1 = nullptr;
                                    rsi_2 = 0;
                                    __builtin_memset(&var_88_1, 0, 0x18);
                                    *(rdx_4 + 8) = r15_2;
                                    *(rdx_4 + 0x10) = r8_3;
                                    *(rdx_4 + 0x18) = rax_20;
                                    rdx_4[0x20] = rax_21;
                                    arg1[1] += 0x28;
                                }
                                
                                int32_t r15_3;
                                
                                if (!rax_21)
                                {
                                    r15_3 = var_c4_1;
                                label_1800087a9:
                                    
                                    if (rsi_2)
                                    {
                                        if (r13_1 - rsi_2 >= 0x1000)
                                        {
                                            int64_t rax_24 = *(rsi_2 - 8);
                                            
                                            if (rsi_2 - rax_24 - 8 > 0x1f)
                                                goto label_180008eae;
                                            
                                            rsi_2 = rax_24;
                                        }
                                        
                                        j_sub_180021340(rsi_2);
                                    }
                                    
                                    rbx_1 = &rbx_1[1] + rdi_3;
                                    r15_3 += 1;
                                    var_c4_1 = r15_3;
                                    
                                    if (r15_3 >= rcx_13)
                                        break;
                                    
                                    continue;
                                }
                                else
                                {
                                    var_68 = 0;
                                    int64_t var_50_1 = 0;
                                    char var_48_1 = 0;
                                    char* rdx_5 = arg1[1];
                                    int64_t rax_22;
                                    int64_t rcx_22;
                                    
                                    if (rdx_5 == arg1[2])
                                    {
                                        sub_180006f80(arg1, rdx_5, &var_68);
                                        rax_22 = var_50_1;
                                        rcx_22 = {0};
                                    }
                                    else
                                    {
                                        *rdx_5 = 0;
                                        rax_22 = 0;
                                        rcx_22 = 0;
                                        __builtin_memset(&rdx_5[8], 0, 0x19);
                                        arg1[1] += 0x28;
                                    }
                                    
                                    if (!rcx_22)
                                    {
                                        r15_3 = var_c4_1 + 1;
                                        goto label_1800087a9;
                                    }
                                    
                                    if (rax_22 - rcx_22 < 0x1000)
                                        goto label_180008793;
                                    
                                    int64_t rdx_6 = *(rcx_22 - 8);
                                    
                                    if (rcx_22 - rdx_6 - 8 <= 0x1f)
                                    {
                                        rcx_22 = rdx_6;
                                    label_180008793:
                                        j_sub_180021340(rcx_22);
                                        r15_3 = var_c4_1 + 1;
                                        goto label_1800087a9;
                                    }
                                }
                            }
                            else
                            {
                                if (rdi_3 + 0x27 <= rdi_3)
                                {
                                    stdext::threads::_Throw_lock_error();
                                    /* no return */
                                }
                                
                                int64_t rax_17 = sub_180016420(rdi_3 + 0x27);
                                
                                if (rax_17)
                                {
                                    r15_2 = (rax_17 + 0x27) & 0xffffffffffffffe0;
                                    *(r15_2 - 8) = rax_17;
                                    goto label_180008685;
                                }
                            }
                            trap(0xd);
                            break;
                        }
                        case 3:
                        case 4:
                        case 9:
                        case 0xa:
                        case 0xb:
                        case 0xc:
                        case 0x11:
                        case 0x12:
                        {
                            rdi_3 = 4;
                            goto label_180008627;
                        }
                        case 5:
                        case 6:
                        {
                            rdi_3 = 8;
                            goto label_180008627;
                        }
                        case 7:
                        case 8:
                        case 0x10:
                        case 0x13:
                        case 0x14:
                        {
                            rdi_3 = 2;
                            goto label_180008627;
                        }
                        case 0xf:
                        {
                            rdi_3 = 3;
                            goto label_180008627;
                        }
                    }
                sub_1800076e0(&var_b0, 
                    sub_180006bd0(&var_90, "class_edit: unknown constant pool tag ", 
                        sub_18000aa20(&var_68, rsi_1)));
                sub_180019520(&var_b0, &data_180045388);
                /* no return */
            }
        }
        
        arg1[4] = rbx_1[1] | *rbx_1 << 8;
        *(arg1 + 0x22) = rbx_1[3] | rbx_1[2] << 8;
        *(arg1 + 0x24) = rbx_1[5] | rbx_1[4] << 8;
        uint16_t i = rbx_1[7] | rbx_1[6] << 8;
        int64_t* rdi_4 = &arg1[9];
        int64_t rsi_5 = *rdi_4;
        int64_t rax_29 = arg1[0xa];
        
        if (rsi_5 == rax_29)
            rsi_5 = rax_29;
        else
            arg1[0xa] = rsi_5;
        
        uint64_t i_5 = i;
        int64_t r12_1 = *rdi_4;
        
        if (i_5 <= (arg1[0xb] - r12_1) >> 1)
            goto label_180008901;
        
        uint64_t rcx_31 = i_5 * 2;
        int128_t* rdi_5;
        
        if (rcx_31)
        {
            if (rcx_31 < 0x1000)
            {
                rdi_5 = sub_180016420(rcx_31);
                goto label_1800088d3;
            }
            
            if (rcx_31 + 0x27 <= rcx_31)
            {
            label_180008f47:
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            int64_t rax_34 = sub_180016420(rcx_31 + 0x27);
            
            if (rax_34)
            {
                rdi_5 = (rax_34 + 0x27) & 0xffffffffffffffe0;
                *(rdi_5 - 8) = rax_34;
                goto label_1800088d3;
            }
        }
        else
        {
            rdi_5 = nullptr;
        label_1800088d3:
            int32_t* rdx_9 = arg1[9];
            memcpy(rdi_5, rdx_9, arg1[0xa] - rdx_9);
            rdi_4 = &arg1[9];
            sub_1800078c0(rdi_4, rdi_5, (rsi_5 - r12_1) >> 1, i_5);
        label_180008901:
            char* rbx_3 = &rbx_1[8];
            int32_t rdx_11 = 0;
            int32_t var_c4_2 = 0;
            
            if (0 < i)
            {
                do
                {
                    uint16_t r13_3 = rbx_3[1] | *rbx_3 << 8;
                    int64_t rcx_35 = arg1[0xb];
                    uint16_t* rsi_8 = arg1[0xa];
                    
                    if (rsi_8 == rcx_35)
                    {
                        int64_t rax_37 = *rdi_4;
                        void* r12_3 = rsi_8 - rax_37;
                        int64_t rdx_13 = r12_3 >> 1;
                        
                        if (rdx_13 == 0x7fffffffffffffff)
                        {
                            sub_1800052a0();
                            /* no return */
                        }
                        
                        int64_t rcx_37 = (rcx_35 - rax_37) >> 1;
                        uint64_t r8_10 = rcx_37 >> 1;
                        
                        if (rcx_37 > 0x7fffffffffffffff - r8_10)
                            goto label_180008f47;
                        
                        int64_t rax_39 = r8_10 + rcx_37;
                        int64_t r15_4 = rdx_13 + 1;
                        
                        if (rax_39 >= rdx_13 + 1)
                            r15_4 = rax_39;
                        
                        if (r15_4 > 0x7fffffffffffffff)
                            goto label_180008f47;
                        
                        uint64_t rcx_38 = r15_4 * 2;
                        int128_t* rdi_7;
                        
                        if (!rcx_38)
                            rdi_7 = nullptr;
                        else if (rcx_38 < 0x1000)
                            rdi_7 = sub_180016420(rcx_38);
                        else
                        {
                            if (rcx_38 + 0x27 <= rcx_38)
                                goto label_180008f47;
                            
                            int64_t rax_41 = sub_180016420(rcx_38 + 0x27);
                            
                            if (!rax_41)
                                goto label_180008eae;
                            
                            rdi_7 = (rax_41 + 0x27) & 0xffffffffffffffe0;
                            *(rdi_7 - 8) = rax_41;
                        }
                        
                        uint16_t* r12_4 = r12_3 & 0xfffffffffffffffe;
                        *(r12_4 + rdi_7) = r13_3;
                        int64_t r8_11 = arg1[0xa];
                        uint16_t* rdx_15 = arg1[9];
                        int128_t* rcx_40 = rdi_7;
                        void* r8_12;
                        
                        if (rsi_8 != r8_11)
                        {
                            memcpy(rcx_40, rdx_15, rsi_8 - rdx_15);
                            rcx_40 = rdi_7 + 2 + r12_4;
                            r8_12 = arg1[0xa] - rsi_8;
                            rdx_15 = rsi_8;
                        }
                        else
                            r8_12 = r8_11 - rdx_15;
                        
                        memcpy(rcx_40, rdx_15, r8_12);
                        rdi_4 = &arg1[9];
                        sub_1800078c0(rdi_4, rdi_7, rdx_13 + 1, r15_4);
                        rdx_11 = var_c4_2;
                    }
                    else
                    {
                        *rsi_8 = r13_3;
                        arg1[0xa] += 2;
                    }
                    
                    rbx_3 = &rbx_3[2];
                    rdx_11 += 1;
                    var_c4_2 = rdx_11;
                } while (rdx_11 < i);
            }
            
            uint64_t rax_43 = *(arg1 + 0x22);
            
            if (!rax_43)
                goto label_180008b67;
            
            uint64_t rax_44 = rax_43 * 5;
            int64_t rcx_43 = *arg1;
            
            if (*(rcx_43 + (rax_44 << 3)) != 7)
                goto label_180008b67;
            
            char* rax_45 = *(rcx_43 + (rax_44 << 3) + 8);
            int128_t* rax_46 = sub_180008240(arg1, &var_b0, *rax_45 << 8 | rax_45[1]);
            
            if (&arg1[5] == rax_46)
                goto label_180008b21;
            
            int64_t rax_47 = arg1[8];
            
            if (rax_47 <= 0xf)
                goto label_180008ae9;
            
            void* rcx_46 = arg1[5];
            void* r8_18;
            
            if (rax_47 + 1 < 0x1000)
            {
                r8_18 = rcx_46;
            label_180008ae4:
                j_sub_180021340(r8_18);
            label_180008ae9:
                arg1[7] = 0;
                arg1[8] = 0xf;
                arg1[5] = 0;
                *(arg1 + 0x28) = *rax_46;
                *(arg1 + 0x38) = rax_46[1];
                rax_46[1] = 0;
                *(rax_46 + 0x18) = 0xf;
                *rax_46 = 0;
            label_180008b21:
                int64_t var_98;
                
                if (var_98 <= 0xf)
                    goto label_180008b67;
                
                void* rcx_50 = var_b0;
                
                if (var_98 + 1 < 0x1000)
                    goto label_180008b53;
                
                void* rax_48 = *(rcx_50 - 8);
                
                if (rcx_50 - rax_48 - 8 <= 0x1f)
                {
                    rcx_50 = rax_48;
                label_180008b53:
                    j_sub_180021340(rcx_50);
                label_180008b67:
                    uint16_t i_4 = rbx_3[1] | *rbx_3 << 8;
                    char* rbx_4 = &rbx_3[2];
                    
                    if (0 < i_4)
                    {
                        uint16_t i_1;
                        
                        do
                        {
                            uint16_t j_1 = rbx_4[7] | rbx_4[6] << 8;
                            rbx_4 = &rbx_4[8];
                            
                            if (0 < j_1)
                            {
                                uint16_t j;
                                
                                do
                                {
                                    rbx_4 = &rbx_4[6 + (
                                        ((rbx_4[2] << 8 | rbx_4[3]) << 8 | rbx_4[4]) << 8
                                        | rbx_4[5])];
                                    j = j_1;
                                    j_1 -= 1;
                                } while (j != 1);
                            }
                            
                            i_1 = i_4;
                            i_4 -= 1;
                        } while (i_1 != 1);
                    }
                    
                    sub_180007480(&arg1[0xc], rbx_3, rbx_4);
                    uint16_t rdi_10 = rbx_4[1] | *rbx_4 << 8;
                    uint16_t var_c8_3 = rdi_10;
                    int64_t* r13_4 = &arg1[0x12];
                    void* rcx_61 = *r13_4;
                    int64_t rsi_10 = arg1[0x13];
                    
                    if (rcx_61 != rsi_10)
                    {
                        sub_180003f30(rcx_61, rsi_10);
                        rsi_10 = *r13_4;
                        arg1[0x13] = rsi_10;
                    }
                    
                    uint64_t r15_5 = rdi_10;
                    int64_t r12_5 = *r13_4;
                    
                    if (r15_5 <= (arg1[0x14] - r12_5) >> 5)
                        goto label_180008cc1;
                    
                    uint64_t rcx_63 = r15_5 << 5;
                    int16_t* rdi_11;
                    
                    if (!rcx_63)
                    {
                        rdi_11 = nullptr;
                    label_180008ca0:
                        sub_180004820(*r13_4, arg1[0x13], rdi_11);
                        sub_180007940(r13_4, rdi_11, (rsi_10 - r12_5) >> 5, r15_5);
                        rdi_10 = var_c8_3;
                    label_180008cc1:
                        char* rbx_6 = &rbx_4[2];
                        
                        if (0 < rdi_10)
                        {
                            int16_t r12_6 = 0;
                            
                            do
                            {
                                int64_t var_a8_1 = {0};
                                void* var_98_1 = nullptr;
                                var_b0 = rbx_6[1] | *rbx_6 << 8;
                                *(&var_b0 + 2) = rbx_6[3] | rbx_6[2] << 8;
                                char* r15_6 = &rbx_6[6];
                                *(&var_b0 + 4) = rbx_6[5] | rbx_6[4] << 8;
                                uint16_t i_3 = rbx_6[7] | *r15_6 << 8;
                                rbx_6 = &rbx_6[8];
                                
                                if (0 < i_3)
                                {
                                    uint16_t i_2;
                                    
                                    do
                                    {
                                        rbx_6 = &rbx_6[6 + (
                                            ((rbx_6[2] << 8 | rbx_6[3]) << 8 | rbx_6[4]) << 8
                                            | rbx_6[5])];
                                        i_2 = i_3;
                                        i_3 -= 1;
                                    } while (i_2 != 1);
                                    r13_4 = &arg1[0x12];
                                }
                                
                                void* rdi_14 = rbx_6 - r15_6;
                                
                                if (rbx_6 == r15_6)
                                {
                                    memcpy(nullptr, r15_6, rdi_14);
                                    *(&var_a8_1 + 8) = rdi_14;
                                }
                                else
                                {
                                    if (rdi_14 > 0x7fffffffffffffff)
                                    {
                                        sub_1800052a0();
                                        /* no return */
                                    }
                                    
                                    int128_t* rsi_14;
                                    
                                    if (rdi_14 < 0x1000)
                                        rsi_14 = sub_180016420(rdi_14);
                                    else
                                    {
                                        if (rdi_14 + 0x27 <= rdi_14)
                                        {
                                            stdext::threads::_Throw_lock_error();
                                            /* no return */
                                        }
                                        
                                        int64_t rax_68 = sub_180016420(rdi_14 + 0x27);
                                        
                                        if (!rax_68)
                                            trap(0xd);
                                        
                                        rsi_14 = (rax_68 + 0x27) & 0xffffffffffffffe0;
                                        *(rsi_14 - 8) = rax_68;
                                    }
                                    
                                    var_a8_1 = rsi_14;
                                    var_98_1 = rsi_14 + rdi_14;
                                    memcpy(rsi_14, r15_6, rdi_14);
                                    *(&var_a8_1 + 8) = rdi_14 + rsi_14;
                                }
                                
                                sub_180006d90(r13_4, &var_b0);
                                int64_t rcx_82 = var_a8_1;
                                
                                if (rcx_82)
                                {
                                    if (var_98_1 - rcx_82 >= 0x1000)
                                    {
                                        int64_t rax_72 = *(rcx_82 - 8);
                                        
                                        if (rcx_82 - rax_72 - 8 > 0x1f)
                                            goto label_180008eae;
                                        
                                        rcx_82 = rax_72;
                                    }
                                    
                                    j_sub_180021340(rcx_82);
                                }
                                
                                r12_6 += 1;
                            } while (r12_6 < var_c8_3);
                        }
                        
                        void* result = sub_180007480(&arg1[0xf], rbx_6, arg3);
                        __security_check_cookie(rax_1 ^ &var_e8);
                        return result;
                    }
                    
                    if (rcx_63 < 0x1000)
                    {
                        rdi_11 = sub_180016420(rcx_63);
                        goto label_180008ca0;
                    }
                    
                    if (rcx_63 + 0x27 <= rcx_63)
                        goto label_180008f47;
                    
                    int64_t rax_59 = sub_180016420(rcx_63 + 0x27);
                    
                    if (rax_59)
                    {
                        rdi_11 = (rax_59 + 0x27) & 0xffffffffffffffe0;
                        *(rdi_11 - 8) = rax_59;
                        goto label_180008ca0;
                    }
                }
            }
            else
            {
                r8_18 = *(rcx_46 - 8);
                
                if (rcx_46 - r8_18 - 8 <= 0x1f)
                    goto label_180008ae4;
            }
        }
    }
    
label_180008eae:
    trap(0xd);
}

