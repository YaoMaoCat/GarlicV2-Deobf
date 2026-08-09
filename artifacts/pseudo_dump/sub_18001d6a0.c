
  uint64_t sub_18001d6a0(int64_t* arg1, int64_t* arg2, int32_t arg3, char arg4)

{
    char* r12 = *arg2;
    int32_t rbp = arg3;
    int64_t* rbx = arg2;
    
    if (r12)
    {
        if (rbp && arg3 - 2 > 0x22)
        {
            arg1[6] = 1;
            *(arg1 + 0x2c) = 0x16;
            _invalid_parameter_internal(0, 0, 0, 0, 0, arg1);
            goto label_18001d711;
        }
        
        int64_t rsi;
        rsi = *r12;
        char* rcx_1 = &r12[1];
        int32_t r14_1 = 0;
        uint32_t rax_4 = arg4;
        *arg2 = rcx_1;
        uint32_t rdi_2 = rax_4 | 2;
        
        if (rsi != 0x2d)
            rdi_2 = rax_4;
        
        if (rsi == 0x2d || rsi == 0x2b)
        {
            rsi = *rcx_1;
            rcx_1 = &rcx_1[1];
            *arg2 = rcx_1;
        }
        
        if (!(rbp & 0xffffffef))
        {
            int32_t rax_7;
            int32_t rax_16;
            
            if (rsi - 0x30 > 9)
            {
                if (rsi - 0x61 <= 0x19)
                {
                    rax_7 = rsi - 0x57;
                    goto label_18001d797;
                }
                
                if (rsi - 0x41 <= 0x19)
                {
                    rax_7 = rsi - 0x37;
                    goto label_18001d797;
                }
                
            label_18001d7e5:
                rax_16 = 0xa;
            label_18001d7ec:
                
                if (rbp)
                    rax_16 = rbp;
                
                rbp = rax_16;
            }
            else
            {
                rax_7 = rsi - 0x30;
            label_18001d797:
                
                if (rax_7)
                    goto label_18001d7e5;
                
                arg2 = *rcx_1;
                *rbx = &rcx_1[1];
                
                if (!(&arg2[-0xb] & 0xdf))
                {
                    rsi = rcx_1[1];
                    *rbx = &rcx_1[2];
                    rax_16 = 0x10;
                    goto label_18001d7ec;
                }
                
                *rbx = rcx_1;
                int32_t rax_13 = 8;
                
                if (rbp)
                    rax_13 = rbp;
                
                rbp = rax_13;
                
                if (arg2 && *rcx_1 != arg2)
                {
                    *sub_18002131c() = 0x16;
                    _invalid_parameter_noinfo();
                }
            }
        }
        
        char* r8_1 = *rbx;
        
        while (true)
        {
            int32_t rcx_4;
            
            if (rsi - 0x30 <= 9)
                rcx_4 = rsi - 0x30;
            else if (rsi - 0x61 <= 0x19)
                rcx_4 = rsi - 0x57;
            else if (rsi - 0x41 > 0x19)
                rcx_4 = -1;
            else
                rcx_4 = rsi - 0x37;
            
            if (rcx_4 >= rbp)
                break;
            
            rsi = *r8_1;
            int32_t rax_21 = r14_1 * rbp;
            int32_t rdx_1 = rax_21 + rcx_4;
            int32_t rcx_7;
            rcx_7 = rdx_1 < rax_21;
            bool cond:1_1 = r14_1 > COMBINE(0, 0xffffffff) / rbp;
            r14_1 = rdx_1;
            int32_t rax_22;
            rax_22 = cond:1_1;
            rdi_2 |= (rcx_7 | rax_22) << 2 | 8;
            r8_1 = &r8_1[1];
            *rbx = r8_1;
        }
        
        *rbx = &r8_1[-1];
        
        if (rsi && r8_1[-1] != rsi)
        {
            *sub_18002131c() = 0x16;
            _invalid_parameter_noinfo();
        }
        
        if (rdi_2 & 8)
        {
            uint32_t rax_26;
            uint32_t rcx_11;
            
            if (rdi_2 & 4)
            {
                rax_26 = 1;
                rcx_11 = rdi_2;
            label_18001d8dd:
                arg1[6] = 1;
                *(arg1 + 0x2c) = 0x22;
                
                if (rax_26 & rcx_11)
                {
                    int64_t* rdx_2 = rbx[1];
                    
                    if (!(2 & rdi_2))
                    {
                        if (rdx_2)
                            *rdx_2 = *rbx;
                        
                        return 0x7fffffff;
                    }
                    
                    if (rdx_2)
                        *rdx_2 = *rbx;
                    
                    return 0x80000000;
                }
                
                r14_1 = -1;
            }
            else if (!(rdi_2 & 1))
            {
                if (2 & rdi_2)
                    r14_1 = -(r14_1);
            }
            else if (2 & rdi_2)
            {
                if (r14_1 > 0x80000000)
                    goto label_18001d8d3;
                
                r14_1 = -(r14_1);
            }
            else if (r14_1 > 0x7fffffff)
            {
            label_18001d8d3:
                rcx_11 = 1;
                rax_26 = rdi_2;
                goto label_18001d8dd;
            }
            int64_t* rax_28 = rbx[1];
            
            if (rax_28)
                *rax_28 = *rbx;
            
            return r14_1;
        }
        
        void** rax_25 = rbx[1];
        *rbx = r12;
        
        if (rax_25)
            *rax_25 = r12;
    }
    else
    {
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
    label_18001d711:
        int64_t* rcx = rbx[1];
        
        if (rcx)
            *rcx = *rbx;
    }
    
    return 0;
}

