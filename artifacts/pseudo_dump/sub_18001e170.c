
  void* sub_18001e170(void* arg1, uint64_t arg2, char arg3)

{
    void* rax = *(arg1 + 0x458);
    void* rcx = arg1 + 0x50;
    int64_t rbx;
    rbx = arg3;
    uint64_t r11 = arg2;
    uint64_t rax_1;
    
    if (rax)
    {
        rcx = rax;
        rax_1 = *(arg1 + 0x450) >> 1;
    }
    else
        rax_1 = 0x200;
    
    char* r8_1 = rcx - 1 + rax_1;
    *(arg1 + 0x40) = r8_1;
    char* r10 = r8_1;
    
    while (true)
    {
        int32_t rax_3 = *(arg1 + 0x30);
        
        if (rax_3 <= 0 && !r11)
        {
            *(arg1 + 0x48) = r8_1 - *(arg1 + 0x40);
            *(arg1 + 0x40) = &r10[1];
            return &r10[1];
        }
        
        *(arg1 + 0x30) = rax_3 - 1;
        uint64_t rdx_1 = r11 / 0xa;
        r11 -= rdx_1 * 0xa;
        r11 += 0x30;
        char rax_5 = r11;
        char rcx_1 = r11;
        r11 = rdx_1;
        
        if (rax_5 > 0x39)
            rax_5 = ((rbx ^ 1) << 5) + 7 + rcx_1;
        
        *r10 = rax_5;
        *(arg1 + 0x40) -= 1;
        r10 = *(arg1 + 0x40);
    }
}

