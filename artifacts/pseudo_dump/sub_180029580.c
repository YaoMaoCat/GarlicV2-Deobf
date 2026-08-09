
  uint64_t sub_180029580(char* arg1, void* arg2, uint64_t arg3, int128_t* arg4)

{
    uint64_t i_1 = arg3;
    void* rdi = arg2;
    char* rsi = arg1;
    
    if (!arg1 || !arg2 || i_1 > 0x7fffffff)
    {
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
        return 0x7fffffff;
    }
    
    if (!i_1)
        return 0;
    
    arg3 = 0;
    char var_10 = 0;
    void** var_28;
    int128_t var_20;
    
    if (arg4)
        var_20 = *arg4;
    else if (data_180047834)
    {
        void** rax_4 = __vcrt_getptd();
        var_28 = rax_4;
        var_20 = rax_4[0x12];
        *(&var_20 + 8) = rax_4[0x11];
        __acrt_update_locale_info(rax_4, &var_20);
        sub_180021804(var_28, (&var_20 + 8));
        int32_t rax_7 = var_28[0x75];
        
        if (rax_7 & 2)
            arg3 = var_10;
        else
        {
            arg3 = 1;
            var_28[0x75] = rax_7 | 2;
            char var_10_1 = 1;
        }
    }
    else
        var_20 = *data_180046b28;
    
    int64_t r9 = *(var_20 + 0x110);
    uint32_t rcx_3;
    uint32_t rdx_2;
    uint64_t i;
    
    do
    {
        uint64_t rax_10 = *rsi;
        rsi = &rsi[1];
        rdi += 1;
        rdx_2 = *(rax_10 + r9);
        rcx_3 = *(*(rdi - 1) + r9);
        
        if (rdx_2 != rcx_3)
            break;
        
        if (!rdx_2)
            break;
        
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    
    if (arg3)
        var_28[0x75] &= 0xfffffffd;
    
    return rdx_2 - rcx_3;
}

