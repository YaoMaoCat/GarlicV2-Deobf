
  void** sub_180023308()

{
    int64_t var_18 = -2;
    uint32_t dwFlsIndex = data_1800469c8;
    void** result;
    
    if (dwFlsIndex != 0xffffffff)
        result = FlsGetValue(dwFlsIndex);
    else
        result = nullptr;
    
    if (result != -1)
    {
        if (result)
            return result;
        
        result = sub_18002317c();
        
        if (result)
            return result;
    }
    
    abort();
    /* no return */
}

