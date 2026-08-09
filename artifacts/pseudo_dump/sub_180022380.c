
  uint64_t sub_180022380(int64_t* arg1, char* arg2, void* arg3, char* arg4, int64_t arg5, int32_t arg6, int32_t arg7, int64_t arg8, int32_t arg9, int64_t* arg10)

{
    void* r11 = arg3;
    char* r10 = arg2;
    int64_t* var_30_1;
    int32_t rbx;
    
    if (arg2)
    {
        if (r11 && arg4 && arg5)
        {
            int64_t rsi;
            
            if (arg6 == 0x41 || arg6 - 0x45 <= 2)
                rsi = 1;
            else
                rsi = 0;
            
            if (!(arg8 & 8))
            {
                int64_t rdx = *arg1;
                
                if ((rdx >> 0x34 & 0x7ff) == 0x7ff)
                {
                    int32_t r8_1 = 0xc;
                    int64_t rax_8 = rdx & 0xfffffffffffff;
                    int64_t rcx_2;
                    
                    if (!rax_8)
                        rcx_2 = 0;
                    else if (rdx >= 0 || rax_8 != 0x8000000000000)
                        rcx_2 = ((0x8000000000000 - 0x8000000000000) & 0xfffffffffffffffc) + 8;
                    else
                        rcx_2 = 0xc;
                    
                    uint64_t rdx_1 = rdx >> 0x3f;
                    
                    if (r11 >= rdx_1 + 4)
                    {
                        int64_t r8_2 = -1;
                        
                        if (rdx_1)
                        {
                            *r10 = 0x2d;
                            r10 = &r10[1];
                            *r10 = 0;
                            
                            if (r11 != -1)
                                r11 -= 1;
                        }
                        
                        int32_t rdx_4 = (rsi ^ 1) * 2;
                        
                        do
                            r8_2 += 1;
                         while ((&data_180039d40)[rdx_4 + rcx_2][r8_2]);
                        
                        int32_t rax_15;
                        rax_15 = r11 <= r8_2;
                        
                        if (sub_180020d70(r10, r11, (&data_180039d40)[rdx_4 + rax_15 + rcx_2]))
                        {
                            int64_t var_38_5 = 0;
                            _invoke_watson();
                            /* no return */
                        }
                        
                        r8_1 = 0;
                    }
                    else
                        *r10 = 0;
                    
                    return r8_1;
                }
            }
            
            int64_t rbx_1;
            rbx_1 = arg8 & 0x20;
            int32_t rdx_9 = (arg8 >> 4 & 1) | 2;
            char temp0_1 = rbx_1;
            rbx_1 = -(rbx_1);
            int32_t rbx_3 = (rbx_1 - rbx_1) & arg9;
            
            if (arg6 != 0x41)
            {
                if (arg6 == 0x45)
                    return fp_format_e(arg1, r10, r11, arg4, arg5, arg7, rsi, rdx_9, rbx_3, arg10);
                
                if (arg6 == 0x46)
                {
                label_1800225a7:
                    int32_t var_20;
                    var_20 = arg10;
                    char var_28;
                    var_28 = rbx_3;
                    return fp_format_f(arg1, r10, r11, arg4, arg5, arg7, var_28, var_20);
                }
                
                if (arg6 == 0x47)
                    return fp_format_g(arg1, r10, r11, arg4, arg5, arg7, rsi, rdx_9, rbx_3, arg10);
                
                if (arg6 != 0x61)
                {
                    if (arg6 == 0x65)
                        return fp_format_e(arg1, r10, r11, arg4, arg5, arg7, rsi, rdx_9, rbx_3, 
                            arg10);
                    
                    if (arg6 == 0x66)
                        goto label_1800225a7;
                    
                    return fp_format_g(arg1, r10, r11, arg4, arg5, arg7, rsi, rdx_9, rbx_3, arg10);
                }
            }
            
            return sub_180021870(arg1, r10, r11, arg4, arg5, arg7, rsi, rdx_9, rbx_3, arg10);
        }
        
        rbx = 0x16;
        var_30_1 = arg10;
        arg10[6] = 1;
        *(arg10 + 0x2c) = 0x16;
    }
    else
    {
        rbx = &arg2[0x16];
        var_30_1 = arg10;
        arg10[6] = 1;
        *(arg10 + 0x2c) = rbx;
    }
    
    _invalid_parameter_internal(0, 0, 0, 0, 0, var_30_1);
    return rbx;
}

