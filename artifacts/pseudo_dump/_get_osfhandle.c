
🌐  int64_t _get_osfhandle(int32_t arg1)

{
    if (arg1 != 0xfffffffe)
    {
        if (arg1 >= 0 && arg1 < data_180047c40)
        {
            int64_t rcx = arg1;
            uint64_t rdx_1 = (rcx & 0x3f) * 9;
            int64_t rax_5 = (&data_180047840)[rcx >> 6];
            
            if (*(rax_5 + (rdx_1 << 3) + 0x38) & 1)
                return *(rax_5 + (rdx_1 << 3) + 0x28);
        }
        
        *sub_1800212f8() = 0;
        *sub_18002131c() = 9;
        _invalid_parameter_noinfo();
    }
    else
    {
        *sub_1800212f8() = 0;
        *sub_18002131c() = 9;
    }
    
    return -1;
}

