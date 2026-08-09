
  int64_t sub_18000b930(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5)

{
    void var_88;
    int64_t rax_1 = __security_cookie ^ &var_88;
    int128_t var_50;
    sub_18000ccf0(&var_50, arg1, arg4);
    void* var_58 = &data_180046130;
    
    if (sub_180017bf0(&data_180046130))
    {
        std::_Throw_Cpp_error(5);
        /* no return */
    }
    
    int32_t rax_3 = data_18004617c;
    
    if (rax_3 == 0x7fffffff)
    {
        data_18004617c = rax_3 - 1;
        std::_Throw_Cpp_error(6);
        /* no return */
    }
    
    uint32_t (* rbx)[0x8] = nullptr;
    int64_t rcx_1 = data_1800474a8;
    int64_t var_38;
    int128_t* rsi;
    
    if (!((data_1800474b0 - rcx_1) >> 3))
    {
    label_18000b9fb:
        sub_180017c80(&data_180046130);
        void* rax_12 = strlen("net.minecraft.network.protocol.game.");
        rsi = &var_50;
        
        if (var_38 > 0xf)
            rsi = var_50;
        
        int64_t var_40;
        
        if (!rax_12)
        {
        label_18000ba54:
            
            if (!sub_18000df40())
            {
                rbx = 0;
                rsi = 1;
            }
            else
            {
                int128_t* rcx_4 = &var_50;
                
                if (var_38 > 0xf)
                    rcx_4 = var_50;
                
                rbx = 0;
                
                if (!strcmp(rcx_4 + 0x24, "ServerboundCustomPayloadPacket"))
                    rsi = 1;
                else
                    rsi = 0;
            }
        }
        else if (rax_12 > var_40)
        {
            rbx = 0;
            rsi = 1;
        }
        else
        {
            rbx = rax_12 + rsi;
            uint32_t (* rax_13)[0x8] =
                j_sub_180017670(rsi, rbx, "net.minecraft.network.protocol.game.", rax_12);
            
            if (rax_13 != rbx && rax_13 == rsi)
                goto label_18000ba54;
            
            rbx = 0;
            rsi = 1;
        }
    }
    else
    {
        while (true)
        {
            if ((*(*arg1 + 0xc0))(arg1, *(rcx_1 + (rbx << 3)), arg4))
            {
                (*(*arg1 + 0xb0))(arg1, *(data_1800474a8 + (rbx << 3)));
                int128_t* rcx_7 = data_1800474a8 + (rbx << 3);
                memcpy(rcx_7, rcx_7 + 8, data_1800474b0 - (rcx_7 + 8));
                data_1800474b0 -= 8;
                rbx = 1;
                sub_180017c80(&data_180046130);
                break;
            }
            
            rbx += 1;
            rcx_1 = data_1800474a8;
            
            if (rbx >= (data_1800474b0 - rcx_1) >> 3)
                goto label_18000b9fb;
        }
        
        rsi = 1;
    }
    
    char const* const rdx_6;
    
    if (!rbx)
    {
        rdx_6 = "DROP";
        
        if (rsi)
            rdx_6 = "PASS";
    }
    else
        rdx_6 = "ROUTE";
    
    int64_t r9_1;
    int512_t zmm2;
    r9_1 = sub_1800023a0("[C2S %s] %s", rdx_6);
    
    if (rsi)
    {
        int64_t var_68_1 = arg5;
        data_1800460f8;
        sub_180001cd0(arg1, arg3, zmm2, arg4);
    }
    else if (arg5 && data_180046128)
        sub_180001cd0(arg1, arg5, zmm2, r9_1);
    
    char result = (*(*arg1 + 0x720))(arg1);
    
    if (result)
        result = (*(*arg1 + 0x88))(arg1);
    
    if (var_38 > 0xf)
    {
        void* rcx_12 = var_50;
        
        if (var_38 + 1 >= 0x1000)
        {
            void* rax_20 = *(rcx_12 - 8);
            
            if (rcx_12 - rax_20 - 8 > 0x1f)
                trap(0xd);
            
            rcx_12 = rax_20;
        }
        
        result = j_sub_180021340(rcx_12);
    }
    
    __security_check_cookie(rax_1 ^ &var_88);
    return result;
}

