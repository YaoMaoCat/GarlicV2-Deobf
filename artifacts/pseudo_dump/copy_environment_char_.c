
🌐  int64_t copy_environment<char>(int64_t* arg1)

{
    int64_t* rdi = arg1;
    
    if (!arg1)
        return 0;
    
    int64_t rcx = 0;
    int64_t* rax_1 = rdi;
    
    if (*rdi)
    {
        do
        {
            rcx += 1;
            rax_1 = &rax_1[1];
        } while (*rax_1);
    }
    
    int64_t result = _calloc_base(rcx + 1, 8);
    
    if (!result)
    {
    label_180025e63:
        abort();
        /* no return */
    }
    
    char* i = *rdi;
    
    if (i)
    {
        int64_t* r14_2 = result - rdi;
        
        do
        {
            int64_t rsi_1 = -1;
            
            do
                rsi_1 += 1;
             while (i[rsi_1]);
            
            *(r14_2 + rdi) = _calloc_base(rsi_1 + 1, 1);
            _free_base(0);
            char* rcx_3 = *(r14_2 + rdi);
            
            if (!rcx_3)
                goto label_180025e63;
            
            if (sub_180020d70(rcx_3, rsi_1 + 1, *rdi))
            {
                int64_t var_18 = 0;
                _invoke_watson();
                /* no return */
            }
            
            rdi = &rdi[1];
            i = *rdi;
        } while (i);
    }
    
    _free_base(0);
    return result;
}

