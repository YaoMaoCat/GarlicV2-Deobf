
  int16_t* sub_180003fc0(int64_t* arg1, int16_t* arg2, int16_t* arg3)

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
            int16_t* rsi_1;
            
            if (!rbx_2)
            {
                rsi_1 = nullptr;
            label_18000408f:
                int16_t* r8 = rsi_1;
                int16_t* result = ((arg2 - r14) & 0xffffffffffffffe0) + rsi_1;
                *result = *arg3;
                result[1] = arg3[1];
                result[2] = arg3[2];
                int64_t rdx_2 = *(arg3 + 0x18);
                int64_t rcx_11 = *(arg3 + 0x10);
                int64_t rax_4 = *(arg3 + 8);
                __builtin_memset(&arg3[4], 0, 0x18);
                *(result + 8) = rax_4;
                *(result + 0x10) = rcx_11;
                *(result + 0x18) = rdx_2;
                int64_t rdx_3 = arg1[1];
                int16_t* rcx_12 = *arg1;
                
                if (arg2 != rdx_3)
                {
                    sub_180004820(rcx_12, arg2, r8);
                    rdx_3 = arg1[1];
                    r8 = &result[0x10];
                    rcx_12 = arg2;
                }
                
                sub_180004820(rcx_12, rdx_3, r8);
                void* rcx_13 = *arg1;
                
                if (!rcx_13)
                    goto label_180004164;
                
                sub_180003f30(rcx_13, arg1[1]);
                void* rax_5 = *arg1;
                void* rcx_14;
                
                if (((arg1[2] - rax_5) & 0xffffffffffffffe0) >= 0x1000)
                {
                    rcx_14 = *(rax_5 - 8);
                    
                    if (rax_5 - rcx_14 - 8 <= 0x1f)
                        goto label_18000415f;
                    
                    trap(0xd);
                }
                
                rcx_14 = rax_5;
            label_18000415f:
                j_sub_180021340(rcx_14);
            label_180004164:
                *arg1 = rsi_1;
                arg1[1] = &rsi_1[(rbp_2 + 1) * 0x10];
                arg1[2] = &rsi_1[rbx_1 * 0x10];
                return result;
            }
            
            if (rbx_2 < 0x1000)
            {
                rsi_1 = sub_180016420(rbx_2);
                goto label_18000408f;
            }
            
            if (rbx_2 + 0x27 > rbx_2)
            {
                int64_t rax_2 = sub_180016420(rbx_2 + 0x27);
                
                if (!rax_2)
                    trap(0xd);
                
                rsi_1 = (rax_2 + 0x27) & 0xffffffffffffffe0;
                *(rsi_1 - 8) = rax_2;
                goto label_18000408f;
            }
        }
    }
    
    stdext::threads::_Throw_lock_error();
    /* no return */
}

