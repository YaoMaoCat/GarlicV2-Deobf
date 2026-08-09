
  int128_t* sub_180006bd0(int128_t* arg1, int32_t* arg2, int64_t* arg3)

{
    int64_t* rbx = arg3;
    void* rax = strlen(arg2);
    void* rdx = rbx[2];
    int64_t rax_1 = rbx[3];
    
    if (rax > rax_1 - rdx)
        rbx = sub_1800071e0(rbx, rax, 0, nullptr, arg2, rax);
    else
    {
        rbx[2] = rdx + rax;
        int64_t* rdi_1;
        
        if (rax_1 <= 0xf)
            rdi_1 = rbx;
        else
            rdi_1 = *rbx;
        
        void* r15_1;
        
        if (rax + arg2 <= rdi_1 || arg2 > rdx + rdi_1)
            r15_1 = rax;
        else if (rdi_1 > arg2)
            r15_1 = rdi_1 - arg2;
        else
            r15_1 = nullptr;
        
        memcpy(rdi_1 + rax, rdi_1, rdx + 1);
        memcpy(rdi_1, arg2, r15_1);
        memcpy(rdi_1 + r15_1, r15_1 + rax + arg2, rax - r15_1);
    }
    
    __builtin_memset(arg1, 0, 0x20);
    *arg1 = *rbx;
    arg1[1] = *(rbx + 0x10);
    rbx[2] = 0;
    rbx[3] = 0xf;
    *rbx = 0;
    return arg1;
}

