
  int64_t sub_180017bf0(int32_t* arg1)

{
    uint32_t rax = GetCurrentThreadId();
    int32_t rax_1 = arg1[0x12];
    
    if ((*arg1 & 0xfffffeff) == 1)
    {
        if (rax_1 != rax)
        {
            AcquireSRWLockExclusive(&arg1[4]);
            arg1[0x12] = rax;
        }
        
        arg1[0x13] += 1;
        return 0;
    }
    
    if (rax_1 != rax)
        AcquireSRWLockExclusive(&arg1[4]);
    
    int32_t rcx_2 = arg1[0x13];
    arg1[0x13] = rcx_2 + 1;
    
    if (rcx_2 + 1 <= 1)
        arg1[0x12] = rax;
    else if (!(*arg1 & 0x100))
    {
        arg1[0x13] = rcx_2;
        return 3;
    }
    
    return 0;
}

