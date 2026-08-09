
🌐  int64_t __acrt_stdio_flush_nolock(int32_t* arg1, int64_t* arg2)

{
    char rcx = arg1[5];
    
    if ((rcx & 3) == 2 && rcx & 0xc0)
    {
        int32_t rdi_2 = *arg1 - arg1[2];
        arg1[4] = 0;
        int16_t* rsi_1 = *(arg1 + 8);
        *arg1 = rsi_1;
        
        if (rdi_2 > 0)
        {
            if (rdi_2 != _write_internal(_fileno(arg1), rsi_1, rdi_2, arg2))
            {
                arg1[5] |= 0x10;
                return 0xffffffff;
            }
            
            if (arg1[5] >> 2 & 1)
                arg1[5] &= 0xfffffffd;
        }
    }
    
    return 0;
}

