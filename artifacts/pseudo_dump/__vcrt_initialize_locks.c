
  BOOL __vcrt_initialize_locks()

{
    uint64_t rbx = 0;
    BOOL result;
    
    while (true)
    {
        if (!InitializeCriticalSectionEx(&data_180047c50 + rbx * 0x28, 0xfa0, 0))
        {
            __vcrt_uninitialize_locks();
            result = 0;
            break;
        }
        
        data_180047ea8 += 1;
        rbx = rbx + 1;
        
        if (rbx >= 0xf)
        {
            result = 1;
            break;
        }
    }
    
    return result;
}

