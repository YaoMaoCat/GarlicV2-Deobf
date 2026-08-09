
  uint64_t sub_18001a280(void* arg1, int64_t* arg2, int32_t* arg3, char* arg4)

{
    int64_t* rdi = arg2;
    int64_t rsi = arg3[1];
    
    if (rsi && _GetImageBase() != -(rsi))
    {
        int64_t rsi_1 = arg3[1];
        void* rax_4;
        int32_t rsi_2;
        
        if (!rsi_1)
        {
            rsi_2 = 0;
            rax_4 = nullptr;
        }
        else
        {
            rax_4 = _GetImageBase() + rsi_1;
            rsi_2 = 0;
        }
        
        if (*(rax_4 + 0x10))
        {
            int64_t rax_5 = arg3[2];
            
            if (rax_5 || *arg3 < rax_5)
            {
                int32_t rcx = *arg3;
                
                if (rcx >= 0)
                    rdi = rax_5 + *rdi;
                
                int64_t rax_7;
                
                if (rcx < 0 && *arg4 & 0x10)
                    rax_7 = data_1800475a0;
                
                if (rcx < 0 && *arg4 & 0x10 && rax_7)
                {
                    int64_t rax_8 = rax_7();
                    
                    if (!rax_8 || !rdi)
                    {
                        abort();
                        /* no return */
                    }
                    
                    *rdi = rax_8;
                    *rdi = sub_1800199f0(rax_8, &arg4[8]);
                }
                else if (rcx & 8)
                {
                    int64_t rcx_2 = *(arg1 + 0x28);
                    
                    if (!rcx_2 || !rdi)
                    {
                        abort();
                        /* no return */
                    }
                    
                    *rdi = rcx_2;
                    *rdi = sub_1800199f0(rcx_2, &arg4[8]);
                }
                else if (!(*arg4 & 1))
                {
                    int64_t rbx_1 = *(arg4 + 0x18);
                    int64_t rdx_4;
                    
                    if (!rbx_1)
                        rdx_4 = 0;
                    else
                        rdx_4 = _GetThrowImageBase() + rbx_1;
                    
                    int64_t rax_13 = *(arg1 + 0x28);
                    
                    if (rdx_4)
                    {
                        if (!rax_13 || !rdi)
                        {
                            abort();
                            /* no return */
                        }
                        
                        int64_t rbx_3 = *(arg4 + 0x18);
                        
                        if (!rbx_3)
                        {
                            abort();
                            /* no return */
                        }
                        
                        if (_GetThrowImageBase() == -(rbx_3))
                        {
                            abort();
                            /* no return */
                        }
                        
                        rsi_2 = *arg4 & 4;
                        rsi_2 += 1;
                        int32_t var_38_1 = rsi_2;
                    }
                    else
                    {
                        if (!rax_13 || !rdi)
                        {
                            abort();
                            /* no return */
                        }
                        
                        memcpy(rdi, sub_1800199f0(rax_13, &arg4[8]), *(arg4 + 0x14));
                    }
                }
                else
                {
                    int32_t* rdx_2 = *(arg1 + 0x28);
                    
                    if (!rdx_2 || !rdi)
                    {
                        abort();
                        /* no return */
                    }
                    
                    memcpy(rdi, rdx_2, *(arg4 + 0x14));
                    
                    if (*(arg4 + 0x14) == 8)
                    {
                        int64_t rcx_4 = *rdi;
                        
                        if (rcx_4)
                            *rdi = sub_1800199f0(rcx_4, &arg4[8]);
                    }
                }
                
                return rsi_2;
            }
        }
    }
    
    return 0;
}

