
  int64_t sub_180006510(int64_t* arg1, char* arg2)

{
    char* r14 = arg1[1];
    int64_t rcx = arg1[2];
    
    if (r14 != rcx)
    {
        char result = *arg2;
        *r14 = result;
        arg1[1] += 1;
        return result;
    }
    
    int64_t rax = *arg1;
    void* rbx = 0x7fffffffffffffff;
    void* rbp_1 = r14 - rax;
    
    if (rbp_1 == 0x7fffffffffffffff)
    {
        sub_1800052a0();
        /* no return */
    }
    
    int64_t rcx_1 = rcx - rax;
    uint64_t rdx_1 = rcx_1 >> 1;
    char* rsi;
    uint64_t rcx_2;
    
    if (rcx_1 <= 0x7fffffffffffffff - rdx_1)
    {
        void* rax_3 = rdx_1 + rcx_1;
        rbx = rbp_1 + 1;
        
        if (rax_3 >= rbp_1 + 1)
            rbx = rax_3;
        
        if (rbx)
        {
            if (rbx >= 0x1000)
            {
                rcx_2 = rbx + 0x27;
                
                if (rcx_2 > rbx)
                    goto label_180006593;
                
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            rsi = sub_180016420(rbx);
        }
        else
            rsi = nullptr;
    }
    else
    {
        rcx_2 = -0x7fffffffffffffda;
    label_180006593:
        int64_t rax_2 = sub_180016420(rcx_2);
        
        if (!rax_2)
            trap(0xd);
        
        rsi = (rax_2 + 0x27) & 0xffffffffffffffe0;
        *(rsi - 8) = rax_2;
    }
    *(rsi + rbp_1) = *arg2;
    int128_t* rcx_6 = rsi;
    int64_t r8 = arg1[1];
    int32_t* rdx_2 = *arg1;
    void* r8_1;
    
    if (r14 != r8)
    {
        memcpy(rcx_6, rdx_2, r14 - rdx_2);
        rcx_6 = rbp_1 + 1 + rsi;
        rdx_2 = r14;
        r8_1 = arg1[1] - r14;
    }
    else
        r8_1 = r8 - rdx_2;
    
    memcpy(rcx_6, rdx_2, r8_1);
    /* tailcall */
    return sub_180004fa0(arg1, rsi, rbp_1 + 1, rbx);
}

