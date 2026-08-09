
  char** sub_180020218(char* arg1)

{
    char* rsi = arg1;
    int64_t rcx = 0;
    char* r8 = rsi;
    
    for (char i = *rsi; i; i = *r8)
    {
        int64_t rax_1 = rcx + 1;
        
        if (i == 0x3d)
            rax_1 = rcx;
        
        rcx = rax_1;
        int64_t rax_2 = -1;
        
        do
            rax_2 += 1;
         while (r8[rax_2]);
        
        r8 = &r8[1 + rax_2];
    }
    
    char** result_1 = _calloc_base(rcx + 1, 8);
    char** result = result_1;
    
    if (result_1)
    {
        char** result_2 = result;
        
        while (true)
        {
            result_1 = *rsi;
            
            if (!result_1)
            {
                _free_base(0);
                return result;
            }
            
            int64_t rbp_1 = -1;
            
            do
                rbp_1 += 1;
             while (rsi[rbp_1]);
            
            if (result_1 != 0x3d)
            {
                char* rax_4 = _calloc_base(rbp_1 + 1, 1);
                
                if (!rax_4)
                    break;
                
                if (sub_180020d70(rax_4, rbp_1 + 1, rsi))
                {
                    int64_t var_18 = 0;
                    _invoke_watson();
                    /* no return */
                }
                
                *result_2 = rax_4;
                result_2 = &result_2[1];
                _free_base(0);
            }
            
            rsi = &rsi[rbp_1 + 1];
        }
        
        free_environment<wchar_t>(result);
        _free_base(0);
    }
    
    _free_base(0);
    return nullptr;
}

