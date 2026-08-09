
  uint64_t sub_1800294f0(char* arg1, char* arg2, uint64_t arg3)

{
    uint64_t i_1 = arg3;
    char* rbx = arg2;
    char* r11 = arg1;
    
    if (data_180047834)
        /* tailcall */
        return sub_180029580(arg1, arg2, arg3, nullptr);
    
    if (!arg1 || !arg2 || arg3 > 0x7fffffff)
        /* tailcall */
        return sub_1800294b0(arg1, arg2, arg3);
    
    if (!arg3)
        return 0;
    
    uint64_t result;
    uint64_t i;
    
    do
    {
        uint32_t rcx = *r11;
        r11 = &r11[1];
        uint32_t r8 = *rbx;
        rbx = &rbx[1];
        
        if (rcx != r8)
        {
            uint32_t rdx = rcx + 0x20;
            
            if (rcx - 0x41 > 0x19)
                rdx = rcx;
            
            rcx = rdx;
            
            if (r8 - 0x41 <= 0x19)
                r8 += 0x20;
        }
        
        result = rcx - r8;
        
        if (rcx != r8 || !rcx)
            return result;
        
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return result;
}

