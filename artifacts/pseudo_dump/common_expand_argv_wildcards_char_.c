
  uint64_t common_expand_argv_wildcards<char>(int64_t* arg1, int64_t* arg2)

{
    int64_t* rbx = arg1;
    
    if (!arg2)
    {
        int32_t rbx_1 = arg2 + 0x16;
        *sub_18002131c() = rbx_1;
        _invalid_parameter_noinfo();
        return rbx_1;
    }
    
    *arg2 = 0;
    char* rax_2 = *arg1;
    int128_t var_58;
    __builtin_memset(&var_58, 0, 0x18);
    int32_t rsi_1;
    int64_t* i_2;
    
    while (true)
    {
        int16_t arg_10;
        
        if (!rax_2)
        {
            i_2 = var_58;
            int64_t rsi_2 = *(&var_58 + 8);
            int64_t rdx_2 = 0;
            int64_t arg_18 = 0;
            int64_t* i_3 = i_2;
            
            if (i_2 != rsi_2)
            {
                do
                {
                    int64_t rcx_3 = -1;
                    
                    do
                        rcx_3 += 1;
                     while ((*i_3)[rcx_3]);
                    
                    i_3 = &i_3[1];
                    rdx_2 = rdx_2 + 1 + rcx_3;
                } while (i_3 != rsi_2);
                
                arg_18 = rdx_2;
            }
            
            int64_t rax_6 = __acrt_allocate_buffer_for_argv(((rsi_2 - i_2) >> 3) + 1, rdx_2, 1);
            
            if (!rax_6)
            {
                _free_base(0);
                int64_t* i_4 = i_2;
                
                if (i_2 != rsi_2)
                {
                    do
                    {
                        _free_base(*i_4);
                        i_4 = &i_4[1];
                    } while (i_4 != rsi_2);
                }
                
                rsi_1 = -1;
                break;
            }
            
            char* rcx_8 = rax_6 + ((((rsi_2 - i_2) >> 3) + 1) << 3);
            int64_t* i_6 = i_2;
            char* arg_20 = rcx_8;
            char* r12_1 = rcx_8;
            
            if (i_2 != rsi_2)
            {
                arg_10 = rax_6 - i_2;
                
                do
                {
                    char* r8_3 = *i_6;
                    int64_t r15_1 = -1;
                    
                    do
                        r15_1 += 1;
                     while (r8_3[r15_1]);
                    
                    if (sub_180029ec0(r12_1, rcx_8 - r12_1 + arg_18, r8_3, r15_1 + 1))
                    {
                        int64_t var_68 = 0;
                        _invoke_watson();
                        /* no return */
                    }
                    
                    rcx_8 = arg_20;
                    *(arg_10 + i_6) = r12_1;
                    r12_1 = &r12_1[r15_1 + 1];
                    i_6 = &i_6[1];
                } while (i_6 != rsi_2);
            }
            
            *arg2 = rax_6;
            _free_base(0);
            int64_t* i_5 = i_2;
            
            if (i_2 != rsi_2)
            {
                do
                {
                    _free_base(*i_5);
                    i_5 = &i_5[1];
                } while (i_5 != rsi_2);
            }
            
            _free_base(i_2);
            return 0;
        }
        
        arg_10 = 0x3f2a;
        char arg_12 = 0;
        char* rax_3 = sub_18002a090(rax_2, &arg_10);
        char* rcx_1 = *rbx;
        
        if (rax_3)
        {
            int32_t rax_5 = sub_180024608(rcx_1, rax_3, &var_58, arg2);
            rsi_1 = rax_5;
            
            if (rax_5)
            {
                i_2 = var_58;
                int64_t* i = i_2;
                
                if (i_2 != *(&var_58 + 8))
                {
                    do
                    {
                        _free_base(*i);
                        i = &i[1];
                    } while (i != *(&var_58 + 8));
                }
                
                break;
            }
        }
        else
        {
            int32_t rax_4 = sub_180024484(rcx_1, 0, 0, &var_58);
            rsi_1 = rax_4;
            
            if (rax_4)
            {
                i_2 = var_58;
                int64_t* i_1 = i_2;
                
                if (i_2 != *(&var_58 + 8))
                {
                    do
                    {
                        _free_base(*i_1);
                        i_1 = &i_1[1];
                    } while (i_1 != *(&var_58 + 8));
                }
                
                break;
            }
        }
        
        rbx = &rbx[1];
        rax_2 = *rbx;
    }
    
    _free_base(i_2);
    return rsi_1;
}

