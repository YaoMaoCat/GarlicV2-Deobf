
  uint64_t sub_18000e4f0(int64_t* arg1, int64_t arg2, int64_t arg3)

{
    void var_68;
    int64_t rax_1 = __security_cookie ^ &var_68;
    int128_t var_40;
    sub_180011120(&var_40, arg1, arg3);
    data_1800466e0;
    int128_t* rdx_1 = &var_40;
    int64_t var_28;
    
    if (var_28 > 0xf)
        rdx_1 = var_40;
    
    int512_t zmm2 = sub_1800023a0("BServer: RX %s (state=%d)", rdx_1);
    int64_t r8_1 = data_1800465c0;
    char rax_3;
    
    if (r8_1)
        rax_3 = (*(*arg1 + 0x100))(arg1, arg3, r8_1);
    
    uint64_t result;
    
    if (!r8_1 || !rax_3)
    {
        int64_t r8_6 = data_1800462e8;
        
        if (r8_6)
            result = (*(*arg1 + 0x100))(arg1, arg3, r8_6);
        
        if (!r8_6 || !result)
        {
            int64_t r8_10 = data_1800465b0;
            char rax_17;
            
            if (r8_10)
                rax_17 = (*(*arg1 + 0x100))(arg1, arg3, r8_10);
            
            if (!r8_10 || !rax_17)
            {
                result = data_1800466e0;
                
                if (result == 2)
                {
                    result = strlen("net.minecraft.network.protocol.game.");
                    int128_t* rbp_2 = &var_40;
                    
                    if (var_28 > 0xf)
                        rbp_2 = var_40;
                    
                    int64_t var_30;
                    
                    if (!result)
                    {
                    label_18000e7bf:
                        int128_t* rcx_16 = &var_40;
                        
                        if (var_28 > 0xf)
                            rcx_16 = var_40;
                        
                        result = strcmp(rcx_16 + 0x24, "ServerboundCustomPayloadPacket");
                        
                        if (result)
                        {
                            void* var_48_2 = &data_180046630;
                            
                            if (sub_180017bf0(&data_180046630))
                            {
                                std::_Throw_Cpp_error(5);
                                /* no return */
                            }
                            
                            int32_t rax_19 = data_18004667c;
                            
                            if (rax_19 == 0x7fffffff)
                            {
                                data_18004667c = rax_19 - 1;
                                std::_Throw_Cpp_error(6);
                                /* no return */
                            }
                            
                            int64_t rdx_19 = data_180046680;
                            
                            if (!rdx_19)
                                result = sub_180017c80(&data_180046630);
                            else
                            {
                                int64_t rax_21 = (*(*arg1 + 0xc8))(arg1, rdx_19);
                                result = sub_180017c80(&data_180046630);
                                
                                if (rax_21)
                                {
                                    if (data_180046280)
                                    {
                                        int512_t zmm2_1 = sub_18000bc20(arg1, arg3);
                                        data_180046280;
                                        sub_180001d00(arg1, rax_21, zmm2_1, arg3);
                                        
                                        if ((*(*arg1 + 0x720))(arg1))
                                            sub_180002210(arg1, "routeToA", zmm2_1);
                                        
                                        result = (*(*arg1 + 0xb8))(arg1, rax_21);
                                    }
                                    else
                                    {
                                        int64_t r8_11 = *arg1;
                                        result = (*(r8_11 + 0xb8))(arg1, rax_21, r8_11);
                                    }
                                }
                            }
                        }
                    }
                    else if (result <= var_30)
                    {
                        uint32_t (* rbx_4)[0x8] = result + rbp_2;
                        result = j_sub_180017670(rbp_2, rbx_4, 
                            "net.minecraft.network.protocol.game.", result);
                        
                        if (result != rbx_4)
                        {
                            uint64_t result_2 = result;
                            result -= rbp_2;
                            
                            if (result_2 == rbp_2)
                                goto label_18000e7bf;
                        }
                    }
                }
            }
            else
                result = sub_180011620(arg1, arg3);
        }
        else
        {
            uint64_t result_1 = 0;
            int64_t r8_7 = data_1800462f0;
            
            if (r8_7)
            {
                result = (*(*arg1 + 0x328))(arg1, arg3, r8_7);
                result_1 = result;
            }
            
            if (data_1800462d8)
            {
                int64_t rax_15 = sub_18000bbf0(arg1, data_1800462d0, zmm2, result_1);
                
                if (rax_15)
                {
                    sub_180016110(arg1, rax_15, zmm2);
                    int64_t r8_9 = *arg1;
                    (*(r8_9 + 0xb8))(arg1, rax_15, r8_9);
                }
                
                result = sub_1800023a0("BServer: replied Pong(%lld)", result_1);
            }
        }
    }
    else
    {
        int64_t rbp_1 = data_180046298;
        int64_t r8_2 = data_1800462f8;
        
        if (r8_2)
        {
            int64_t rax_5 = (*(*arg1 + 0x2f8))(arg1, arg3, r8_2);
            
            if (rax_5)
            {
                int64_t r9_1 = *arg1;
                char rax_6 = (*(r9_1 + 0xc0))(arg1, rax_5, data_1800462a8, r9_1);
                rbp_1 = data_180046298;
                
                if (rax_6)
                    rbp_1 = data_1800462a8;
                
                (*(*arg1 + 0xb8))(arg1, rax_5);
            }
        }
        
        void* var_48_1 = &data_180046688;
        
        if (sub_180017bf0(&data_180046688))
        {
            std::_Throw_Cpp_error(5);
            /* no return */
        }
        
        int32_t rax_9 = data_1800466d4;
        
        if (rax_9 == 0x7fffffff)
        {
            data_1800466d4 = rax_9 - 1;
            std::_Throw_Cpp_error(6);
            /* no return */
        }
        
        int64_t rdx_6 = data_1800466d8;
        
        if (!rdx_6)
            sub_180017c80(&data_180046688);
        else
        {
            int64_t rax_12 = (*(*arg1 + 0xc8))(arg1, rdx_6);
            int64_t r9_2 = sub_180017c80(&data_180046688);
            
            if (rax_12)
            {
                sub_180015970(arg1, rax_12, rbp_1, r9_2, zmm2);
                int64_t r8_5 = *arg1;
                (*(r8_5 + 0xb8))(arg1, rax_12, r8_5);
            }
        }
        
        int32_t rbx_3;
        rbx_3 = rbp_1 != data_1800462a8;
        data_1800466e0 = rbx_3;
        char const* const rdx_9 = "LOGIN";
        
        if (rbp_1 == data_1800462a8)
            rdx_9 = "STATUS";
        
        result = sub_1800023a0("BServer: intention ", rdx_9);
    }
    
    if (var_28 > 0xf)
    {
        void* rcx_24 = var_40;
        
        if (var_28 + 1 >= 0x1000)
        {
            void* rax_25 = *(rcx_24 - 8);
            
            if (rcx_24 - rax_25 - 8 > 0x1f)
                trap(0xd);
            
            rcx_24 = rax_25;
        }
        
        result = j_sub_180021340(rcx_24);
    }
    
    __security_check_cookie(rax_1 ^ &var_68);
    return result;
}

