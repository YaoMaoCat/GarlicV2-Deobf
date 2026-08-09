
  void* sub_18001e100(void* arg1, uint64_t arg2)

{
    void* r8 = arg1 + 0x50;
    uint64_t r9 = arg2;
    void* rax = *(r8 + 0x408);
    uint64_t rax_1;
    
    if (rax)
    {
        r8 = rax;
        rax_1 = *(arg1 + 0x450) >> 1;
    }
    else
        rax_1 = 0x200;
    
    char* rdx_1 = r8 - 1 + rax_1;
    *(arg1 + 0x40) = rdx_1;
    char* r8_1 = rdx_1;
    
    while (true)
    {
        int32_t rax_3 = *(arg1 + 0x30);
        
        if (rax_3 <= 0 && !r9)
        {
            *(arg1 + 0x48) = rdx_1 - *(arg1 + 0x40);
            *(arg1 + 0x40) = &r8_1[1];
            return &r8_1[1];
        }
        
        *(arg1 + 0x30) = rax_3 - 1;
        int32_t rax_4;
        rax_4 = r9;
        rax_4 &= 7;
        r9 u>>= 3;
        rax_4 += 0x30;
        *r8_1 = rax_4;
        *(arg1 + 0x40) -= 1;
        r8_1 = *(arg1 + 0x40);
    }
}

