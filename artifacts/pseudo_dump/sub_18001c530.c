
  void sub_18001c530(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4) __noreturn

{
    int32_t arg_20 = 1;
    *(sub_180019c40() + 0x40) = 0;
    void* rax_1;
    int64_t rdx;
    rax_1 = sub_180019c40();
    *(rax_1 + 0x78) = arg3;
    int32_t* rcx_1 = arg1;
    
    if (arg4)
    {
        rdx = 1;
        sub_180019930(rcx_1);
        rcx_1 = arg2;
    }
    
    RaiseException(*rcx_1, rcx_1[1], rcx_1[6], &rcx_1[8]);
    /* no return */
}

