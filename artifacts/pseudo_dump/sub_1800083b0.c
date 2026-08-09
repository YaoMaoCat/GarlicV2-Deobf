
  uint64_t sub_1800083b0(int64_t* arg1, int64_t* arg2)

{
    int64_t rdi = *arg1;
    int64_t rax;
    int64_t rdx;
    rdx = HIGHQ(0x6666666666666667 * (arg1[1] - rdi));
    rax = LOWQ(0x6666666666666667 * (arg1[1] - rdi));
    int64_t rsi_1 = rdx >> 4;
    int64_t i = rsi_1 + (rsi_1 >> 0x3f);
    
    if (i > 1)
    {
        int16_t rbx_1 = 1;
        
        do
        {
            uint64_t rax_4 = rbx_1 * 5;
            
            if (*(rdi + (rax_4 << 3)) == 1)
            {
                char* rcx = *(rdi + (rax_4 << 3) + 8);
                
                if (*(rdi + (rax_4 << 3) + 0x10) - rcx >= 2)
                {
                    uint64_t r8_4 = *rcx << 8 | rcx[1];
                    
                    if (r8_4 == arg2[1] && !memcmp(&rcx[2], *arg2, r8_4))
                        return rbx_1;
                }
            }
            
            rbx_1 += 1;
        } while (rbx_1 < i);
    }
    
    return 0;
}

