
🌐  int64_t __crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>(void* arg1, int64_t arg2, void* arg3)

{
    int64_t result;
    
    if (arg2 <= 0x7fffffffffffffff)
    {
        char rdi_1 = 0;
        uint64_t rsi_1 = arg2 * 2;
        
        if (*(arg1 + 0x408))
        {
            if (rsi_1 > *(arg1 + 0x400))
                goto label_18001d657;
            
            result = 1;
        }
        else if (rsi_1 <= 0x400 || rsi_1 <= *(arg1 + 0x400))
            result = 1;
        else
        {
        label_18001d657:
            int64_t rax = _malloc_base(rsi_1);
            
            if (rax)
            {
                _free_base(*(arg1 + 0x408));
                *(arg1 + 0x408) = rax;
                rdi_1 = 1;
                *(arg1 + 0x400) = rsi_1;
            }
            
            _free_base(0);
            result = rdi_1;
        }
    }
    else
    {
        *(arg3 + 0x30) = 1;
        result = 0;
        *(arg3 + 0x2c) = 0xc;
    }
    
    return result;
}

