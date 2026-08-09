
  int64_t sub_180011620(int64_t* arg1, int64_t arg2)

{
    void var_b8;
    int64_t rax_1 = __security_cookie ^ &var_b8;
    int64_t r8 = data_1800465b8;
    int64_t result;
    
    if (r8)
    {
        int64_t rax_3;
        int64_t rdx;
        rax_3 = (*(*arg1 + 0x2f8))(arg1, arg2, r8);
        
        if (rax_3)
        {
            void* rax_5 = (*(*arg1 + 0x548))(arg1, rax_3, 0);
            void* const rdx_2 = &data_1800321d8;
            
            if (rax_5)
                rdx_2 = rax_5;
            
            sub_1800023a0("login: B says name='%s'", rdx_2);
            int16_t var_7a_1 = 0;
            int64_t var_78_1 = 0xe;
            int64_t var_70_1 = 0xf;
            void* var_88;
            __builtin_strncpy(&var_88, "OfflinePlayer:", 0xf);
            void* rbx_1 = &data_180034db8;
            
            if (rax_5)
                rbx_1 = rax_5;
            
            int64_t* rax_7;
            int512_t zmm2_1;
            rax_7 = sub_1800026b0(&var_88, rbx_1, strlen(rbx_1));
            int128_t var_68;
            __builtin_memset(&var_68, 0, 0x14);
            int64_t var_50_1 = 0;
            var_68 = *rax_7;
            int32_t zmm1_1 = *(rax_7 + 0x10);
            rax_7[2] = 0;
            rax_7[3] = 0xf;
            *rax_7 = 0;
            
            if (var_70_1 > 0xf)
            {
                void* rcx_3 = var_88;
                
                if (var_70_1 + 1 >= 0x1000)
                {
                    void* rax_8 = *(rcx_3 - 8);
                    
                    if (rcx_3 - rax_8 - 8 > 0x1f)
                        trap(0xd);
                    
                    rcx_3 = rax_8;
                }
                
                j_sub_180021340(rcx_3);
            }
            
            int64_t var_78_2 = 0;
            int64_t var_70_2 = 0xf;
            var_88 = 0;
            
            if (rax_5)
                (*(*arg1 + 0x550))(arg1, rax_3, rax_5);
            
            int64_t rax_11 = (*(*arg1 + 0x580))(arg1, zmm1_1);
            int128_t* rcx_8 = &var_68;
            
            if (var_50_1 > 0xf)
                rcx_8 = var_68;
            
            (*(*arg1 + 0x680))(arg1, rax_11, 0, zmm1_1, rcx_8);
            data_180046600;
            int64_t rax_12 = sub_18000e9f0(arg1, data_1800465f8, zmm2_1, rax_11);
            int64_t r8_4 = *arg1;
            (*(r8_4 + 0xb8))(arg1, rax_11, r8_4);
            char rax_13;
            int64_t rdx_13;
            
            if (rax_12)
            {
                int64_t rdx_12 = *arg1;
                rax_13 = (*(rdx_12 + 0x720))(arg1, rdx_12);
            }
            
            if (!rax_12 || rax_13)
            {
                sub_180002210(arg1, "login: nameUUIDFromBytes", zmm2_1);
                result = (*(*arg1 + 0xb8))(arg1, rax_3);
            }
            else
            {
                int64_t rdx_14;
                int512_t zmm2_2;
                rdx_14 = sub_1800023a0("login: computed offline UUID", rdx_13);
                
                if (data_1800463c8)
                {
                    int64_t var_98_2 = rax_3;
                    int64_t rax_15 = sub_18000bbf0(arg1, data_1800463c0, zmm2_2, rax_12);
                    char rax_16;
                    int64_t rdx_18;
                    
                    if (rax_15)
                    {
                        int64_t rdx_17 = *arg1;
                        rax_16 = (*(rdx_17 + 0x720))(arg1, rdx_17);
                    }
                    
                    if (!rax_15 || rax_16)
                    {
                        sub_180002210(arg1, "login: GameProfile ctor", zmm2_2);
                        (*(*arg1 + 0xb8))(arg1, rax_12);
                        result = (*(*arg1 + 0xb8))(arg1, rax_3);
                    }
                    else if (data_1800465a8)
                    {
                        int64_t rax_17 = sub_18000bbf0(arg1, data_1800465a0, zmm2_2, rax_15);
                        int64_t r8_7 = *arg1;
                        (*(r8_7 + 0xb8))(arg1, rax_15, r8_7);
                        char rax_18;
                        
                        if (rax_17)
                        {
                            int64_t rdx_21 = *arg1;
                            rax_18 = (*(rdx_21 + 0x720))(arg1, rdx_21);
                        }
                        
                        if (!rax_17 || rax_18)
                            result = sub_180002210(arg1, "login: LoginFinished ctor", zmm2_2);
                        else
                        {
                            sub_180016110(arg1, rax_17, zmm2_2);
                            int512_t zmm2_3 = sub_1800023a0(
                                "login: sent ClientboundGameProfilePacket to B", 
                                (*(*arg1 + 0xb8))(arg1, rax_17));
                            void* var_48 = &data_180046688;
                            
                            if (sub_180017bf0(&data_180046688))
                            {
                                std::_Throw_Cpp_error(5);
                                /* no return */
                            }
                            
                            int32_t rax_21 = data_1800466d4;
                            
                            if (rax_21 == 0x7fffffff)
                            {
                                data_1800466d4 = rax_21 - 1;
                                std::_Throw_Cpp_error(6);
                                /* no return */
                            }
                            
                            int64_t rdx_25 = data_1800466d8;
                            int64_t r9_5;
                            
                            if (!rdx_25)
                                r9_5 = sub_180017c80(&data_180046688);
                            else
                            {
                                int64_t rax_24 = (*(*arg1 + 0xc8))(arg1, rdx_25);
                                r9_5 = sub_180017c80(&data_180046688);
                                
                                if (rax_24)
                                {
                                    int64_t rdx_28;
                                    rdx_28 = sub_1800023a0("login: protocol switched to PLAY", 
                                        sub_180015970(arg1, rax_24, data_1800462a0, r9_5, zmm2_3));
                                    
                                    if (data_1800466e5)
                                    {
                                        int64_t r9_6;
                                        int512_t zmm2_4;
                                        r9_6 = sub_1800023a0("login: mid-session ", rdx_28);
                                        zmm2_3 = sub_180014ae0(arg1, rax_24, zmm2_4, r9_6);
                                    }
                                    
                                    r9_5 = (*(*arg1 + 0xb8))(arg1, rax_24);
                                }
                            }
                            
                            if (data_1800465f0 && data_1800466d8)
                            {
                                int64_t rax_26;
                                rax_26 = sub_18000bbf0(arg1, data_1800465e8, zmm2_3, 1);
                                
                                if (rax_26)
                                {
                                    sub_180016110(arg1, rax_26, zmm2_3);
                                    int64_t r8_10 = *arg1;
                                    r9_5 = (*(r8_10 + 0xb8))(arg1, rax_26, r8_10);
                                }
                            }
                            
                            int64_t r9_7;
                            int512_t zmm2_5;
                            r9_7 = sub_1800154b0(arg1, rax_12, rax_3, r9_5, zmm2_3);
                            
                            if (sub_180015e20(arg1, rax_12, &var_48, r9_7, zmm2_5))
                            {
                                data_180046561 = var_48;
                                data_180046571 = 1;
                            }
                            
                            int64_t rdx_36 = data_1800464c0;
                            
                            if (rdx_36)
                                (*(*arg1 + 0xb0))(arg1, rdx_36);
                            
                            data_1800464c0 = (*(*arg1 + 0xa8))(arg1, rax_12);
                            int64_t rdx_38 = data_180046528;
                            
                            if (rdx_38)
                                (*(*arg1 + 0xb0))(arg1, rdx_38);
                            
                            data_180046528 = (*(*arg1 + 0xa8))(arg1, rax_3);
                            sub_180012ae0(arg1);
                            (*(*arg1 + 0xb8))(arg1, rax_12);
                            (*(*arg1 + 0xb8))(arg1, rax_3);
                            data_1800466e0 = 2;
                            
                            if (sub_180017bf0(&data_180046780))
                            {
                                std::_Throw_Cpp_error(5);
                                /* no return */
                            }
                            
                            int32_t rax_37 = data_1800467cc;
                            
                            if (rax_37 == 0x7fffffff)
                            {
                                data_1800467cc = rax_37 - 1;
                                std::_Throw_Cpp_error(6);
                                /* no return */
                            }
                            
                            data_180047518 = 1;
                            sub_180017c80(&data_180046780);
                            result = sub_1800023a0(
                                "login: B in PLAY (empty world); released A's Render thread ", 
                                sub_1800182b0(&data_1800474d0));
                        }
                    }
                    else
                        result = sub_1800023a0("login: no LoginFinished ctor", rdx_18);
                }
                else
                {
                    sub_1800023a0("login: no GameProfile ctor", rdx_14);
                    (*(*arg1 + 0xb8))(arg1, rax_12);
                    result = (*(*arg1 + 0xb8))(arg1, rax_3);
                }
            }
            
            if (var_50_1 > 0xf)
            {
                void* rcx_44 = var_68;
                
                if (var_50_1 + 1 >= 0x1000)
                {
                    void* rax_40 = *(rcx_44 - 8);
                    
                    if (rcx_44 - rax_40 - 8 > 0x1f)
                        trap(0xd);
                    
                    rcx_44 = rax_40;
                }
                
                result = j_sub_180021340(rcx_44);
            }
        }
        else
            result = sub_1800023a0("login: hello.name is null", rdx);
    }
    else
        result = sub_1800023a0("login: no hello.name field", arg2);
    
    __security_check_cookie(rax_1 ^ &var_b8);
    return result;
}

