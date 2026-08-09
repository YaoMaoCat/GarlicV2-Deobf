
🌐  int64_t __acrt_free_locale(void* arg1)

{
    int64_t rax = *(arg1 + 0xf8);
    
    if (rax && rax != &data_180047090)
    {
        int32_t* rax_1 = *(arg1 + 0xe0);
        
        if (rax_1 && !*rax_1)
        {
            int32_t* rcx = *(arg1 + 0xf0);
            
            if (rcx && !*rcx)
            {
                _free_base(rcx);
                __acrt_locale_free_monetary(*(arg1 + 0xf8));
            }
            
            int32_t* rcx_2 = *(arg1 + 0xe8);
            
            if (rcx_2 && !*rcx_2)
            {
                _free_base(rcx_2);
                __acrt_locale_free_numeric(*(arg1 + 0xf8));
            }
            
            _free_base(*(arg1 + 0xe0));
            _free_base(*(arg1 + 0xf8));
        }
    }
    
    int32_t* rax_2 = *(arg1 + 0x100);
    
    if (rax_2 && !*rax_2)
    {
        _free_base(*(arg1 + 0x108) - 0xfe);
        _free_base(*(arg1 + 0x110) - 0x80);
        _free_base(*(arg1 + 0x118) - 0x80);
        _free_base(*(arg1 + 0x100));
    }
    
    __acrt_locale_free_lc_time_if_unreferenced(*(arg1 + 0x120));
    int64_t* rsi = arg1 + 0x128;
    int64_t i_1 = 6;
    int64_t* rdi = arg1 + 0x38;
    int64_t i;
    
    do
    {
        if (rdi[-2] != &data_180046b38)
        {
            int32_t* rcx_14 = *rdi;
            
            if (rcx_14 && !*rcx_14)
            {
                _free_base(rcx_14);
                _free_base(*rsi);
            }
        }
        
        if (rdi[-3])
        {
            int32_t* rcx_16 = rdi[-1];
            
            if (rcx_16 && !*rcx_16)
                _free_base(rcx_16);
        }
        
        rsi = &rsi[1];
        rdi = &rdi[4];
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    /* tailcall */
    return _free_base(arg1);
}

