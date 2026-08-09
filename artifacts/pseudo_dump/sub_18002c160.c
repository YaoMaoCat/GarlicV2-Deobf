
  int64_t sub_18002c160(int32_t arg1, int32_t arg2 @ mxcsr) __pure

{
    int32_t rcx = arg1 & 0xc00;
    int32_t rdx_3 = (arg1 >> 0x18 & 0x3f) | (arg1 >> 0x16 & 0x300);
    int16_t rdi = 0x400;
    int16_t r11 = 0x800;
    int16_t r9;
    
    if (rcx == 0x400)
        r9 = -0x7fc0;
    else if (rcx == 0x800)
        r9 = 0x40;
    else if (rcx == 0xc00)
        r9 = -0x8000;
    else
        r9 = 0;
    
    int16_t rbx = 0x100;
    int16_t r10 = 0x200;
    int32_t rax_4 = rdx_3 & 0x300;
    int16_t r8;
    
    if (!rax_4)
        r8 = 0;
    else if (rax_4 == 0x100)
        r8 = 0x2000;
    else if (rax_4 == 0x200)
        r8 = 0x4000;
    else if (rax_4 != 0x300)
        r8 = 0;
    else
        r8 = 0x6000;
    
    int16_t rcx_1;
    
    rcx_1 = !TEST_BITD(rdx_3, 0) ? 0 : 0x1000;
    
    if (!TEST_BITD(rdx_3, 1))
        r11 = 0;
    
    if (!TEST_BITD(rdx_3, 2))
        rdi = 0;
    
    if (!TEST_BITD(rdx_3, 3))
        r10 = 0;
    
    int16_t rax_5;
    
    rax_5 = !TEST_BITD(rdx_3, 4) ? 0 : 0x80;
    
    if (!TEST_BITD(rdx_3, 5))
        rbx = 0;
    
    int32_t result =
        (arg2 & 0xffff003f) | ((r8 | rcx_1 | r11 | rdi | r10 | rax_5 | rbx | r9) & 0xffc0);
    int32_t result_1 = result;
    return result;
}

