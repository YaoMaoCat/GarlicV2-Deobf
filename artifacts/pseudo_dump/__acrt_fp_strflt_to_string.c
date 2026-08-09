
🌐  uint64_t __acrt_fp_strflt_to_string(char* arg1, int64_t arg2, int32_t arg3, int32_t* arg4, int32_t arg5, int32_t arg6, int64_t* arg7)

{
    int32_t rbx;
    
    if (arg1 && arg2)
    {
        int32_t rax_3 = 0;
        *arg1 = 0;
        
        if (arg3 > 0)
            rax_3 = arg3;
        
        if (arg2 > rax_3 + 1)
        {
            if (arg4)
            {
                char* rcx = *(arg4 + 8);
                char* rbx_1 = &arg1[1];
                char* rdx = rcx;
                *arg1 = 0x30;
                
                for (; arg3 > 0; arg3 -= 1)
                {
                    int64_t rax_5;
                    rax_5 = *rdx;
                    
                    if (!rax_5)
                        rax_5 = 0x30;
                    else
                        rdx = &rdx[1];
                    
                    *rbx_1 = rax_5;
                    rbx_1 = &rbx_1[1];
                }
                
                *rbx_1 = 0;
                
                if (arg3 >= 0 && should_round_up(rcx, rdx, *arg4, arg5, arg6))
                {
                    char rax_7;
                    
                    while (true)
                    {
                        rbx_1 -= 1;
                        rax_7 = *rbx_1;
                        
                        if (rax_7 != 0x39)
                            break;
                        
                        *rbx_1 = 0x30;
                    }
                    
                    *rbx_1 = rax_7 + 1;
                }
                
                if (*arg1 != 0x31)
                {
                    void* r8_1 = -ffffffffffffffff;
                    
                    do
                        r8_1 += 1;
                     while (*(r8_1 + arg1 + 1));
                    
                    memcpy(arg1, &arg1[1], r8_1 + 1);
                }
                else
                    arg4[1] += 1;
                
                return 0;
            }
            
            rbx = 0x16;
        }
        else
            rbx = 0x22;
    }
    else
        rbx = 0x16;
    
    *(arg7 + 0x2c) = rbx;
    arg7[6] = 1;
    _invalid_parameter_internal(0, 0, 0, 0, 0, arg7);
    return rbx;
}

