
  int64_t sub_180005820(void* arg1, int128_t* arg2, int128_t* arg3, int16_t arg4)

{
    int64_t var_48 = 0;
    int64_t result_1 = {0};
    int64_t var_30 = 0;
    int16_t rsi = arg4 | 0x100;
    var_48 = rsi;
    int128_t var_58 = *arg2;
    int16_t rax = sub_180006790(arg1, &var_58);
    *(&var_48 + 2) = rax;
    var_58 = *arg3;
    int16_t rax_1 = sub_180006790(arg1, &var_58);
    *(&var_48 + 4) = rax_1;
    int16_t* r9 = *(arg1 + 0xa8);
    int64_t result;
    int64_t rdx_2;
    
    if (r9 == *(arg1 + 0xb0))
    {
        sub_180003fc0(arg1 + 0xa0, r9, &var_48);
        rdx_2 = var_30;
        result = result_1;
    }
    else
    {
        *r9 = rsi;
        r9[1] = rax;
        r9[2] = rax_1;
        rdx_2 = 0;
        result = 0;
        __builtin_memset(&r9[4], 0, 0x18);
        *(arg1 + 0xa8) += 0x20;
    }
    
    if (!result)
        return result;
    
    if (rdx_2 - result < 0x1000)
        return j_sub_180021340(result);
    
    int64_t rcx_2 = *(result - 8);
    
    if (result - rcx_2 - 8 > 0x1f)
        trap(0xd);
    
    /* tailcall */
    return j_sub_180021340(rcx_2);
}

