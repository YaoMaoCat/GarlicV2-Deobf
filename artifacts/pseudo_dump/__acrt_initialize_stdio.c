
  int64_t __acrt_initialize_stdio()

{
    int32_t rax = data_1800477e8;
    void** rbx = nullptr;
    int64_t i_1 = 3;
    
    if (!rax)
    {
        rax = 0x200;
        data_1800477e8 = rax;
    }
    else if (rax < 3)
    {
        rax = 3;
        data_1800477e8 = rax;
    }
    
    data_1800477f0 = _calloc_base(rax, 8);
    _free_base(0);
    
    if (!data_1800477f0)
    {
        data_1800477e8 = 3;
        data_1800477f0 = _calloc_base(3, 8);
        _free_base(0);
        
        if (!data_1800477f0)
            return 0xffffffff;
    }
    
    int64_t rbp_1 = 0;
    int32_t* rsi_1 = &data_1800468c8;
    void* r14_1 = &data_1800468b0;
    int64_t i;
    
    do
    {
        InitializeCriticalSectionEx(r14_1 + 0x30, 0xfa0, 0);
        *(rbx + data_1800477f0) = r14_1;
        
        if (*((&data_180047840)[rbp_1 >> 6] + (rbp_1 & 0x3f) * 0x48 + 0x28) + 2 <= 2)
            *rsi_1 = 0xfffffffe;
        
        rbp_1 += 1;
        r14_1 += 0x58;
        rbx = &rbx[1];
        rsi_1 = &rsi_1[0x16];
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return 0;
}

