
🌐  int64_t strcmp(char* arg1, int64_t arg2)

{
    char* rdx = arg2 - arg1;
    
    if (arg1 & 7)
        goto label_18002e208;
    
    while (true)
    {
        if (((rdx + arg1) & 0xfff) <= 0xff8)
        {
            int64_t rax_4 = *arg1;
            
            if (rax_4 == *(rdx + arg1))
            {
                arg1 = &arg1[8];
                
                if (-0x7f7f7f7f7f7f7f80 & ~rax_4 & (rax_4 - 0x101010101010101))
                    return 0;
                
                continue;
            }
        }
        
    label_18002e208:
        uint64_t rax_1 = *arg1;
        char temp0_1 = *(rdx + arg1);
        
        if (rax_1 != temp0_1)
            return (rax_1 - rax_1) | 1;
        
        arg1 = &arg1[1];
        
        if (!rax_1)
            return 0;
        
        if (arg1 & 7)
            break;
    }
}

