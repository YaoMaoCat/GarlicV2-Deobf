
  uint64_t sub_180012620(int64_t* arg1, int64_t arg2)

{
    void var_228;
    uint64_t var_48 = __security_cookie ^ &var_228;
    uint64_t result;
    
    if (!data_180046260 || !data_180046268)
    {
        void* var_128;
        sub_180002e20(&var_128, 2, 3);
        sub_1800033a0();
        int64_t* var_148;
        sub_180003410(&var_148, &data_180046008, &var_128);
        int128_t var_1c8;
        int128_t* var_158 = &var_1c8;
        __builtin_memset(&var_1c8, 0, 0x20);
        int64_t rax_1 = sub_180016420(0x20);
        var_1c8 = rax_1;
        int64_t var_1b8_1 = 0x10;
        int64_t var_1b0_1 = 0x1f;
        __builtin_strncpy(rax_1, "java/lang/Thread", 0x11);
        int128_t var_1a8;
        void var_108;
        sub_180004930(&var_108, sub_1800029d0(&var_1a8, &var_148), &var_1c8, 0x34);
        char const* const var_1e8 = &data_180030c10;
        int64_t var_1e0_1 = 3;
        var_158 = "<init>";
        int64_t var_150_1 = 6;
        char const* const var_1d8 = "java/lang/Thread";
        int64_t var_1d0_1 = 0x10;
        uint16_t rax_3 = sub_180006080(&var_108, &var_1d8, &var_158, &var_1e8);
        var_158 = 0xb72a;
        *(&var_158 + 2) = (rax_3 >> 8);
        *(&var_158 + 3) = rax_3;
        *(&var_158 + 4) = 0xb1;
        int32_t* rax_4 = sub_180016420(5);
        var_1c8 = rax_4;
        void* var_1b8_2 = rax_4 + 5;
        *rax_4 = var_158;
        rax_4[1] = *(&var_158 + 4);
        *(&var_1c8 + 8) = rax_4 + 5;
        __builtin_memset(&var_1a8, 0, 0x18);
        int32_t* rax_5 = sub_180016420(5);
        var_1a8 = rax_5;
        *(&var_1a8 + 8) = rax_5;
        void* var_198_1 = rax_5 + 5;
        *rax_5 = *rax_4;
        rax_5[1] = rax_4[1];
        *(&var_1a8 + 8) = rax_5 + 5;
        var_1d8 = &data_180030c10;
        int64_t var_1d0_2 = 3;
        var_1e8 = "<init>";
        int64_t var_1e0_2 = 6;
        int16_t var_1f8_1 = 1;
        sub_1800052c0(&var_108, &var_1e8, &var_1d8, 1, &var_1a8, 1);
        var_1d8 = &data_180030c10;
        int64_t var_1d0_3 = 3;
        var_1e8 = &data_18003274c;
        int64_t var_1e0_3 = 3;
        sub_180005820(&var_108, &var_1e8, &var_1d8, 0x101);
        void* var_188;
        int512_t zmm2_1 = sub_180005940(&var_108, &var_188);
        void* r10_1 = var_188;
        int64_t* rdx_7 = &var_148;
        int64_t var_130;
        
        if (var_130 > 0xf)
            rdx_7 = var_148;
        
        int32_t* var_208_1;
        int32_t var_180;
        var_208_1 = var_180 - r10_1;
        int64_t rax_7 = (*(*arg1 + 0x28))(arg1, rdx_7, arg2, r10_1, var_208_1);
        int64_t* rbx;
        
        if (rax_7)
        {
            void* const var_170 = &data_18003274c;
            void* const var_168_1 = &data_180030c10;
            int64_t (* var_160_1)() = sub_18000ec30;
            
            if (!(*(*arg1 + 0x6b8))(arg1, rax_7, &var_170, 1))
            {
                data_180046268 = (*(*arg1 + 0x108))(arg1, rax_7, "<init>", &data_180030c10);
                data_180046260 = (*(*arg1 + 0xa8))(arg1, rax_7);
                (*(*arg1 + 0xb8))(arg1, rax_7);
                
                if (!data_180046268 || !data_180046260)
                {
                    sub_180002210(arg1, "BServer/MainGateCtor", zmm2_1);
                    rbx = 0;
                }
                else
                {
                    int64_t* rdx_14 = &var_148;
                    
                    if (var_130 > 0xf)
                        rdx_14 = var_148;
                    
                    sub_1800023a0("BServer: defined A main-thread gate as %s", rdx_14);
                    rbx = 1;
                }
            }
            else
            {
                sub_180002210(arg1, "BServer/RegisterMainGate", zmm2_1);
                (*(*arg1 + 0xb8))(arg1, rax_7);
                rbx = 0;
            }
        }
        else
        {
            sub_180002210(arg1, "BServer/DefineMainGate", zmm2_1);
            rbx = 0;
        }
        
        void* rax_16 = var_188;
        
        if (rax_16)
        {
            int64_t var_178;
            void* rcx_19;
            
            if (var_178 - rax_16 < 0x1000)
                rcx_19 = rax_16;
            else
            {
                rcx_19 = *(rax_16 - 8);
                
                if (rax_16 - rcx_19 - 8 > 0x1f)
                    trap(0xd);
            }
            
            j_sub_180021340(rcx_19);
            __builtin_memset(&var_188, 0, 0x18);
        }
        
        int32_t* rcx_21;
        
        if (5 < 0x1000)
            rcx_21 = rax_4;
        else
        {
            rcx_21 = *(rax_4 - 8);
            
            if (rax_4 - rcx_21 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_21);
        sub_18000ab00(&var_108);
        
        if (var_130 > 0xf)
        {
            int64_t* rcx_24 = var_148;
            
            if (var_130 + 1 >= 0x1000)
            {
                int64_t* rax_19 = rcx_24[-1];
                
                if (rcx_24 - rax_19 - 8 > 0x1f)
                    trap(0xd);
                
                rcx_24 = rax_19;
            }
            
            j_sub_180021340(rcx_24);
        }
        
        int64_t var_138_1 = 0;
        int64_t var_130_1 = 0xf;
        var_148 = 0;
        int64_t var_110;
        
        if (var_110 > 0xf)
        {
            void* rcx_27 = var_128;
            
            if (var_110 + 1 >= 0x1000)
            {
                void* rax_20 = *(rcx_27 - 8);
                
                if (rcx_27 - rax_20 - 8 > 0x1f)
                    trap(0xd);
                
                rcx_27 = rax_20;
            }
            
            j_sub_180021340(rcx_27);
        }
        
        result = rbx;
    }
    else
        result = 1;
    
    __security_check_cookie(var_48 ^ &var_228);
    return result;
}

