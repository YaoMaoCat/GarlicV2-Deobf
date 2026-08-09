
  uint64_t sub_1800237d0(char* arg1, char* arg2, uint64_t arg3)

{
    char* rsi = arg2;
    char* r14 = arg1;
    
    if (!data_180047834)
        return sub_1800294f0(arg1, arg2, arg3);
    
    char var_10_1 = 0;
    void** rax_1 = __vcrt_getptd();
    int64_t var_20 = rax_1[0x12];
    int64_t var_18 = rax_1[0x11];
    __acrt_update_locale_info(rax_1, &var_20);
    sub_180021804(rax_1, &var_18);
    void** rax_4 = rax_1;
    int32_t rcx_2 = rax_4[0x75];
    uint32_t rcx_3;
    
    if (rcx_2 & 2)
        rcx_3 = var_10_1;
    else
    {
        rax_4[0x75] = rcx_2 | 2;
        rcx_3 = 1;
        rax_4 = rax_1;
        var_10_1 = 1;
    }
    
    int32_t rbx_1;
    
    if (!arg3)
    {
        if (rcx_3)
            rax_4[0x75] &= 0xfffffffd;
        
        rbx_1 = 0;
    }
    else if (r14 && rsi)
    {
        rbx_1 = 0x7fffffff;
        
        if (arg3 <= 0x7fffffff)
        {
            int64_t rax_8 = var_20;
            int64_t rdx_2 = *(rax_8 + 0x130);
            
            if (rdx_2)
            {
                int32_t rax_11 = __acrt_CompareStringA(&var_20, rdx_2, 0x1001, r14, arg3, rsi, 
                    arg3, *(rax_8 + 0x14));
                
                if (rax_11)
                    rbx_1 = rax_11 - 2;
                else
                    *sub_18002131c() = 0x16;
                
                goto label_180023944;
            }
            
            int32_t rax_9 = sub_180029580(r14, rsi, arg3, &var_20);
            
            if (var_10_1)
                rax_1[0x75] &= 0xfffffffd;
            
            rbx_1 = rax_9;
        }
        else
        {
            *sub_18002131c() = 0x16;
            _invalid_parameter_noinfo();
        label_180023944:
            
            if (var_10_1)
                rax_1[0x75] &= 0xfffffffd;
        }
    }
    else
    {
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
        
        if (var_10_1)
            rax_1[0x75] &= 0xfffffffd;
        
        rbx_1 = 0x7fffffff;
    }
    
    return rbx_1;
}

