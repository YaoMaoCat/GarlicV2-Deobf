
  int64_t sub_18001b590(int32_t* arg1, int64_t* arg2, int64_t arg3, void* arg4, char* arg5, int32_t arg6, int32_t arg7, int32_t arg8)

{
    void var_178;
    int64_t rax_1 = __security_cookie ^ &var_178;
    int32_t result = arg8;
    
    if (*arg1 != 0x80000003)
    {
        if (*(sub_180019c40() + 0x10) && *(sub_180019c40() + 0x10) != EncodePointer(nullptr))
        {
            int32_t rax_5 = *arg1;
            
            if (rax_5 != 0xe0434f4d && rax_5 != 0xe0434352)
            {
                int32_t var_140_1 = arg6;
                int32_t result_1 = result;
                int32_t var_150_1 = arg7;
                char* var_158_1 = arg5;
                sub_180018610(arg1);
            }
        }
        
        int32_t var_78;
        sub_18001c060(&var_78, arg5, *(arg4 + 8));
        
        if (var_78 <= 0)
        {
            abort();
            /* no return */
        }
        
        int32_t var_150_2 = arg7;
        char* var_158_2 = arg5;
        int32_t* var_f0;
        sub_180018bc0(&var_f0, &var_78, arg6);
        int32_t result_3;
        result = result_3;
        int32_t* rsi_1 = var_f0;
        int32_t result_2 = result;
        int32_t var_d8;
        
        while (result < var_d8)
        {
            int32_t r15_1 = rsi_1[6];
            
            if (r15_1 <= arg6 && arg6 <= rsi_1[7])
            {
                int32_t rax_7 = rsi_1[8];
                int64_t rdx_3 = rsi_1[9];
                int64_t r8_3 = *(arg4 + 8);
                int32_t rcx_3 = **(arg4 + 0x10);
                int64_t var_c0_1;
                __builtin_memset(&var_c0_1, 0, 0x11);
                int64_t var_ac_1 = 0;
                int64_t var_a4_1 = 0;
                int64_t var_88_1 = r8_3;
                int32_t var_80_1 = rcx_3;
                int128_t var_98_1 = {0};
                uint32_t var_c8;
                
                if (!rdx_3)
                    var_c8 = 0;
                else
                {
                    char* rax_9 = rdx_3 + r8_3;
                    char* var_c0_2 = rax_9;
                    uint64_t rcx_5 = *rax_9 & 0xf;
                    void* rdx_5 = rdx_3 - *(rcx_5 + 0x180038880) + r8_3;
                    var_c8 = *(rdx_5 - 4) >> *(rcx_5 + 0x180038890);
                    void* var_c0_3 = rdx_5;
                    void* var_b8_1 = rdx_5;
                    sub_18001c630(&var_c8);
                }
                
                sub_18001d200(&var_c8, 0);
                sub_18001d200(&var_c8, var_c8 - 1);
                int64_t rbx_2 = *(&var_ac_1 + 4);
                
                if (!rbx_2)
                {
                label_18001b7a4:
                    
                    if (!(var_ac_1 & 0x40))
                    {
                        char var_128_1 = 0;
                        var_150_2 = arg5;
                        void var_d0;
                        char var_b0;
                        sub_180018e70(arg2, arg1, arg3, 
                            __FrameHandler4::GetEstablisherFrame(arg2, arg4, arg5, &var_d0), 
                            _GetImageBase() + *(&var_a4_1 + 4), var_150_2, r15_1, rax_7, &var_b0, 
                            arg4);
                    }
                }
                else
                {
                    if (_GetImageBase() == -(rbx_2))
                        goto label_18001b7a4;
                    
                    int64_t rbx_3 = *(&var_ac_1 + 4);
                    void* rax_16;
                    
                    if (!rbx_3)
                        rax_16 = nullptr;
                    else
                        rax_16 = _GetImageBase() + rbx_3;
                    
                    if (!*(rax_16 + 0x10))
                        goto label_18001b7a4;
                }
            }
            
            char* r10_1 = *(rsi_1 + 8);
            uint64_t rcx_14 = *r10_1 & 0xf;
            int64_t r9_4 = *(rcx_14 + 0x180038880);
            char* rdx_11 = r10_1 - r9_4;
            uint32_t rax_21 = *(rdx_11 - 4) >> *(rcx_14 + 0x180038890);
            *(rsi_1 + 8) = rdx_11;
            rsi_1[6] = rax_21;
            uint64_t rcx_17 = *rdx_11 & 0xf;
            int64_t r8_6 = *(rcx_17 + 0x180038880);
            char* rdx_14 = r10_1 - r8_6 - r9_4;
            rsi_1[7] = *(rdx_14 - 4) >> *(rcx_17 + 0x180038890);
            *(rsi_1 + 8) = rdx_14;
            uint64_t rcx_20 = *rdx_14 & 0xf;
            int32_t* r10_4 = r10_1 - *(rcx_20 + 0x180038880) - r8_6 - r9_4;
            rsi_1[8] = r10_4[-1] >> *(rcx_20 + 0x180038890);
            *(rsi_1 + 8) = r10_4;
            int32_t rcx_22 = *r10_4;
            *(rsi_1 + 8) = &r10_4[1];
            result = result_2 + 1;
            rsi_1[9] = rcx_22;
            result_2 = result;
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_178);
    return result;
}

