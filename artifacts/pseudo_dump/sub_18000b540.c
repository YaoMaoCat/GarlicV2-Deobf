
  int64_t* sub_18000b540(int64_t* arg1, int32_t* arg2, int64_t* arg3)

{
    int64_t r14 = *arg1;
    int64_t r9_2 = (arg1[1] - r14) >> 3;
    
    if (r9_2 == 0x1fffffffffffffff)
    {
        sub_1800052a0();
        /* no return */
    }
    
    int64_t rcx_2 = (arg1[2] - r14) >> 3;
    uint64_t rdx_1 = rcx_2 >> 1;
    
    if (rcx_2 <= 0x1fffffffffffffff - rdx_1)
    {
        int64_t rax_1 = rdx_1 + rcx_2;
        int64_t rsi_1 = r9_2 + 1;
        
        if (rax_1 >= r9_2 + 1)
            rsi_1 = rax_1;
        
        if (rsi_1 <= 0x1fffffffffffffff)
        {
            int64_t rsi_2 = rsi_1 << 3;
            int128_t* rbx_1;
            
            if (!rsi_2)
            {
                rbx_1 = nullptr;
            label_18000b61a:
                int64_t* result = ((arg2 - r14) & 0xfffffffffffffff8) + rbx_1;
                *result = *arg3;
                int128_t* rcx_9 = rbx_1;
                int64_t r8 = arg1[1];
                int32_t* rdx_2 = *arg1;
                void* r8_1;
                
                if (arg2 != r8)
                {
                    memcpy(rcx_9, rdx_2, arg2 - rdx_2);
                    rcx_9 = &result[1];
                    r8_1 = arg1[1] - arg2;
                    rdx_2 = arg2;
                }
                else
                    r8_1 = r8 - rdx_2;
                
                memcpy(rcx_9, rdx_2, r8_1);
                void* rcx_10 = *arg1;
                
                if (!rcx_10)
                    goto label_18000b6b5;
                
                void* rax_7;
                
                if ((arg1[2] - rcx_10) >> 3 << 3 >= 0x1000)
                {
                    rax_7 = *(rcx_10 - 8);
                    
                    if (rcx_10 - rax_7 - 8 <= 0x1f)
                        goto label_18000b69f;
                    
                    trap(0xd);
                }
                
                rax_7 = rcx_10;
            label_18000b69f:
                j_sub_180021340(rax_7);
            label_18000b6b5:
                *arg1 = rbx_1;
                arg1[1] = rbx_1 + ((r9_2 + 1) << 3);
                arg1[2] = rsi_2 + rbx_1;
                return result;
            }
            
            if (rsi_2 < 0x1000)
            {
                rbx_1 = sub_180016420(rsi_2);
                goto label_18000b61a;
            }
            
            if (rsi_2 + 0x27 > rsi_2)
            {
                int64_t rax_2 = sub_180016420(rsi_2 + 0x27);
                
                if (!rax_2)
                    trap(0xd);
                
                rbx_1 = (rax_2 + 0x27) & 0xffffffffffffffe0;
                *(rbx_1 - 8) = rax_2;
                goto label_18000b61a;
            }
        }
    }
    
    stdext::threads::_Throw_lock_error();
    /* no return */
}

