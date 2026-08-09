
  int64_t sub_18000b810(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4)

{
    void var_78;
    int64_t rax_1 = __security_cookie ^ &var_78;
    int128_t var_50;
    int512_t zmm2 = sub_18000ccf0(&var_50, arg1, arg4);
    int64_t var_38;
    
    if (sub_18000df40())
    {
        int128_t* rsi_1 = &var_50;
        
        if (var_38 > 0xf)
            rsi_1 = var_50;
        
        int64_t var_40;
        
        if (var_40 >= 0x24)
        {
            uint32_t (* rax_3)[0x8];
            rax_3 =
                j_sub_180017670(rsi_1, rsi_1 + 0x24, "net.minecraft.network.protocol.game.", 0x24);
            
            if (rax_3 != rsi_1 + 0x24 && rax_3 == rsi_1)
                zmm2 = sub_18000dda0(arg1, arg4);
        }
    }
    
    data_1800460f0;
    sub_180001cd0(arg1, arg3, zmm2, arg4);
    char result = (*(*arg1 + 0x720))(arg1);
    
    if (result)
        result = (*(*arg1 + 0x88))(arg1);
    
    if (var_38 > 0xf)
    {
        void* rcx_6 = var_50;
        
        if (var_38 + 1 >= 0x1000)
        {
            void* rax_6 = *(rcx_6 - 8);
            
            if (rcx_6 - rax_6 - 8 > 0x1f)
                trap(0xd);
            
            rcx_6 = rax_6;
        }
        
        result = j_sub_180021340(rcx_6);
    }
    
    __security_check_cookie(rax_1 ^ &var_78);
    return result;
}

