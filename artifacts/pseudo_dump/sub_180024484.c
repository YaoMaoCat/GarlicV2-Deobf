
  uint64_t sub_180024484(char* arg1, int64_t arg2, int64_t arg3, int64_t* arg4)

{
    int64_t rbp = -1;
    int32_t rdi = 0;
    
    do
        rbp += 1;
     while (arg1[rbp]);
    
    if (rbp + 1 > ~arg3)
        return 0xc;
    
    int64_t r15_2 = arg3 + 1 + rbp + 1;
    char* rax_3 = _calloc_base(r15_2, 1);
    int32_t rax_4;
    
    if (arg3)
        rax_4 = sub_180029ec0(rax_3, r15_2, arg2, arg3);
    
    if (!arg3 || !rax_4)
    {
        int32_t rax_5 = sub_180029ec0(&rax_3[arg3], r15_2 - arg3, arg1, rbp + 1);
        
        if (!rax_5)
        {
            int64_t r14_1 = arg4[2];
            uint64_t r15_4 = rax_5 + 8;
            
            if (arg4[1] != r14_1)
            {
                *arg4[1] = rax_3;
                arg4[1] += r15_4;
            }
            else if (*arg4)
            {
                int64_t r14_3 = (r14_1 - *arg4) >> 3;
                
                if (r14_3 > 0x7fffffffffffffff)
                {
                    rdi = 0xc;
                    _free_base(rax_3);
                }
                else
                {
                    int64_t rbp_2 = r14_3 * 2;
                    void* rax_9 = _recalloc_base(*arg4, rbp_2, r15_4);
                    
                    if (rax_9)
                    {
                        *arg4 = rax_9;
                        arg4[1] = rax_9 + (r14_3 << 3);
                        arg4[2] = rax_9 + (rbp_2 << 3);
                        _free_base(0);
                        *arg4[1] = rax_3;
                        arg4[1] += r15_4;
                    }
                    else
                    {
                        _free_base(0);
                        rdi = 0xc;
                        _free_base(rax_3);
                    }
                }
            }
            else
            {
                *arg4 = _calloc_base(rax_5 + 4, r15_4);
                _free_base(0);
                int64_t rax_7 = *arg4;
                
                if (!rax_7)
                {
                    rdi = 0xc;
                    _free_base(rax_3);
                }
                else
                {
                    arg4[1] = rax_7;
                    arg4[2] = rax_7 + 0x20;
                    *arg4[1] = rax_3;
                    arg4[1] += r15_4;
                }
            }
            
            _free_base(0);
            return rdi;
        }
    }
    
    int64_t var_38 = 0;
    _invoke_watson();
    /* no return */
}

