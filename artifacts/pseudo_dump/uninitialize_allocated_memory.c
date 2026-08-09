
🌐  int64_t uninitialize_allocated_memory()

{
    int32_t* rcx = data_180047ec0;
    int32_t result = *rcx;
    *rcx -= 1;
    
    if (result == 1)
    {
        int64_t rcx_1 = data_180047ec0;
        
        if (rcx_1 != &data_180046b40)
        {
            _free_base(rcx_1);
            data_180047ec0 = &data_180046b40;
        }
    }
    
    result = 1;
    return result;
}

