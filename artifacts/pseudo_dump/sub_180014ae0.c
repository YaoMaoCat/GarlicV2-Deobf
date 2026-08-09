
  int64_t sub_180014ae0(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2, int64_t arg4)

{
    int64_t arg_10 = arg2;
    
    if (data_180046760)
    {
        arg2 = data_1800463d0;
        
        if (arg2 && data_1800463d8 && data_1800466e8 && data_180046700 && data_180046708
            && data_180046710 && data_180046728 && data_180046720 && data_180046730
            && data_180046740 && data_180046750 && data_180046768 && data_180046770)
        {
            int64_t rax = sub_18000e9f0(arg1, arg2, arg3, arg4);
            
            if (rax)
            {
                int64_t rdx = *arg1;
                char rax_1;
                int64_t r9;
                rax_1 = (*(rdx + 0x720))(arg1, rdx);
                
                if (!rax_1)
                {
                    data_1800466e8;
                    int64_t rax_2 = sub_180001cd0(arg1, rax, arg3, r9);
                    
                    if (rax_2)
                    {
                        int64_t rdx_2 = *arg1;
                        char rax_3;
                        int64_t r9_1;
                        rax_3 = (*(rdx_2 + 0x720))(arg1, rdx_2);
                        
                        if (!rax_3)
                        {
                            data_180046700;
                            int64_t rax_4 = sub_180001cd0(arg1, rax_2, arg3, r9_1);
                            int64_t r13_1 = rax_4;
                            char rax_5;
                            int64_t r9_2;
                            
                            if (rax_4)
                            {
                                int64_t rdx_4 = *arg1;
                                rax_5 = (*(rdx_4 + 0x720))(arg1, rdx_4);
                            }
                            
                            int64_t arg_18;
                            int64_t r15_1;
                            int64_t rdi_1;
                            
                            if (!rax_4 || rax_5)
                            {
                                rdi_1 = 0;
                                (*(*arg1 + 0xb8))(arg1, rax_2);
                            label_180014cd2:
                                r15_1 = 0;
                                arg_18 = 0;
                                
                                if (rdi_1)
                                    (*(*arg1 + 0xb8))(arg1, rdi_1);
                            }
                            else
                            {
                                data_180046708;
                                rdi_1 = sub_180001cd0(arg1, rax_2, arg3, r9_2);
                                (*(*arg1 + 0xb8))(arg1, rax_2);
                                
                                if (!rdi_1)
                                    goto label_180014cd2;
                                
                                char rax_9;
                                int64_t r9_3;
                                rax_9 = (*(*arg1 + 0x720))(arg1);
                                
                                if (rax_9)
                                    goto label_180014cd2;
                                
                                data_180046710;
                                int64_t rax_10 = sub_180001cd0(arg1, rdi_1, arg3, r9_3);
                                r15_1 = rax_10;
                                arg_18 = rax_10;
                                (*(*arg1 + 0xb8))(arg1, rdi_1);
                            }
                            
                            if (r13_1 && r15_1 && !(*(*arg1 + 0x720))(arg1))
                            {
                                int64_t rax_16 = (*(*arg1 + 0x2f8))(arg1, rax, data_180046720);
                                char rax_17;
                                int64_t r9_4;
                                
                                if (rax_16)
                                {
                                    int64_t rdx_11 = *arg1;
                                    rax_17 = (*(rdx_11 + 0x720))(arg1, rdx_11);
                                }
                                
                                int64_t arg_20;
                                
                                if (!rax_16 || rax_17)
                                {
                                    arg_20 = 0;
                                    
                                    if (rax_16)
                                        (*(*arg1 + 0xb8))(arg1, rax_16);
                                }
                                else
                                {
                                    data_180046730;
                                    arg_20 = sub_180001cd0(arg1, rax_16, arg3, r9_4);
                                    (*(*arg1 + 0xb8))(arg1, rax_16);
                                }
                                
                                if ((*(*arg1 + 0x720))(arg1))
                                    (*(*arg1 + 0x88))(arg1);
                                
                                int64_t rax_24 = (*(*arg1 + 0x2f8))(arg1, rax, data_180046728);
                                int64_t r8_9 = *arg1;
                                int64_t rdi_3 = rax_24;
                                int64_t r9_5 = (*(r8_9 + 0xb8))(arg1, rax, r8_9);
                                int64_t r14_1 = 0;
                                int64_t rbp_1 = 0;
                                
                                if (rdi_3)
                                {
                                    int64_t rdx_16 = *arg1;
                                    char rax_25;
                                    int64_t r9_6;
                                    rax_25 = (*(rdx_16 + 0x720))(arg1, rdx_16);
                                    
                                    if (!rax_25)
                                    {
                                        int32_t r15_2 = 0;
                                        int64_t var_48 = data_180046740;
                                        int64_t var_40_1 = data_180046748;
                                        
                                        while ((&var_48)[r15_2])
                                        {
                                            int64_t rax_29 = sub_180001cd0(arg1, rdi_3, arg3, r9_6);
                                            char rax_30;
                                            int64_t r9_7;
                                            
                                            if (rax_29)
                                            {
                                                int64_t rdx_18 = *arg1;
                                                rax_30 = (*(rdx_18 + 0x720))(arg1, rdx_18);
                                            }
                                            
                                            if (!rax_29 || rax_30)
                                            {
                                                r9_6 = (*(*arg1 + 0x88))(arg1);
                                                
                                                if (rax_29)
                                                    r9_6 = (*(*arg1 + 0xb8))(arg1, rax_29);
                                            }
                                            else
                                            {
                                                data_180046750;
                                                int64_t rax_31 =
                                                    sub_180001cd0(arg1, rax_29, arg3, r9_7);
                                                char rax_32;
                                                
                                                if (rax_31)
                                                {
                                                    int64_t rdx_20 = *arg1;
                                                    rax_32 = (*(rdx_20 + 0x720))(arg1, rdx_20);
                                                }
                                                
                                                if (!rax_31 || rax_32)
                                                {
                                                    char rax_38;
                                                    rax_38 = (*(*arg1 + 0x720))(arg1);
                                                    
                                                    if (rax_38)
                                                        r9_6 = (*(*arg1 + 0x88))(arg1);
                                                    
                                                    goto label_180014f25;
                                                }
                                                
                                                int64_t r9_8 = *arg1;
                                                r13_1 = 0;
                                                uint128_t* rax_33 =
                                                    (*(r9_8 + 0x548))(arg1, rax_31, 0, r9_8);
                                                
                                                if (rax_33)
                                                {
                                                    uint128_t* rax_34;
                                                    rax_34 =
                                                        sub_1800195d0(rax_33, "dimension_type");
                                                    int64_t r9_9 = *arg1;
                                                    r13_1 = rax_34;
                                                    (*(r9_9 + 0x550))(arg1, rax_31, rax_33, r9_9);
                                                }
                                                
                                                r9_6 = (*(*arg1 + 0xb8))(arg1, rax_31);
                                                
                                                if (!r13_1)
                                                {
                                                label_180014f25:
                                                    
                                                    if (r14_1)
                                                        r9_6 = (*(*arg1 + 0xb8))(arg1, r14_1);
                                                    
                                                    r14_1 = rax_29;
                                                }
                                                else
                                                {
                                                    if (rbp_1)
                                                        r9_6 = (*(*arg1 + 0xb8))(arg1, rbp_1);
                                                    
                                                    rbp_1 = rax_29;
                                                }
                                            }
                                            
                                            rdi_3 = rax_24;
                                            r15_2 += 1;
                                            
                                            if (r15_2 >= 2)
                                                break;
                                        }
                                        
                                        r15_1 = arg_18;
                                        r13_1 = rax_4;
                                    }
                                    
                                    r9_5 = (*(*arg1 + 0xb8))(arg1, rdi_3);
                                }
                                
                                if (!arg_20 || !r14_1 || !rbp_1)
                                {
                                    sub_1800023a0(
                                        "mid-login: incomplete (gameType=%p dim=%p dimType=%p), abort", 
                                        arg_20);
                                    (*(*arg1 + 0xb8))(arg1, r13_1);
                                    (*(*arg1 + 0xb8))(arg1, r15_1);
                                    
                                    if (arg_20)
                                        (*(*arg1 + 0xb8))(arg1, arg_20);
                                    
                                    if (r14_1)
                                        (*(*arg1 + 0xb8))(arg1, r14_1);
                                    
                                    if (rbp_1)
                                        (*(*arg1 + 0xb8))(arg1, rbp_1);
                                }
                                else
                                {
                                    data_180046770;
                                    int64_t rax_44 =
                                        sub_18000e9f0(arg1, data_180046768, arg3, r9_5);
                                    char rax_45;
                                    
                                    if (rax_44)
                                    {
                                        int64_t rdx_29 = *arg1;
                                        rax_45 = (*(rdx_29 + 0x720))(arg1, rdx_29);
                                    }
                                    
                                    if (!rax_44 || rax_45)
                                    {
                                        sub_1800023a0("mid-login: Optional.empty() failed, abort", 
                                            (*(*arg1 + 0x88))(arg1));
                                        
                                        if (rax_44)
                                            (*(*arg1 + 0xb8))(arg1, rax_44);
                                        
                                        (*(*arg1 + 0xb8))(arg1, r13_1);
                                        (*(*arg1 + 0xb8))(arg1, r15_1);
                                        (*(*arg1 + 0xb8))(arg1, arg_20);
                                        (*(*arg1 + 0xb8))(arg1, r14_1);
                                        (*(*arg1 + 0xb8))(arg1, rbp_1);
                                    }
                                    else
                                    {
                                        data_180046760;
                                        int64_t var_68_1 = 0;
                                        int64_t var_70_1 = rax_44;
                                        int64_t var_78_1 = 0;
                                        int64_t var_80_1 = 0;
                                        int32_t var_88_1 = 1;
                                        int64_t var_90_1 = 0;
                                        int32_t var_98_1 = 0x10;
                                        int32_t var_a0_1 = 0x10;
                                        int32_t var_a8_1 = 0x14;
                                        int64_t var_b0_1 = 0;
                                        int64_t var_b8_1 = r14_1;
                                        int64_t var_c0_1 = rbp_1;
                                        int64_t var_c8_1 = r15_1;
                                        int64_t var_d0_1 = r13_1;
                                        int64_t var_d8_1 = 0;
                                        int64_t var_e0_1 = arg_20;
                                        int64_t var_e8_1 = 0;
                                        int64_t rax_46 =
                                            sub_18000bbf0(arg1, data_180046758, arg3, 0x77359400);
                                        int64_t r8_15 = *arg1;
                                        (*(r8_15 + 0xb8))(arg1, r13_1, r8_15);
                                        int64_t r8_16 = *arg1;
                                        (*(r8_16 + 0xb8))(arg1, r15_1, r8_16);
                                        int64_t r8_17 = *arg1;
                                        (*(r8_17 + 0xb8))(arg1, arg_20, r8_17);
                                        int64_t r8_18 = *arg1;
                                        (*(r8_18 + 0xb8))(arg1, r14_1, r8_18);
                                        (*(*arg1 + 0xb8))(arg1, rbp_1);
                                        (*(*arg1 + 0xb8))(arg1, rax_44);
                                        char rax_50;
                                        
                                        if (rax_46)
                                            rax_50 = (*(*arg1 + 0x720))(arg1);
                                        
                                        if (!rax_46 || rax_50)
                                            sub_180002210(arg1, "mid-login: ctor", arg3);
                                        else
                                        {
                                            data_180046320;
                                            sub_180001cd0(arg1, arg_10, arg3, rax_46);
                                            
                                            if (!(*(*arg1 + 0x720))(arg1))
                                            {
                                                int64_t r9_11;
                                                int512_t zmm2;
                                                r9_11 = sub_1800023a0(
                                                    "mid-login: rebuilt ClientboundLoginPacket sent to B", 
                                                    (*(*arg1 + 0xb8))(arg1, rax_46));
                                                
                                                if (data_1800465d0 && data_1800465e0)
                                                {
                                                    int64_t rdx_41 = data_1800465d8;
                                                    
                                                    if (rdx_41)
                                                    {
                                                        int64_t rax_56 = sub_18000e9f0(arg1, 
                                                            rdx_41, zmm2, r9_11);
                                                        
                                                        if (rax_56)
                                                        {
                                                            int64_t rdx_42 = *arg1;
                                                            
                                                            if (!(*(rdx_42 + 0x720))(arg1, rdx_42))
                                                            {
                                                                data_1800465d0;
                                                                int64_t rdx_43 = data_1800465c8;
                                                                int64_t var_c0_2 = 0;
                                                                int64_t var_c8_2 = rax_56;
                                                                int64_t var_e0_2;
                                                                __builtin_memset(&var_e0_2, 0, 0x18);
                                                                int64_t var_e8_2 = 0x4059000000000000;
                                                                int64_t rax_58 =
                                                                    sub_18000bbf0(arg1, rdx_43, zmm2, 0);
                                                                
                                                                if (rax_58)
                                                                {
                                                                    int64_t rdx_44 = *arg1;
                                                                    
                                                                    if (!(*(rdx_44 + 0x720))(arg1, rdx_44))
                                                                    {
                                                                        data_180046320;
                                                                        sub_180001cd0(arg1, arg_10, zmm2, 
                                                                            rax_58);
                                                                        
                                                                        if ((*(*arg1 + 0x720))(arg1))
                                                                            (*(*arg1 + 0x88))(arg1);
                                                                        
                                                                        sub_1800023a0(
                                                                            "mid-login: sent placeholder spawn "
                                                                        "position to B", 
                                                                            (*(*arg1 + 0xb8))(arg1, rax_58));
                                                                        (*(*arg1 + 0xb8))(arg1, rax_56);
                                                                        return 1;
                                                                    }
                                                                }
                                                                
                                                                if ((*(*arg1 + 0x720))(arg1))
                                                                    (*(*arg1 + 0x88))(arg1);
                                                                
                                                                (*(*arg1 + 0xb8))(arg1, rax_56);
                                                                return 1;
                                                            }
                                                        }
                                                        
                                                        if ((*(*arg1 + 0x720))(arg1))
                                                            (*(*arg1 + 0x88))(arg1);
                                                    }
                                                }
                                                
                                                return 1;
                                            }
                                            
                                            sub_180002210(arg1, "mid-login: writeAndFlush", arg3);
                                            (*(*arg1 + 0xb8))(arg1, rax_46);
                                        }
                                    }
                                }
                                
                                return 0;
                            }
                            
                            sub_1800023a0("mid-login: levels/registry unavailable", 
                                (*(*arg1 + 0x88))(arg1));
                            
                            if (r13_1)
                                (*(*arg1 + 0xb8))(arg1, r13_1);
                            
                            if (r15_1)
                                (*(*arg1 + 0xb8))(arg1, r15_1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax);
                            return 0;
                        }
                    }
                    
                    (*(*arg1 + 0x88))(arg1);
                    (*(*arg1 + 0xb8))(arg1, rax);
                    return 0;
                }
            }
            
            (*(*arg1 + 0x88))(arg1);
            int64_t rax_88;
            rax_88 = 0;
            return rax_88;
        }
    }
    
    sub_1800023a0("mid-login: refs missing, cannot rebuild login", arg2);
    int64_t rax_89;
    rax_89 = 0;
    return rax_89;
}

