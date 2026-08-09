
🌐  int64_t _malloc_base(uint64_t arg1)

{
    uint64_t dwBytes = arg1;
    
    if (arg1 <= -0x20)
    {
        if (!arg1)
            dwBytes = 1;
        
        int32_t i;
        
        do
        {
            int64_t result = HeapAlloc(data_180047fb8, HEAP_NONE, dwBytes);
            
            if (result)
                return result;
            
            if (!sub_180026d90())
                break;
            
            i = sub_18001f8e0();
        } while (i);
    }
    
    *sub_18002131c() = 0xc;
    return 0;
}

