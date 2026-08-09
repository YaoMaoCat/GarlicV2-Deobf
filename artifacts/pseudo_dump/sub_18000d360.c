
  int64_t sub_18000d360(int64_t* arg1, char* arg2, int32_t arg3, char* arg4, int32_t* arg5, int128_t** arg6)

{
    void var_198;
    int64_t result = __security_cookie ^ &var_198;
    int64_t result_1 = result;
    int64_t rsi = arg3;
    
    if (arg2)
    {
        result = strcmp(arg2, "net/minecraft/network/Connection");
        
        if (!result)
        {
            int64_t rdx_2 = sub_1800023a0("ClassFileLoadHook fired for %s (len=%d)", arg2);
            
            if (data_180046030)
            {
                void var_e8;
                sub_180007650(&var_e8, arg4, rsi);
                int64_t* rcx_2 = &data_180046048;
                
                if (data_180046060 > 0xf)
                    rcx_2 = data_180046048;
                
                int64_t rax_1 = data_180046058;
                char const* const var_108 = "(Ljava/lang/Object;Ljava/lang/Object;)V";
                int64_t var_100_1 = 0x27;
                char const* const var_128 = "onChannelActive";
                int64_t var_120_1 = 0xf;
                int64_t* var_118 = rcx_2;
                int64_t var_110_1 = rax_1;
                uint32_t rdi_1 = sub_180007b50(&var_e8, &var_118, &var_128, &var_108);
                int16_t var_f0_1 = 0x2b2a;
                char var_ee_1 = 0xb8;
                char var_ed_1 = (rdi_1 >> 8);
                char var_ec_1 = rdi_1;
                int128_t var_168;
                __builtin_memset(&var_168, 0, 0x18);
                int32_t* rax_3 = sub_180016420(5);
                var_168 = rax_3;
                *rax_3 = var_f0_1;
                rax_3[1] = var_ec_1;
                *(&var_168 + 8) = rax_3 + 5;
                var_118 = "(Lio/netty/channel/ChannelHandlerContext;)V";
                int64_t var_110_2 = 0x2b;
                var_128 = "channelActive";
                int64_t var_120_2 = 0xd;
                
                if (sub_180008fb0(&var_e8, &var_128, &var_118, &var_168, 2))
                {
                    sub_1800023a0("  patched channelActive OK, mref=%u", rdi_1);
                    int32_t* var_150;
                    sub_18000a130(&var_e8, &var_150);
                    int128_t* var_138 = nullptr;
                    int64_t var_148;
                    int32_t rax_9;
                    int64_t rdx_14;
                    rax_9 = (*(*arg1 + 0x168))(arg1, var_148 - var_150, &var_138);
                    int64_t var_140;
                    
                    if (!rax_9)
                    {
                        int32_t* rdx_21 = var_150;
                        memcpy(var_138, rdx_21, var_148 - rdx_21);
                        *arg6 = var_138;
                        *arg5 = var_148 - var_150;
                        sub_1800023a0("  emitted patched bytes: %u -> %u", rsi);
                        int32_t* rax_17 = var_150;
                        
                        if (rax_17)
                        {
                            int32_t* rcx_16;
                            
                            if (var_140 - rax_17 < 0x1000)
                                rcx_16 = rax_17;
                            else
                            {
                                rcx_16 = *(rax_17 - 8);
                                
                                if (rax_17 - rcx_16 - 8 > 0x1f)
                                    trap(0xd);
                            }
                            
                            j_sub_180021340(rcx_16);
                            __builtin_memset(&var_150, 0, 0x18);
                        }
                        
                        void* rax_20 = var_168;
                        
                        if (!rax_20)
                            result = sub_18000d0b0(&var_e8);
                        else
                        {
                            void* rcx_18;
                            
                            if (rax_3 + 5 - rax_20 < 0x1000)
                                rcx_18 = rax_20;
                            else
                            {
                                rcx_18 = *(rax_20 - 8);
                                
                                if (rax_20 - rcx_18 - 8 > 0x1f)
                                    trap(0xd);
                            }
                            
                            j_sub_180021340(rcx_18);
                            __builtin_memset(&var_168, 0, 0x18);
                            result = sub_18000d0b0(&var_e8);
                        }
                    }
                    else
                    {
                        sub_1800023a0("  jvmti->Allocate failed", rdx_14);
                        int32_t* rax_10 = var_150;
                        
                        if (rax_10)
                        {
                            int32_t* rcx_12;
                            
                            if (var_140 - rax_10 < 0x1000)
                                rcx_12 = rax_10;
                            else
                            {
                                rcx_12 = *(rax_10 - 8);
                                
                                if (rax_10 - rcx_12 - 8 > 0x1f)
                                    trap(0xd);
                            }
                            
                            j_sub_180021340(rcx_12);
                            __builtin_memset(&var_150, 0, 0x18);
                        }
                        
                        void* rax_13 = var_168;
                        
                        if (!rax_13)
                            result = sub_18000d0b0(&var_e8);
                        else
                        {
                            void* rcx_13;
                            
                            if (rax_3 + 5 - rax_13 < 0x1000)
                                rcx_13 = rax_13;
                            else
                            {
                                rcx_13 = *(rax_13 - 8);
                                
                                if (rax_13 - rcx_13 - 8 > 0x1f)
                                    trap(0xd);
                            }
                            
                            j_sub_180021340(rcx_13);
                            __builtin_memset(&var_168, 0, 0x18);
                            result = sub_18000d0b0(&var_e8);
                        }
                    }
                }
                else
                {
                    sub_1800023a0("  channelActive(%s) NOT FOUND in %s", 
                        "(Lio/netty/channel/ChannelHandlerContext;)V");
                    void* rax_5 = var_168;
                    
                    if (!rax_5)
                        result = sub_18000d0b0(&var_e8);
                    else
                    {
                        void* rcx_8;
                        
                        if (rax_3 + 5 - rax_5 < 0x1000)
                            rcx_8 = rax_5;
                        else
                        {
                            rcx_8 = *(rax_5 - 8);
                            
                            if (rax_5 - rcx_8 - 8 > 0x1f)
                                trap(0xd);
                        }
                        
                        j_sub_180021340(rcx_8);
                        __builtin_memset(&var_168, 0, 0x18);
                        result = sub_18000d0b0(&var_e8);
                    }
                }
            }
            else
                result = sub_1800023a0("  ...but g_hook not valid yet, skipping", rdx_2);
        }
    }
    
    __security_check_cookie(result_1 ^ &var_198);
    return result;
}

