
  uint64_t sub_18000adb0(int64_t* arg1)

{
    void var_258;
    uint64_t var_58 = __security_cookie ^ &var_258;
    uint64_t result;
    
    if (!data_180046030)
    {
        int512_t entry_zmm2;
        
        if (arg1)
            result = sub_180001de0(arg1, data_180047468, entry_zmm2);
        
        if (!arg1 || !result)
            result = 0;
        else
        {
            void* var_140;
            sub_180002e20(&var_140, 2, 3);
            sub_1800033a0();
            int64_t* var_180;
            sub_180003410(&var_180, &data_180046008, &var_140);
            int64_t* var_160;
            sub_1800029d0(&var_160, &var_180);
            int64_t* rax_1 = &var_160;
            int64_t* rdi_1 = var_160;
            int64_t var_148;
            int64_t rsi_1 = var_148;
            
            if (rsi_1 > 0xf)
                rax_1 = rdi_1;
            
            int64_t* rdx_3 = &var_160;
            
            if (rsi_1 > 0xf)
                rdx_3 = rdi_1;
            
            void* var_150;
            void* r8_3 = var_150 + rdx_3;
            
            if (rax_1 != r8_3)
            {
                do
                {
                    if (*rax_1 == 0x2f)
                        *rax_1 = 0x2e;
                    
                    rax_1 += 1;
                } while (rax_1 != r8_3);
                
                rsi_1 = var_148;
                rdi_1 = var_160;
            }
            
            int128_t var_1f0;
            int128_t* var_228 = &var_1f0;
            __builtin_memset(&var_1f0, 0, 0x20);
            int64_t rax_2 = sub_180016420(0x20);
            var_1f0 = rax_2;
            int64_t var_1e0_1 = 0x10;
            int64_t var_1d8_1 = 0x1f;
            __builtin_strncpy(rax_2, "java/lang/Object", 0x11);
            void var_1a0;
            void var_118;
            sub_180004930(&var_118, sub_1800029d0(&var_1a0, &var_180), &var_1f0, 0x34);
            char const* const var_218 = "(Ljava/lang/String;)V";
            int64_t var_210_1 = 0x15;
            var_228 = "trace";
            int64_t var_220_1 = 5;
            sub_180005820(&var_118, &var_228, &var_218, 0x109);
            var_218 = "(Ljava/lang/Object;Ljava/lang/Object;)V";
            int64_t var_210_2 = 0x27;
            var_228 = "onChannelActive";
            int64_t var_220_2 = 0xf;
            sub_180005820(&var_118, &var_228, &var_218, 0x109);
            void* var_208;
            int512_t zmm2 = sub_180005940(&var_118, &var_208);
            int32_t var_200;
            int32_t rcx_9 = var_200 - var_208;
            int64_t* rdx_9 = &var_180;
            int64_t var_168;
            
            if (var_168 > 0xf)
                rdx_9 = var_180;
            
            int64_t rax_5 = (*(*arg1 + 0x28))(arg1, rdx_9, result);
            int64_t* rbx;
            
            if (rax_5)
            {
                char const* const var_1d0 = "trace";
                char const* const var_1c8_1 = "(Ljava/lang/String;)V";
                void (* var_1c0_1)(int64_t* arg1, int64_t arg2, int64_t arg3) = sub_18000b2d0;
                char const* const var_1b8_1 = "onChannelActive";
                char const* const var_1b0_1 = "(Ljava/lang/Object;Ljava/lang/Object;)V";
                int64_t (* var_1a8_1)(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4) =
                    sub_18000b270;
                int64_t* rcx_12 = arg1;
                char const* const rdx_11;
                
                if (!(*(*arg1 + 0x6b8))(arg1, rax_5, &var_1d0, 2, rcx_9))
                {
                    int64_t rax_9 =
                        (*(*arg1 + 0x388))(rcx_12, rax_5, "trace", "(Ljava/lang/String;)V");
                    int64_t rax_10 = (*(*arg1 + 0x388))(arg1, rax_5, "onChannelActive", 
                        "(Ljava/lang/Object;Ljava/lang/Object;)V");
                    
                    if (!rax_9 || !rax_10)
                    {
                        rdx_11 = "InstallHookBridge/GetStaticMethodID";
                        rcx_12 = arg1;
                        goto label_18000b0ec;
                    }
                    
                    int64_t r8_9 = *arg1;
                    data_180046030 = (*(r8_9 + 0xa8))(arg1, rax_5, r8_9);
                    data_180046040 = rax_9;
                    data_180046038 = rax_10;
                    sub_180002c30(&data_180046048, &var_180);
                    sub_180002c30(&data_180046068, &var_160);
                    (*(*arg1 + 0xb8))(arg1, rax_5);
                    (*(*arg1 + 0xb0))(arg1, result);
                    rbx = 1;
                    rsi_1 = var_148;
                    rdi_1 = var_160;
                }
                else
                {
                    rdx_11 = "InstallHookBridge/RegisterNatives";
                label_18000b0ec:
                    sub_180002210(rcx_12, rdx_11, zmm2);
                    (*(*arg1 + 0xb8))(arg1, rax_5);
                    (*(*arg1 + 0xb0))(arg1, result);
                    rbx = 0;
                }
            }
            else
            {
                sub_180002210(arg1, "InstallHookBridge/DefineClass", zmm2);
                (*(*arg1 + 0xb0))(arg1, result);
                rbx = 0;
            }
            
            void* rax_16 = var_208;
            
            if (rax_16)
            {
                int64_t var_1f8;
                void* rcx_19;
                
                if (var_1f8 - rax_16 < 0x1000)
                    rcx_19 = rax_16;
                else
                {
                    rcx_19 = *(rax_16 - 8);
                    
                    if (rax_16 - rcx_19 - 8 > 0x1f)
                        trap(0xd);
                }
                
                j_sub_180021340(rcx_19);
                __builtin_memset(&var_208, 0, 0x18);
            }
            
            sub_18000ab00(&var_118);
            
            if (rsi_1 > 0xf)
            {
                if (rsi_1 + 1 >= 0x1000)
                {
                    int64_t* rax_19 = rdi_1[-1];
                    
                    if (rdi_1 - rax_19 - 8 > 0x1f)
                        trap(0xd);
                    
                    rdi_1 = rax_19;
                }
                
                j_sub_180021340(rdi_1);
            }
            
            if (var_168 > 0xf)
            {
                int64_t* rcx_23 = var_180;
                
                if (var_168 + 1 >= 0x1000)
                {
                    int64_t* rax_20 = rcx_23[-1];
                    
                    if (rcx_23 - rax_20 - 8 > 0x1f)
                        trap(0xd);
                    
                    rcx_23 = rax_20;
                }
                
                j_sub_180021340(rcx_23);
            }
            
            int64_t var_170_1 = 0;
            int64_t var_168_1 = 0xf;
            var_180 = 0;
            int64_t var_128;
            
            if (var_128 > 0xf)
            {
                void* rcx_26 = var_140;
                
                if (var_128 + 1 >= 0x1000)
                {
                    void* rax_21 = *(rcx_26 - 8);
                    
                    if (rcx_26 - rax_21 - 8 > 0x1f)
                        trap(0xd);
                    
                    rcx_26 = rax_21;
                }
                
                j_sub_180021340(rcx_26);
            }
            
            result = rbx;
        }
    }
    else
        result = 1;
    
    __security_check_cookie(var_58 ^ &var_258);
    return result;
}

