
  int64_t __vcrt_uninitialize_locks()

{
    uint64_t rbx = data_180047ea8;
    
    while (rbx)
    {
        rbx = rbx - 1;
        DeleteCriticalSection(&data_180047c50 + rbx * 0x28);
        data_180047ea8 -= 1;
    }
    
    int64_t result;
    result = 1;
    return result;
}

