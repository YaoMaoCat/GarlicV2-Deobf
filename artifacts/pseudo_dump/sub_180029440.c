
  uint64_t sub_180029440(int16_t* arg1, int16_t* arg2, int64_t arg3)

{
    int64_t i_1 = arg3;
    int16_t* r11 = arg2;
    int16_t* r10 = arg1;
    
    if (!arg3)
        return 0;
    
    uint32_t rcx;
    uint32_t r8;
    int64_t i;
    
    do
    {
        rcx = *r10;
        r10 = &r10[1];
        r8 = *r11;
        r11 = &r11[1];
        
        if (rcx != r8)
        {
            uint32_t rdx = rcx + 0x20;
            
            if (rcx - 0x41 > 0x19)
                rdx = rcx;
            
            rcx = rdx;
            uint32_t rdx_1 = r8 + 0x20;
            
            if (r8 - 0x41 > 0x19)
                rdx_1 = r8;
            
            r8 = rdx_1;
        }
        
        if (rcx != r8)
            break;
        
        if (!rcx)
            break;
        
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return rcx - r8;
}

