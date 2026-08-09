
🌐  int64_t strncmp(char* arg1, int64_t arg2, int64_t arg3)

{
    char* rdx = arg2 - arg1;
    
    if (!arg3)
        return 0;
    
    if (arg1 & 7)
        goto label_18002e350;
    
    while (true)
    {
        if (((rdx + arg1) & 0xfff) <= 0xff8)
        {
            int64_t rax_4 = *arg1;
            
            if (rax_4 == *(rdx + arg1))
            {
                arg1 = &arg1[8];
                int64_t temp2_1 = arg3;
                arg3 -= 8;
                
                if (temp2_1 <= 8)
                    return 0;
                
                if (-0x7f7f7f7f7f7f7f80 & ~rax_4 & (-0x101010101010101 + rax_4))
                    return 0;
                
                continue;
            }
        }
        
    label_18002e350:
        uint64_t rax_1 = *arg1;
        char temp0_1 = *(rdx + arg1);
        
        if (rax_1 != temp0_1)
            return (rax_1 - rax_1) | 1;
        
        arg1 = &arg1[1];
        int64_t temp1_1 = arg3;
        arg3 -= 1;
        
        if (temp1_1 == 1)
            return 0;
        
        if (!rax_1)
            return 0;
        
        if (arg1 & 7)
            break;
    }
}

