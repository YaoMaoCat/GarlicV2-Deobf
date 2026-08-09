
  int64_t sub_18002c9c0(int64_t arg1, int32_t arg2, int64_t arg3, int32_t arg4, int32_t arg5, int64_t arg6, int32_t arg7)

{
    void var_128;
    int64_t rax_1 = __security_cookie ^ &var_128;
    int64_t var_f0 = 0;
    int64_t var_f8 = arg3;
    uint128_t zmm6 = arg6;
    int64_t arg_38;
    
    if (sub_18002c8b0(arg5, &var_f0))
    {
        int128_t var_b8;
        __builtin_memset(&var_b8, 0, 0x70);
        
        if (arg7 == 2)
        {
            int128_t var_88;
            var_88 = zmm6;
            int128_t var_78;
            var_78 = 3;
        }
        
        sub_18002ced0(&var_b8, &var_f0, arg5, arg2, &arg_38, &var_f8);
        /* no return */
    }
    
    int32_t result;
    
    if (!__acrt_has_user_matherr() || !arg4)
    {
        int512_t zmm0_2;
        result = sub_18002d210(arg4);
        zmm0_2 = var_f8;
    }
    else
    {
        int64_t zmm1 = var_f8;
        int64_t var_d8_1 = arg_38;
        int32_t var_e4_1 = 0;
        uint64_t var_d0_1 = zmm6;
        int32_t var_e8_1 = arg4;
        int64_t var_e0_1 = arg1;
        int512_t zmm0_1;
        result = sub_180026920();
        
        if (!result)
            result = sub_18002d210(arg4);
        
        zmm0_1 = zmm1;
    }
    
    __security_check_cookie(rax_1 ^ &var_128);
    return result;
}

