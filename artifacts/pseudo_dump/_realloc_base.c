
🌐  int64_t _realloc_base(int64_t arg1, uint64_t arg2)

{
    if (!arg1)
        return _malloc_base(arg2);
    
    if (arg2)
    {
        if (arg2 <= -0x20)
        {
            int32_t i;
            
            do
            {
                int64_t result = HeapReAlloc(data_180047fb8, HEAP_NONE, arg1, arg2);
                
                if (result)
                    return result;
                
                if (!sub_180026d90())
                    break;
                
                i = sub_18001f8e0();
            } while (i);
        }
        
        *sub_18002131c() = 0xc;
    }
    else
        _free_base(arg1);
    
    return 0;
}

