
  void sub_18002cf00(uint64_t arg1, int64_t* arg2, char arg3, int32_t arg4, int32_t* arg5, int32_t* arg6, int32_t arg7) __noreturn

{
    uint64_t arguments = arg1;
    uint32_t dwExceptionCode = -0x3ffffff3;
    *(arg1 + 4) = 0;
    *(arguments + 8) = 0;
    *(arguments + 0xc) = 0;
    
    if (arg3 & 0x10)
    {
        uint64_t arguments_1 = arguments;
        dwExceptionCode = -0x3fffff71;
        *(arguments_1 + 4) |= 1;
    }
    
    if (arg3 & 2)
    {
        uint64_t arguments_2 = arguments;
        dwExceptionCode = -0x3fffff6d;
        *(arguments_2 + 4) |= 2;
    }
    
    if (arg3 & 1)
    {
        uint64_t arguments_3 = arguments;
        dwExceptionCode = -0x3fffff6f;
        *(arguments_3 + 4) |= 4;
    }
    
    if (arg3 & 4)
    {
        uint64_t arguments_4 = arguments;
        dwExceptionCode = -0x3fffff72;
        *(arguments_4 + 4) |= 8;
    }
    
    if (arg3 & 8)
    {
        uint64_t arguments_5 = arguments;
        dwExceptionCode = -0x3fffff70;
        *(arguments_5 + 4) |= 0x10;
    }
    
    uint64_t arguments_24 = arguments;
    *(arguments_24 + 8) ^= (~(*arg2 >> 7 << 4) ^ *(arguments_24 + 8)) & 0x10;
    uint64_t arguments_25 = arguments;
    *(arguments_25 + 8) ^= (~(*arg2 >> 9 << 3) ^ *(arguments_25 + 8)) & 8;
    uint64_t arguments_26 = arguments;
    *(arguments_26 + 8) ^= (~(*arg2 >> 0xa << 2) ^ *(arguments_26 + 8)) & 4;
    uint64_t arguments_27 = arguments;
    *(arguments_27 + 8) ^= (~((*arg2 >> 0xb) * 2) ^ *(arguments_27 + 8)) & 2;
    uint64_t arguments_28 = arguments;
    *(arguments_28 + 8) ^= (~(*arg2 >> 0xc) ^ *(arguments_28 + 8)) & 1;
    int32_t mxcsr;
    char rax_2 = sub_18002cec0(mxcsr);
    
    if (rax_2 & 1)
    {
        uint64_t arguments_20 = arguments;
        *(arguments_20 + 0xc) |= 0x10;
    }
    
    if (rax_2 & 4)
    {
        uint64_t arguments_21 = arguments;
        *(arguments_21 + 0xc) |= 8;
    }
    
    if (rax_2 & 8)
    {
        uint64_t arguments_6 = arguments;
        *(arguments_6 + 0xc) |= 4;
    }
    
    if (rax_2 & 0x10)
    {
        uint64_t arguments_7 = arguments;
        *(arguments_7 + 0xc) |= 2;
    }
    
    if (rax_2 & 0x20)
    {
        uint64_t arguments_8 = arguments;
        *(arguments_8 + 0xc) |= 1;
    }
    
    uint64_t rax_4 = *arg2 & 0x6000;
    
    if (!rax_4)
    {
        uint64_t arguments_14 = arguments;
        *arguments_14 &= 0xfffffffc;
    }
    else if (rax_4 == 0x2000)
    {
        uint64_t arguments_12 = arguments;
        *arguments_12 &= 0xfffffffd;
        uint64_t arguments_13 = arguments;
        *arguments_13 |= 1;
    }
    else if (rax_4 == 0x4000)
    {
        uint64_t arguments_10 = arguments;
        *arguments_10 &= 0xfffffffe;
        uint64_t arguments_11 = arguments;
        *arguments_11 |= 2;
    }
    else if (rax_4 == 0x6000)
    {
        uint64_t arguments_9 = arguments;
        *arguments_9 |= 3;
    }
    
    uint64_t arguments_22 = arguments;
    *arguments_22 ^= (arg4 << 5 ^ *arguments_22) & 0x1ffe0;
    uint64_t arguments_15 = arguments;
    *(arguments_15 + 0x20) |= 1;
    
    if (!arg7)
    {
        uint64_t arguments_23 = arguments;
        *(arguments_23 + 0x20) = (*(arguments_23 + 0x20) & 0xffffffe3) | 2;
        *(arguments + 0x10) = *arg5;
        uint64_t arguments_19 = arguments;
        *(arguments_19 + 0x60) |= 1;
        uint64_t arguments_29 = arguments;
        *(arguments_29 + 0x60) = (*(arguments_29 + 0x60) & 0xffffffe3) | 2;
        *(arguments + 0x50) = *arg6;
    }
    else
    {
        uint64_t arguments_16 = arguments;
        *(arguments_16 + 0x20) &= 0xffffffe1;
        *(arguments + 0x10) = *arg5;
        uint64_t arguments_17 = arguments;
        *(arguments_17 + 0x60) |= 1;
        uint64_t arguments_18 = arguments;
        *(arguments_18 + 0x60) &= 0xffffffe1;
        *(arguments + 0x50) = *arg6;
    }
    
    RaiseException(dwExceptionCode, 0, 1, &arguments);
    /* no return */
}

