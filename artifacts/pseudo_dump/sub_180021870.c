
  int64_t sub_180021870(int64_t* arg1, char* arg2, void* arg3, char* arg4, int64_t arg5, int32_t arg6, char arg7, int32_t arg8, int32_t arg9, int64_t* arg10)

{
    *arg2 = 0;
    int32_t rdi = 0;
    
    if (arg6 >= 0)
        rdi = arg6;
    
    char* rbx = arg2;
    
    if (arg3 <= rdi + 0xb)
    {
        arg10[6] = 1;
        *(arg10 + 0x2c) = 0x22;
        _invalid_parameter_internal(0, 0, 0, 0, 0, arg10);
        return 0x22;
    }
    
    if ((*arg1 >> 0x34 & 0x7ff) != 0x7ff)
    {
        if (*arg1 < 0)
        {
            *arg2 = 0x2d;
            rbx = &rbx[1];
        }
        
        int64_t rax_4;
        rax_4 = arg7;
        rax_4 ^= 1;
        uint64_t r15_1 = 0x3ff;
        uint32_t r13_1 = rax_4;
        
        if (*arg1 & 0x7ff0000000000000)
            *rbx = 0x31;
        else
        {
            *rbx = 0x30;
            r15_1 = (0x3ff - 0x3ff) & 0x3fe;
        }
        
        char* rsi_1 = &rbx[2];
        int64_t rax_10;
        
        if (rdi)
        {
            if (!arg10[5])
                __crt_cached_ptd_host::update_locale_slow(arg10);
            
            rax_10 = ***(arg10[3] + 0xf8);
        }
        else
            rax_10 = 0;
        
        rbx[1] = rax_10;
        
        if ((*arg1 & 0xfffffffffffff) > 0)
        {
            arg2 = 0x30;
            uint64_t r10_1 = 0xf000000000000;
            int16_t temp2_1;
            
            do
            {
                int16_t rcx_6 = arg2;
                
                if (rdi <= 0)
                {
                    char rax_18;
                    rax_18 = should_round_up(arg1, r10_1, rcx_6, arg9);
                    
                    if (!rax_18)
                        goto label_180021ae8;
                    
                    char* rcx_8 = &rsi_1[-1];
                    
                    while (true)
                    {
                        arg2 = *rcx_8;
                        
                        if (&arg2[-0x46] & 0xdf)
                            break;
                        
                        *rcx_8 = 0x30;
                        rcx_8 -= 1;
                    }
                    
                    if (rcx_8 == &rbx[1])
                        rcx_8[-1] += 1;
                    else
                    {
                        if (arg2 == 0x39)
                            arg2 += ((r13_1 << 5) + 7);
                        
                        arg2 += 1;
                        *rcx_8 = arg2;
                    }
                    
                    goto label_180021ac2;
                }
                
                uint16_t rax_17 = ((*arg1 & r10_1 & 0xfffffffffffff) >> rcx_6) + 0x30;
                
                if (rax_17 > 0x39)
                    rax_17 += (r13_1 << 5) + 7;
                
                *rsi_1 = rax_17;
                rdi -= 1;
                rsi_1 = &rsi_1[1];
                r10_1 u>>= 4;
                temp2_1 = arg2;
                arg2 -= 4;
            } while (temp2_1 - 4 >= 0);
        }
        
    label_180021ac2:
        
        if (rdi > 0)
        {
            arg2 = 0x30;
            sub_18002de50(rsi_1, arg2, rdi);
            rsi_1 = &rsi_1[rdi];
        }
        
    label_180021ae8:
        
        if (!rbx[1])
            rsi_1 = &rbx[1];
        
        r13_1 <<= 5;
        r13_1 += 0x50;
        *rsi_1 = r13_1;
        uint64_t rax_22 = *arg1 >> 0x34 & 0x7ff;
        uint64_t rcx_10 = rax_22;
        uint64_t rcx_11 = rcx_10 - r15_1;
        uint64_t rdx_1 = rcx_11;
        
        if (rcx_10 - r15_1 < 0)
            rcx_11 = r15_1 - rax_22;
        
        char rax_23 = 0x2b;
        char* r8_2 = &rsi_1[2];
        
        if (rdx_1 < 0)
            rax_23 = 0x2d;
        
        rsi_1[1] = rax_23;
        rsi_1[2] = 0x30;
        
        if (rcx_11 < 0x3e8)
        {
            if (rcx_11 < 0x64)
                goto label_180021ba8;
            
            goto label_180021b7f;
        }
        
        r8_2 = &rsi_1[3];
        rsi_1[2] = 0x30 + rcx_11 / 0x3e8;
        rcx_11 = rcx_11 % 0x3e8;
        
        if (r8_2 != &rsi_1[2] || rcx_11 >= 0x64)
        {
        label_180021b7f:
            *r8_2 = 0x30 + rcx_11 / 0x64;
            r8_2 = &r8_2[1];
            rcx_11 = rcx_11 % 0x64;
            
            if (r8_2 != &rsi_1[2] || rcx_11 >= 0xa)
            {
            label_180021bb8:
                *r8_2 = 0x30 + rcx_11 / 0xa;
                r8_2 = &r8_2[1];
                rcx_11 = rcx_11 % 0xa;
            }
        }
        else
        {
        label_180021ba8:
            
            if (rcx_11 >= 0xa)
                goto label_180021bb8;
        }
        
        rcx_11 += 0x30;
        *r8_2 = rcx_11;
        r8_2[1] = 0;
    }
    else
    {
        int32_t result = fp_format_e(arg1, arg2, arg3, arg4, arg5, rdi, 0, arg8, arg9, arg10);
        
        if (result)
        {
            *rbx = 0;
            return result;
        }
        
        char* rax_9 = sub_18002d460(rbx, 0x65);
        
        if (rax_9)
        {
            *rax_9 = ((arg7 ^ 1) << 5) + 0x50;
            rax_9[3] = 0;
        }
    }
    
    return 0;
}

