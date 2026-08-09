
  int128_t* sub_180008240(int64_t* arg1, int128_t* arg2, int16_t arg3)

{
    int128_t zmm0;
    
    if (!arg3)
        zmm0 = {0};
    else
    {
        int64_t r9_1 = *arg1;
        uint64_t r8 = arg3;
        int64_t rax_1;
        int64_t rdx;
        rdx = HIGHQ(0x6666666666666667 * (arg1[1] - r9_1));
        rax_1 = LOWQ(0x6666666666666667 * (arg1[1] - r9_1));
        int64_t rdx_1 = rdx >> 4;
        
        if (r8 >= rdx_1 + (rdx_1 >> 0x3f))
            zmm0 = {0};
        else
        {
            uint64_t rax_4 = r8 * 5;
            
            if (*(r9_1 + (rax_4 << 3)) == 1)
            {
                char* rcx_2 = *(r9_1 + (rax_4 << 3) + 8);
                zmm0 = {0};
                
                if (*(r9_1 + (rax_4 << 3) + 0x10) - rcx_2 >= 2)
                {
                    uint64_t rdi = rcx_2[1];
                    uint64_t rax_9 = *rcx_2 << 8;
                    __builtin_memset(arg2, 0, 0x20);
                    uint64_t rdi_1 = rdi | rax_9;
                    
                    if (rdi_1 > 0xf)
                    {
                        int64_t rsi_2 = rdi_1 | 0xf;
                        
                        if (rsi_2 < 0x16)
                            rsi_2 = 0x16;
                        
                        int128_t* r14_2;
                        
                        if (rsi_2 + 1 < 0x1000)
                            r14_2 = sub_180016420(rsi_2 + 1);
                        else
                        {
                            if (rsi_2 + 0x28 <= rsi_2 + 1)
                            {
                                stdext::threads::_Throw_lock_error();
                                /* no return */
                            }
                            
                            int64_t rax_11 = sub_180016420(rsi_2 + 0x28);
                            
                            if (!rax_11)
                                trap(0xd);
                            
                            r14_2 = (rax_11 + 0x27) & 0xffffffffffffffe0;
                            *(r14_2 - 8) = rax_11;
                        }
                        
                        *arg2 = r14_2;
                        arg2[1] = rdi_1;
                        *(arg2 + 0x18) = rsi_2;
                        memcpy(r14_2, &rcx_2[2], rdi_1);
                        *(r14_2 + rdi_1) = 0;
                    }
                    else
                    {
                        arg2[1] = rdi_1;
                        *(arg2 + 0x18) = 0xf;
                        memcpy(arg2, &rcx_2[2], rdi_1);
                        *(arg2 + rdi_1) = 0;
                    }
                    
                    return arg2;
                }
            }
            else
                zmm0 = {0};
        }
    }
    
    *arg2 = zmm0;
    arg2[1] = 0;
    *(arg2 + 0x18) = 0xf;
    *arg2 = 0;
    return arg2;
}

