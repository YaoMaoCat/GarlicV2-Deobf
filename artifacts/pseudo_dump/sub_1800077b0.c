
  void sub_1800077b0(int64_t* arg1)

{
    void* rcx = *arg1;
    
    if (!rcx)
        return;
    
    sub_180006d00(rcx, arg1[1]);
    void* r8_2 = *arg1;
    int64_t rax_1;
    int64_t rdx_4;
    rdx_4 = HIGHQ(0x6666666666666667 * (arg1[2] - r8_2));
    rax_1 = LOWQ(0x6666666666666667 * (arg1[2] - r8_2));
    int64_t rdx_5 = rdx_4 >> 4;
    void* rcx_1;
    
    if ((rdx_5 + (rdx_5 >> 0x3f)) * 0x28 < 0x1000)
        rcx_1 = r8_2;
    else
    {
        rcx_1 = *(r8_2 - 8);
        
        if (r8_2 - rcx_1 - 8 > 0x1f)
            trap(0xd);
    }
    
    j_sub_180021340(rcx_1);
    __builtin_memset(arg1, 0, 0x18);
}

