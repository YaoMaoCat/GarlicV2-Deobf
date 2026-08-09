
  int64_t* sub_180002840(int64_t* arg1, int64_t arg2, int64_t arg3, int32_t* arg4, void* arg5)

{
    void* r14 = arg1[2];
    int64_t rbx = 0x7fffffffffffffff;
    
    if (0x7fffffffffffffff - r14 < arg2)
    {
        sub_180003aa0();
        /* no return */
    }
    
    int64_t rbp = arg1[3];
    void* r15 = r14 + arg2;
    int64_t rcx_1 = r15 | 0xf;
    uint64_t rdx_1;
    
    if (rcx_1 <= 0x7fffffffffffffff)
        rdx_1 = rbp >> 1;
    
    uint64_t rcx_2;
    int128_t* rdi_1;
    
    if (rcx_1 <= 0x7fffffffffffffff && rbp <= 0x7fffffffffffffff - rdx_1)
    {
        int64_t rax_2 = rdx_1 + rbp;
        rbx = rcx_1;
        
        if (rcx_1 < rax_2)
            rbx = rax_2;
        
        if (rbx == -1)
        {
            rdi_1 = nullptr;
            goto label_180002912;
        }
        
        if (rbx + 1 < 0x1000)
        {
            rdi_1 = sub_180016420(rbx + 1);
            goto label_180002912;
        }
        
        rcx_2 = rbx + 0x28;
        
        if (rcx_2 > rbx + 1)
            goto label_1800028e7;
        
        stdext::threads::_Throw_lock_error();
        /* no return */
    }
    
    rcx_2 = -0x7fffffffffffffd9;
label_1800028e7:
    int64_t rax_4 = sub_180016420(rcx_2);
    
    if (rax_4)
    {
        rdi_1 = (rax_4 + 0x27) & 0xffffffffffffffe0;
        *(rdi_1 - 8) = rax_4;
    label_180002912:
        arg1[2] = r15;
        char* r15_1 = rdi_1 + r14;
        arg1[3] = rbx;
        
        if (rbp <= 0xf)
        {
            memcpy(rdi_1, arg1, r14);
            memcpy(r15_1, arg4, arg5);
            *(r15_1 + arg5) = 0;
            *arg1 = rdi_1;
            return arg1;
        }
        
        int32_t* rbx_1 = *arg1;
        memcpy(rdi_1, rbx_1, r14);
        memcpy(r15_1, arg4, arg5);
        *(r15_1 + arg5) = 0;
        
        if (rbp + 1 < 0x1000)
        {
            j_sub_180021340(rbx_1);
            *arg1 = rdi_1;
            return arg1;
        }
        
        int64_t rcx_6 = *(rbx_1 - 8);
        
        if (rbx_1 - rcx_6 - 8 <= 0x1f)
        {
            j_sub_180021340(rcx_6);
            *arg1 = rdi_1;
            return arg1;
        }
    }
    
    trap(0xd);
}

