
  uint64_t common_set_variable_in_environment_nolock<char>(char* arg1, int32_t arg2)

{
    if (arg1)
    {
        char* rdi_1 = arg1;
        char* rax_1 = sub_18002d5a0(arg1, 0x3d);
        
        if (rax_1 && rax_1 != arg1)
        {
            int64_t* r14_1 = data_180047798;
            int64_t rbp;
            rbp = rax_1[1];
            char arg_8 = rbp;
            
            if (r14_1 == data_1800477b0)
            {
                int64_t* rax_2 = copy_environment<char>(r14_1);
                r14_1 = rax_2;
                data_180047798 = rax_2;
            }
            
            int32_t rbp_1;
            
            if (r14_1)
            {
            label_180025b86:
                char* rax_11 = *r14_1;
                char* r12_2 = rax_1 - arg1;
                int64_t* rbx_1 = r14_1;
                int64_t rbx_4;
                
                while (true)
                {
                    if (!rax_11)
                    {
                        rbx_4 = -(((rbx_1 - r14_1) >> 3));
                        break;
                    }
                    
                    if (!sub_1800237d0(arg1, rax_11, r12_2))
                    {
                        int64_t rax_10 = *rbx_1;
                        
                        if (r12_2[rax_10] == 0x3d || !r12_2[rax_10])
                        {
                            rbx_4 = (rbx_1 - r14_1) >> 3;
                            break;
                        }
                    }
                    
                    rbx_1 = &rbx_1[1];
                    rax_11 = *rbx_1;
                }
                
                if (rbx_4 >= 0 && *r14_1)
                {
                    _free_base(r14_1[rbx_4]);
                    
                    if (!rbp)
                    {
                        while (r14_1[rbx_4])
                        {
                            r14_1[rbx_4] = r14_1[rbx_4 + 1];
                            rbx_4 += 1;
                        }
                        
                        void* rax_13 = _recalloc_base(r14_1, rbx_4, 8);
                        _free_base(0);
                        
                        if (rax_13)
                            data_180047798 = rax_13;
                    }
                    else
                    {
                        r14_1[rbx_4] = arg1;
                    label_180025c91:
                        rdi_1 = nullptr;
                    }
                    
                    if (arg2)
                    {
                        int64_t rbp_2 = rbp | 0xffffffffffffffff;
                        int64_t r14_3 = rbp_2;
                        
                        do
                            r14_3 += 1;
                         while (arg1[r14_3]);
                        
                        char* rax_15 = _calloc_base(r14_3 + 2, 1);
                        
                        if (!rax_15)
                        {
                            _free_base(0);
                            _free_base(rdi_1);
                            return 0;
                        }
                        
                        int32_t rax_16;
                        int64_t rdx_4;
                        rax_16 = sub_180020d70(rax_15, r14_3 + 2, arg1);
                        
                        if (rax_16)
                        {
                            int64_t var_48 = 0;
                            _invoke_watson();
                            /* no return */
                        }
                        
                        char* rax_18 = rax_15 - arg1;
                        char temp0_1 = arg_8;
                        arg_8 = -(arg_8);
                        *(rax_18 + rax_1) = 0;
                        
                        if (!__acrt_SetEnvironmentVariableA(rax_15, 
                            (rdx_4 - rdx_4) & (&rax_1[1] + rax_18)))
                        {
                            *sub_18002131c() = 0x2a;
                            _free_base(rax_15);
                            _free_base(rdi_1);
                            return rbp_2;
                        }
                        
                        _free_base(rax_15);
                    }
                    
                    _free_base(rdi_1);
                    return 0;
                }
                
                if (rbp)
                {
                    int64_t rbx_7 = -(rbx_4);
                    
                    if (rbx_7 + 2 < rbx_7 || rbx_7 + 2 >= 0x1fffffffffffffff)
                        rbp_1 = rbp | 0xffffffff;
                    else
                    {
                        void* rax_14 = _recalloc_base(r14_1, rbx_7 + 2, 8);
                        _free_base(0);
                        
                        if (rax_14)
                        {
                            *(rax_14 + (rbx_7 << 3)) = arg1;
                            *(rax_14 + (rbx_7 << 3) + 8) = 0;
                            data_180047798 = rax_14;
                            goto label_180025c91;
                        }
                        
                        rbp_1 = rbp | 0xffffffff;
                    }
                }
                else
                    rbp_1 = 0;
            }
            else if (arg2 && data_1800477a0)
            {
                if (__dcrt_get_or_create_narrow_environment_nolock())
                {
                    r14_1 = data_180047798;
                    
                    if (r14_1 == data_1800477b0)
                    {
                        int64_t* rax_6 = copy_environment<char>(r14_1);
                        r14_1 = rax_6;
                        data_180047798 = rax_6;
                    }
                    
                    goto label_180025b7d;
                }
                
                *sub_18002131c() = 0x16;
                rbp_1 = rbp | 0xffffffff;
            }
            else if (!rbp)
                rbp_1 = 0;
            else
            {
                data_180047798 = _calloc_base(1, 8);
                _free_base(0);
                r14_1 = data_180047798;
                
                if (!r14_1)
                    rbp_1 = rbp | 0xffffffff;
                else
                {
                    if (data_1800477a0)
                        goto label_180025b7d;
                    
                    data_1800477a0 = _calloc_base(1, 8);
                    _free_base(0);
                    
                    if (!data_1800477a0)
                        rbp_1 = rbp | 0xffffffff;
                    else
                    {
                        r14_1 = data_180047798;
                    label_180025b7d:
                        
                        if (r14_1)
                            goto label_180025b86;
                        
                        rbp_1 = rbp | 0xffffffff;
                    }
                }
            }
            
            _free_base(arg1);
            return rbp_1;
        }
        
        *sub_18002131c() = 0x16;
        _free_base(arg1);
    }
    else
        *sub_18002131c() = 0x16;
    
    return -1;
}

