
  uint64_t sub_18001f048(void* arg1)

{
    int32_t rcx = *(arg1 + 0x34);
    uint64_t result;
    char* rdi;
    
    if (rcx == 2 ||
        (rcx != 3 && rcx != 0xc && (*(arg1 + 0x34) == 0xd || !((*(arg1 + 0x39) - 0x63) & 0xef))))
    {
        char* rcx_5 = *(arg1 + 0x18);
        rdi = arg1 + 0x50;
        char* rdx_2 = *(rdi + 0x408);
        
        if (!rdx_2)
            rdx_2 = rdi;
        
        *(arg1 + 0x18) = &rcx_5[8];
        result = *rcx_5;
        *rdx_2 = result;
        *(arg1 + 0x48) = 1;
    }
    else
    {
        wchar16* rcx_3 = *(arg1 + 0x18);
        *(arg1 + 0x18) = &rcx_3[4];
        char* rdx_1 = *(arg1 + 0x458);
        uint64_t r8_1;
        
        if (rdx_1)
        {
            rdi = arg1 + 0x50;
            r8_1 = *(arg1 + 0x450) >> 1;
        }
        else
        {
            rdx_1 = arg1 + 0x50;
            r8_1 = 0x200;
            rdi = rdx_1;
        }
        
        if (_wctomb_internal(arg1 + 0x48, rdx_1, r8_1, *rcx_3, *(arg1 + 8)))
            *(arg1 + 0x38) = 1;
    }
    
    char* rcx_6 = *(rdi + 0x408);
    result = 1;
    
    if (!rcx_6)
        rcx_6 = rdi;
    
    *(arg1 + 0x40) = rcx_6;
    return result;
}

