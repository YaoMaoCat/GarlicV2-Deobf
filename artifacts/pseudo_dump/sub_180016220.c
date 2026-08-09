
  int64_t sub_180016220(int64_t arg1, void* arg2, int32_t* arg3)

{
    int64_t rsi = *arg3;
    int64_t r10_2;
    
    if (!(rsi & 4))
        r10_2 = arg1;
    else
        r10_2 = (arg3[1] + arg1) & -(arg3[2]);
    
    char* r8_2 = *(*(arg2 + 0x10) + 8) + *(arg2 + 8);
    uint32_t rcx = r8_2[3];
    int64_t r9_1;
    
    if ((*r8_2 & 7) >= 3)
    {
        int32_t r11_2 = rcx & 0x1f;
        
        if (r11_2)
        {
            r9_1 = 0;
            uint32_t rdx_1 = rcx >> 5;
            char* r8_4 = &r8_2[4 + r11_2];
            int32_t rcx_1 = 0;
            
            if (rdx_1)
            {
                do
                {
                    uint32_t rax_6 = *r8_4;
                    r8_4 = &r8_4[3];
                    uint64_t rax_7 = rax_6 >> 3;
                    
                    if (rax_7)
                        r8_4 = &r8_4[3 + rax_7];
                    
                    rcx_1 += 1;
                } while (rcx_1 < rdx_1);
            }
            
            int32_t rbx_1 = 0;
            
            if (r11_2)
            {
                while (true)
                {
                    char rax_8 = *r8_4;
                    char rdx_2 = rax_8;
                    
                    if (rax_8 <= 3)
                    {
                    label_180016304:
                        
                        if (!rdx_2)
                        {
                            break;
                            break;
                        }
                        
                        if (rax_8 > 3)
                        {
                            char rdx_3 = rax_8 & 0xf;
                            
                            if (rdx_3 - 8 > 2)
                            {
                                rdx_3 = rax_8 & 7;
                                
                                if (rdx_3 - 4 > 3)
                                    goto label_180016328;
                            }
                            
                            rax_8 = rdx_3;
                            
                            if (rax_8 > 0x20)
                            {
                                sub_1800161f0();
                                /* no return */
                            }
                        }
                    }
                    else
                    {
                        rdx_2 &= 0xf;
                        
                        if (rdx_2 - 8 <= 2)
                            goto label_180016304;
                        
                        rdx_2 = rax_8 & 7;
                        
                        if (rdx_2 - 4 <= 3)
                            goto label_180016304;
                        
                    label_180016328:
                        rax_8 &= 0x3f;
                        
                        if (rax_8 != 0x20)
                        {
                            sub_1800161f0();
                            /* no return */
                        }
                    }
                    
                    int64_t rax_11;
                    
                    switch (jump_table_1800163b0[lookup_table_1800163c4[rax_8]])
                    {
                        case 0x1634e:
                        {
                            rax_11 = 1;
                            break;
                        }
                        case 0x16355:
                        {
                            rax_11 = 2;
                            break;
                        }
                        case 0x1635c:
                        {
                            rax_11 = 3;
                            break;
                        }
                        case 0x16363:
                        {
                            rax_11 = 5;
                            break;
                        }
                        case 0x163a9:
                        {
                            sub_1800161f0();
                            /* no return */
                        }
                    }
                    
                    r8_4 = &r8_4[rax_11];
                    rbx_1 += 1;
                    
                    if (rbx_1 >= r11_2)
                        goto label_1800163a4;
                }
                
                r9_1 = r8_4[1] & 0xfffffffffffffff0;
            }
        }
        else
            r9_1 = 0;
    }
    else if (!(rcx & 0xf))
        r9_1 = 0;
    else
        r9_1 = rcx & 0xfffffffffffffff0;
    
label_1800163a4:
    /* tailcall */
    return __security_check_cookie((r9_1 + arg1) ^ *((rsi & 0xfffffffffffffff8) + r10_2));
}

