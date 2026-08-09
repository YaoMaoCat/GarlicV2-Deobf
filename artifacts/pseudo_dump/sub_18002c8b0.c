
  uint64_t sub_18002c8b0(int32_t arg1, uint64_t* arg2)

{
    int32_t rbx_1 = arg1 & 0x1f;
    
    if (!arg1)
        return 0;
    
    int32_t mxcsr;
    uint64_t rax_1 = get_fpsw_inline(mxcsr);
    *arg2 = rax_1;
    
    if (arg1 & 8 && rax_1 < 0)
        rbx_1 &= 0xfffffff7;
    else if (arg1 & 4 && TEST_BITQ(rax_1, 9))
        rbx_1 &= 0xfffffffb;
    else if (arg1 & 1 && TEST_BITQ(rax_1, 0xa))
        rbx_1 &= 0xfffffffe;
    else if (arg1 & 2 && TEST_BITQ(rax_1, 0xb))
        rbx_1 &= 0xfffffffd;
    
    if (arg1 & 0x10 && TEST_BITQ(rax_1, 0xc))
        rbx_1 &= 0xffffffef;
    
    if (rbx_1)
        sub_18002ce00(0x1f80, 0xffc0, mxcsr);
    
    return rbx_1;
}

