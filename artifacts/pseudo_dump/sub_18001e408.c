
  uint64_t sub_18001e408(int64_t* arg1)

{
    int64_t* rax = arg1[1];
    int64_t* var_10_1;
    
    if (arg1[0x8c])
    {
        char* rcx = arg1[2];
        
        if (rcx)
        {
            int32_t rax_2 = arg1[0x8d] + 1;
            arg1[0x8d] = rax_2;
            
            if (rax_2 == 2)
                return arg1[4];
            
            while (true)
            {
                arg1[9] = 0;
                *(arg1 + 0x24) = 0;
                int64_t r8;
                r8 = *rcx;
                rcx = &rcx[1];
                
                while (true)
                {
                    arg1[2] = rcx;
                    *(arg1 + 0x39) = r8;
                    
                    if (!r8 || arg1[4] < 0)
                    {
                        arg1[0x8d] += 1;
                        
                        if (arg1[0x8d] != 2)
                            break;
                        
                        return arg1[4];
                    }
                    
                    if (r8 - 0x20 > 0x5a)
                        rcx = 0;
                    else
                        rcx = *((((r8 - 0x20) & 0x7f) << 1) + 0x1800397f1);
                    
                    uint32_t rax_8 =
                        *(&data_1800397f0 + (((*(arg1 + 0x24) + (rcx << 3)) & 0x7f) << 1));
                    *(arg1 + 0x24) = rax_8;
                    
                    if (rax_8 < 8)
                    {
                        if (rax_8)
                        {
                            if (rax_8 == 1)
                            {
                                arg1[5] = 0;
                                arg1[7] = 0;
                                arg1[6] = 0xffffffff;
                                *(arg1 + 0x34) = 0;
                                *(arg1 + 0x4c) = 0;
                            }
                            else if (rax_8 == 2)
                            {
                                if (r8 == 0x20)
                                    arg1[5] |= 2;
                                else if (r8 == 0x23)
                                    arg1[5] |= 0x20;
                                else if (r8 == 0x2b)
                                    arg1[5] |= 1;
                                else if (r8 == 0x2d)
                                    arg1[5] |= 4;
                                else if (r8 == 0x30)
                                    arg1[5] |= 8;
                            }
                            else
                            {
                                int32_t rax_9;
                                int32_t* rdx_3;
                                
                                if (rax_8 == 3)
                                {
                                    if (r8 == 0x2a)
                                    {
                                        int32_t* rcx_14 = arg1[3];
                                        arg1[3] = &rcx_14[2];
                                        rax_9 = *rcx_14;
                                        *(arg1 + 0x2c) = rax_9;
                                        
                                        if (rax_9 < 0)
                                        {
                                            arg1[5] |= 4;
                                            *(arg1 + 0x2c) = -(rax_9);
                                        }
                                        
                                    label_18001e59f:
                                        rax_9 = 1;
                                        goto label_18001e5a1;
                                    }
                                    
                                    rdx_3 = arg1 + 0x2c;
                                label_18001e54c:
                                    rax_9 = sub_18001e378(arg1, rdx_3);
                                label_18001e5a1:
                                    
                                    if (!rax_9)
                                        return 0xffffffff;
                                }
                                else
                                {
                                    if (rax_8 != 4)
                                    {
                                        if (rax_8 != 5)
                                        {
                                            if (rax_8 == 6)
                                                rax_9 = sub_18001e778(arg1);
                                            else
                                            {
                                                if (rax_8 != 7)
                                                    return 0xffffffff;
                                                
                                                rax_9 = sub_18001e900(arg1);
                                            }
                                            
                                            goto label_18001e5a1;
                                        }
                                        
                                        if (r8 != 0x2a)
                                        {
                                            rdx_3 = &arg1[6];
                                            goto label_18001e54c;
                                        }
                                        
                                        int32_t* rcx_13 = arg1[3];
                                        arg1[3] = &rcx_13[2];
                                        rax_9 = *rcx_13;
                                        arg1[6] = rax_9;
                                        
                                        if (rax_9 < 0)
                                            arg1[6] = 0xffffffff;
                                        
                                        goto label_18001e59f;
                                    }
                                    
                                    arg1[6] = 0;
                                }
                            }
                            
                            goto label_18001e6e0;
                        }
                        
                        int64_t* rdi_1 = arg1[1];
                        *(arg1 + 0x4c) = 0;
                        
                        if (!rdi_1[5])
                            __crt_cached_ptd_host::update_locale_slow(rdi_1);
                        
                        r8 = *(arg1 + 0x39);
                        
                        if (r8 < 0xffffffff || !(*(*rdi_1[3] + (r8 << 1)) & 0x8000))
                        {
                        label_18001e6a1:
                            void* rcx_19 = arg1[0x8c];
                            
                            if (*(rcx_19 + 0x10) != *(rcx_19 + 8))
                            {
                                arg1[4] += 1;
                                *(rcx_19 + 0x10) += 1;
                                **arg1[0x8c] = r8;
                                int64_t* rax_20 = arg1[0x8c];
                                *rax_20 += 1;
                            }
                            else if (!*(rcx_19 + 0x18))
                                arg1[4] = 0xffffffff;
                            else
                                arg1[4] += 1;
                            
                        label_18001e6e0:
                            char* rax_21 = arg1[2];
                            r8 = *rax_21;
                            rcx = &rax_21[1];
                            continue;
                        }
                        else
                        {
                            void* rcx_17 = arg1[0x8c];
                            
                            if (*(rcx_17 + 0x10) != *(rcx_17 + 8))
                            {
                                arg1[4] += 1;
                                *(rcx_17 + 0x10) += 1;
                                **arg1[0x8c] = r8;
                                int64_t* rax_15 = arg1[0x8c];
                                *rax_15 += 1;
                            }
                            else if (!*(rcx_17 + 0x18))
                                arg1[4] = 0xffffffff;
                            else
                                arg1[4] += 1;
                            
                            char* rax_16 = arg1[2];
                            r8 = *rax_16;
                            arg1[2] = &rax_16[1];
                            *(arg1 + 0x39) = r8;
                            
                            if (r8)
                                goto label_18001e6a1;
                        }
                        
                        void* rax_23 = arg1[1];
                        *(rax_23 + 0x30) = 1;
                        *(rax_23 + 0x2c) = 0x16;
                        _invalid_parameter_internal(0, 0, 0, 0, 0, arg1[1]);
                    }
                    
                    void* rax_25 = arg1[1];
                    *(rax_25 + 0x30) = 1;
                    *(rax_25 + 0x2c) = 0x16;
                    rax = arg1[1];
                    goto label_18001e76c;
                }
            }
        }
        else
        {
            rax[6] = 1;
            *(rax + 0x2c) = 0x16;
            var_10_1 = arg1[1];
        }
    }
    else
    {
        rax[6] = 1;
        *(rax + 0x2c) = 0x16;
    label_18001e76c:
        var_10_1 = rax;
    }
    
    _invalid_parameter_internal(0, 0, 0, 0, 0, var_10_1);
    return 0xffffffff;
}

