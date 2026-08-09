
  uint64_t sub_180020024(int32_t arg1)

{
    int32_t rdi = 0;
    
    if (arg1)
    {
        if (arg1 - 1 <= 1)
        {
            __acrt_initialize_multibyte();
            __acrt_GetModuleFileNameA(nullptr, &data_180047690, 0x104);
            char* rsi_1 = data_180047ef0;
            data_180047ed0 = &data_180047690;
            
            if (!rsi_1 || !*rsi_1)
                rsi_1 = &data_180047690;
            
            int64_t arg_18 = 0;
            int64_t arg_20 = 0;
            sub_18001fe04(rsi_1, nullptr, nullptr, &arg_18, &arg_20);
            int64_t r15_1 = arg_18;
            int64_t* rax_3 = __acrt_allocate_buffer_for_argv(r15_1, arg_20, 1);
            
            if (rax_3)
            {
                sub_18001fe04(rsi_1, rax_3, &rax_3[r15_1], &arg_18, &arg_20);
                
                if (arg1 != 1)
                {
                    int64_t* arg_10 = nullptr;
                    int32_t rax_7 = j_common_expand_argv_wildcards<char>(rax_3, &arg_10);
                    
                    if (!rax_7)
                    {
                        int64_t* rdx_4 = arg_10;
                        int64_t rcx_6 = 0;
                        int64_t* rax_8 = rdx_4;
                        
                        if (*rdx_4)
                        {
                            do
                            {
                                rax_8 = &rax_8[1];
                                rcx_6 += 1;
                            } while (*rax_8);
                        }
                        
                        data_180047ed8 = rcx_6;
                        arg_10 = nullptr;
                        data_180047ee0 = rdx_4;
                        _free_base(0);
                        arg_10 = nullptr;
                        _free_base(rax_3);
                    }
                    else
                    {
                        _free_base(arg_10);
                        arg_10 = nullptr;
                        _free_base(rax_3);
                        rdi = rax_7;
                    }
                }
                else
                {
                    int32_t rax_6 = arg_18 - 1;
                    data_180047ee0 = rax_3;
                    data_180047ed8 = rax_6;
                    _free_base(nullptr);
                }
            }
            else
            {
                rdi = rax_3 + 0xc;
                *sub_18002131c() = rdi;
                _free_base(nullptr);
            }
        }
        else
        {
            rdi = 0x16;
            *sub_18002131c() = 0x16;
            _invalid_parameter_noinfo();
        }
    }
    
    return rdi;
}

