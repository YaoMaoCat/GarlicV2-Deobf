
  int64_t sub_180015be0(int64_t* arg1, int64_t arg2, int128_t* arg3, int512_t arg4 @ zmm1, int512_t arg5 @ zmm2)

{
    void var_78;
    int64_t result = __security_cookie ^ &var_78;
    int64_t result_1 = result;
    
    if (data_180046428 && data_180046438 && data_1800463e8 && data_1800463f0 && data_180046440
        && data_180046448)
    {
        int64_t rax_1 = *arg1;
        int128_t var_46_1 = *arg3;
        int16_t var_48 = 0x101;
        int16_t var_36_1 = 0;
        result = (*(rax_1 + 0x580))(arg1, 0x14);
        
        if (result)
        {
            (*(*arg1 + 0x680))(arg1, result, 0, 0x14, &var_48);
            data_180046438;
            int64_t rax_2 = sub_18000e9f0(arg1, data_180046428, arg5, result);
            int64_t r8_1 = *arg1;
            (*(r8_1 + 0xb8))(arg1, result, r8_1);
            char rax_3;
            
            if (rax_2)
            {
                int64_t rdx_3 = *arg1;
                rax_3 = (*(rdx_3 + 0x720))(arg1, rdx_3);
            }
            
            if (!rax_2 || rax_3)
                result = (*(*arg1 + 0x88))(arg1);
            else
            {
                data_1800463f0;
                int64_t rax_4 = sub_18000bbf0(arg1, data_1800463e8, arg5, rax_2);
                int64_t r8_3 = *arg1;
                (*(r8_3 + 0xb8))(arg1, rax_2, r8_3);
                char rax_5;
                
                if (rax_4)
                {
                    int64_t rdx_6 = *arg1;
                    rax_5 = (*(rdx_6 + 0x720))(arg1, rdx_6);
                }
                
                if (!rax_4 || rax_5)
                    result = (*(*arg1 + 0x88))(arg1);
                else
                {
                    data_180046448;
                    int64_t rax_6 = sub_18000bbf0(arg1, data_180046440, arg5, rax_4);
                    int64_t r8_5 = *arg1;
                    (*(r8_5 + 0xb8))(arg1, rax_4, r8_5);
                    char rax_7;
                    
                    if (rax_6)
                    {
                        int64_t r8_6 = *arg1;
                        rax_7 = (*(r8_6 + 0x720))(arg1, arg4, r8_6);
                    }
                    
                    if (!rax_6 || rax_7)
                        result = sub_180002210(arg1, "synth-tab: packet ctor", arg5);
                    else
                    {
                        data_180046320;
                        sub_180001cd0(arg1, arg2, arg5, rax_6);
                        
                        if ((*(*arg1 + 0x720))(arg1))
                            sub_180002210(arg1, "synth-tab: writeAndFlush", arg5);
                        
                        result = (*(*arg1 + 0xb8))(arg1, rax_6);
                    }
                }
            }
        }
    }
    
    __security_check_cookie(result_1 ^ &var_78);
    return result;
}

