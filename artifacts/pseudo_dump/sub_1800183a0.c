
  int64_t sub_1800183a0(int32_t* arg1, int64_t arg2, void* arg3, int64_t* arg4)

{
    __except_validate_context_record(arg3);
    int64_t r12 = arg4[1];
    int32_t* rdi = arg4[7];
    int64_t r15_1 = *arg4 - r12;
    int32_t i = arg4[9];
    
    if (arg1[1] & 0x66)
    {
        int32_t r8_2 = *rdi;
        
        if (i < r8_2)
        {
            int64_t rbx_5 = arg4[4] - r12;
            
            do
            {
                uint64_t rcx_7 = i * 2;
                void* r11_1 = &rdi[rcx_7 * 2];
                
                if (r15_1 >= rdi[rcx_7 * 2 + 1] && r15_1 < *(r11_1 + 8))
                {
                    int32_t rbp_2 = arg1[1] & 0x20;
                    
                    if (rbp_2)
                    {
                        int32_t rdx_4 = 0;
                        
                        if (r8_2)
                        {
                            do
                            {
                                uint64_t rcx_9 = rdx_4 * 2;
                                
                                if (rbx_5 >= rdi[rcx_9 * 2 + 1] && rbx_5 < rdi[rcx_9 * 2 + 2]
                                        && rdi[rcx_9 * 2 + 4] == rdi[rcx_7 * 2 + 4]
                                        && rdi[rcx_9 * 2 + 3] == rdi[rcx_7 * 2 + 3])
                                    break;
                                
                                rdx_4 += 1;
                            } while (rdx_4 < r8_2);
                        }
                        
                        if (rdx_4 != *rdi)
                            break;
                    }
                    
                    uint64_t rax_16 = *(r11_1 + 0x10);
                    
                    if (!rax_16)
                    {
                        arg4[9] = i + 1;
                        int64_t* rcx_10;
                        rcx_10 = 1;
                        (*(r11_1 + 0xc) + r12)(rcx_10, arg2);
                    }
                    else if (rbx_5 == rax_16 && rbp_2)
                        break;
                }
                
                r8_2 = *rdi;
                i += 1;
            } while (i < r8_2);
        }
    }
    else
    {
        int32_t* var_58 = arg1;
        void* var_50_1 = arg3;
        
        for (; i < *rdi; i += 1)
        {
            void* rbx_3 = &rdi[i * 4];
            
            if (r15_1 >= *(rbx_3 + 4) && r15_1 < *(rbx_3 + 8) && *(rbx_3 + 0x10))
            {
                uint64_t rax_3 = *(rbx_3 + 0xc);
                
                if (rax_3 == 1)
                {
                label_180018451:
                    
                    if (*arg1 == 0xe06d7363 && sub_18002d2a0(&data_1800389d8))
                        sub_180019930(arg1);
                    
                    *(rbx_3 + 0x10);
                    sub_180019b40();
                    RtlUnwindEx(arg2, *(rbx_3 + 0x10) + r12, arg1, *arg1, arg4[5], arg4[8]);
                }
                else
                {
                    int32_t rax_5 = (rax_3 + r12)(&var_58, arg2);
                    
                    if (rax_5 < 0)
                        return 0;
                    
                    if (rax_5 > 0)
                        goto label_180018451;
                }
            }
        }
    }
    
    return 1;
}

