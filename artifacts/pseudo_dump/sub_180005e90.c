
  uint64_t sub_180005e90(void* arg1, int128_t* arg2)

{
    int128_t var_88 = *arg2;
    uint16_t rax = sub_180006790(arg1, &var_88);
    void** r8 = *(arg1 + 0x70);
    void** rdx_1 = r8[1];
    void** rax_1 = r8;
    
    while (!*(rdx_1 + 0x19))
    {
        if (*(rdx_1 + 0x1a) >= rax)
        {
            rax_1 = rdx_1;
            rdx_1 = *rdx_1;
        }
        else
            rdx_1 = rdx_1[2];
    }
    
    if (!*(rax_1 + 0x19) && rax >= *(rax_1 + 0x1a) && rax_1 != r8)
        return *(rax_1 + 0x1c);
    
    int128_t var_68;
    __builtin_memset(&var_68, 0, 0x18);
    char arg_8 = (rax >> 8);
    sub_180006510(&var_68, &arg_8);
    arg_8 = rax;
    sub_180006510(&var_68, &arg_8);
    int64_t rcx_2 = *(&var_68 + 8);
    int64_t rax_4 = var_68;
    __builtin_memset(&var_68, 0, 0x18);
    var_88 = rax_4;
    *(&var_88 + 8) = rcx_2;
    int64_t var_58;
    int64_t var_78_1 = var_58;
    int64_t rdx_4;
    rdx_4 = 7;
    int16_t rax_5 = sub_1800056d0(arg1, rdx_4, &var_88);
    void** rdx_5 = *(arg1 + 0x70);
    void** rcx_4 = rdx_5[1];
    int32_t rsi_1;
    void** r14_1;
    
    if (*(rcx_4 + 0x19))
    {
        rsi_1 = 0;
        r14_1 = rcx_4;
    }
    else
    {
        do
        {
            r14_1 = rcx_4;
            
            if (*(rcx_4 + 0x1a) >= rax)
            {
                rsi_1 = 1;
                rdx_5 = rcx_4;
                rcx_4 = *rcx_4;
            }
            else
            {
                rsi_1 = 0;
                rcx_4 = rcx_4[2];
            }
        } while (!*(rcx_4 + 0x19));
    }
    
    if (*(rdx_5 + 0x19) || rax < *(rdx_5 + 0x1a))
    {
        if (*(arg1 + 0x78) == 0x7ffffffffffffff)
        {
            sub_180005280();
            /* no return */
        }
        
        void* rbx_1 = *(arg1 + 0x70);
        var_88 = arg1 + 0x70;
        *(&var_88 + 8) = 0;
        void** rax_6 = sub_180016420(0x20);
        *(rax_6 + 0x1a) = rax;
        *(rax_6 + 0x1c) = rax_5;
        *rax_6 = rbx_1;
        rax_6[1] = rbx_1;
        rax_6[2] = rbx_1;
        rax_6[3] = 0;
        var_88 = r14_1;
        *(&var_88 + 8) = rsi_1;
        *(&var_88 + 0xc) = *(&var_68 + 0xc);
        sub_180005010(arg1 + 0x70, &var_88, rax_6);
    }
    
    void* rax_7 = var_68;
    
    if (rax_7)
    {
        int64_t var_58_1;
        void* rcx_6;
        
        if (var_58_1 - rax_7 < 0x1000)
            rcx_6 = rax_7;
        else
        {
            rcx_6 = *(rax_7 - 8);
            
            if (rax_7 - rcx_6 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_6);
    }
    
    return rax_5;
}

