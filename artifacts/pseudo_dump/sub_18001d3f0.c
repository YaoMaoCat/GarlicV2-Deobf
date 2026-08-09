
  BOOL sub_18001d3f0()

{
    uint64_t rbx = 0;
    BOOL result;
    
    while (InitializeCriticalSectionEx(&data_180047630 + rbx * 0x28, 0xfa0, 0))
    {
        data_180047658 += 1;
        rbx = rbx + 1;
        
        if (rbx >= 1)
        {
            result = 1;
            return result;
        }
    }
    
    uint64_t rbx_1 = data_180047658;
    
    while (rbx_1)
    {
        rbx_1 = rbx_1 - 1;
        DeleteCriticalSection(&data_180047630 + rbx_1 * 0x28);
        data_180047658 -= 1;
    }
    
    result = 0;
    return result;
}

