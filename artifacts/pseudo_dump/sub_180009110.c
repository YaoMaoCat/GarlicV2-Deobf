
  int64_t* sub_180009110(int64_t* arg1, int64_t* arg2, int64_t* arg3, int16_t arg4, int32_t* arg5, uint16_t arg6)

{
    uint128_t zmm6;
    uint128_t var_48 = zmm6;
    void var_1c8;
    int64_t rax_1 = __security_cookie ^ &var_1c8;
    int16_t r13 = arg4;
    int64_t* result = arg2;
    int64_t* var_88 = arg2;
    int32_t* r12 = arg5;
    int32_t* var_88_1 = r12;
    int32_t r14 = 0;
    int32_t var_1a0 = 0;
    char* r9 = *arg3;
    
    if (arg3[1] - r9 >= 2)
    {
        uint16_t rcx_1 = *r9;
        uint16_t i = r9[1] | rcx_1 << 8;
        char* rdi_1 = &r9[2];
        char* var_b0_1 = rdi_1;
        int128_t var_150;
        __builtin_memset(&var_150, 0, 0x18);
        uint8_t var_1a8 = rcx_1;
        sub_180006510(&var_150, &var_1a8);
        var_1a8 = i;
        sub_180006510(&var_150, &var_1a8);
        int32_t var_120_1 = 0;
        
        if (0 < i)
        {
            int32_t rdx_88;
            
            do
            {
                uint16_t rsi_1 = rdi_1[1] | *rdi_1 << 8;
                uint64_t r15_6 = ((rdi_1[3] | rdi_1[2] << 8) << 8 | rdi_1[4]) << 8 | rdi_1[5];
                
                if (rsi_1 == r13)
                {
                    uint16_t r8_3 = rdi_1[7] | rdi_1[6] << 8;
                    uint16_t rcx_11 = rdi_1[9] | rdi_1[8] << 8;
                    uint64_t rcx_17 =
                        ((rdi_1[0xb] | rdi_1[0xa] << 8) << 8 | rdi_1[0xc]) << 8 | rdi_1[0xd];
                    uint64_t rax_21 = rcx_17;
                    int128_t* var_98_1 = rax_21;
                    void* rdx_10 = &rdi_1[rcx_17];
                    uint64_t rsi_2 = rdi_1[rcx_17 + 0xf] | rdi_1[rax_21 + 0xe] << 8;
                    uint64_t var_b8_1 = rsi_2;
                    uint16_t rcx_19 = *(rdx_10 + (rsi_2 << 3) + 0x10);
                    uint16_t j = *(rdx_10 + (rsi_2 << 3) + 0x11) | rcx_19 << 8;
                    char* r15_8 = rdx_10 + 0x12 + (rsi_2 << 3);
                    char* var_a0_1 = r15_8;
                    int32_t r13_2 = r12[2] - *r12;
                    
                    if (arg6 > r8_3)
                        r8_3 = arg6;
                    
                    int128_t var_e8;
                    __builtin_memset(&var_e8, 0, 0x18);
                    var_1a8 = rcx_19;
                    sub_180006510(&var_e8, &var_1a8);
                    var_1a8 = j;
                    sub_180006510(&var_e8, &var_1a8);
                    int32_t var_17c_1 = 0;
                    
                    if (0 < j)
                    {
                        int32_t rcx_68;
                        
                        do
                        {
                            uint16_t r12_1 = r15_8[1];
                            uint16_t rbx = *r15_8;
                            uint64_t r13_8 =
                                ((r15_8[3] | r15_8[2] << 8) << 8 | r15_8[4]) << 8 | r15_8[5];
                            zmm6 = {0};
                            uint128_t var_d0;
                            __builtin_memset(&var_d0, 0, 0x18);
                            void* var_c0_1;
                            int128_t* rsi_4;
                            void* rdi_2;
                            
                            if (!r13_8)
                            {
                                rdi_2 = _mm_bsrli_si128({0}, 8);
                                rsi_4 = zmm6;
                            }
                            else
                            {
                                if (r13_8 < 0x1000)
                                    rsi_4 = sub_180016420(r13_8);
                                else
                                {
                                    if (r13_8 + 0x27 <= r13_8)
                                    {
                                        stdext::threads::_Throw_lock_error();
                                        /* no return */
                                    }
                                    
                                    int64_t rax_28 = sub_180016420(r13_8 + 0x27);
                                    
                                    if (!rax_28)
                                        goto label_18000a100;
                                    
                                    rsi_4 = (rax_28 + 0x27) & 0xffffffffffffffe0;
                                    *(rsi_4 - 8) = rax_28;
                                }
                                
                                var_d0 = rsi_4;
                                rdi_2 = rsi_4 + r13_8;
                                var_c0_1 = rdi_2;
                                memcpy(rsi_4, &r15_8[6], r13_8);
                                void* var_c8_1 = rdi_2;
                                zmm6 = var_d0;
                            }
                            
                            r12_1 |= rbx << 8;
                            int64_t* var_70;
                            sub_180008240(arg1, &var_70, r12_1);
                            uint128_t var_118;
                            __builtin_memset(&var_118, 0, 0x18);
                            void* r15_9 = nullptr;
                            int64_t* rcx_26 = &var_70;
                            int64_t* r12_2 = var_70;
                            int64_t var_58;
                            
                            if (var_58 > 0xf)
                                rcx_26 = r12_2;
                            
                            int64_t var_60;
                            int32_t* rbx_12;
                            int64_t rdi_7;
                            uint128_t var_138;
                            uint128_t zmm1_1;
                            
                            if (var_60 != 0xd)
                            {
                            label_1800098f9:
                                int64_t* rcx_51 = &var_70;
                                
                                if (var_58 > 0xf)
                                    rcx_51 = r12_2;
                                
                                if (var_60 != 0xf)
                                {
                                label_1800099c4:
                                    int64_t* rcx_55 = &var_70;
                                    
                                    if (var_58 > 0xf)
                                        rcx_55 = r12_2;
                                    
                                    if (var_60 == 0x12
                                        && !memcmp(rcx_55, "LocalVariableTable", var_60))
                                    {
                                    label_180009a1b:
                                        int32_t** rax_61 = sub_18000a820(&var_138, &var_d0, r13_2);
                                        
                                        if (&var_118 == rax_61)
                                            goto label_18000996b;
                                        
                                        rbx_12 = *rax_61;
                                        var_118 = rbx_12;
                                        rdi_7 = rax_61[1];
                                        *(&var_118 + 8) = rdi_7;
                                        r15_9 = rax_61[2];
                                        void* var_108_3 = r15_9;
                                        __builtin_memset(rax_61, 0, 0x18);
                                        goto label_180009973;
                                    }
                                    
                                    int64_t* rcx_56 = &var_70;
                                    
                                    if (var_58 > 0xf)
                                        rcx_56 = r12_2;
                                    
                                    if (var_60 == 0x16
                                            && !memcmp(rcx_56, "LocalVariableTypeTable", var_60))
                                        goto label_180009a1b;
                                    
                                    var_118 = zmm6;
                                    zmm1_1 = var_c0_1;
                                    uint64_t var_108_4 = zmm1_1;
                                    __builtin_memset(&var_d0, 0, 0x18);
                                    rsi_4 = nullptr;
                                    r15_9 = zmm1_1;
                                    rbx_12 = zmm6;
                                    rdi_7 = _mm_bsrli_si128(zmm6, 8);
                                }
                                else
                                {
                                    if (memcmp(rcx_51, "LineNumberTable", var_60))
                                        goto label_1800099c4;
                                    
                                    int32_t** rax_55 = sub_18000a650(&var_138, &var_d0, r13_2);
                                    
                                    if (&var_118 == rax_55)
                                    {
                                    label_18000996b:
                                        rdi_7 = *(&var_118 + 8);
                                        rbx_12 = var_118;
                                        goto label_180009973;
                                    }
                                    
                                    rbx_12 = *rax_55;
                                    var_118 = rbx_12;
                                    rdi_7 = rax_55[1];
                                    *(&var_118 + 8) = rdi_7;
                                    r15_9 = rax_55[2];
                                    void* var_108_2 = r15_9;
                                    __builtin_memset(rax_55, 0, 0x18);
                                label_180009973:
                                    void* rax_56 = var_138;
                                    int64_t var_128;
                                    
                                    if (!rax_56)
                                        rsi_4 = var_d0;
                                    else if (var_128 - rax_56 < 0x1000)
                                    {
                                        j_sub_180021340(rax_56);
                                        rsi_4 = var_d0;
                                    }
                                    else
                                    {
                                        int64_t rcx_53 = *(rax_56 - 8);
                                        
                                        if (rax_56 - rcx_53 - 8 > 0x1f)
                                            trap(0xd);
                                        
                                        j_sub_180021340(rcx_53);
                                        rsi_4 = var_d0;
                                    }
                                }
                            }
                            else
                            {
                                if (memcmp(rcx_26, "StackMapTable", var_60))
                                    goto label_1800098f9;
                                
                                uint64_t rbx_3;
                                bool cond:0_1;
                                
                                if (rsi_4 != rdi_2)
                                {
                                    rbx_3 = rdi_2 - rsi_4;
                                    
                                    if (rbx_3 < 2)
                                    {
                                        r15_9 = nullptr;
                                        cond:0_1 = !rbx_3;
                                        goto label_180009510;
                                    }
                                    
                                    if (!(*rsi_4 << 8 | *(rsi_4 + 1)))
                                    {
                                        r15_9 = nullptr;
                                        cond:0_1 = !rbx_3;
                                        goto label_180009510;
                                    }
                                    
                                    uint32_t r15_10 = *(rsi_4 + 2);
                                    var_1a8 = r15_10;
                                    int128_t var_198;
                                    __builtin_memset(&var_198, 0, 0x18);
                                    void* var_188_1;
                                    
                                    if (rbx_3 != -3)
                                    {
                                        if (rbx_3 + 3 > 0x7fffffffffffffff)
                                        {
                                            sub_1800052a0();
                                            /* no return */
                                        }
                                        
                                        int128_t* r14_4;
                                        
                                        if (rbx_3 + 3 < 0x1000)
                                            r14_4 = sub_180016420(rbx_3 + 3);
                                        else
                                        {
                                            if (rbx_3 + 0x2a <= rbx_3 + 3)
                                            {
                                                stdext::threads::_Throw_lock_error();
                                                /* no return */
                                            }
                                            
                                            int64_t rax_35 = sub_180016420(rbx_3 + 0x2a);
                                            
                                            if (!rax_35)
                                                trap(0xd);
                                            
                                            r14_4 = (rax_35 + 0x27) & 0xffffffffffffffe0;
                                            *(r14_4 - 8) = rax_35;
                                        }
                                        
                                        int32_t* rdx_16 = var_198;
                                        memcpy(r14_4, rdx_16, *(&var_198 + 8) - rdx_16);
                                        void* rcx_34 = var_198;
                                        
                                        if (rcx_34)
                                        {
                                            void* rax_37;
                                            
                                            if (var_188_1 - rcx_34 < 0x1000)
                                                rax_37 = rcx_34;
                                            else
                                            {
                                                rax_37 = *(rcx_34 - 8);
                                                
                                                if (rcx_34 - rax_37 - 8 > 0x1f)
                                                    trap(0xd);
                                            }
                                            
                                            j_sub_180021340(rax_37);
                                        }
                                        
                                        var_198 = r14_4;
                                        *(&var_198 + 8) = r14_4;
                                        var_188_1 = rbx_3 + 3 + r14_4;
                                    }
                                    
                                    sub_180006510(&var_198, rsi_4);
                                    sub_180006510(&var_198, rsi_4 + 1);
                                    int32_t* r14_5 = rsi_4 + 3;
                                    int64_t* rcx_40;
                                    uint8_t* rdx_22;
                                    int32_t rbx_5;
                                    
                                    if (r15_10 <= 0x3f)
                                    {
                                        rbx_5 = r15_10 + r13_2;
                                        rdx_22 = &var_1a8;
                                        rcx_40 = &var_198;
                                        
                                        if (rbx_5 <= 0x3f)
                                            goto label_180009706;
                                        
                                        var_1a8 = 0xfb;
                                    label_1800096df:
                                        sub_180006510(rcx_40, rdx_22);
                                        var_1a8 = rbx_5 >> 8;
                                        sub_180006510(&var_198, &var_1a8);
                                        rdx_22 = &var_1a8;
                                        rcx_40 = &var_198;
                                    label_180009706:
                                        var_1a8 = rbx_5;
                                        sub_180006510(rcx_40, rdx_22);
                                        goto label_1800097db;
                                    }
                                    
                                    if (r15_10 - 0x40 > 0x3f)
                                    {
                                        if (r15_10 == 0xf7 || r15_10 + 8 <= 2 || r15_10 == 0xfb
                                            || r15_10 + 4 <= 2 || r15_10 == 0xff)
                                        {
                                            int32_t rbx_11 = (*r14_5 << 8 | *(rsi_4 + 4)) + r13_2;
                                            sub_180006510(&var_198, &var_1a8);
                                            var_1a8 = rbx_11 >> 8;
                                            sub_180006510(&var_198, &var_1a8);
                                            var_1a8 = rbx_11;
                                            sub_180006510(&var_198, &var_1a8);
                                            r14_5 = rsi_4 + 5;
                                            goto label_1800097db;
                                        }
                                        
                                        var_138 = {0};
                                        r15_9 = nullptr;
                                        
                                        if (rbx_3)
                                        {
                                            if (rbx_3 > 0x7fffffffffffffff)
                                            {
                                                sub_1800052a0();
                                                /* no return */
                                            }
                                            
                                            int128_t* r14_7;
                                            
                                            if (rbx_3 < 0x1000)
                                                r14_7 = sub_180016420(rbx_3);
                                            else
                                            {
                                                if (rbx_3 + 0x27 <= rbx_3)
                                                {
                                                    stdext::threads::_Throw_lock_error();
                                                    /* no return */
                                                }
                                                
                                                int64_t rax_48 = sub_180016420(rbx_3 + 0x27);
                                                
                                                if (!rax_48)
                                                    trap(0xd);
                                                
                                                r14_7 = (rax_48 + 0x27) & 0xffffffffffffffe0;
                                                *(r14_7 - 8) = rax_48;
                                            }
                                            
                                            var_138 = r14_7;
                                            r15_9 = r14_7 + rbx_3;
                                            void* rdi_5 = rdi_2 - rsi_4;
                                            memcpy(r14_7, rsi_4, rdi_5);
                                            *(&var_138 + 8) = rdi_5 + r14_7;
                                        }
                                        
                                        void* rax_51 = var_198;
                                        
                                        if (!rax_51)
                                            r14 = var_1a0;
                                        else
                                        {
                                            void* rcx_50;
                                            
                                            if (var_188_1 - rax_51 < 0x1000)
                                                rcx_50 = rax_51;
                                            else
                                            {
                                                rcx_50 = *(rax_51 - 8);
                                                
                                                if (rax_51 - rcx_50 - 8 > 0x1f)
                                                    trap(0xd);
                                            }
                                            
                                            j_sub_180021340(rcx_50);
                                            r14 = var_1a0;
                                        }
                                    }
                                    else
                                    {
                                        rbx_5 = r13_2 - 0x40 + r15_10;
                                        rdx_22 = &var_1a8;
                                        rcx_40 = &var_198;
                                        
                                        if (rbx_5 > 0x3f)
                                        {
                                            var_1a8 = 0xf7;
                                            goto label_1800096df;
                                        }
                                        
                                        rbx_5 += 0x40;
                                        var_1a8 = rbx_5;
                                        sub_180006510(rcx_40, rdx_22);
                                    label_1800097db:
                                        sub_1800045a0(&var_198, *(&var_198 + 8), r14_5, 
                                            rdi_2 - r14_5);
                                        r15_9 = var_188_1;
                                        int64_t rcx_46 = *(&var_198 + 8);
                                        int64_t rax_47 = var_198;
                                        __builtin_memset(&var_198, 0, 0x18);
                                        var_138 = rax_47;
                                        *(&var_138 + 8) = rcx_46;
                                        r14 = var_1a0;
                                    }
                                }
                                else
                                {
                                    rbx_3 = rdi_2 - rsi_4;
                                    cond:0_1 = rdi_2 == rsi_4;
                                label_180009510:
                                    var_138 = {0};
                                    
                                    if (!cond:0_1)
                                    {
                                        if (rbx_3 > 0x7fffffffffffffff)
                                        {
                                            sub_1800052a0();
                                            /* no return */
                                        }
                                        
                                        int128_t* r14_2;
                                        
                                        if (rbx_3 < 0x1000)
                                            r14_2 = sub_180016420(rbx_3);
                                        else
                                        {
                                            if (rbx_3 + 0x27 <= rbx_3)
                                            {
                                                stdext::threads::_Throw_lock_error();
                                                /* no return */
                                            }
                                            
                                            int64_t rax_31 = sub_180016420(rbx_3 + 0x27);
                                            
                                            if (!rax_31)
                                                trap(0xd);
                                            
                                            r14_2 = (rax_31 + 0x27) & 0xffffffffffffffe0;
                                            *(r14_2 - 8) = rax_31;
                                        }
                                        
                                        var_138 = r14_2;
                                        r15_9 = r14_2 + rbx_3;
                                        void* rdi_3 = rdi_2 - rsi_4;
                                        memcpy(r14_2, rsi_4, rdi_3);
                                        *(&var_138 + 8) = rdi_3 + r14_2;
                                        r14 = var_1a0;
                                    }
                                }
                                zmm1_1 = var_138;
                                var_118 = zmm1_1;
                                void* var_108_1 = r15_9;
                                var_1a0 = r14 | 2;
                                rbx_12 = zmm1_1;
                                rdi_7 = _mm_bsrli_si128(zmm1_1, 8);
                            }
                            var_1a8 = (r12_1 >> 8);
                            sub_180006510(&var_e8, &var_1a8);
                            var_1a8 = r12_1;
                            sub_180006510(&var_e8, &var_1a8);
                            int32_t r14_11 = rdi_7 - rbx_12;
                            var_1a8 = r14_11 >> 0x18;
                            sub_180006510(&var_e8, &var_1a8);
                            var_1a8 = r14_11 >> 0x10;
                            sub_180006510(&var_e8, &var_1a8);
                            var_1a8 = r14_11 >> 8;
                            sub_180006510(&var_e8, &var_1a8);
                            var_1a8 = r14_11;
                            sub_180006510(&var_e8, &var_1a8);
                            sub_1800045a0(&var_e8, *(&var_e8 + 8), rbx_12, rdi_7 - rbx_12);
                            
                            if (rbx_12)
                            {
                                int32_t* rcx_65;
                                
                                if (r15_9 - rbx_12 < 0x1000)
                                    rcx_65 = rbx_12;
                                else
                                {
                                    rcx_65 = *(rbx_12 - 8);
                                    
                                    if (rbx_12 - rcx_65 - 8 > 0x1f)
                                        trap(0xd);
                                }
                                
                                j_sub_180021340(rcx_65);
                            }
                            
                            if (var_58 > 0xf)
                            {
                                if (var_58 + 1 >= 0x1000)
                                {
                                    int64_t* rax_70 = r12_2[-1];
                                    
                                    if (r12_2 - rax_70 - 8 > 0x1f)
                                        trap(0xd);
                                    
                                    r12_2 = rax_70;
                                }
                                
                                j_sub_180021340(r12_2);
                            }
                            
                            if (rsi_4)
                            {
                                int128_t* rcx_67;
                                
                                if (var_c0_1 - rsi_4 < 0x1000)
                                    rcx_67 = rsi_4;
                                else
                                {
                                    rcx_67 = *(rsi_4 - 8);
                                    
                                    if (rsi_4 - rcx_67 - 8 > 0x1f)
                                        goto label_18000a100;
                                }
                                
                                j_sub_180021340(rcx_67);
                            }
                            
                            r15_8 = &var_a0_1[6 + r13_8];
                            var_a0_1 = r15_8;
                            rcx_68 = var_17c_1 + 1;
                            var_17c_1 = rcx_68;
                            r14 = var_1a0;
                        } while (rcx_68 < j);
                        rdi_1 = var_b0_1;
                        rsi_2 = var_b8_1;
                    }
                    
                    char* r12_7 = &var_98_1[1] + rdi_1;
                    int32_t rbx_15 = var_98_1 + r13_2;
                    int128_t var_100;
                    __builtin_memset(&var_100, 0, 0x18);
                    var_1a8 = (rsi_2 >> 8);
                    sub_180006510(&var_100, &var_1a8);
                    var_1a8 = rsi_2;
                    sub_180006510(&var_100, &var_1a8);
                    
                    if (0 < rsi_2)
                    {
                        int16_t j_1;
                        
                        do
                        {
                            uint16_t rcx_71 = r12_7[1] | *r12_7 << 8;
                            uint16_t rdi_9 = r12_7[3] | r12_7[2] << 8;
                            uint16_t rsi_7 = r12_7[5] | r12_7[4] << 8;
                            uint16_t r14_12 = r12_7[6];
                            uint16_t r15_14 = r12_7[7] | r14_12 << 8;
                            r12_7 = &r12_7[8];
                            uint16_t rbx_16 = rcx_71 + r13_2;
                            var_1a8 = (rbx_16 >> 8);
                            sub_180006510(&var_100, &var_1a8);
                            var_1a8 = rbx_16;
                            sub_180006510(&var_100, &var_1a8);
                            uint16_t rbx_17 = rdi_9 + r13_2;
                            var_1a8 = (rbx_17 >> 8);
                            sub_180006510(&var_100, &var_1a8);
                            var_1a8 = rbx_17;
                            sub_180006510(&var_100, &var_1a8);
                            uint16_t rbx_18 = rsi_7 + r13_2;
                            var_1a8 = (rbx_18 >> 8);
                            sub_180006510(&var_100, &var_1a8);
                            var_1a8 = rbx_18;
                            sub_180006510(&var_100, &var_1a8);
                            var_1a8 = r14_12;
                            sub_180006510(&var_100, &var_1a8);
                            var_1a8 = r15_14;
                            sub_180006510(&var_100, &var_1a8);
                            j_1 = var_b8_1;
                            var_b8_1 -= 1;
                        } while (j_1 != 1);
                        rdi_1 = var_b0_1;
                    }
                    
                    int128_t var_178;
                    __builtin_memset(&var_178, 0, 0x18);
                    var_1a8 = (r8_3 >> 8);
                    sub_180006510(&var_178, &var_1a8);
                    var_1a8 = r8_3;
                    sub_180006510(&var_178, &var_1a8);
                    var_1a8 = (rcx_11 >> 8);
                    sub_180006510(&var_178, &var_1a8);
                    var_1a8 = rcx_11;
                    sub_180006510(&var_178, &var_1a8);
                    var_1a8 = rbx_15 >> 0x18;
                    sub_180006510(&var_178, &var_1a8);
                    var_1a8 = rbx_15 >> 0x10;
                    sub_180006510(&var_178, &var_1a8);
                    var_1a8 = rbx_15 >> 8;
                    sub_180006510(&var_178, &var_1a8);
                    var_1a8 = rbx_15;
                    sub_180006510(&var_178, &var_1a8);
                    r12 = var_88_1;
                    int32_t* r8_18 = *r12;
                    sub_1800045a0(&var_178, *(&var_178 + 8), r8_18, *(r12 + 8) - r8_18);
                    sub_1800045a0(&var_178, *(&var_178 + 8), &rdi_1[0xe], var_98_1);
                    int32_t* r8_20 = var_100;
                    sub_1800045a0(&var_178, *(&var_178 + 8), r8_20, *(&var_100 + 8) - r8_20);
                    int32_t* r8_21 = var_e8;
                    sub_1800045a0(&var_178, *(&var_178 + 8), r8_21, *(&var_e8 + 8) - r8_21);
                    var_1a8 = (rsi_1 >> 8);
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = rsi_1;
                    sub_180006510(&var_150, &var_1a8);
                    int32_t rbx_21 = *(&var_178 + 8) - var_178;
                    var_1a8 = rbx_21 >> 0x18;
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = rbx_21 >> 0x10;
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = rbx_21 >> 8;
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = rbx_21;
                    sub_180006510(&var_150, &var_1a8);
                    int32_t* r8_22 = var_178;
                    sub_1800045a0(&var_150, *(&var_150 + 8), r8_22, *(&var_178 + 8) - r8_22);
                    void* rax_95 = var_178;
                    
                    if (rax_95)
                    {
                        int64_t var_168;
                        void* rcx_99;
                        
                        if (var_168 - rax_95 < 0x1000)
                            rcx_99 = rax_95;
                        else
                        {
                            rcx_99 = *(rax_95 - 8);
                            
                            if (rax_95 - rcx_99 - 8 > 0x1f)
                                trap(0xd);
                        }
                        
                        j_sub_180021340(rcx_99);
                        __builtin_memset(&var_178, 0, 0x18);
                    }
                    
                    void* rax_98 = var_100;
                    
                    if (rax_98)
                    {
                        int64_t var_f0;
                        void* rcx_100;
                        
                        if (var_f0 - rax_98 < 0x1000)
                            rcx_100 = rax_98;
                        else
                        {
                            rcx_100 = *(rax_98 - 8);
                            
                            if (rax_98 - rcx_100 - 8 > 0x1f)
                            {
                            label_18000a100:
                                trap(0xd);
                            }
                        }
                        
                        j_sub_180021340(rcx_100);
                        __builtin_memset(&var_100, 0, 0x18);
                    }
                    
                    void* rax_101 = var_e8;
                    
                    if (rax_101)
                    {
                        int64_t var_d8;
                        void* rcx_101;
                        
                        if (var_d8 - rax_101 < 0x1000)
                            rcx_101 = rax_101;
                        else
                        {
                            rcx_101 = *(rax_101 - 8);
                            
                            if (rax_101 - rcx_101 - 8 > 0x1f)
                                trap(0xd);
                        }
                        
                        j_sub_180021340(rcx_101);
                    }
                    
                    r13 = arg4;
                    r14 = var_1a0;
                }
                else
                {
                    var_1a8 = (rsi_1 >> 8);
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = rsi_1;
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = r15_6 >> 0x18;
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = r15_6 >> 0x10;
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = r15_6 >> 8;
                    sub_180006510(&var_150, &var_1a8);
                    var_1a8 = r15_6;
                    sub_180006510(&var_150, &var_1a8);
                    sub_1800045a0(&var_150, *(&var_150 + 8), &rdi_1[6], r15_6);
                }
                
                rdx_88 = var_120_1 + 1;
                var_120_1 = rdx_88;
                rdi_1 = &rdi_1[6 + r15_6];
                var_b0_1 = rdi_1;
            } while (rdx_88 < i);
            result = arg2;
        }
        
        int64_t rcx_102 = *(&var_150 + 8);
        *result = var_150;
        result[1] = rcx_102;
        int64_t var_140;
        result[2] = var_140;
    }
    else
        sub_1800075d0(result, arg3);
    
    __security_check_cookie(rax_1 ^ &var_1c8);
    return result;
}

