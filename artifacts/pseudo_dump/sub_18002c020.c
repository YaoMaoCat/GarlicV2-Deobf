
  uint64_t sub_18002c020(int32_t arg1 @ mxcsr) __pure

{
    int16_t rax = arg1 & 0x8040;
    int32_t r8;
    
    if (rax == 0x8000)
        r8 = 0xc00;
    else if (rax != 0x40)
    {
        r8 = 0;
        
        if (rax == 0x8040)
            r8 = 0x400;
    }
    else
        r8 = 0x800;
    
    int32_t rax_2 = arg1 & 0x6000;
    int32_t rcx;
    
    if (!rax_2)
        rcx = 0;
    else if (rax_2 == 0x2000)
        rcx = 0x100;
    else if (rax_2 == 0x4000)
        rcx = 0x200;
    else
    {
        rcx = 0x300;
        
        if (rax_2 != 0x6000)
            rcx = 0;
    }
    
    uint64_t rdx_12 = (
        ((((arg1 >> 2 & 0x400) | (arg1 & 0x800)) >> 2 | (arg1 & 0x400)) >> 2 | (arg1 & 0x200)) >> 3
        | (arg1 & 0x180)) >> 3 | r8 | rcx;
    return ((rdx_12 & 0xffffff00) | rdx_12 << 2) << 0x16 | rdx_12;
}

