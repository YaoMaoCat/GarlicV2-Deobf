
  int64_t* sub_180014a30(int64_t* arg1)

{
    int64_t rax = _Query_perf_frequency();
    int64_t rax_1 = sub_180018260();
    
    if (rax == 0x989680)
    {
        *arg1 = rax_1 * 0x64;
        return arg1;
    }
    
    if (rax == 0x16e3600)
    {
        *arg1 = rax_1 * 2 / 3 + rax_1 * 0x29;
        return arg1;
    }
    
    int64_t rax_9;
    int64_t rdx_3;
    rdx_3 = HIGHQ(rax_1);
    rax_9 = LOWQ(rax_1);
    *arg1 =
        COMBINE(rdx_3, rax_9) % rax * 0x3b9aca00 / rax + COMBINE(rdx_3, rax_9) / rax * 0x3b9aca00;
    return arg1;
}

