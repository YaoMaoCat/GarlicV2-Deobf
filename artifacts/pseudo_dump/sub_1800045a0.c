
  void sub_1800045a0(int64_t* arg1, int128_t* arg2, int32_t* arg3, int128_t* arg4)

{
    if (!arg4)
        return;
    
    int128_t* arg_20 = arg4;
    int32_t* arg_10 = arg2;
    int64_t* arg_8 = arg1;
    int128_t* r14_1 = arg1[1];
    int64_t rdx = arg1[2];
    
    if (arg4 <= rdx - r14_1)
    {
        int64_t* var_60_2 = &arg1[1];
        int128_t* var_68 = r14_1;
        void* r15_5 = r14_1 - arg2;
        
        if (arg4 >= r15_5)
        {
            int128_t* rdi_5 = arg2 + arg4;
            arg_20 = rdi_5;
            memcpy(rdi_5, arg2, r15_5);
            arg1[1] = r15_5 + rdi_5;
            memcpy(arg2, arg3, arg4);
        }
        else
        {
            int32_t* rdi_3 = r14_1 - arg4;
            memcpy(r14_1, rdi_3, arg4);
            arg1[1] = arg4 + r14_1;
            void* rdi_4 = rdi_3 - arg2;
            memcpy(r14_1 - rdi_4, arg2, rdi_4);
            memcpy(arg2, arg3, arg4);
        }
        
        return;
    }
    
    int32_t* r15_1 = *arg1;
    void* r12_3 = r14_1 - r15_1;
    void* rdi_1 = 0x7fffffffffffffff;
    
    if (arg4 > 0x7fffffffffffffff - r12_3)
    {
        sub_1800052a0();
        /* no return */
    }
    
    void* r8 = r12_3 + arg4;
    void* rdx_1 = rdx - r15_1;
    uint64_t rcx_1 = rdx_1 >> 1;
    int128_t* r15_2;
    uint64_t rcx_2;
    
    if (rdx_1 <= 0x7fffffffffffffff - rcx_1)
    {
        void* rax_6 = rcx_1 + rdx_1;
        rdi_1 = r8;
        
        if (rax_6 >= r8)
            rdi_1 = rax_6;
        
        if (rdi_1)
        {
            if (rdi_1 >= 0x1000)
            {
                rcx_2 = rdi_1 + 0x27;
                
                if (rcx_2 > rdi_1)
                    goto label_180004641;
                
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            r15_2 = sub_180016420(rdi_1);
        }
        else
            r15_2 = nullptr;
    }
    else
    {
        rcx_2 = -0x7fffffffffffffda;
    label_180004641:
        int64_t rax_5 = sub_180016420(rcx_2);
        
        if (!rax_5)
            trap(0xd);
        
        r15_2 = (rax_5 + 0x27) & 0xffffffffffffffe0;
        *(r15_2 - 8) = rax_5;
    }
    int64_t* rax_9 = arg2 - r15_1;
    int128_t* rax_10 = rax_9 + r15_2;
    memcpy(rax_10, arg3, arg4);
    int128_t* rcx_6;
    int32_t* rdx_3;
    void* r8_2;
    
    if (arg4 != 1 || arg2 != r14_1)
    {
        memcpy(r15_2, r15_1, rax_9);
        rcx_6 = rax_10 + arg4;
        r8_2 = r14_1 - arg2;
        rdx_3 = arg2;
    }
    else
    {
        r8_2 = r12_3;
        rdx_3 = r15_1;
        rcx_6 = r15_2;
    }
    
    memcpy(rcx_6, rdx_3, r8_2);
    sub_180004fa0(arg1, r15_2, r8, rdi_1);
}

