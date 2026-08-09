
🌐  uint64_t _fflush_nolock(int32_t* arg1, int512_t arg2 @ zmm1)

{
    void* var_48 = nullptr;
    char var_38 = 0;
    char var_20 = 0;
    char var_18 = 0;
    char var_10 = 0;
    
    if (!data_180047834)
    {
        var_20 = 1;
        int128_t var_30_1 = *data_180046b28;
    }
    
    int32_t rdi;
    
    if (arg1)
    {
        int32_t rax_1 = __acrt_stdio_flush_nolock(arg1, &var_48);
        int32_t rax_5;
        
        if (!rax_1 && arg1[5] >> 0xb & 1)
            rax_5 = _commit(_fileno(arg1));
        
        if (rax_1 || (arg1[5] >> 0xb & 1 && rax_5))
            rdi = -1;
        else
            rdi = 0;
    }
    else
        rdi = common_flush_all(0, arg2);
    
    if (var_20 == 2)
    {
        void* rax_6 = var_48;
        *(rax_6 + 0x3a8) &= 0xfffffffd;
    }
    
    int32_t var_1c;
    
    if (var_18)
        *(sub_18001e310(&var_48) + 0x20) = var_1c;
    int32_t var_14;
    
    if (var_10)
        *(sub_18001e310(&var_48) + 0x24) = var_14;
    return rdi;
}

