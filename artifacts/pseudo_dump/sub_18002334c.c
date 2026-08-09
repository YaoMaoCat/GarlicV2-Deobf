
  void** sub_18002334c()

{
    int64_t var_18 = -2;
    void** rdi = nullptr;
    
    if (!data_180047830)
    {
        enum WIN32_ERROR dwErrCode = GetLastError();
        uint32_t dwFlsIndex = data_1800469c8;
        void** rax_1;
        
        if (dwFlsIndex != 0xffffffff)
            rax_1 = FlsGetValue(dwFlsIndex);
        else
            rax_1 = nullptr;
        
        if (rax_1 != -1)
        {
            if (!rax_1)
                rax_1 = sub_18002317c();
            
            rdi = rax_1;
        }
        
        SetLastError(dwErrCode);
    }
    else
    {
        void** rax;
        
        if (data_1800469c8 != 0xffffffff)
            rax = sub_180026298();
        else
            rax = nullptr;
        
        if (rax != -1)
        {
            if (rax)
                return rax;
            
            return sub_18002317c();
        }
    }
    
    return rdi;
}

