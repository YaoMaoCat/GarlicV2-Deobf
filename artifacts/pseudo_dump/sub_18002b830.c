
  int64_t sub_18002b830(int32_t* arg1, int32_t arg2, int32_t arg3)

{
    int32_t r8 = arg3 & 0xfff7ffff;
    
    if (!(arg2 & r8 & 0xfcf0fce0))
    {
        if (!arg1)
        {
            j_sub_18002c610(arg2, r8);
            return 0;
        }
        
        *arg1 = j_sub_18002c610(arg2, r8);
        return 0;
    }
    
    if (arg1)
        *arg1 = j_sub_18002c610(0, 0);
    
    *sub_18002131c() = 0x16;
    _invalid_parameter_noinfo();
    return 0x16;
}

