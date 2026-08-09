
  uint64_t sub_1800062d0(void* arg1, int128_t* arg2, int128_t* arg3)

{
    int128_t var_88 = *arg2;
    uint32_t rsi = sub_180006790(arg1, &var_88);
    var_88 = *arg3;
    uint64_t rbx_1 = sub_180006790(arg1, &var_88);
    uint64_t rdi_2 = rsi << 0x10 | rbx_1;
    void** rdx_2 = *(arg1 + 0x80);
    void** rcx_1 = rdx_2[1];
    void** rax_2 = rdx_2;
    
    while (!*(rcx_1 + 0x19))
    {
        if (rcx_1[4] >= rdi_2)
        {
            rax_2 = rcx_1;
            rcx_1 = *rcx_1;
        }
        else
            rcx_1 = rcx_1[2];
    }
    
    if (!*(rax_2 + 0x19) && rdi_2 >= rax_2[4] && rax_2 != rdx_2)
        return rax_2[5];
    
    int128_t var_68;
    __builtin_memset(&var_68, 0, 0x18);
    char arg_8 = (rsi >> 8);
    sub_180006510(&var_68, &arg_8);
    arg_8 = rsi;
    sub_180006510(&var_68, &arg_8);
    arg_8 = (rbx_1 >> 8);
    sub_180006510(&var_68, &arg_8);
    arg_8 = rbx_1;
    sub_180006510(&var_68, &arg_8);
    int64_t rcx_6 = *(&var_68 + 8);
    int64_t rax_6 = var_68;
    __builtin_memset(&var_68, 0, 0x18);
    var_88 = rax_6;
    *(&var_88 + 8) = rcx_6;
    int64_t var_58;
    int64_t var_78_1 = var_58;
    int64_t rdx_7;
    rdx_7 = 0xc;
    int16_t rax_7 = sub_1800056d0(arg1, rdx_7, &var_88);
    void** rdx_8 = *(arg1 + 0x80);
    void** rcx_8 = rdx_8[1];
    int32_t rsi_1;
    void** r14_1;
    
    if (*(rcx_8 + 0x19))
    {
        rsi_1 = 0;
        r14_1 = rcx_8;
    }
    else
    {
        do
        {
            r14_1 = rcx_8;
            
            if (rcx_8[4] >= rdi_2)
            {
                rsi_1 = 1;
                rdx_8 = rcx_8;
                rcx_8 = *rcx_8;
            }
            else
            {
                rsi_1 = 0;
                rcx_8 = rcx_8[2];
            }
        } while (!*(rcx_8 + 0x19));
    }
    
    if (*(rdx_8 + 0x19) || rdi_2 < rdx_8[4])
    {
        if (*(arg1 + 0x88) == 0x555555555555555)
        {
            sub_180005280();
            /* no return */
        }
        
        int64_t rbx_2 = *(arg1 + 0x80);
        var_88 = arg1 + 0x80;
        *(&var_88 + 8) = 0;
        int64_t* rax_8 = sub_180016420(0x30);
        rax_8[4] = rdi_2;
        rax_8[5] = rax_7;
        *rax_8 = rbx_2;
        rax_8[1] = rbx_2;
        rax_8[2] = rbx_2;
        rax_8[3] = 0;
        var_88 = r14_1;
        *(&var_88 + 8) = rsi_1;
        *(&var_88 + 0xc) = *(&var_68 + 0xc);
        sub_180005010(arg1 + 0x80, &var_88, rax_8);
    }
    
    void* rax_9 = var_68;
    
    if (rax_9)
    {
        int64_t var_58_1;
        void* rcx_10;
        
        if (var_58_1 - rax_9 < 0x1000)
            rcx_10 = rax_9;
        else
        {
            rcx_10 = *(rax_9 - 8);
            
            if (rax_9 - rcx_10 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_10);
    }
    
    return rax_7;
}

