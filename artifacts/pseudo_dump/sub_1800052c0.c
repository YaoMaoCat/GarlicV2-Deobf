
  void* sub_1800052c0(void* arg1, int128_t* arg2, int128_t* arg3, int16_t arg4, int32_t* arg5, uint16_t arg6)

{
    int128_t var_a8;
    
    if (!*(arg1 + 0xb8))
    {
        var_a8 = "Code";
        *(&var_a8 + 8) = 4;
        *(arg1 + 0xb8) = sub_180006790(arg1, &var_a8);
    }
    
    int128_t var_98;
    __builtin_memset(&var_98, 0, 0x18);
    uint16_t arg_30;
    uint16_t rbx = arg_30;
    arg_30 = (rbx >> 8);
    sub_180006510(&var_98, &arg_30);
    arg_30 = rbx;
    sub_180006510(&var_98, &arg_30);
    arg_30 = (arg6 >> 8);
    sub_180006510(&var_98, &arg_30);
    arg_30 = arg6;
    sub_180006510(&var_98, &arg_30);
    int32_t rbx_3 = arg5[2] - *arg5;
    arg_30 = rbx_3 >> 0x18;
    sub_180006510(&var_98, &arg_30);
    arg_30 = rbx_3 >> 0x10;
    sub_180006510(&var_98, &arg_30);
    arg_30 = rbx_3 >> 8;
    sub_180006510(&var_98, &arg_30);
    arg_30 = rbx_3;
    sub_180006510(&var_98, &arg_30);
    int32_t* r8 = *arg5;
    sub_1800045a0(&var_98, *(&var_98 + 8), r8, *(arg5 + 8) - r8);
    arg_30 = 0;
    sub_180006510(&var_98, &arg_30);
    arg_30 = 0;
    sub_180006510(&var_98, &arg_30);
    arg_30 = 0;
    sub_180006510(&var_98, &arg_30);
    arg_30 = 0;
    sub_180006510(&var_98, &arg_30);
    int128_t var_80;
    __builtin_memset(&var_80, 0, 0x18);
    uint16_t rbx_4 = *(arg1 + 0xb8);
    arg_30 = (rbx_4 >> 8);
    sub_180006510(&var_80, &arg_30);
    arg_30 = rbx_4;
    sub_180006510(&var_80, &arg_30);
    int32_t rbx_6 = *(&var_98 + 8) - var_98;
    arg_30 = rbx_6 >> 0x18;
    sub_180006510(&var_80, &arg_30);
    arg_30 = rbx_6 >> 0x10;
    sub_180006510(&var_80, &arg_30);
    arg_30 = rbx_6 >> 8;
    sub_180006510(&var_80, &arg_30);
    arg_30 = rbx_6;
    sub_180006510(&var_80, &arg_30);
    int32_t* r8_1 = var_98;
    sub_1800045a0(&var_80, *(&var_80 + 8), r8_1, *(&var_98 + 8) - r8_1);
    int64_t var_68 = 0;
    int64_t var_60 = {0};
    int64_t var_50 = 0;
    var_68 = arg4;
    var_a8 = *arg2;
    int16_t rax_17 = sub_180006790(arg1, &var_a8);
    *(&var_68 + 2) = rax_17;
    var_a8 = *arg3;
    int16_t rax_18 = sub_180006790(arg1, &var_a8);
    *(&var_68 + 4) = rax_18;
    int64_t rcx_22 = var_80;
    var_60 = rcx_22;
    int64_t r8_2 = *(&var_80 + 8);
    *(&var_60 + 8) = r8_2;
    __builtin_memset(&var_80, 0, 0x18);
    int16_t* r9_4 = *(arg1 + 0xa8);
    int64_t rax_19;
    int64_t rdx_23;
    int64_t var_70;
    
    if (r9_4 == *(arg1 + 0xb0))
    {
        sub_180003fc0(arg1 + 0xa0, r9_4, &var_68);
        rdx_23 = var_70;
        rax_19 = var_60;
    }
    else
    {
        *r9_4 = arg4;
        r9_4[1] = rax_17;
        r9_4[2] = rax_18;
        rdx_23 = 0;
        rax_19 = 0;
        *(r9_4 + 8) = rcx_22;
        *(r9_4 + 0x10) = r8_2;
        *(r9_4 + 0x18) = var_70;
        *(arg1 + 0xa8) += 0x20;
    }
    
    if (rax_19)
    {
        int64_t rcx_24;
        
        if (rdx_23 - rax_19 < 0x1000)
            rcx_24 = rax_19;
        else
        {
            rcx_24 = *(rax_19 - 8);
            
            if (rax_19 - rcx_24 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_24);
    }
    
    void* rax_22 = var_80;
    
    if (rax_22)
    {
        int64_t var_70_1;
        void* rcx_26;
        
        if (var_70_1 - rax_22 < 0x1000)
            rcx_26 = rax_22;
        else
        {
            rcx_26 = *(rax_22 - 8);
            
            if (rax_22 - rcx_26 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_26);
        __builtin_memset(&var_80, 0, 0x18);
    }
    
    void* rax_25 = var_98;
    
    if (rax_25)
    {
        int64_t var_88;
        void* rcx_28;
        
        if (var_88 - rax_25 < 0x1000)
            rcx_28 = rax_25;
        else
        {
            rcx_28 = *(rax_25 - 8);
            
            if (rax_25 - rcx_28 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_28);
        __builtin_memset(&var_98, 0, 0x18);
    }
    
    void* result = *arg5;
    
    if (result)
    {
        void* result_1;
        
        if (*(arg5 + 0x10) - result < 0x1000)
            result_1 = result;
        else
        {
            result_1 = *(result - 8);
            
            if (result - result_1 - 8 > 0x1f)
                trap(0xd);
        }
        
        result = j_sub_180021340(result_1);
        __builtin_memset(arg5, 0, 0x18);
    }
    
    return result;
}

