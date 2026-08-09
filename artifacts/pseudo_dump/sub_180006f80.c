
  char* sub_180006f80(int64_t* arg1, char* arg2, char* arg3)

{
    int64_t r15 = *arg1;
    int64_t rax;
    int64_t rdx;
    rdx = HIGHQ(0x6666666666666667 * (arg1[1] - r15));
    rax = LOWQ(0x6666666666666667 * (arg1[1] - r15));
    int64_t r9_3 = rdx >> 4;
    int64_t r9_4 = r9_3 + (r9_3 >> 0x3f);
    
    if (r9_4 == 0x666666666666666)
    {
        sub_1800052a0();
        /* no return */
    }
    
    int64_t rax_3;
    int64_t rdx_1;
    rdx_1 = HIGHQ(0x6666666666666667 * (arg1[2] - r15));
    rax_3 = LOWQ(0x6666666666666667 * (arg1[2] - r15));
    int64_t rdx_2 = rdx_1 >> 4;
    int64_t rdx_3 = rdx_2 + (rdx_2 >> 0x3f);
    uint64_t rcx_3 = rdx_3 >> 1;
    
    if (rdx_3 <= 0x666666666666666 - rcx_3)
    {
        int64_t rax_7 = rcx_3 + rdx_3;
        int64_t rcx_4 = r9_4 + 1;
        
        if (rax_7 >= r9_4 + 1)
            rcx_4 = rax_7;
        
        if (rcx_4 <= 0x666666666666666)
        {
            int64_t rsi_1 = rcx_4 * 0x28;
            char* rbx_1;
            
            if (!rsi_1)
            {
                rbx_1 = nullptr;
            label_180007091:
                char* r8 = rbx_1;
                char* result = &rbx_1[(arg2 - r15) / 0x28 * 0x28];
                *result = *arg3;
                int64_t rdx_7 = *(arg3 + 0x18);
                int64_t rcx_9 = *(arg3 + 0x10);
                int64_t rax_16 = *(arg3 + 8);
                __builtin_memset(&arg3[8], 0, 0x18);
                *(result + 8) = rax_16;
                *(result + 0x10) = rcx_9;
                *(result + 0x18) = rdx_7;
                result[0x20] = arg3[0x20];
                int64_t rdx_8 = arg1[1];
                char* rcx_10 = *arg1;
                
                if (arg2 != rdx_8)
                {
                    sub_180007400(rcx_10, arg2, r8);
                    rdx_8 = arg1[1];
                    r8 = &result[0x28];
                    rcx_10 = arg2;
                }
                
                sub_180007400(rcx_10, rdx_8, r8);
                void* rcx_11 = *arg1;
                
                if (!rcx_11)
                    goto label_1800071a9;
                
                sub_180006d00(rcx_11, arg1[1]);
                void* r8_2 = *arg1;
                int64_t rax_18;
                int64_t rdx_11;
                rdx_11 = HIGHQ(0x6666666666666667 * (arg1[2] - r8_2));
                rax_18 = LOWQ(0x6666666666666667 * (arg1[2] - r8_2));
                int64_t rdx_12 = rdx_11 >> 4;
                void* rcx_14;
                
                if ((rdx_12 + (rdx_12 >> 0x3f)) * 0x28 >= 0x1000)
                {
                    rcx_14 = *(r8_2 - 8);
                    
                    if (r8_2 - rcx_14 - 8 <= 0x1f)
                        goto label_18000718e;
                    
                    trap(0xd);
                }
                
                rcx_14 = r8_2;
            label_18000718e:
                j_sub_180021340(rcx_14);
            label_1800071a9:
                *arg1 = rbx_1;
                arg1[1] = &rbx_1[(r9_4 + 1) * 0x28];
                arg1[2] = &rbx_1[rsi_1];
                return result;
            }
            
            if (rsi_1 < 0x1000)
            {
                rbx_1 = sub_180016420(rsi_1);
                goto label_180007091;
            }
            
            if (rsi_1 + 0x27 > rsi_1)
            {
                int64_t rax_9 = sub_180016420(rsi_1 + 0x27);
                
                if (!rax_9)
                    trap(0xd);
                
                rbx_1 = (rax_9 + 0x27) & 0xffffffffffffffe0;
                *(rbx_1 - 8) = rax_9;
                goto label_180007091;
            }
        }
    }
    
    stdext::threads::_Throw_lock_error();
    /* no return */
}

