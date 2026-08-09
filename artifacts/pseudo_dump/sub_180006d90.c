
  int16_t* sub_180006d90(int64_t* arg1, int16_t* arg2)

{
    int16_t* rdi = arg1[1];
    int64_t rcx = arg1[2];
    
    if (rdi != rcx)
    {
        *rdi = *arg2;
        rdi[1] = arg2[1];
        rdi[2] = arg2[2];
        int64_t rcx_1 = *(arg2 + 0x10);
        int64_t rax_3 = *(arg2 + 8);
        int64_t r8 = *(arg2 + 0x18);
        __builtin_memset(&arg2[4], 0, 0x18);
        *(rdi + 0x10) = rcx_1;
        *(rdi + 8) = rax_3;
        *(rdi + 0x18) = r8;
        int64_t rax_4 = arg1[1];
        arg1[1] = rax_4 + 0x20;
        return rax_4;
    }
    
    int64_t rax_5 = *arg1;
    void* r12_1 = rdi - rax_5;
    int64_t rdx_1 = r12_1 >> 5;
    
    if (rdx_1 == 0x7ffffffffffffff)
    {
        sub_1800052a0();
        /* no return */
    }
    
    int64_t rcx_4 = (rcx - rax_5) >> 5;
    uint64_t r8_2 = rcx_4 >> 1;
    
    if (rcx_4 <= 0x7ffffffffffffff - r8_2)
    {
        int64_t rax_7 = r8_2 + rcx_4;
        int64_t r15_1 = rdx_1 + 1;
        
        if (rax_7 >= rdx_1 + 1)
            r15_1 = rax_7;
        
        if (r15_1 <= 0x7ffffffffffffff)
        {
            int64_t rcx_6 = r15_1 << 5;
            int16_t* rbp;
            
            if (!rcx_6)
            {
                rbp = nullptr;
            label_180006ec9:
                int16_t* r12_3 = (r12_1 & 0xffffffffffffffe0) + rbp;
                int16_t* r8_3 = rbp;
                *r12_3 = *arg2;
                r12_3[1] = arg2[1];
                r12_3[2] = arg2[2];
                int64_t rdx_2 = *(arg2 + 0x18);
                int64_t rcx_12 = *(arg2 + 0x10);
                int64_t rax_11 = *(arg2 + 8);
                __builtin_memset(&arg2[4], 0, 0x18);
                *(r12_3 + 8) = rax_11;
                *(r12_3 + 0x10) = rcx_12;
                *(r12_3 + 0x18) = rdx_2;
                int64_t rdx_3 = arg1[1];
                int16_t* rcx_13 = *arg1;
                
                if (rdi != rdx_3)
                {
                    sub_180004820(rcx_13, rdi, r8_3);
                    rdx_3 = arg1[1];
                    r8_3 = &r12_3[0x10];
                    rcx_13 = rdi;
                }
                
                sub_180004820(rcx_13, rdx_3, r8_3);
                sub_180007940(arg1, rbp, rdx_1 + 1, r15_1);
                return r12_3;
            }
            
            if (rcx_6 < 0x1000)
            {
                rbp = sub_180016420(rcx_6);
                goto label_180006ec9;
            }
            
            if (rcx_6 + 0x27 > rcx_6)
            {
                int64_t rax_9 = sub_180016420(rcx_6 + 0x27);
                
                if (!rax_9)
                    trap(0xd);
                
                rbp = (rax_9 + 0x27) & 0xffffffffffffffe0;
                *(rbp - 8) = rax_9;
                goto label_180006ec9;
            }
        }
    }
    
    stdext::threads::_Throw_lock_error();
    /* no return */
}

