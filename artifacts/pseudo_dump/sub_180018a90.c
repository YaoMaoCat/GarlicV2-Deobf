
  int64_t* sub_180018a90(int64_t* arg1, int64_t arg2, int32_t arg3, int64_t* arg4, void* arg5)

{
    int32_t rbp = *(arg5 + 0xc);
    int32_t rax = sub_180019fb0(arg5, arg4);
    
    if (!rbp)
    {
        abort();
        /* no return */
    }
    
    int64_t r11 = arg4[1];
    int32_t r9 = -1;
    int64_t rbx_1 = *(arg5 + 0x10);
    int32_t rdx_1 = rbp;
    int32_t r15 = -1;
    int64_t rdi_1 = r11 + rbx_1;
    void* r8_1;
    int32_t r10_1;
    
    while (true)
    {
        uint64_t r8 = rdx_1 - 1;
        uint64_t rcx_1 = r8 * 5;
        
        if (rax > *(r11 + (rcx_1 << 2) + rbx_1 + 4) && rax <= *(rdi_1 + (rcx_1 << 2) + 8))
        {
            r8_1 = r11 + (rdx_1 - 1) * 0x14 + rbx_1;
            r10_1 = 0;
            break;
        }
        
        rdx_1 = r8;
        
        if (!r8)
        {
            r10_1 = 0;
            r8_1 = nullptr;
            break;
        }
    }
    
    int32_t rdx_2 = 0;
    
    do
    {
        uint64_t rcx_2 = rdx_2 * 5;
        
        if (!r8_1)
        {
        label_180018b3e:
            
            if (arg3 >= *(rdi_1 + (rcx_2 << 2)) && arg3 <= *(rdi_1 + (rcx_2 << 2) + 4))
            {
                r15 = rdx_2;
                
                if (r9 == 0xffffffff)
                    r9 = rdx_2;
            }
        }
        else if (*(rdi_1 + (rcx_2 << 2)) > *(r8_1 + 4)
                && *(rdi_1 + (rcx_2 << 2) + 4) <= *(r8_1 + 8))
            goto label_180018b3e;
        
        rdx_2 += 1;
    } while (rdx_2 < rbp);
    
    int32_t rax_5 = 0;
    *arg1 = arg2;
    arg1[2] = arg2;
    
    if (r9 != 0xffffffff)
        rax_5 = r9;
    
    arg1[1] = rax_5;
    int32_t var_3c;
    *(arg1 + 0xc) = var_3c;
    
    if (r9 != 0xffffffff)
        r10_1 = r15 + 1;
    
    *(arg1 + 0x1c) = var_3c;
    arg1[3] = r10_1;
    return arg1;
}

