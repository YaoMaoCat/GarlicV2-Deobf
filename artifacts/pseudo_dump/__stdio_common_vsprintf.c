
🌐  uint64_t __stdio_common_vsprintf(int64_t arg1, char* arg2, int64_t arg3, int64_t arg4, int128_t* arg5, int64_t arg6)

{
    void var_548;
    int64_t rax_1 = __security_cookie ^ &var_548;
    void* var_4f8 = nullptr;
    char var_4e8 = 0;
    char var_4d0 = 0;
    char var_4c8 = 0;
    char var_4c0 = 0;
    int128_t var_4e0_1;
    
    if (arg5)
    {
        var_4d0 = 1;
        var_4e0_1 = *arg5;
    }
    else if (!data_180047834)
    {
        var_4d0 = 1;
        var_4e0_1 = *data_180046b28;
    }
    int32_t var_4cc;
    int64_t rdi_1;
    
    if (arg4 && (!arg3 || arg2))
    {
        int32_t var_4ff_1 = 0;
        int16_t var_4fb_1 = 0;
        char var_4f9_1 = 0;
        char* var_518 = arg2;
        int64_t var_510_1 = arg3;
        char* var_508_1 = nullptr;
        uint64_t r14_2 = arg1 & 2;
        
        if (!r14_2)
            char var_500_1 = 0;
        
        if (r14_2 || !arg2)
            char var_500_2 = 1;
        
        int32_t var_498_1 = 0;
        void** var_4b0_1 = &var_4f8;
        char var_494_1 = 0;
        int64_t* var_58_1 = &var_518;
        int128_t zmm0 = {0};
        int64_t var_4a0_1 = arg6;
        int64_t var_490_1 = 0;
        int32_t var_488_1 = 0;
        int16_t var_480_1 = 0;
        int32_t var_470_1 = 0;
        char var_46c_1 = 0;
        int64_t var_4b8 = arg1;
        int64_t var_4a8_1 = arg4;
        int32_t var_50_1 = 0;
        int32_t rax_4 = sub_18001e408(&var_4b8);
        rdi_1 = rax_4;
        
        if (!arg2)
            _free_base(*(&zmm0 + 8));
        else if (!(arg1 & 1))
        {
            if (!r14_2)
            {
                if (!arg3)
                {
                    _free_base(*(&zmm0 + 8));
                    rdi_1 = 0xffffffff;
                }
                else if (var_508_1 != arg3)
                {
                    *(var_508_1 + arg2) = 0;
                    _free_base(*(&zmm0 + 8));
                }
                else
                {
                    arg2[arg3 - 1] = 0;
                    _free_base(*(&zmm0 + 8));
                    rdi_1 = 0xfffffffe;
                }
            }
            else if (!arg3)
                _free_base(*(&zmm0 + 8));
            else if (rax_4 >= 0)
            {
                if (var_508_1 != arg3)
                {
                    *(var_508_1 + arg2) = 0;
                    _free_base(*(&zmm0 + 8));
                }
                else
                {
                    arg2[arg3 - 1] = 0;
                    _free_base(*(&zmm0 + 8));
                }
            }
            else
            {
                *arg2 = 0;
                _free_base(*(&zmm0 + 8));
            }
        }
        else if (arg3 || !rax_4)
        {
            if (var_508_1 != arg3)
            {
                *(var_508_1 + arg2) = 0;
                _free_base(*(&zmm0 + 8));
            }
            else if (rdi_1 < 0 || rdi_1 <= arg3)
                _free_base(*(&zmm0 + 8));
            else
            {
                _free_base(*(&zmm0 + 8));
                rdi_1 = 0xffffffff;
            }
        }
        else
        {
            _free_base(*(&zmm0 + 8));
            rdi_1 = 0xffffffff;
        }
    }
    else
    {
        var_4c8 = 1;
        var_4cc = 0x16;
        _invalid_parameter_internal(0, 0, 0, 0, 0, &var_4f8);
        rdi_1 = 0xffffffff;
    }
    
    if (var_4d0 == 2)
    {
        void* rax_6 = var_4f8;
        *(rax_6 + 0x3a8) &= 0xfffffffd;
    }
    
    if (var_4c8)
        *(sub_18001e310(&var_4f8) + 0x20) = var_4cc;
    
    int32_t var_4c4;
    
    if (var_4c0)
        *(sub_18001e310(&var_4f8) + 0x24) = var_4c4;
    __security_check_cookie(rax_1 ^ &var_548);
    return rdi_1;
}

