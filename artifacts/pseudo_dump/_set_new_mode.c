
🌐  uint64_t _set_new_mode(int32_t arg1)

{
    if (arg1 <= 1)
    {
        int32_t temp0_1 = data_180047fe8;
        data_180047fe8 = arg1;
        return temp0_1;
    }
    
    *sub_18002131c() = 0x16;
    _invalid_parameter_noinfo();
    return 0xffffffff;
}

