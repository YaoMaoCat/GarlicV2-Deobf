
  uint64_t sub_18001edec(int64_t* arg1)

{
    arg1[5] |= 0x10;
    int32_t rax = arg1[6];
    
    if (rax < 0)
    {
        rax = *(arg1 + 0x39);
        rax -= 0x41;
        rax &= 0xdf;
        char temp1_1 = rax;
        rax = -(rax);
        rax = ((rax - rax) & 0xfffffff9) + 0xd;
        arg1[6] = rax;
    }
    else if (!rax && (*(arg1 + 0x39) == 0x67 || *(arg1 + 0x39) == 0x47))
    {
        arg1[6] = 1;
        rax = 1;
    }
    
    void* r10 = 0x200;
    int32_t r8_1;
    void* r9;
    
    if (__crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>(&arg1[0xa], 
        rax + 0x15d, arg1[1]))
    {
        r8_1 = arg1[6];
        r9 = &arg1[0xa];
    }
    else
    {
        uint32_t rax_5;
        
        if (arg1[0x8b])
            rax_5 = arg1[0x8a] >> 1;
        else
            rax_5 = 0x200;
        
        r8_1 = rax_5 - 0x15d;
        arg1[6] = r8_1;
        r9 = &arg1[0xa];
    }
    
    void* rax_7 = arg1[0x8b];
    
    if (!rax_7)
        rax_7 = &arg1[0xa];
    
    arg1[8] = rax_7;
    int64_t* rcx_1 = arg1[3];
    int64_t arg_8 = 0;
    arg1[3] = &rcx_1[1];
    char* rdx_2 = arg1[0x8b];
    int64_t* r11 = arg1[1];
    int64_t rdi_1 = *arg1;
    int32_t rsi = *(arg1 + 0x39);
    arg_8 = *rcx_1;
    uint64_t rcx_2;
    char* r9_1;
    
    if (rdx_2)
    {
        r9_1 = &rdx_2[*(r9 + 0x400) >> 1];
        rcx_2 = arg1[0x8a] >> 1;
        r10 = arg1[0x8a] >> 1;
    }
    else
    {
        r9_1 = r9 + 0x200;
        rdx_2 = &arg1[0xa];
        rcx_2 = 0x200;
    }
    
    sub_180022380(&arg_8, rdx_2, r10, r9_1, rcx_2, rsi, r8_1, rdi_1, 1, r11);
    uint64_t result;
    
    if ((arg1[5] >> 5) & 1 && !arg1[6])
    {
        int64_t* rdi_2 = arg1[1];
        
        if (!rdi_2[5])
            __crt_cached_ptd_host::update_locale_slow(rdi_2);
        
        char* r9_4 = arg1[8];
        int64_t* r10_2 = rdi_2[3];
        uint64_t r8_3 = *r9_4;
        
        if (*(r8_3 + r10_2[0x22]) != 0x65)
        {
            do
            {
                r9_4 = &r9_4[1];
                r8_3 = *r9_4;
            } while (*(*r10_2 + (r8_3 << 1)) & 4);
        }
        
        char temp2_1 = *(r8_3 + r10_2[0x22]);
        
        if (temp2_1 == 0x78)
            r8_3 = r9_4[2];
        
        char* rdx_3 = &r9_4[2];
        
        if (temp2_1 != 0x78)
            rdx_3 = r9_4;
        
        result = **r10_2[0x1f];
        *rdx_3 = result;
        char* rdx_4 = &rdx_3[1];
        char* rcx_7;
        
        do
        {
            result = *rdx_4;
            rcx_7 = r8_3;
            *rdx_4 = r8_3;
            rdx_4 = &rdx_4[1];
            r8_3 = result;
        } while (rcx_7);
    }
    
    result = *(arg1 + 0x39);
    result -= 0x47;
    
    if (!(result & 0xdf) && !((arg1[5] >> 5) & 1))
    {
        int64_t* rdi_3 = arg1[1];
        
        if (!rdi_3[5])
            __crt_cached_ptd_host::update_locale_slow(rdi_3);
        
        __crt_stdio_output::crop_zeroes(arg1[8], &rdi_3[3]);
    }
    
    char* rcx_10 = arg1[8];
    result = *rcx_10;
    
    if (result == 0x2d)
    {
        arg1[5] |= 0x40;
        rcx_10 = &rcx_10[1];
        arg1[8] = rcx_10;
        result = *rcx_10;
    }
    
    result -= 0x49;
    
    if (result <= 0x25 && TEST_BITQ(0x2100000021, result))
    {
        arg1[5] &= 0xfffffff7;
        *(arg1 + 0x39) = 0x73;
    }
    
    int64_t rdx_6 = -1;
    
    do
        rdx_6 += 1;
     while (rcx_10[rdx_6]);
    
    result = 1;
    arg1[9] = rdx_6;
    return result;
}

