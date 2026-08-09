
  int32_t* sub_180002740(int128_t* arg1, int32_t* arg2, void* arg3)

{
    int64_t rsi = 0x7fffffffffffffff;
    char* r14 = arg1;
    
    if (arg3 > 0x7fffffffffffffff)
    {
        sub_180003aa0();
        /* no return */
    }
    
    if (arg3 <= 0xf)
    {
        arg1[1] = arg3;
        *(arg1 + 0x18) = 0xf;
        int32_t* rax = memcpy(arg1, arg2, arg3);
        *(r14 + arg3) = 0;
        return rax;
    }
    
    int64_t rax_2 = arg3 | 0xf;
    char* rdi;
    uint64_t rcx;
    
    if (rax_2 <= 0x7fffffffffffffff)
    {
        rsi = rax_2;
        
        if (rax_2 < 0x16)
            rsi = 0x16;
        
        if (rsi != -1)
        {
            if (rsi + 1 >= 0x1000)
            {
                rcx = rsi + 0x28;
                
                if (rcx > rsi + 1)
                    goto label_1800027ab;
                
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            rdi = sub_180016420(rsi + 1);
        }
        else
            rdi = nullptr;
    }
    else
    {
        rcx = -0x7fffffffffffffd9;
    label_1800027ab:
        int64_t rax_3 = sub_180016420(rcx);
        
        if (!rax_3)
            trap(0xd);
        
        rdi = (rax_3 + 0x27) & 0xffffffffffffffe0;
        *(rdi - 8) = rax_3;
    }
    *r14 = rdi;
    *(r14 + 0x10) = arg3;
    *(r14 + 0x18) = rsi;
    int32_t* rax_6 = memcpy(rdi, arg2, arg3);
    *(rdi + arg3) = 0;
    return rax_6;
}

