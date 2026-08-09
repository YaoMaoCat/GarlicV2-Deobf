
  int64_t sub_1800294b0(int64_t arg1, int64_t arg2, int64_t arg3)

{
    if (!arg1 || !arg2 || arg3 > 0x7fffffff)
    {
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
    }
    
    return 0x7fffffff;
}

