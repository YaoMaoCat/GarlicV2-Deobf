
  void* sub_180027100()

{
    void** rax = __vcrt_getptd();
    void* result;
    
    if (data_180047080 & rax[0x75])
        result = rax[0x12];
    
    if (!(data_180047080 & rax[0x75]) || !result)
    {
        sub_1800239bc(4);
        result = _updatetlocinfoEx_nolock(&rax[0x12], data_180047838);
        sub_180023a10(4);
        
        if (!result)
        {
            abort();
            /* no return */
        }
    }
    
    return result;
}

