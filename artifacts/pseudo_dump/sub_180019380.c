
  uint64_t sub_180019380(int32_t* arg1, int64_t arg2, void* arg3, int64_t* arg4, int512_t arg5 @ zmm1)

{
    int64_t rbx = arg4[1];
    int64_t var_34;
    __builtin_memset(&var_34, 0, 0x14);
    char var_38 = 0;
    int64_t arg_8 = arg2;
    *(sub_180019c40() + 0x60) = rbx;
    *(sub_180019c40() + 0x68) = *(arg1 + 0x38);
    void* rax_2 = sub_180019c40();
    char var_58 = 0;
    sub_180018660(*arg4[7] + *(rax_2 + 0x60), &var_38, arg4[1], *arg4[2], 0);
    var_58 = &var_38;
    return sub_18001c000(arg1, &arg_8, arg3, arg4, arg5, var_58, 0, 0, 0);
}

