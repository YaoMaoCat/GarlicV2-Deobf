
  uint64_t sub_18002ce00(int32_t arg1, int32_t arg2, int32_t arg3 @ mxcsr)

{
    int32_t var_24 = arg3;
    int32_t rax_4 = ((~arg2 | 0xffff807f) & arg3) | (arg1 & arg2);
    int32_t var_28 = rax_4;
    int32_t arg_8;
    
    if (data_180047248 && rax_4 & 0x40)
    {
        arg_8 = rax_4;
        return arg3;
    }
    
    arg_8 = rax_4 & 0xffffffbf;
    return arg3;
}

