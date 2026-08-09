
🌐  uint8_t __acrt_stdio_free_buffer_nolock(void* arg1)

{
    uint8_t result = *(arg1 + 0x14) >> 0xd;
    
    if (result & 1)
    {
        result = *(arg1 + 0x14) >> 6;
        
        if (result & 1)
        {
            _free_base(*(arg1 + 8));
            *(arg1 + 0x14) &= 0xfffffebf;
            result = 0;
            __builtin_memset(arg1, 0, 0x14);
        }
    }
    
    return result;
}

