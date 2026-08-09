
  void* const* sub_18001b330(int32_t* arg1, int64_t* arg2, int64_t arg3, int64_t* arg4, void* arg5, int32_t arg6, int32_t arg7, int32_t arg8)

{
    void* const* result = &__return_addr;
    
    if (*arg1 != 0x80000003)
    {
        if (*(sub_180019c40() + 0x10) && *(sub_180019c40() + 0x10) != EncodePointer(nullptr))
        {
            int32_t rax_3 = *arg1;
            
            if (rax_3 != 0xe0434f4d && rax_3 != 0xe0434352)
            {
                int32_t var_a0_1 = arg6;
                int32_t var_a8 = arg8;
                int32_t var_b0_1 = arg7;
                void* var_b8_1 = arg5;
                sub_1800185c0(arg1);
            }
        }
        
        int64_t var_60_1 = arg4[1];
        void* var_68 = arg5;
        
        if (*(arg5 + 0xc) <= 0)
        {
            abort();
            /* no return */
        }
        
        int32_t var_b0_2 = arg7;
        int64_t* var_58;
        result = sub_180018a90(&var_58, &var_68, arg6, arg4, arg5);
        int32_t i_1;
        int32_t i = i_1;
        int64_t* r13_1 = var_58;
        int32_t var_40;
        
        for (; i < var_40; i += 1)
        {
            result = i;
            int32_t* r8_3 = *(*r13_1 + 0x10) + result * 0x14 + r13_1[1];
            int32_t r15_1 = *r8_3;
            
            if (r15_1 <= arg6 && arg6 <= r8_3[1])
            {
                int32_t rax_7 = r8_3[2];
                result = r8_3[4];
                char* rsi_3 = arg4[1] - 0x14 + result + r8_3[3] * 0x14;
                int64_t rbx_2 = *(rsi_3 + 4);
                
                if (!rbx_2)
                {
                label_18001b4cb:
                    
                    if (!(*rsi_3 & 0x40))
                    {
                        void var_70;
                        int64_t* rax_11 = sub_180018960(arg2, arg4, arg5, &var_70);
                        int64_t rax_12 = _GetImageBase();
                        char var_88_1 = 0;
                        int64_t* var_90_1 = arg4;
                        var_b0_2 = arg5;
                        result = sub_180018d40(arg2, arg1, arg3, rax_11, *(rsi_3 + 0xc) + rax_12, 
                            var_b0_2, r15_1, rax_7, rsi_3);
                    }
                }
                else
                {
                    void* rax_9 = _GetImageBase();
                    result = rax_9 + rbx_2;
                    
                    if (rax_9 == -(rbx_2))
                        goto label_18001b4cb;
                    
                    int64_t rbx_3 = *(rsi_3 + 4);
                    
                    if (!rbx_3)
                        result = nullptr;
                    else
                        result = _GetImageBase() + rbx_3;
                    
                    if (!result[2])
                        goto label_18001b4cb;
                }
            }
        }
    }
    
    return result;
}

