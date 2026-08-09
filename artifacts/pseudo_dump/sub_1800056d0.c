
  uint64_t sub_1800056d0(void* arg1, char arg2, int64_t* arg3)

{
    int64_t* arg_18 = arg3;
    char var_48 = arg2;
    int64_t r8 = arg3[2];
    int64_t r9 = arg3[1];
    void* r10 = *arg3;
    __builtin_memset(arg3, 0, 0x18);
    int64_t var_38 = r9;
    char* rcx = *(arg1 + 0x50);
    void* rax;
    int64_t rdx;
    
    if (rcx == *(arg1 + 0x58))
    {
        sub_1800041b0(arg1 + 0x48, rcx, &var_48);
        rdx = r8;
        rax = r10;
    }
    else
    {
        *rcx = arg2;
        rdx = 0;
        rax = nullptr;
        *(rcx + 8) = r10;
        *(rcx + 0x10) = r9;
        *(rcx + 0x18) = r8;
        *(arg1 + 0x50) += 0x20;
    }
    
    if (rax)
    {
        void* rcx_2;
        
        if (rdx - rax < 0x1000)
            rcx_2 = rax;
        else
        {
            rcx_2 = *(rax - 8);
            
            if (rax - rcx_2 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_2);
    }
    
    int64_t rdi_3 = (*(arg1 + 0x50) - *(arg1 + 0x48)) >> 5;
    
    if (rdi_3 > 0xfffe)
    {
        sub_180004ba0(&var_48, "classfile: constant pool overflow");
        sub_180019520(&var_48, &data_180045388);
        /* no return */
    }
    
    void* rax_3 = *arg3;
    
    if (rax_3)
    {
        void* rcx_4;
        
        if (arg3[2] - rax_3 < 0x1000)
            rcx_4 = rax_3;
        else
        {
            rcx_4 = *(rax_3 - 8);
            
            if (rax_3 - rcx_4 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_4);
        __builtin_memset(arg3, 0, 0x18);
    }
    
    return rdi_3;
}

