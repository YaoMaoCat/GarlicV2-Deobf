
  char* sub_180006aa0(char* arg1, int32_t* arg2, int64_t arg3)

{
    char* rsi = nullptr;
    __builtin_memset(arg1, 0, 0x20);
    
    if (arg2 == arg3)
    {
        *(arg1 + 0x18) = 0xf;
        *arg1 = 0;
        return arg1;
    }
    
    void* rdi_1 = arg3 - arg2;
    int64_t rbp = 0x7fffffffffffffff;
    
    if (rdi_1 > 0x7fffffffffffffff)
    {
        sub_180003aa0();
        /* no return */
    }
    
    if (rdi_1 <= 0xf)
    {
        *(arg1 + 0x10) = rdi_1;
        *(arg1 + 0x18) = 0xf;
        memcpy(arg1, arg2, rdi_1);
        *(arg1 + rdi_1) = 0;
        return arg1;
    }
    
    int64_t rax_3 = rdi_1 | 0xf;
    uint64_t rcx;
    
    if (rax_3 <= 0x7fffffffffffffff)
    {
        rbp = rax_3;
        
        if (rax_3 < 0x16)
            rbp = 0x16;
        
        if (rbp != -1)
        {
            if (rbp + 1 >= 0x1000)
            {
                rcx = rbp + 0x28;
                
                if (rcx > rbp + 1)
                    goto label_180006b3e;
                
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            rsi = sub_180016420(rbp + 1);
        }
    }
    else
    {
        rcx = -0x7fffffffffffffd9;
    label_180006b3e:
        int64_t rax_4 = sub_180016420(rcx);
        
        if (!rax_4)
            trap(0xd);
        
        rsi = (rax_4 + 0x27) & 0xffffffffffffffe0;
        *(rsi - 8) = rax_4;
    }
    *arg1 = rsi;
    *(arg1 + 0x10) = rdi_1;
    *(arg1 + 0x18) = rbp;
    memcpy(rsi, arg2, rdi_1);
    *(rsi + rdi_1) = 0;
    return arg1;
}

