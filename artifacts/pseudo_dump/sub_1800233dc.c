
  void* sub_1800233dc(int64_t arg1, int64_t arg2)

{
    int64_t var_18 = -2;
    uint32_t dwFlsIndex = data_1800469c8;
    void** rax;
    
    if (dwFlsIndex != 0xffffffff)
        rax = FlsGetValue(dwFlsIndex);
    else
        rax = nullptr;
    
    if (rax != -1)
    {
        if (rax)
            return arg2 * 0x3c8 + rax;
        
        rax = sub_18002317c();
        
        if (rax)
            return arg2 * 0x3c8 + rax;
    }
    
    return nullptr;
}

