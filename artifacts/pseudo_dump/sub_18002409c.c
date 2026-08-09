
  uint64_t sub_18002409c(int16_t* arg1, void* arg2, int64_t arg3, uint32_t arg4)

{
    if (!arg1)
    {
        if (*(arg2 + 0x28))
        {
            _free_base(*(arg2 + 0x10));
            *(arg2 + 0x28) = 0;
        }
        
        __builtin_memset(arg2 + 0x10, 0, 0x18);
    }
    else if (*arg1)
    {
        int64_t var_10_1 = 0;
        int64_t var_18_1 = 0;
        int32_t rax_4 = __acrt_WideCharToMultiByte(arg4, 0, arg1, 0xffffffff, 0, nullptr);
        int64_t rsi_1 = rax_4;
        int64_t rax_10;
        
        if (rax_4)
        {
            int64_t rdx_4 = *(arg2 + 0x18);
            
            if (rsi_1 > rdx_4)
            {
                if (*(arg2 + 0x28))
                {
                    _free_base(*(arg2 + 0x10));
                    *(arg2 + 0x28) = 0;
                }
                
                int64_t rax_7;
                int64_t rdx_5;
                int32_t r8_1;
                rax_7 = _malloc_base(rsi_1);
                *(arg2 + 0x10) = rax_7;
                rdx_4 = (rdx_5 - rdx_5) & rsi_1;
                int32_t r8_4 = ~(r8_1 - r8_1) & 0xc;
                
                if (rax_7)
                    r8_4 = 0;
                
                *(arg2 + 0x28) = rax_7;
                *(arg2 + 0x18) = rdx_4;
                
                if (r8_4)
                    return r8_4;
            }
            
            int64_t var_10_2 = 0;
            int64_t var_18_2 = 0;
            rax_10 = __acrt_WideCharToMultiByte(arg4, 0, arg1, 0xffffffff, *(arg2 + 0x10), rdx_4);
        }
        
        if (!rax_4 || !rax_10)
        {
            sub_1800212ac(GetLastError());
            return *sub_18002131c();
        }
        
        *(arg2 + 0x20) = rax_10 - 1;
    }
    else
    {
        if (!*(arg2 + 0x18))
        {
            if (*(arg2 + 0x28))
            {
                _free_base(*(arg2 + 0x10));
                *(arg2 + 0x28) = 0;
            }
            
            int64_t rax_1;
            int32_t rdx;
            rax_1 = _malloc_base(1);
            *(arg2 + 0x10) = rax_1;
            int32_t rdx_3 = ~(rdx - rdx) & 0xc;
            
            if (rax_1)
                rdx_3 = 0;
            
            *(arg2 + 0x28) = rax_1;
            int64_t rcx_4;
            rcx_4 = rax_1;
            *(arg2 + 0x18) = rcx_4;
            
            if (rdx_3)
                return rdx_3;
        }
        
        **(arg2 + 0x10) = 0;
    }
    
    return 0;
}

