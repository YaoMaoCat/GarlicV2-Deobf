
  int64_t sub_180007f00(int64_t* arg1, char arg2, int64_t* arg3, char arg4)

{
    int64_t* arg_18 = arg3;
    int128_t var_90;
    __builtin_memset(&var_90, 0, 0x18);
    char var_98 = arg2;
    int64_t rax = 0;
    int64_t rcx = 0;
    int64_t rdx = 0;
    int64_t var_80_1;
    
    if (&var_90 != arg3)
    {
        rdx = *arg3;
        var_90 = rdx;
        rcx = arg3[1];
        *(&var_90 + 8) = rcx;
        rax = arg3[2];
        var_80_1 = rax;
        __builtin_memset(arg3, 0, 0x18);
    }
    
    char var_78 = arg4;
    char* r14 = arg1[1];
    int64_t r12 = *arg1;
    void* rbx;
    int64_t rbp;
    
    if (r14 == arg1[2])
    {
        sub_180006f80(arg1, r14, &var_98);
        rbp = var_80_1;
        rbx = var_90;
    }
    else
    {
        *r14 = arg2;
        rbp = 0;
        rbx = nullptr;
        __builtin_memset(&var_90, 0, 0x18);
        *(r14 + 8) = rdx;
        *(r14 + 0x10) = rcx;
        *(r14 + 0x18) = rax;
        r14[0x20] = arg4;
        arg1[1] += 0x28;
    }
    
    if (arg4)
    {
        char var_70 = 0;
        int64_t var_68_1 = {0};
        int64_t var_58_1 = 0;
        char var_50_1 = 0;
        char* rdx_2 = arg1[1];
        int64_t rax_1;
        int64_t rcx_2;
        
        if (rdx_2 == arg1[2])
        {
            sub_180006f80(arg1, rdx_2, &var_70);
            rcx_2 = var_58_1;
            rax_1 = var_68_1;
        }
        else
        {
            *rdx_2 = 0;
            rcx_2 = 0;
            rax_1 = 0;
            __builtin_memset(&rdx_2[8], 0, 0x19);
            arg1[1] += 0x28;
        }
        
        if (rax_1)
        {
            int64_t r8_3;
            
            if (rcx_2 - rax_1 < 0x1000)
                r8_3 = rax_1;
            else
            {
                r8_3 = *(rax_1 - 8);
                
                if (rax_1 - r8_3 - 8 > 0x1f)
                    trap(0xd);
            }
            
            j_sub_180021340(r8_3);
        }
    }
    
    if (rbx)
    {
        void* rcx_7;
        
        if (rbp - rbx < 0x1000)
            rcx_7 = rbx;
        else
        {
            rcx_7 = *(rbx - 8);
            
            if (rbx - rcx_7 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_7);
    }
    
    void* rax_4 = *arg3;
    
    if (rax_4)
    {
        void* rcx_9;
        
        if (arg3[2] - rax_4 < 0x1000)
            rcx_9 = rax_4;
        else
        {
            rcx_9 = *(rax_4 - 8);
            
            if (rax_4 - rcx_9 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_9);
        __builtin_memset(arg3, 0, 0x18);
    }
    
    return (r14 - r12) / 0x28;
}

