
  int64_t sub_180006790(void* arg1, int64_t* arg2)

{
    int128_t zmm6;
    int128_t var_48 = zmm6;
    void var_d8;
    int64_t rax_1 = __security_cookie ^ &var_d8;
    int32_t* r12 = *arg2;
    int128_t* rsi = arg2[1];
    int128_t var_70;
    __builtin_memset(&var_70, 0, 0x20);
    sub_180002740(&var_70, r12, rsi);
    int64_t* var_a8;
    sub_1800044d0(arg1 + 0x60, &var_a8, &var_70);
    void* var_98;
    void* rbx = var_98;
    char rax_2;
    
    if (!*(rbx + 0x19))
        rax_2 = sub_180004f30(arg1 + 0x60, &var_70, rbx + 0x20);
    
    if (*(rbx + 0x19) || rax_2)
        rbx = *(arg1 + 0x60);
    
    int64_t var_58;
    
    if (var_58 <= 0xf)
        goto label_180006860;
    
    void* rcx_3 = var_70;
    
    if (var_58 + 1 < 0x1000)
        goto label_180006858;
    
    void* rax_3 = *(rcx_3 - 8);
    
    if (rcx_3 - rax_3 - 8 <= 0x1f)
    {
        rcx_3 = rax_3;
    label_180006858:
        j_sub_180021340(rcx_3);
    label_180006860:
        int16_t rax_4;
        
        if (rbx != *(arg1 + 0x60))
            rax_4 = *(rbx + 0x40);
        
        if (rbx != *(arg1 + 0x60) && rax_4)
        {
            __security_check_cookie(rax_1 ^ &var_d8);
            return rax_4;
        }
        
        if (rsi > 0xffff)
        {
            sub_180004ba0(&var_a8, "classfile: utf8 too long");
            sub_180019520(&var_a8, &data_180045388);
            /* no return */
        }
        
        int128_t var_88;
        __builtin_memset(&var_88, 0, 0x18);
        sub_180006670(&var_88, rsi + 2);
        char var_b8 = (rsi >> 8);
        sub_180006510(&var_88, &var_b8);
        var_b8 = rsi;
        sub_180006510(&var_88, &var_b8);
        sub_1800045a0(&var_88, *(&var_88 + 8), r12, rsi);
        int64_t rcx_10 = *(&var_88 + 8);
        int64_t* rax_6 = var_88;
        __builtin_memset(&var_88, 0, 0x18);
        var_a8 = rax_6;
        int64_t var_a0_1 = rcx_10;
        int64_t var_78;
        int64_t var_98_1 = var_78;
        int16_t rax_7 = sub_1800056d0(arg1, 1, &var_a8);
        __builtin_memset(&var_70, 0, 0x20);
        sub_180002740(&var_70, r12, rsi);
        void*** rax_8 = sub_1800044d0(arg1 + 0x60, &var_a8, &var_70);
        zmm6 = *rax_8;
        void* r8_7 = rax_8[2];
        char rax_9;
        
        if (!*(r8_7 + 0x19))
            rax_9 = sub_180004f30(arg1 + 0x60, &var_70, r8_7 + 0x20);
        
        int64_t rsi_1;
        int64_t var_58_1;
        
        if (*(r8_7 + 0x19) || rax_9)
        {
            if (*(arg1 + 0x68) == 0x38e38e38e38e38e)
            {
                sub_180005280();
                /* no return */
            }
            
            void* rbx_1 = *(arg1 + 0x60);
            var_a8 = arg1 + 0x60;
            int64_t var_a0_2 = 0;
            void** rax_10 = sub_180016420(0x48);
            *(rax_10 + 0x20) = var_70;
            int64_t var_60;
            *(rax_10 + 0x30) = var_60;
            rsi_1 = 0xf;
            var_70 = 0;
            rax_10[8] = rax_7;
            *rax_10 = rbx_1;
            rax_10[1] = rbx_1;
            rax_10[2] = rbx_1;
            rax_10[3] = 0;
            var_a8 = zmm6;
            sub_180005010(arg1 + 0x60, &var_a8, rax_10);
        }
        else
            rsi_1 = var_58_1;
        
        if (rsi_1 > 0xf)
        {
            void* rcx_16 = var_70;
            
            if (rsi_1 + 1 >= 0x1000)
            {
                void* rax_11 = *(rcx_16 - 8);
                
                if (rcx_16 - rax_11 - 8 > 0x1f)
                    trap(0xd);
                
                rcx_16 = rax_11;
            }
            
            j_sub_180021340(rcx_16);
        }
        
        void* rax_12 = var_88;
        
        if (!rax_12)
            goto label_180006a45;
        
        int64_t var_78_1;
        void* rcx_19;
        
        if (var_78_1 - rax_12 < 0x1000)
        {
            rcx_19 = rax_12;
        label_180006a40:
            j_sub_180021340(rcx_19);
        label_180006a45:
            __security_check_cookie(rax_1 ^ &var_d8);
            return rax_7;
        }
        
        rcx_19 = *(rax_12 - 8);
        
        if (rax_12 - rcx_19 - 8 <= 0x1f)
            goto label_180006a40;
    }
    
    trap(0xd);
}

