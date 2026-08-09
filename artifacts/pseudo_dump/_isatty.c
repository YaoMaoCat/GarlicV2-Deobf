
🌐  uint64_t _isatty(int32_t arg1)

{
    if (arg1 != 0xfffffffe)
    {
        if (arg1 >= 0 && arg1 < data_180047c40)
        {
            int64_t rcx = arg1;
            return *((&data_180047840)[rcx >> 6] + (rcx & 0x3f) * 0x48 + 0x38) & 0x40;
        }
        
        *sub_18002131c() = 9;
        _invalid_parameter_noinfo();
    }
    else
        *sub_18002131c() = 9;
    
    return 0;
}

