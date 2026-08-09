
  void sub_180019930(int32_t* arg1)

{
    if (!arg1)
        return;
    
    char rdx;
    char arg_10 = rdx;
    
    if (*arg1 != 0xe06d7363 || arg1[6] != 4 || arg1[8] - 0x19930520 > 2)
        return;
    
    uint64_t rax = *(arg1 + 0x30);
    
    if (!rax)
        return;
    
    int64_t rdx_1 = *(rax + 4);
    
    if (rdx_1)
        sub_1800199a0(*(arg1 + 0x28), rdx_1 + *(arg1 + 0x38));
    else if (*rax & 0x10)
    {
        int64_t* rcx_1 = **(arg1 + 0x28);
        
        if (rcx_1)
            (*(*rcx_1 + 0x10))();
    }
}

