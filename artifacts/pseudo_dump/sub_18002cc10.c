
  int32_t sub_18002cc10(int32_t arg1 @ zmm0, int128_t arg2 @ zmm1, int32_t arg3, int32_t arg4, int64_t arg5)

{
    int128_t zmm6 = arg2;
    
    if (arg3 == 1)
    {
        int32_t var_28_2 = 1;
        int64_t var_30_2 = {0};
        zmm6 = sub_18002c9c0(arg5, arg4, zmm6, 2, 4, 0x22, arg1);
    }
    else if (arg3 == 2)
    {
        int32_t var_28_1 = arg3 - 1;
        int64_t var_30_1 = {0};
        zmm6 = sub_18002c9c0(arg5, arg4, zmm6, arg3 - 1, 8, 0x21, arg1);
    }
    
    return zmm6;
}

