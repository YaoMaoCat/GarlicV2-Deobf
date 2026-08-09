
  int64_t sub_180016510()

{
    int32_t result;
    
    if (!data_180047531)
    {
        if (!sub_180016fc0())
            __builtin_memset(&data_180047538, 0xff, 0x30);
        else
        {
            if (_initialize_onexit_table(&data_180047538))
            {
                result = 0;
                return result;
            }
            
            if (_initialize_onexit_table(&data_180047550))
            {
                result = 0;
                return result;
            }
        }
        
        data_180047531 = 1;
    }
    
    result = 1;
    return result;
}

