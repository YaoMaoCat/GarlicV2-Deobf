
  int64_t sub_18001d480()

{
    uint64_t rbx = data_180047658;
    
    while (rbx)
    {
        rbx = rbx - 1;
        DeleteCriticalSection(&data_180047630 + rbx * 0x28);
        data_180047658 -= 1;
    }
    
    int64_t result;
    result = 1;
    return result;
}

