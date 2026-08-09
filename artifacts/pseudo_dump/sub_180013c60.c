
  int64_t sub_180013c60(int64_t* arg1, int64_t arg2, int64_t arg3, int512_t arg4 @ zmm2)

{
    void var_a8;
    int64_t result = __security_cookie ^ &var_a8;
    int64_t result_1 = result;
    
    if (data_180046440 && data_180046448 && data_180046450 && data_1800463e8 && data_1800463f0
        && data_180046428 && data_180046430 && data_1800464b8 && data_1800464a8 && data_1800464b0
        && data_180046458 && data_180046470 && data_1800463f8 && data_180046408 && data_180046410
        && data_180046400 && data_180046560 && data_180046571 && data_1800464c0)
    {
        int64_t r9_1;
        result = (*(*arg1 + 0x100))(arg1, arg3);
        
        if (result)
        {
            data_180046430;
            int64_t rax_2 = sub_18000e9f0(arg1, data_180046428, arg4, r9_1);
            char rax_3;
            
            if (rax_2)
            {
                int64_t rdx_2 = *arg1;
                rax_3 = (*(rdx_2 + 0x720))(arg1, rdx_2);
            }
            
            if (!rax_2 || rax_3)
                result = (*(*arg1 + 0x88))(arg1);
            else
            {
                data_1800463f0;
                int64_t rax_4 = sub_18000bbf0(arg1, data_1800463e8, arg4, rax_2);
                int64_t r8_3 = *arg1;
                (*(r8_3 + 0xb8))(arg1, rax_2, r8_3);
                
                if (!rax_4)
                    result = (*(*arg1 + 0x88))(arg1);
                else
                {
                    int64_t rdx_5 = *arg1;
                    
                    if ((*(rdx_5 + 0x720))(arg1, rdx_5))
                        result = (*(*arg1 + 0x88))(arg1);
                    else
                    {
                        data_180046450;
                        sub_180001d00(arg1, arg3, arg4, rax_4);
                        
                        if (!(*(*arg1 + 0x720))(arg1))
                        {
                            data_1800464b8;
                            char rax_10 = sub_18000e960(arg1, rax_4, arg4, 0);
                            int64_t r8_6 = *arg1;
                            uint32_t rsi_2 = rax_10;
                            (*(r8_6 + 0xb8))(arg1, rax_4, r8_6);
                            int64_t rdx_10 = *arg1;
                            char rax_11;
                            int32_t rcx_11;
                            rax_11 = (*(rdx_10 + 0x720))(arg1, rdx_10);
                            
                            if (rax_11)
                                result = (*(*arg1 + 0x88))(arg1);
                            else
                            {
                                int32_t rax_13 = rsi_2 & 0x20;
                                int32_t rdx_12 = rsi_2 & 4;
                                int32_t r8_8 = rsi_2 & 8;
                                uint64_t r9_5 = rsi_2 & 0x10;
                                int32_t var_70_1 = r9_5;
                                int32_t rax_14 = r9_5;
                                int32_t rax_15 = -(rax_14);
                                data_180046458;
                                int32_t rax_19 = -(r8_8);
                                int32_t rax_21 = (rax_19 - rax_19) & 8;
                                int32_t rax_23 = -(rdx_12);
                                int64_t rax_26 = sub_180001cd0(arg1, arg3, arg4, r9_5);
                                int64_t rsi_3 = rax_26;
                                int64_t var_68_1 = rax_26;
                                char rax_28;
                                int64_t r9_6;
                                rax_28 = (*(*arg1 + 0x720))(arg1);
                                
                                if (rax_28)
                                {
                                    r9_6 = (*(*arg1 + 0x88))(arg1);
                                    rsi_3 = 0;
                                    var_68_1 = 0;
                                }
                                
                                int64_t r12_1;
                                
                                if (!data_180046460)
                                    r12_1 = 0;
                                else
                                    r12_1 = sub_180001cd0(arg1, arg3, arg4, r9_6);
                                
                                int64_t r9_7;
                                result = (*(*arg1 + 0x720))(arg1);
                                
                                if (result)
                                {
                                    result = (*(*arg1 + 0x88))(arg1);
                                    r12_1 = 0;
                                }
                                
                                int32_t rdi_2 = -1;
                                int32_t r15_1 = -1;
                                
                                if (rsi_3)
                                {
                                    data_1800464a8;
                                    int32_t rax_33 = sub_18000e990(arg1, rsi_3, arg4, r9_7);
                                    int64_t rdx_16 = *arg1;
                                    r15_1 = rax_33;
                                    result = (*(rdx_16 + 0x720))(arg1, rdx_16);
                                    
                                    if (result)
                                    {
                                        result = (*(*arg1 + 0x88))(arg1);
                                        r15_1 = -1;
                                    }
                                }
                                
                                if (r12_1)
                                {
                                    data_1800464a8;
                                    int32_t rax_35 = sub_18000e990(arg1, r12_1, arg4, r9_7);
                                    int64_t rdx_18 = *arg1;
                                    result = (*(rdx_18 + 0x720))(arg1, rdx_18);
                                    
                                    if (!result)
                                        rdi_2 = rax_35;
                                    else
                                        result = (*(*arg1 + 0x88))(arg1);
                                    
                                    rsi_3 = var_68_1;
                                }
                                
                                int64_t r13_1 = rsi_3;
                                
                                if (rdi_2 > r15_1)
                                    r13_1 = r12_1;
                                
                                if (rdi_2 > r15_1)
                                    r15_1 = rdi_2;
                                
                                int64_t i = 0;
                                int32_t r14_1 = 0;
                                
                                if (r15_1 > 0)
                                {
                                    while (!i)
                                    {
                                        data_1800464b0;
                                        int64_t rax_37 = sub_180001cd0(arg1, r13_1, arg4, r14_1);
                                        char rax_38;
                                        int64_t r9_9;
                                        
                                        if (rax_37)
                                        {
                                            int64_t rdx_20 = *arg1;
                                            rax_38 = (*(rdx_20 + 0x720))(arg1, rdx_20);
                                        }
                                        
                                        if (!rax_37 || rax_38)
                                        {
                                            result = (*(*arg1 + 0x88))(arg1);
                                            
                                            if (rax_37)
                                                result = (*(*arg1 + 0xb8))(arg1, rax_37);
                                            
                                            i = 0;
                                        }
                                        else
                                        {
                                            data_180046470;
                                            int64_t rax_39 =
                                                sub_180001cd0(arg1, rax_37, arg4, r9_9);
                                            char rax_40;
                                            int64_t r9_10;
                                            
                                            if (rax_39)
                                            {
                                                int64_t rdx_22 = *arg1;
                                                rax_40 = (*(rdx_22 + 0x720))(arg1, rdx_22);
                                            }
                                            
                                            void var_58;
                                            
                                            if (!rax_39 || rax_40)
                                            {
                                                if ((*(*arg1 + 0x720))(arg1))
                                                    (*(*arg1 + 0x88))(arg1);
                                                
                                                i = 0;
                                                result = (*(*arg1 + 0xb8))(arg1, rax_37);
                                            }
                                            else if (
                                                !sub_180015e20(arg1, rax_39, &var_58, r9_10, arg4))
                                            {
                                                i = 0;
                                                (*(*arg1 + 0xb8))(arg1, rax_39);
                                                result = (*(*arg1 + 0xb8))(arg1, rax_37);
                                            }
                                            else if (memcmp(&var_58, &data_180046550, 0x10))
                                            {
                                                (*(*arg1 + 0xb8))(arg1, rax_39);
                                                result = (*(*arg1 + 0xb8))(arg1, rax_37);
                                            }
                                            else
                                            {
                                                i = (*(*arg1 + 0xc8))(arg1, rax_37);
                                                (*(*arg1 + 0xb8))(arg1, rax_39);
                                                result = (*(*arg1 + 0xb8))(arg1, rax_37);
                                            }
                                        }
                                        
                                        r14_1 += 1;
                                        
                                        if (r14_1 >= r15_1)
                                            break;
                                    }
                                    
                                    rsi_3 = var_68_1;
                                }
                                
                                if (rsi_3)
                                    result = (*(*arg1 + 0xb8))(arg1, rsi_3);
                                
                                if (r12_1)
                                    result = (*(*arg1 + 0xb8))(arg1, r12_1);
                                
                                if (i)
                                {
                                    int32_t r14_5 = ((rcx_11 - rcx_11) & 0x20)
                                        | ((rax_15 - rax_15) & 0x10) | rax_21
                                        | ((rax_23 - rax_23) & 4);
                                    int64_t r9_11;
                                    int512_t zmm2;
                                    r9_11 = sub_180013830(arg1, arg2, arg4, r9_7, r14_5, rax_21, 
                                        rdx_12, var_70_1, var_68_1, arg2);
                                    
                                    if (r14_5)
                                    {
                                        data_180046430;
                                        int64_t rax_58 =
                                            sub_18000e9f0(arg1, data_180046428, zmm2, r9_11);
                                        
                                        if (!rax_58)
                                        {
                                        label_1800145f7:
                                            (*(*arg1 + 0x88))(arg1);
                                            result = (*(*arg1 + 0xb8))(arg1, i);
                                        }
                                        else
                                        {
                                            int64_t rdx_36 = *arg1;
                                            
                                            if ((*(rdx_36 + 0x720))(arg1, rdx_36))
                                                goto label_1800145f7;
                                            
                                            data_1800463f0;
                                            int64_t rax_60 =
                                                sub_18000bbf0(arg1, data_1800463e8, zmm2, rax_58);
                                            int64_t r8_18 = *arg1;
                                            (*(r8_18 + 0xb8))(arg1, rax_58, r8_18);
                                            
                                            if (!rax_60)
                                                goto label_1800145f7;
                                            
                                            int64_t rdx_39 = *arg1;
                                            
                                            if ((*(rdx_39 + 0x720))(arg1, rdx_39))
                                                goto label_1800145f7;
                                            
                                            data_1800463f8;
                                            sub_180001cd0(arg1, rax_60, zmm2, r14_5);
                                            data_180046408;
                                            sub_180001cd0(arg1, rax_60, zmm2, 1);
                                            data_180046410;
                                            int64_t r9_15 =
                                                sub_180001cd0(arg1, rax_60, zmm2, data_1800464c0);
                                            
                                            if (rdx_12 && data_180046478 && data_180046498)
                                            {
                                                int64_t rax_62 =
                                                    sub_180001cd0(arg1, i, zmm2, r9_15);
                                                int32_t r14_6 = 0;
                                                
                                                if (rax_62)
                                                {
                                                    int64_t rdx_44 = *arg1;
                                                    char rax_63;
                                                    int64_t r9_16;
                                                    rax_63 = (*(rdx_44 + 0x720))(arg1, rdx_44);
                                                    
                                                    if (!rax_63)
                                                    {
                                                        data_180046498;
                                                        r14_6 = sub_18000e990(arg1, rax_62, zmm2, 
                                                            r9_16);
                                                    }
                                                    
                                                    (*(*arg1 + 0xb8))(arg1, rax_62);
                                                }
                                                
                                                if ((*(*arg1 + 0x720))(arg1))
                                                    (*(*arg1 + 0x88))(arg1);
                                                
                                                data_180046408;
                                                r9_15 = sub_180001cd0(arg1, rax_60, zmm2, r14_6);
                                            }
                                            
                                            if (r8_8 && data_180046480)
                                            {
                                                char rax_69 = sub_18000e930(arg1, i, zmm2, r9_15);
                                                int64_t rdx_49 = *arg1;
                                                char rsi_8 = rax_69;
                                                
                                                if ((*(rdx_49 + 0x720))(arg1, rdx_49))
                                                {
                                                    (*(*arg1 + 0x88))(arg1);
                                                    rsi_8 = 1;
                                                }
                                                
                                                data_180046400;
                                                r9_15 = sub_180001cd0(arg1, rax_60, zmm2, rsi_8);
                                            }
                                            
                                            if (var_70_1 && data_180046488)
                                            {
                                                int32_t rsi_9 = sub_18000e990(arg1, i, zmm2, r9_15);
                                                
                                                if ((*(*arg1 + 0x720))(arg1))
                                                {
                                                    (*(*arg1 + 0x88))(arg1);
                                                    rsi_9 = 0;
                                                }
                                                
                                                data_180046408;
                                                r9_15 = sub_180001cd0(arg1, rax_60, zmm2, rsi_9);
                                            }
                                            
                                            if (rax_13)
                                            {
                                                int64_t rsi_10;
                                                
                                                if (!data_180046490)
                                                    rsi_10 = 0;
                                                else
                                                    rsi_10 = sub_180001cd0(arg1, i, zmm2, r9_15);
                                                
                                                if (!(*(*arg1 + 0x720))(arg1))
                                                {
                                                    if (!rsi_10 || !data_1800464a0)
                                                        goto label_18001449f;
                                                    
                                                    data_180046400;
                                                    sub_180001cd0(arg1, rax_60, zmm2, 1);
                                                    data_1800464a0;
                                                    sub_180001cd0(arg1, rax_60, zmm2, rsi_10);
                                                    (*(*arg1 + 0xb8))(arg1, rsi_10);
                                                }
                                                else
                                                {
                                                    (*(*arg1 + 0x88))(arg1);
                                                    rsi_10 = 0;
                                                label_18001449f:
                                                    data_180046400;
                                                    sub_180001cd0(arg1, rax_60, zmm2, 0);
                                                    
                                                    if (rsi_10)
                                                        (*(*arg1 + 0xb8))(arg1, rsi_10);
                                                }
                                                
                                                if ((*(*arg1 + 0x720))(arg1))
                                                    (*(*arg1 + 0x88))(arg1);
                                            }
                                            
                                            (*(*arg1 + 0xb8))(arg1, i);
                                            data_180046448;
                                            int64_t rax_85 =
                                                sub_18000bbf0(arg1, data_180046440, zmm2, rax_60);
                                            int64_t r8_32 = *arg1;
                                            (*(r8_32 + 0xb8))(arg1, rax_60, r8_32);
                                            char rax_86;
                                            
                                            if (rax_85)
                                                rax_86 = (*(*arg1 + 0x720))(arg1);
                                            
                                            if (!rax_85 || rax_86)
                                                result = sub_180002210(arg1, 
                                                    "mirror: single-entry ctor", zmm2);
                                            else
                                            {
                                                data_180046320;
                                                sub_180001cd0(arg1, arg2, zmm2, rax_85);
                                                
                                                if ((*(*arg1 + 0x720))(arg1))
                                                    sub_180002210(arg1, "mirror: writeAndFlush", 
                                                        zmm2);
                                                
                                                (*(*arg1 + 0xb8))(arg1, rax_85);
                                                result = sub_1800023a0(
                                                    "mirror: single-entry PlayerInfoUpdate to B (bits=0x"
                                                ")", 
                                                    r14_5);
                                            }
                                        }
                                    }
                                    else
                                        result = (*(*arg1 + 0xb8))(arg1, i);
                                }
                            }
                        }
                        else
                        {
                            (*(*arg1 + 0x88))(arg1);
                            result = (*(*arg1 + 0xb8))(arg1, rax_4);
                        }
                    }
                }
            }
        }
    }
    
    __security_check_cookie(result_1 ^ &var_a8);
    return result;
}

