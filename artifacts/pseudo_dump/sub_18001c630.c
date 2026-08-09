
  uint64_t sub_18001c630(void* arg1)

{
    *(arg1 + 0x18) = 0;
    *(arg1 + 0x1c) = 0;
    *(arg1 + 0x24) = 0;
    *(arg1 + 0x30) = {0};
    char* rax = *(arg1 + 8);
    char r10 = *rax;
    char* rdx = &rax[1];
    *(arg1 + 0x18) = r10;
    *(arg1 + 8) = rdx;
    
    if (r10 & 1)
    {
        uint64_t rcx_1 = *rdx & 0xf;
        rdx -= *(rcx_1 + 0x180038880);
        *(arg1 + 0x1c) = *(rdx - 4) >> *(rcx_1 + 0x180038890);
        *(arg1 + 8) = rdx;
    }
    
    if (r10 & 2)
    {
        int32_t rax_4 = *rdx;
        rdx = &rdx[4];
        *(arg1 + 8) = rdx;
        *(arg1 + 0x20) = rax_4;
    }
    
    if (r10 & 4)
    {
        uint64_t rcx_4 = *rdx & 0xf;
        rdx -= *(rcx_4 + 0x180038880);
        *(arg1 + 0x24) = *(rdx - 4) >> *(rcx_4 + 0x180038890);
        *(arg1 + 8) = rdx;
    }
    
    *(arg1 + 0x28) = *rdx;
    uint32_t rax_9;
    rax_9 = r10 & 0x30;
    *(arg1 + 8) = &rdx[4];
    
    if (!(r10 & 8))
    {
        if (rax_9 == 0x10)
        {
            uint64_t rcx_9 = rdx[4] & 0xf;
            void* r9_1 = &rdx[4] - *(rcx_9 + 0x180038880);
            uint64_t rax_15 = *(arg1 + 0x48) + (*(r9_1 - 4) >> *(rcx_9 + 0x180038890));
            *(arg1 + 8) = r9_1;
            *(arg1 + 0x30) = rax_15;
            return rax_15;
        }
        
        if (rax_9 == 0x20)
        {
            int32_t rdx_4 = *(arg1 + 0x48);
            uint64_t rcx_12 = rdx[4] & 0xf;
            char* r9_2 = &rdx[4] - *(rcx_12 + 0x180038880);
            uint32_t rax_18 = *(r9_2 - 4) >> *(rcx_12 + 0x180038890);
            *(arg1 + 8) = r9_2;
            *(arg1 + 0x30) = rdx_4 + rax_18;
            uint64_t rcx_16 = *r9_2 & 0xf;
            void* r9_3 = r9_2 - *(rcx_16 + 0x180038880);
            rax_9 = *(r9_3 - 4) >> *(rcx_16 + 0x180038890);
            *(arg1 + 8) = r9_3;
            *(arg1 + 0x38) = rdx_4 + rax_9;
        }
    }
    else
    {
        if (rax_9 == 0x10)
        {
            int64_t rcx_6 = *(rdx + 4);
            *(arg1 + 8) = &rdx[8];
            *(arg1 + 0x30) = rcx_6;
            return &rdx[8];
        }
        
        if (rax_9 == 0x20)
        {
            int64_t rax_11 = *(rdx + 4);
            *(arg1 + 8) = &rdx[8];
            *(arg1 + 0x30) = rax_11;
            int64_t rcx_7 = *(rdx + 8);
            *(arg1 + 8) = &rdx[0xc];
            *(arg1 + 0x38) = rcx_7;
            return &rdx[0xc];
        }
    }
    
    return rax_9;
}

