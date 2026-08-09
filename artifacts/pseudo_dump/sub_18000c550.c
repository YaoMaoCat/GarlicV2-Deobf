
  uint64_t sub_18000c550(int64_t* arg1, int64_t arg2)

{
    void var_268;
    int64_t rax_1 = __security_cookie ^ &var_268;
    void* var_128;
    sub_180002e20(&var_128, 2, 3);
    sub_1800033a0();
    int64_t* var_168;
    sub_180003410(&var_168, &data_180046008, &var_128);
    int128_t var_148;
    __builtin_memset(&var_148, 0, 0x20);
    void* var_158;
    void* r14 = var_158;
    int64_t* r15 = &var_168;
    int64_t var_150;
    
    if (var_150 > 0xf)
        r15 = var_168;
    
    int64_t rdi = 0x7fffffffffffffff;
    
    if (r14 > 0x7fffffffffffffff)
    {
        sub_180003aa0();
        /* no return */
    }
    
    void* var_138_1;
    int64_t var_130_1;
    int128_t* rbx_1;
    
    if (r14 > 0xf)
    {
        int64_t rax_3 = r14 | 0xf;
        uint64_t rcx_2;
        
        if (rax_3 <= 0x7fffffffffffffff)
        {
            rdi = rax_3;
            
            if (rax_3 < 0x16)
                rdi = 0x16;
            
            if (rdi == -1)
            {
                rbx_1 = nullptr;
                goto label_18000c682;
            }
            
            if (rdi + 1 < 0x1000)
            {
                rbx_1 = sub_180016420(rdi + 1);
                goto label_18000c682;
            }
            
            rcx_2 = rdi + 0x28;
            
            if (rcx_2 > rdi + 1)
                goto label_18000c627;
            
            stdext::threads::_Throw_lock_error();
            /* no return */
        }
        
        rcx_2 = -0x7fffffffffffffd9;
    label_18000c627:
        int64_t rax_4 = sub_180016420(rcx_2);
        
        if (rax_4)
        {
            rbx_1 = (rax_4 + 0x27) & 0xffffffffffffffe0;
            *(rbx_1 - 8) = rax_4;
        label_18000c682:
            var_148 = rbx_1;
            var_138_1 = r14;
            var_130_1 = rdi;
            memcpy(rbx_1, r15, r14 + 1);
            goto label_18000c6a0;
        }
    }
    else
    {
        var_138_1 = r14;
        rdi = 0xf;
        var_130_1 = 0xf;
        int128_t zmm0_1 = *r15;
        var_148 = zmm0_1;
        rbx_1 = zmm0_1;
    label_18000c6a0:
        int128_t* rax_7 = &var_148;
        
        if (rdi > 0xf)
            rax_7 = rbx_1;
        
        int128_t* rdx_1 = &var_148;
        
        if (rdi > 0xf)
            rdx_1 = rbx_1;
        
        void* rdx_2 = rdx_1 + r14;
        
        if (rax_7 != rdx_2)
        {
            do
            {
                if (*rax_7 == 0x2f)
                    *rax_7 = 0x2e;
                
                rax_7 += 1;
            } while (rax_7 != rdx_2);
            
            rdi = var_130_1;
            r14 = var_138_1;
            rbx_1 = var_148;
        }
        
        int128_t var_208;
        int128_t* var_178 = &var_208;
        __builtin_memset(&var_208, 0, 0x20);
        void* rax_8 = sub_180016420(0x30);
        var_208 = rax_8;
        int64_t var_1f8_1 = 0x25;
        int64_t var_1f0_1 = 0x2f;
        __builtin_strncpy(rax_8, "io/netty/channel/ChannelDuplexHa", 0x20);
        *(rax_8 + 0x1d) = 0x72656c646e614878;
        *(rax_8 + 0x25) = 0;
        int128_t var_1e8;
        void var_108;
        sub_180004930(&var_108, sub_1800029d0(&var_1e8, &var_168), &var_208, 0x34);
        char const* const var_228 = &data_180030c10;
        int64_t var_220_1 = 3;
        var_178 = "<init>";
        int64_t var_170_1 = 6;
        char const* const var_218 = "io/netty/channel/ChannelDuplexHandler";
        int64_t var_210_1 = 0x25;
        uint16_t rax_10 = sub_180006080(&var_108, &var_218, &var_178, &var_228);
        var_178 = 0xb72a;
        *(&var_178 + 2) = (rax_10 >> 8);
        *(&var_178 + 3) = rax_10;
        *(&var_178 + 4) = 0xb1;
        int32_t* rax_11 = sub_180016420(5);
        var_208 = rax_11;
        void* var_1f8_2 = rax_11 + 5;
        *rax_11 = var_178;
        rax_11[1] = *(&var_178 + 4);
        *(&var_208 + 8) = rax_11 + 5;
        __builtin_memset(&var_1e8, 0, 0x18);
        int32_t* rax_12 = sub_180016420(5);
        var_1e8 = rax_12;
        *(&var_1e8 + 8) = rax_12;
        void* var_1d8_1 = rax_12 + 5;
        *rax_12 = *rax_11;
        rax_12[1] = rax_11[1];
        *(&var_1e8 + 8) = rax_12 + 5;
        var_218 = &data_180030c10;
        int64_t var_210_2 = 3;
        var_228 = "<init>";
        int64_t var_220_2 = 6;
        int16_t var_238_1 = 1;
        sub_1800052c0(&var_108, &var_228, &var_218, 1, &var_1e8, 1);
        var_218 = "(Lio/netty/channel/ChannelHandlerContext;Ljava/lang/Object;)V";
        int64_t var_210_3 = 0x3d;
        var_228 = "channelRead";
        int64_t var_220_3 = 0xb;
        sub_180005820(&var_108, &var_228, &var_218, 0x101);
        var_218 = "(Lio/netty/channel/ChannelHandlerContext;Ljava/lang/Object;"
        "Lio/netty/channel/ChannelPromise;)V";
        int64_t var_210_4 = 0x5e;
        var_228 = "write";
        int64_t var_220_4 = 5;
        sub_180005820(&var_108, &var_228, &var_218, 0x101);
        void* var_1c8;
        int512_t zmm2_1 = sub_180005940(&var_108, &var_1c8);
        void* r10_1 = var_1c8;
        int64_t* rdx_11 = &var_168;
        
        if (var_150 > 0xf)
            rdx_11 = var_168;
        
        int32_t* var_248_1;
        int32_t var_1c0;
        var_248_1 = var_1c0 - r10_1;
        int64_t rax_14 = (*(*arg1 + 0x28))(arg1, rdx_11, arg2, r10_1, var_248_1);
        int64_t* rsi;
        
        if (rax_14)
        {
            char const* const var_1b0 = "channelRead";
            char const* const var_1a8_1 =
                "(Lio/netty/channel/ChannelHandlerContext;Ljava/lang/Object;)V";
            int64_t (* var_1a0_1)(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4) =
                sub_18000b810;
            char const* const var_198_1 = "write";
            char const* const var_190_1 = "(Lio/netty/channel/ChannelHandlerContext;"
            "Ljava/lang/Object;Lio/netty/channel/ChannelPromise;)V";
            int64_t (* var_188_1)(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, 
                int64_t arg5) = sub_18000b930;
            int64_t* rcx_19 = arg1;
            char const* const rdx_13;
            
            if (!(*(*arg1 + 0x6b8))(arg1, rax_14, &var_1b0, 2))
            {
                int128_t* rax_18 = (*(*arg1 + 0x108))(rcx_19, rax_14, "<init>", &data_180030c10);
                var_178 = rax_18;
                rcx_19 = arg1;
                
                if (!rax_18)
                {
                    rdx_13 = "InstallRelayHandler/ctor";
                    goto label_18000ca05;
                }
                
                data_180046090 = (*(*arg1 + 0xa8))(rcx_19, rax_14);
                data_180046098 = var_178;
                int64_t rdx_17 = data_1800460b8;
                
                if (rdx_17 > 0xf)
                {
                    void* rcx_21 = data_1800460a0;
                    
                    if (rdx_17 + 1 >= 0x1000)
                    {
                        void* rax_23 = *(rcx_21 - 8);
                        
                        if (rcx_21 - rax_23 - 8 > 0x1f)
                            trap(0xd);
                        
                        rcx_21 = rax_23;
                    }
                    
                    j_sub_180021340(rcx_21);
                }
                
                data_1800460a0 = var_168;
                int64_t var_160;
                data_1800460a8 = var_160;
                data_1800460b0 = var_158;
                data_1800460b8 = var_150;
                int64_t var_158_1 = 0;
                var_150 = 0xf;
                var_168 = 0;
                int64_t rdx_20 = data_1800460d8;
                
                if (rdx_20 > 0xf)
                {
                    void* rcx_24 = data_1800460c0;
                    
                    if (rdx_20 + 1 >= 0x1000)
                    {
                        void* rax_28 = *(rcx_24 - 8);
                        
                        if (rcx_24 - rax_28 - 8 > 0x1f)
                            trap(0xd);
                        
                        rcx_24 = rax_28;
                    }
                    
                    j_sub_180021340(rcx_24);
                }
                
                data_1800460c0 = rbx_1;
                data_1800460c8 = *(&var_148 + 8);
                data_1800460d0 = r14;
                data_1800460d8 = rdi;
                int64_t var_138_2 = 0;
                rdi = 0xf;
                int64_t var_130_2 = 0xf;
                var_148 = 0;
                (*(*arg1 + 0xb8))(arg1, rax_14);
                rsi = 1;
                rbx_1 = var_148;
            }
            else
            {
                rdx_13 = "InstallRelayHandler/RegisterNatives";
            label_18000ca05:
                sub_180002210(rcx_19, rdx_13, zmm2_1);
                (*(*arg1 + 0xb8))(arg1, rax_14);
                rsi = 0;
            }
        }
        else
        {
            sub_180002210(arg1, "InstallRelayHandler/DefineClass", zmm2_1);
            rsi = 0;
        }
        
        void* rax_31 = var_1c8;
        
        if (rax_31)
        {
            int64_t var_1b8;
            void* rcx_28;
            
            if (var_1b8 - rax_31 < 0x1000)
                rcx_28 = rax_31;
            else
            {
                rcx_28 = *(rax_31 - 8);
                
                if (rax_31 - rcx_28 - 8 > 0x1f)
                    trap(0xd);
            }
            
            j_sub_180021340(rcx_28);
            __builtin_memset(&var_1c8, 0, 0x18);
        }
        
        int32_t* rcx_31;
        
        if (5 < 0x1000)
            rcx_31 = rax_11;
        else
        {
            rcx_31 = *(rax_11 - 8);
            
            if (rax_11 - rcx_31 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_31);
        sub_18000ab00(&var_108);
        
        if (rdi <= 0xf)
            goto label_18000cc22;
        
        if (rdi + 1 < 0x1000)
            goto label_18000cc14;
        
        int128_t* rax_34 = *(rbx_1 - 8);
        
        if (rbx_1 - rax_34 - 8 <= 0x1f)
        {
            rbx_1 = rax_34;
        label_18000cc14:
            j_sub_180021340(rbx_1);
        label_18000cc22:
            
            if (var_150 > 0xf)
            {
                int64_t* rcx_35 = var_168;
                
                if (var_150 + 1 >= 0x1000)
                {
                    int64_t* rax_35 = rcx_35[-1];
                    
                    if (rcx_35 - rax_35 - 8 > 0x1f)
                        trap(0xd);
                    
                    rcx_35 = rax_35;
                }
                
                j_sub_180021340(rcx_35);
            }
            
            int64_t var_158_2 = 0;
            int64_t var_150_1 = 0xf;
            var_168 = 0;
            int64_t var_110;
            
            if (var_110 > 0xf)
            {
                void* rcx_38 = var_128;
                
                if (var_110 + 1 >= 0x1000)
                {
                    void* rax_36 = *(rcx_38 - 8);
                    
                    if (rcx_38 - rax_36 - 8 > 0x1f)
                        trap(0xd);
                    
                    rcx_38 = rax_36;
                }
                
                j_sub_180021340(rcx_38);
            }
            
            __security_check_cookie(rax_1 ^ &var_268);
            return rsi;
        }
    }
    trap(0xd);
}

