
  uint32_t sub_18001ed70(void* arg1)

{
    int64_t* rdx_4 = *(arg1 + 0x18);
    *(arg1 + 0x18) = &rdx_4[1];
    int16_t* r9 = *rdx_4;
    int64_t r10_1;
    
    if (r9)
        r10_1 = *(r9 + 8);
    
    uint32_t result;
    
    if (!r9 || !r10_1)
    {
        result = 6;
        *(arg1 + 0x40) = "(null)";
        *(arg1 + 0x4c) = 0;
    }
    else
    {
        int32_t rdx = *(arg1 + 0x34);
        void* rax;
        
        if (rdx == 2)
            rax = 0;
        else if (rdx == 3 || rdx == 0xc)
            rax = 1;
        else if (*(arg1 + 0x34) == 0xd)
            rax = 0;
        else
            rax = (*(arg1 + 0x39) - 0x63) & 0xef;
        
        *(arg1 + 0x40) = r10_1;
        result = *r9;
        
        if (!rax)
            *(arg1 + 0x4c) = 0;
        else
        {
            *(arg1 + 0x4c) = 1;
            result u>>= 1;
        }
    }
    
    *(arg1 + 0x48) = result;
    result = 1;
    return result;
}

