
  int128_t* sub_1800029d0(int128_t* arg1, void** arg2)

{
    void** r14 = arg2;
    __builtin_memset(arg1, 0, 0x20);
    void* rsi = r14[2];
    
    if (r14[3] > 0xf)
        r14 = *r14;
    
    int64_t rdi = 0x7fffffffffffffff;
    
    if (rsi > 0x7fffffffffffffff)
    {
        sub_180003aa0();
        /* no return */
    }
    
    if (rsi <= 0xf)
    {
        arg1[1] = rsi;
        *(arg1 + 0x18) = 0xf;
        *arg1 = *r14;
        return arg1;
    }
    
    int64_t rax_2 = rsi | 0xf;
    int128_t* rax_5;
    uint64_t rcx;
    
    if (rax_2 <= 0x7fffffffffffffff)
    {
        rdi = rax_2;
        
        if (rax_2 < 0x16)
            rdi = 0x16;
        
        if (rdi != -1)
        {
            if (rdi + 1 >= 0x1000)
            {
                rcx = rdi + 0x28;
                
                if (rcx > rdi + 1)
                    goto label_180002a51;
                
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            rax_5 = sub_180016420(rdi + 1);
        }
        else
            rax_5 = nullptr;
    }
    else
    {
        rcx = -0x7fffffffffffffd9;
    label_180002a51:
        int64_t rax_3 = sub_180016420(rcx);
        
        if (!rax_3)
            trap(0xd);
        
        rax_5 = (rax_3 + 0x27) & 0xffffffffffffffe0;
        *(rax_5 - 8) = rax_3;
    }
    *arg1 = rax_5;
    arg1[1] = rsi;
    *(arg1 + 0x18) = rdi;
    memcpy(rax_5, r14, rsi + 1);
    return arg1;
}

