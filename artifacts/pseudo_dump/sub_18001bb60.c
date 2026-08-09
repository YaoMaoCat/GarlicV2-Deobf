
  int64_t sub_18001bb60(int32_t* arg1, int64_t* arg2, void* arg3, int64_t* arg4, int32_t* arg5, int32_t arg6, int64_t arg7, char arg8)

{
    __except_validate_context_record(arg3);
    
    if (*(sub_180019c40() + 0x40))
    {
    label_18001bbd3:
        char rax_4 = arg1[1];
        
        if (rax_4 & 0x66)
        {
            int32_t rcx_1 = arg5[1];
            
            if (rcx_1 && !arg6)
            {
                if (!(rax_4 & 0x20))
                    sub_1800187f0(arg2, arg4, arg5);
                else
                {
                    int32_t rax_5 = *arg1;
                    
                    if (rax_5 == 0x80000026)
                    {
                        int32_t rax_6 = sub_18001a120(arg5, arg4, arg4[4]);
                        
                        if (rax_6 < 0xffffffff || rax_6 >= arg5[1])
                        {
                            abort();
                            /* no return */
                        }
                        
                        sub_18001c880(arg2, arg4, arg5, rax_6);
                    }
                    else if (rax_5 != 0x80000029)
                        sub_1800187f0(arg2, arg4, arg5);
                    else
                    {
                        int32_t r9_1 = arg1[0xe];
                        
                        if (r9_1 < 0xffffffff || r9_1 >= rcx_1)
                        {
                            abort();
                            /* no return */
                        }
                        
                        sub_18001c880(*(arg1 + 0x28), arg4, arg5, r9_1);
                    }
                }
            }
        }
        else if (arg5[3])
        {
        label_18001bcd7:
            
            if (*arg1 == 0xe06d7363 && arg1[6] >= 3 && arg1[8] > 0x19930522)
            {
                int64_t rbp_2 = *(*(arg1 + 0x30) + 8);
                
                if (rbp_2)
                {
                    int64_t rax_14 = _GetThrowImageBase();
                    
                    if (rax_14 != -(rbp_2))
                    {
                        int64_t var_50;
                        var_50 = arg8;
                        int32_t var_58;
                        var_58 = arg7;
                        char var_60;
                        var_60 = arg6;
                        return (rax_14 + rbp_2)(arg1, arg2, arg3, arg4, arg5, var_60, var_58, 
                            var_50);
                    }
                }
            }
            
            sub_18001a7d0(arg1, arg2, arg3, arg4, arg5, arg8, arg6, arg7);
        }
        else
        {
            if ((*arg5 & 0x1fffffff) >= 0x19930521)
            {
                int64_t rbp_1 = arg5[8];
                
                if (rbp_1 && _GetImageBase() != -(rbp_1))
                    goto label_18001bcd7;
            }
            
            if ((*arg5 & 0x1fffffff) >= 0x19930522 && arg5[9] & 4)
                goto label_18001bcd7;
        }
    }
    else
    {
        int32_t rax_1 = *arg1;
        
        if (rax_1 == 0xe06d7363)
            goto label_18001bbd3;
        
        bool cond:0_1;
        
        if (rax_1 != 0x80000029)
        {
            cond:0_1 = rax_1 == 0x80000026;
        label_18001bbb9:
            
            if (cond:0_1 || (*arg5 & 0x1fffffff) < 0x19930522 || !(arg5[9] & 1))
                goto label_18001bbd3;
        }
        else
        {
            if (arg1[6] == 0xf)
            {
                cond:0_1 = *(arg1 + 0x60) == 0x19930520;
                goto label_18001bbb9;
            }
            
            if ((*arg5 & 0x1fffffff) < 0x19930522 || !(arg5[9] & 1))
                goto label_18001bbd3;
        }
    }
    
    return 1;
}

