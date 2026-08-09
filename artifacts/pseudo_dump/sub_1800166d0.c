
  struct Section_Header* const sub_1800166d0(int64_t arg1)

{
    struct Section_Header* const result = &__section_headers;
    
    while (true)
    {
        struct Section_Header* const result_1 = result;
        
        if (result == &data_180000330)
        {
            result = 0;
            return result;
        }
        
        uint64_t virtualAddress = result->virtualAddress;
        
        if (arg1 - &__dos_header >= virtualAddress
            && arg1 - &__dos_header < result->virtualSize + virtualAddress)
        {
            if (result->characteristics >= 0)
                result = 1;
            else
                result = 0;
            
            return result;
        }
        
        result = &result[1];
    }
}

