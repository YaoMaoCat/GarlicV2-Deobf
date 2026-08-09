
  int64_t sub_18001bd90(int32_t* arg1, int64_t* arg2, void* arg3, int64_t* arg4, int512_t arg5 @ zmm1, char* arg6, int32_t arg7, int64_t arg8, char arg9)

{
    __except_validate_context_record(arg3);
    
    if (*(sub_180019c40() + 0x40))
    {
    label_18001bdf7:
        char r8 = arg1[1];
        
        if (!(r8 & 0x66))
        {
            uint32_t var_68[0xe];
            sub_18001c060(&var_68, arg6, arg4[1]);
            
            if (var_68[0] || *arg6 & 0x40)
            {
                if (*arg1 == 0xe06d7363 && arg1[6] >= 3 && arg1[8] > 0x19930522)
                {
                    int64_t rbp_2 = *(*(arg1 + 0x30) + 8);
                    
                    if (rbp_2)
                    {
                        int64_t rax_11 = _GetThrowImageBase();
                        
                        if (rax_11 != -(rbp_2))
                        {
                            int64_t var_80;
                            var_80 = arg9;
                            int32_t var_88;
                            var_88 = arg8;
                            char var_90;
                            var_90 = arg7;
                            return (rax_11 + rbp_2)(arg1, arg2, arg3, arg4, arg6, var_90, var_88, 
                                var_80);
                        }
                    }
                }
                
                common_assert_to_message_box_build_string<char>(arg1, arg2, arg3, arg4, arg6, arg9, 
                    arg7, arg8);
            }
        }
        else
        {
            int64_t rax_2 = *(arg6 + 8);
            
            if (rax_2)
            {
                char* rdx_1 = arg4[1] + rax_2;
                uint64_t rcx_2 = *rdx_1 & 0xf;
                
                if (*(rdx_1 - *(rcx_2 + 0x180038880) - 4) >> *(rcx_2 + 0x180038890) && !arg7)
                {
                    if (!(r8 & 0x20))
                        __FrameHandler4::FrameUnwindToEmptyState(arg2, arg4, arg6, arg5);
                    else
                    {
                        int32_t rax_6 = *arg1;
                        
                        if (rax_6 == 0x80000026)
                        {
                            int32_t rax_7 = sub_18001a190(arg6, arg4, arg4[4]);
                            
                            if (rax_7 < 0xffffffff)
                            {
                                abort();
                                /* no return */
                            }
                            
                            if (rax_7 >= sub_18001ce80(arg4, arg6))
                            {
                                abort();
                                /* no return */
                            }
                            
                            sub_18001ca30(arg2, arg4, arg6, rax_7, arg5);
                        }
                        else if (rax_6 != 0x80000029)
                            __FrameHandler4::FrameUnwindToEmptyState(arg2, arg4, arg6, arg5);
                        else
                        {
                            int32_t rbp_1 = arg1[0xe];
                            
                            if (rbp_1 < 0xffffffff)
                            {
                                abort();
                                /* no return */
                            }
                            
                            if (rbp_1 >= sub_18001ce80(arg4, arg6))
                            {
                                abort();
                                /* no return */
                            }
                            
                            sub_18001ca30(*(arg1 + 0x28), arg4, arg6, rbp_1, arg5);
                        }
                    }
                }
            }
        }
    }
    else
    {
        int32_t rax_1 = *arg1;
        
        if (rax_1 == 0xe06d7363)
            goto label_18001bdf7;
        
        bool cond:0_1;
        
        if (rax_1 != 0x80000029)
        {
            cond:0_1 = rax_1 == 0x80000026;
        label_18001bdec:
            
            if (cond:0_1 || !(*arg6 & 0x20))
                goto label_18001bdf7;
        }
        else
        {
            if (arg1[6] == 0xf)
            {
                cond:0_1 = *(arg1 + 0x60) == 0x19930520;
                goto label_18001bdec;
            }
            
            if (!(*arg6 & 0x20))
                goto label_18001bdf7;
        }
    }
    
    return 1;
}

