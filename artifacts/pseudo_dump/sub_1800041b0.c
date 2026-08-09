
  char* sub_1800041b0(int64_t* arg1, char* arg2, char* arg3)

{
    int64_t r14 = *arg1;
    int64_t rbp_2 = (arg1[1] - r14) >> 5;
    
    if (rbp_2 == 0x7ffffffffffffff)
    {
        sub_1800052a0();
        /* no return */
    }
    
    int64_t rcx_2 = (arg1[2] - r14) >> 5;
    uint64_t rdx_1 = rcx_2 >> 1;
    
    if (rcx_2 <= 0x7ffffffffffffff - rdx_1)
    {
        int64_t rax_1 = rdx_1 + rcx_2;
        int64_t rbx_1 = rbp_2 + 1;
        
        if (rax_1 >= rbp_2 + 1)
            rbx_1 = rax_1;
        
        if (rbx_1 <= 0x7ffffffffffffff)
        {
            int64_t rbx_2 = rbx_1 << 5;
            char* rsi_1;
            
            if (!rbx_2)
            {
                rsi_1 = nullptr;
            label_180004286:
                char* result = ((arg2 - r14) & 0xffffffffffffffe0) + rsi_1;
                *result = *arg3;
                int64_t r8 = *(arg3 + 0x18);
                int64_t rdx_2 = *(arg3 + 0x10);
                int64_t rcx_9 = *(arg3 + 8);
                __builtin_memset(&arg3[8], 0, 0x18);
                *(result + 0x18) = r8;
                char* r8_1 = rsi_1;
                *(result + 8) = rcx_9;
                *(result + 0x10) = rdx_2;
                int64_t rdx_3 = arg1[1];
                char* rcx_10 = *arg1;
                
                if (arg2 != rdx_3)
                {
                    sub_1800048b0(rcx_10, arg2, r8_1);
                    rdx_3 = arg1[1];
                    r8_1 = &result[0x20];
                    rcx_10 = arg2;
                }
                
                sub_1800048b0(rcx_10, rdx_3, r8_1);
                void* rcx_11 = *arg1;
                
                if (!rcx_11)
                    goto label_18000433f;
                
                sub_180003f30(rcx_11, arg1[1]);
                void* rax_4 = *arg1;
                void* rcx_12;
                
                if (((arg1[2] - rax_4) & 0xffffffffffffffe0) >= 0x1000)
                {
                    rcx_12 = *(rax_4 - 8);
                    
                    if (rax_4 - rcx_12 - 8 <= 0x1f)
                        goto label_18000433a;
                    
                    trap(0xd);
                }
                
                rcx_12 = rax_4;
            label_18000433a:
                j_sub_180021340(rcx_12);
            label_18000433f:
                *arg1 = rsi_1;
                arg1[1] = &rsi_1[(rbp_2 + 1) << 5];
                arg1[2] = &rsi_1[rbx_2];
                return result;
            }
            
            if (rbx_2 < 0x1000)
            {
                rsi_1 = sub_180016420(rbx_2);
                goto label_180004286;
            }
            
            if (rbx_2 + 0x27 > rbx_2)
            {
                int64_t rax_2 = sub_180016420(rbx_2 + 0x27);
                
                if (!rax_2)
                    trap(0xd);
                
                rsi_1 = (rax_2 + 0x27) & 0xffffffffffffffe0;
                *(rsi_1 - 8) = rax_2;
                goto label_180004286;
            }
        }
    }
    
    stdext::threads::_Throw_lock_error();
    /* no return */
}

