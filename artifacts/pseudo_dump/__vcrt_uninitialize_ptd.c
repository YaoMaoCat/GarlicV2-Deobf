
  int64_t __vcrt_uninitialize_ptd()

{
    uint32_t dwFlsIndex = data_1800469c8;
    
    if (dwFlsIndex != 0xffffffff)
    {
        FlsFree(dwFlsIndex);
        data_1800469c8 = 0xffffffff;
    }
    
    int64_t result;
    result = 1;
    return result;
}

