
  wchar16* sub_180020370()

{
    int64_t* rdi = data_1800477a0;
    
    if (rdi)
    {
        while (true)
        {
            wchar16* result = *rdi;
            
            if (!result)
                return result;
            
            int64_t var_10_1 = 0;
            int64_t var_18_1 = 0;
            int32_t rax_1 = __acrt_WideCharToMultiByte(0, 0, result, 0xffffffff, 0, nullptr);
            int64_t rsi_1 = rax_1;
            
            if (!rax_1)
                break;
            
            char* rax_2 = _calloc_base(rsi_1, 1);
            char* rcx_2;
            
            if (!rax_2)
                rcx_2 = nullptr;
            else
            {
                int64_t var_10_2 = 0;
                int64_t var_18_2 = 0;
                rcx_2 = rax_2;
                
                if (__acrt_WideCharToMultiByte(0, 0, *rdi, 0xffffffff, rax_2, rsi_1))
                {
                    j_common_set_variable_in_environment_nolock<char>(rcx_2, 0);
                    _free_base(0);
                    rdi = &rdi[1];
                    continue;
                }
            }
            
            _free_base(rcx_2);
            break;
        }
    }
    
    return 0xffffffff;
}

