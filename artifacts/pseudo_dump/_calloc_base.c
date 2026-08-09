
🌐  int64_t _calloc_base(int64_t arg1, int64_t arg2)

{
    if (!arg1 || -0x20 / arg1 >= arg2)
    {
        uint64_t dwBytes = arg1 * arg2;
        
        if (!dwBytes)
            dwBytes = 1;
        
        int32_t i;
        
        do
        {
            int64_t result = HeapAlloc(data_180047fb8, HEAP_ZERO_MEMORY, dwBytes);
            
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

