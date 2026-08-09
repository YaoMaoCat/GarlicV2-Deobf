
  void* sub_180007480(int64_t* arg1, int32_t* arg2, int64_t arg3)

{
    int128_t* rbx = *arg1;
    uint64_t rdi_1 = arg3 - arg2;
    int64_t rdx = arg1[2];
    void* rcx_1 = rdx - rbx;
    
    if (rdi_1 <= rcx_1)
    {
        void* r14_1 = arg1[1] - rbx;
        void* rax_2;
        
        if (rdi_1 <= r14_1)
        {
            memcpy(rbx, arg2, rdi_1);
            rax_2 = rbx + rdi_1;
        }
        else
        {
            memcpy(rbx, arg2, r14_1);
            int128_t* rbx_4 = arg1[1];
            void* rdi_2 = rdi_1 - r14_1;
            memcpy(rbx_4, r14_1 + arg2, rdi_2);
            rax_2 = rdi_2 + rbx_4;
        }
        
        arg1[1] = rax_2;
        return rax_2;
    }
    
    uint64_t rbp = 0x7fffffffffffffff;
    
    if (rdi_1 > 0x7fffffffffffffff)
    {
        sub_1800052a0();
        /* no return */
    }
    
    uint64_t r8_1 = rcx_1 >> 1;
    
    if (rcx_1 <= 0x7fffffffffffffff - r8_1)
    {
        rbp = r8_1 + rcx_1;
        
        if (rbp < rdi_1)
            rbp = rdi_1;
    }
    
    if (rbx)
    {
        int128_t* rcx_2;
        
        if (rdx - rbx < 0x1000)
            rcx_2 = rbx;
        else
        {
            rcx_2 = *(rbx - 8);
            
            if (rbx - rcx_2 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_2);
        __builtin_memset(arg1, 0, 0x18);
    }
    
    sub_180007840(arg1, rbp);
    int128_t* rbx_3 = *arg1;
    memcpy(rbx_3, arg2, rdi_1);
    void* rax_1 = rdi_1 + rbx_3;
    arg1[1] = rax_1;
    return rax_1;
}

