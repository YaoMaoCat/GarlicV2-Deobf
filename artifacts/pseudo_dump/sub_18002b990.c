
  void sub_18002b990(int64_t arg1 @ zmm0)

{
    if (data_180046858 >= 2)
    {
        _mm_round_sd(arg1, arg1, 0xa);
        return;
    }
    
    int64_t rax_1 = arg1 & 0x7fffffffffffffff;
    int64_t r9;
    r9 = arg1 != rax_1;
    
    if (rax_1 >> 0x34 >= 0x433 && rax_1 > 0x7ff0000000000000)
        /* tailcall */
        return sub_18002cb00(arg1);
}

