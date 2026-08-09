
  void sub_18000dda0(int64_t* arg1, int64_t arg2)

{
    if (!arg2)
        return;
    
    void var_68;
    int64_t rax_2 = __security_cookie ^ &var_68;
    
    if (data_1800466e0 == 2)
    {
        int128_t var_40;
        sub_180011120(&var_40, arg1, arg2);
        int128_t* rsi_1 = &var_40;
        int64_t var_28;
        
        if (var_28 > 0xf)
            rsi_1 = var_40;
        
        int64_t var_30;
        
        if (var_30 >= 0x24)
        {
            uint64_t rax;
            int512_t zmm1_1;
            int512_t zmm2_1;
            rax =
                j_sub_180017670(rsi_1, rsi_1 + 0x24, "net.minecraft.network.protocol.game.", 0x24);
            
            if (rax != rsi_1 + 0x24 && rax == rsi_1)
            {
                void* var_48_1 = &data_180046688;
                
                if (sub_180017bf0(&data_180046688))
                {
                    std::_Throw_Cpp_error(5);
                    /* no return */
                }
                
                int32_t rax_4 = data_1800466d4;
                
                if (rax_4 == 0x7fffffff)
                {
                    data_1800466d4 = rax_4 - 1;
                    std::_Throw_Cpp_error(6);
                    /* no return */
                }
                
                int64_t rdx_2 = data_1800466d8;
                
                if (!rdx_2)
                    sub_180017c80(&data_180046688);
                else
                {
                    int64_t rax_6 = (*(*arg1 + 0xc8))(arg1, rdx_2);
                    sub_180017c80(&data_180046688);
                    
                    if (rax_6)
                    {
                        char rax_7;
                        int512_t zmm1_2;
                        int512_t zmm2_2;
                        rax_7 = sub_1800135d0(arg1, rax_6, arg2, zmm1_1, zmm2_1);
                        
                        if (!rax_7)
                            sub_180015f80(arg1, rax_6, arg2, zmm1_2, zmm2_2);
                        
                        (*(*arg1 + 0xb8))(arg1, rax_6);
                    }
                }
            }
        }
        
        if (var_28 > 0xf)
        {
            void* rcx_6 = var_40;
            
            if (var_28 + 1 >= 0x1000)
            {
                void* rax_9 = *(rcx_6 - 8);
                
                if (rcx_6 - rax_9 - 8 > 0x1f)
                    trap(0xd);
                
                rcx_6 = rax_9;
            }
            
            j_sub_180021340(rcx_6);
        }
    }
    
    __security_check_cookie(rax_2 ^ &var_68);
}

