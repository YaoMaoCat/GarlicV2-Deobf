
  int64_t* sub_1800071e0(int64_t* arg1, int64_t arg2, int64_t arg3, void* arg4, int32_t* arg5, void* arg6)

{
    int64_t r14 = arg1[2];
    int64_t rbx = 0x7fffffffffffffff;
    
    if (0x7fffffffffffffff - r14 < arg2)
    {
        sub_180003aa0();
        /* no return */
    }
    
    int64_t rbp = arg1[3];
    int64_t r12 = r14 + arg2;
    int64_t rcx_1 = r12 | 0xf;
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
            goto label_1800072b1;
        }
        
        if (rbx + 1 < 0x1000)
        {
            rdi_1 = sub_180016420(rbx + 1);
            goto label_1800072b1;
        }
        
        rcx_2 = rbx + 0x28;
        
        if (rcx_2 > rbx + 1)
            goto label_180007287;
        
        stdext::threads::_Throw_lock_error();
        /* no return */
    }
    
    rcx_2 = -0x7fffffffffffffd9;
label_180007287:
    int64_t rax_4 = sub_180016420(rcx_2);
    
    if (rax_4)
    {
        rdi_1 = (rax_4 + 0x27) & 0xffffffffffffffe0;
        *(rdi_1 - 8) = rax_4;
    label_1800072b1:
        arg1[2] = r12;
        arg1[3] = rbx;
        int128_t* r12_1 = rdi_1 + arg4;
        
        if (rbp <= 0xf)
        {
            memcpy(rdi_1, arg1, arg4);
            memcpy(r12_1, arg5, arg6);
            memcpy(r12_1 + arg6, arg1 + arg4, r14 - arg4 + 1);
            *arg1 = rdi_1;
            return arg1;
        }
        
        int32_t* rbx_2 = *arg1;
        memcpy(rdi_1, rbx_2, arg4);
        memcpy(r12_1, arg5, arg6);
        memcpy(r12_1 + arg6, rbx_2 + arg4, r14 - arg4 + 1);
        
        if (rbp + 1 < 0x1000)
        {
            j_sub_180021340(rbx_2);
            *arg1 = rdi_1;
            return arg1;
        }
        
        int64_t rcx_7 = *(rbx_2 - 8);
        
        if (rbx_2 - rcx_7 - 8 <= 0x1f)
        {
            j_sub_180021340(rcx_7);
            *arg1 = rdi_1;
            return arg1;
        }
    }
    
    trap(0xd);
}

