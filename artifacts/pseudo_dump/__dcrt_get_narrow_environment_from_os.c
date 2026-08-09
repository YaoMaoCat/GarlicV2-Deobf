
  int64_t __dcrt_get_narrow_environment_from_os()

{
    PWSTR penv = GetEnvironmentStringsW();
    int64_t result = 0;
    
    if (penv)
    {
        PWSTR penv_1 = penv;
        
        if (*penv)
        {
            do
            {
                int64_t rax = -1;
                
                do
                    rax += 1;
                 while (penv_1[rax]);
                
                penv_1 = &penv_1[rax + 1];
            } while (*penv_1);
        }
        
        int64_t var_10_1 = 0;
        int64_t var_18_1 = 0;
        int32_t rbp_4 = (penv_1 - penv + 2) >> 1;
        int32_t rax_1 = __acrt_WideCharToMultiByte(0, 0, penv, rbp_4, 0, nullptr);
        int64_t r14_1 = rax_1;
        
        if (rax_1)
        {
            int64_t result_1 = _malloc_base(r14_1);
            
            if (result_1)
            {
                int64_t var_10_2 = 0;
                int64_t var_18_2 = 0;
                
                if (__acrt_WideCharToMultiByte(0, 0, penv, rbp_4, result_1, r14_1))
                {
                    _free_base(0);
                    result = result_1;
                }
                else
                    _free_base(result_1);
                
                FreeEnvironmentStringsW(penv);
                return result;
            }
            
            _free_base(0);
        }
        
        FreeEnvironmentStringsW(penv);
    }
    
    return 0;
}

