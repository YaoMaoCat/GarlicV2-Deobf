
  void sub_18001c2d6(int32_t arg1, int32_t* arg2, int32_t* arg3) __noreturn

{
    int32_t arg_20 = 1;
    void* rax;
    int64_t rdx;
    rax = sub_180019c40();
    *(rax + 0x40) = 0;
    int32_t* rcx = arg2;
    
    if (arg1)
    {
        rdx = 1;
        sub_180019930(rcx);
        rcx = arg3;
    }
    
    RaiseException(*rcx, rcx[1], rcx[6], &rcx[8]);
    /* no return */
}

