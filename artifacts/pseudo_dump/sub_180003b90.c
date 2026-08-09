
  void* sub_180003b90(int64_t* arg1, char arg2)

{
    void* rdi = arg1[2];
    int64_t r14 = arg1[3];
    int64_t* rbx = arg1;
    
    if (rdi < r14)
    {
        arg1[2] = rdi + 1;
        
        if (r14 > 0xf)
            rbx = *arg1;
        
        *(rbx + rdi) = arg2;
        *(rbx + rdi + 1) = 0;
        return rdi + 1;
    }
    
    int64_t rbp = 0x7fffffffffffffff;
    
    if (0x7fffffffffffffff - rdi < 1)
    {
        sub_180003aa0();
        /* no return */
    }
    
    int64_t rcx_1 = (rdi + 1) | 0xf;
    uint64_t rdx_1;
    
    if (rcx_1 <= 0x7fffffffffffffff)
        rdx_1 = r14 >> 1;
    
    uint64_t rcx_2;
    char* rsi_1;
    
    if (rcx_1 <= 0x7fffffffffffffff && r14 <= 0x7fffffffffffffff - rdx_1)
    {
        int64_t rax_3 = rdx_1 + r14;
        rbp = rcx_1;
        
        if (rcx_1 < rax_3)
            rbp = rax_3;
        
        if (rbp == -1)
        {
            rsi_1 = nullptr;
            goto label_180003c88;
        }
        
        if (rbp + 1 < 0x1000)
        {
            rsi_1 = sub_180016420(rbp + 1);
            goto label_180003c88;
        }
        
        rcx_2 = rbp + 0x28;
        
        if (rcx_2 > rbp + 1)
            goto label_180003c65;
        
        stdext::threads::_Throw_lock_error();
        /* no return */
    }
    
    rcx_2 = -0x7fffffffffffffd9;
label_180003c65:
    int64_t rax_5 = sub_180016420(rcx_2);
    
    if (rax_5)
    {
        rsi_1 = (rax_5 + 0x27) & 0xffffffffffffffe0;
        *(rsi_1 - 8) = rax_5;
    label_180003c88:
        rbx[2] = rdi + 1;
        rbx[3] = rbp;
        int128_t* rcx_4 = rsi_1;
        int32_t* result;
        
        if (r14 <= 0xf)
        {
            result = memcpy(rcx_4, rbx, rdi);
            *(rsi_1 + rdi) = arg2;
            *(rsi_1 + rdi + 1) = 0;
            *rbx = rsi_1;
            return result;
        }
        
        int32_t* rbp_1 = *rbx;
        memcpy(rcx_4, rbp_1, rdi);
        *(rsi_1 + rdi) = arg2;
        *(rsi_1 + rdi + 1) = 0;
        
        if (r14 + 1 < 0x1000)
        {
            result = j_sub_180021340(rbp_1);
            *rbx = rsi_1;
            return result;
        }
        
        int64_t rcx_5 = *(rbp_1 - 8);
        
        if (rbp_1 - rcx_5 - 8 <= 0x1f)
        {
            result = j_sub_180021340(rcx_5);
            *rbx = rsi_1;
            return result;
        }
    }
    
    trap(0xd);
}

