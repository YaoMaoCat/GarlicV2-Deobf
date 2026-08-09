
  void sub_180003d30(int128_t* arg1, int64_t arg2)

{
    void* r15 = arg1[1];
    
    if (r15 > arg2)
        return;
    
    int64_t rsi_1 = *(arg1 + 0x18);
    
    if (rsi_1 == arg2)
        return;
    
    if (rsi_1 < arg2)
    {
        int64_t rdi_1 = 0x7fffffffffffffff;
        
        if (0x7fffffffffffffff - r15 < arg2 - r15)
        {
            sub_180003aa0();
            /* no return */
        }
        
        int64_t rcx_1 = arg2 | 0xf;
        uint64_t rdx_1;
        
        if (rcx_1 <= 0x7fffffffffffffff)
            rdx_1 = rsi_1 >> 1;
        
        int128_t* r14_1;
        uint64_t rcx_2;
        
        if (rcx_1 > 0x7fffffffffffffff || rsi_1 > 0x7fffffffffffffff - rdx_1)
        {
            rcx_2 = -0x7fffffffffffffd9;
        label_180003deb:
            int64_t rax_5 = sub_180016420(rcx_2);
            
            if (!rax_5)
                trap(0xd);
            
            r14_1 = (rax_5 + 0x27) & 0xffffffffffffffe0;
            *(r14_1 - 8) = rax_5;
        }
        else
        {
            int64_t rax_3 = rdx_1 + rsi_1;
            rdi_1 = rcx_1;
            
            if (rcx_1 < rax_3)
                rdi_1 = rax_3;
            
            if (rdi_1 != -1)
            {
                if (rdi_1 + 1 >= 0x1000)
                {
                    rcx_2 = rdi_1 + 0x28;
                    
                    if (rcx_2 > rdi_1 + 1)
                        goto label_180003deb;
                    
                    stdext::threads::_Throw_lock_error();
                    /* no return */
                }
                
                r14_1 = sub_180016420(rdi_1 + 1);
            }
            else
                r14_1 = nullptr;
        }
        arg1[1] = arg2;
        *(arg1 + 0x18) = rdi_1;
        
        if (rsi_1 <= 0xf)
        {
            memcpy(r14_1, arg1, r15 + 1);
            *arg1 = r14_1;
            arg1[1] = r15;
        }
        else
        {
            int32_t* rdi_2 = *arg1;
            memcpy(r14_1, rdi_2, r15 + 1);
            
            if (rsi_1 + 1 < 0x1000)
            {
                j_sub_180021340(rdi_2);
                *arg1 = r14_1;
                arg1[1] = r15;
            }
            else
            {
                int64_t rcx_5 = *(rdi_2 - 8);
                
                if (rdi_2 - rcx_5 - 8 > 0x1f)
                    trap(0xd);
                
                j_sub_180021340(rcx_5);
                *arg1 = r14_1;
                arg1[1] = r15;
            }
        }
    }
    else if (arg2 <= 0xf && rsi_1 > 0xf)
    {
        int32_t* rdi_5 = *arg1;
        memcpy(arg1, rdi_5, r15 + 1);
        
        if (*(arg1 + 0x18) + 1 < 0x1000)
        {
            j_sub_180021340(rdi_5);
            *(arg1 + 0x18) = 0xf;
        }
        else
        {
            int32_t* rcx_7 = *(rdi_5 - 8);
            
            if (rdi_5 - rcx_7 - 8 > 0x1f)
                trap(0xd);
            
            j_sub_180021340(rcx_7);
            *(arg1 + 0x18) = 0xf;
        }
    }
}

