
  int64_t* sub_18000bf60(int64_t* arg1, int32_t* arg2)

{
    void* rax = strlen(arg2);
    int64_t r14 = arg1[3];
    
    if (rax <= r14)
    {
        int128_t* rdi;
        
        if (r14 <= 0xf)
            rdi = arg1;
        else
            rdi = *arg1;
        
        arg1[2] = rax;
        memcpy(rdi, arg2, rax);
        *(rdi + rax) = 0;
        return arg1;
    }
    
    int64_t rdi_1 = 0x7fffffffffffffff;
    
    if (rax > 0x7fffffffffffffff)
    {
        sub_180003aa0();
        /* no return */
    }
    
    int64_t rcx_3 = rax | 0xf;
    uint64_t rdx_2;
    
    if (rcx_3 <= 0x7fffffffffffffff)
        rdx_2 = r14 >> 1;
    
    uint64_t rcx_4;
    char* rsi_1;
    
    if (rcx_3 <= 0x7fffffffffffffff && r14 <= 0x7fffffffffffffff - rdx_2)
    {
        int64_t rax_3 = rdx_2 + r14;
        rdi_1 = rcx_3;
        
        if (rcx_3 < rax_3)
            rdi_1 = rax_3;
        
        if (rdi_1 == -1)
        {
            rsi_1 = nullptr;
            goto label_18000c051;
        }
        
        if (rdi_1 + 1 < 0x1000)
        {
            rsi_1 = sub_180016420(rdi_1 + 1);
            goto label_18000c051;
        }
        
        rcx_4 = rdi_1 + 0x28;
        
        if (rcx_4 > rdi_1 + 1)
            goto label_18000c02b;
        
        stdext::threads::_Throw_lock_error();
        /* no return */
    }
    
    rcx_4 = -0x7fffffffffffffd9;
label_18000c02b:
    int64_t rax_5 = sub_180016420(rcx_4);
    
    if (rax_5)
    {
        rsi_1 = (rax_5 + 0x27) & 0xffffffffffffffe0;
        *(rsi_1 - 8) = rax_5;
    label_18000c051:
        arg1[2] = rax;
        arg1[3] = rdi_1;
        memcpy(rsi_1, arg2, rax);
        *(rsi_1 + rax) = 0;
        
        if (r14 <= 0xf)
        {
            *arg1 = rsi_1;
            return arg1;
        }
        
        void* rcx_7 = *arg1;
        void* rax_7;
        
        if (r14 + 1 < 0x1000)
        {
            rax_7 = rcx_7;
        label_18000c0a2:
            j_sub_180021340(rax_7);
            *arg1 = rsi_1;
            return arg1;
        }
        
        rax_7 = *(rcx_7 - 8);
        
        if (rcx_7 - rax_7 - 8 <= 0x1f)
            goto label_18000c0a2;
    }
    
    trap(0xd);
}

