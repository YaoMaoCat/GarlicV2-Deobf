
  uint64_t sub_18002c610(int32_t arg1, int32_t arg2)

{
    int32_t rdi_1 = arg2 & 0x308031f;
    int32_t mxcsr;
    int32_t rax = get_fpsw_inline(mxcsr);
    int32_t r9_2 = rax >> 3 & 0x10;
    int32_t r10_1 = r9_2 | 8;
    
    if (!TEST_BITD(rax, 9))
        r10_1 = r9_2;
    
    int32_t rcx_1 = r10_1 | 4;
    
    if (!TEST_BITD(rax, 0xa))
        rcx_1 = r10_1;
    
    int32_t rdx_1 = rcx_1 | 2;
    
    if (!TEST_BITD(rax, 0xb))
        rdx_1 = rcx_1;
    
    int32_t rcx_3 = rdx_1 | 1;
    
    if (!TEST_BITD(rax, 0xc))
        rcx_3 = rdx_1;
    
    int32_t rdx_3 = rcx_3 | 0x80000;
    
    if (!TEST_BITD(rax, 8))
        rdx_3 = rcx_3;
    
    int32_t rax_1 = rax & 0x6000;
    
    if (rax_1)
    {
        if (rax_1 == 0x2000)
            rdx_3 |= 0x100;
        else if (rax_1 == 0x4000)
            rdx_3 |= 0x200;
        else if (rax_1 == 0x6000)
            rdx_3 |= 0x300;
    }
    
    int32_t r11_1 = rax & 0x8040;
    
    if (r11_1 == 0x40)
        rdx_3 |= 0x2000000;
    else if (r11_1 == 0x8000)
        rdx_3 |= 0x3000000;
    else if (r11_1 == 0x8040)
        rdx_3 |= 0x1000000;
    
    int32_t r8_3 = (~rdi_1 & rdx_3) | (arg1 & rdi_1);
    
    if (r8_3 != rdx_3)
    {
        int32_t rcx_6 = (r8_3 & 0x10) << 3;
        int32_t rdx_5 = rcx_6 | 0x200;
        
        if (!(r8_3 & 8))
            rdx_5 = rcx_6;
        
        int32_t rcx_8 = rdx_5 | 0x400;
        
        if (!(r8_3 & 4))
            rcx_8 = rdx_5;
        
        int32_t rdx_7 = rcx_8 | 0x800;
        
        if (!(r8_3 & 2))
            rdx_7 = rcx_8;
        
        int32_t rcx_10 = rdx_7 | 0x1000;
        
        if (!(r8_3 & 1))
            rcx_10 = rdx_7;
        
        int32_t rbx_3 = rcx_10 | 0x100;
        
        if (!TEST_BITD(r8_3, 0x13))
            rbx_3 = rcx_10;
        
        int32_t rax_3 = r8_3 & 0x300;
        int32_t arg_8;
        
        if (!rax_3)
            arg_8 = rbx_3;
        else if (rax_3 == 0x100)
        {
            rbx_3 |= 0x2000;
            arg_8 = rbx_3;
        }
        else if (rax_3 == 0x200)
        {
            rbx_3 |= 0x4000;
            arg_8 = rbx_3;
        }
        else
        {
            arg_8 = rbx_3;
            
            if (rax_3 == 0x300)
            {
                rbx_3 |= 0x6000;
                arg_8 = rbx_3;
            }
        }
        
        int32_t r8_4 = r8_3 & 0x3000000;
        
        if (r8_4 == 0x1000000)
        {
            rbx_3 |= 0x8040;
            arg_8 = rbx_3;
        }
        else if (r8_4 == 0x2000000)
        {
            rbx_3 |= 0x40;
            arg_8 = rbx_3;
        }
        else if (r8_4 == 0x3000000)
        {
            rbx_3 |= 0x8000;
            arg_8 = rbx_3;
        }
        
        if (!data_180047230 || !(rbx_3 & 0x40))
            rbx_3 &= 0xffffffbf;
        
        int32_t rcx_15 = rbx_3 >> 3 & 0x10;
        int32_t rdx_9 = rcx_15 | 8;
        
        if (!TEST_BITD(rbx_3, 9))
            rdx_9 = rcx_15;
        
        int32_t rcx_17 = rdx_9 | 4;
        
        if (!TEST_BITD(rbx_3, 0xa))
            rcx_17 = rdx_9;
        
        int32_t rdx_11 = rcx_17 | 2;
        
        if (!TEST_BITD(rbx_3, 0xb))
            rdx_11 = rcx_17;
        
        int32_t rcx_19 = rdx_11 | 1;
        
        if (!TEST_BITD(rbx_3, 0xc))
            rcx_19 = rdx_11;
        
        rdx_3 = rcx_19 | 0x80000;
        
        if (!TEST_BITD(rbx_3, 8))
            rdx_3 = rcx_19;
        
        int32_t rax_5 = rbx_3 & 0x6000;
        
        if (rax_5)
        {
            if (rax_5 == 0x2000)
                rdx_3 |= 0x100;
            else if (rax_5 == 0x4000)
                rdx_3 |= 0x200;
            else if (rax_5 == 0x6000)
                rdx_3 |= 0x300;
        }
        
        int32_t rbx_4 = rbx_3 & 0x8040;
        
        if (rbx_4 == 0x40)
            rdx_3 |= 0x2000000;
        else
        {
            if (rbx_4 == 0x8000)
                return rdx_3 | 0x3000000;
            
            if (rbx_4 == 0x8040)
                return rdx_3 | 0x1000000;
        }
    }
    
    return rdx_3;
}

