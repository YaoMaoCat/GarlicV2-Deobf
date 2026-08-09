
  int64_t sub_18000d0b0(int64_t* arg1)

{
    void* i = arg1[0x12];
    
    if (!i)
        goto label_18000d187;
    
    for (int64_t rsi_1 = arg1[0x13]; i != rsi_1; i += 0x20)
    {
        void* rax_1 = *(i + 8);
        
        if (rax_1)
        {
            void* rcx;
            
            if (*(i + 0x18) - rax_1 < 0x1000)
                rcx = rax_1;
            else
            {
                rcx = *(rax_1 - 8);
                
                if (rax_1 - rcx - 8 > 0x1f)
                    goto label_18000d333;
            }
            
            j_sub_180021340(rcx);
            __builtin_memset(i + 8, 0, 0x18);
        }
    }
    
    void* rax_4 = arg1[0x12];
    void* rcx_1;
    
    if (((arg1[0x14] - rax_4) & 0xffffffffffffffe0) < 0x1000)
    {
        rcx_1 = rax_4;
    label_18000d16d:
        j_sub_180021340(rcx_1);
        __builtin_memset(&arg1[0x12], 0, 0x18);
    label_18000d187:
        void* rax_7 = arg1[0xf];
        
        if (!rax_7)
            goto label_18000d1d8;
        
        void* rcx_2;
        
        if (arg1[0x11] - rax_7 < 0x1000)
        {
            rcx_2 = rax_7;
        label_18000d1c1:
            j_sub_180021340(rcx_2);
            __builtin_memset(&arg1[0xf], 0, 0x18);
        label_18000d1d8:
            void* rax_10 = arg1[0xc];
            
            if (!rax_10)
                goto label_18000d220;
            
            void* rcx_3;
            
            if (arg1[0xe] - rax_10 < 0x1000)
            {
                rcx_3 = rax_10;
            label_18000d20f:
                j_sub_180021340(rcx_3);
                __builtin_memset(&arg1[0xc], 0, 0x18);
            label_18000d220:
                void* rcx_4 = arg1[9];
                
                if (!rcx_4)
                    goto label_18000d276;
                
                void* rax_16;
                
                if (((arg1[0xb] - rcx_4) >> 1) * 2 < 0x1000)
                {
                    rax_16 = rcx_4;
                label_18000d261:
                    j_sub_180021340(rax_16);
                    __builtin_memset(&arg1[9], 0, 0x18);
                label_18000d276:
                    int64_t result = j_sub_180003a30(&arg1[5]);
                    void* i_1 = *arg1;
                    
                    if (!i_1)
                        return result;
                    
                    for (int64_t rsi_2 = arg1[1]; i_1 != rsi_2; i_1 += 0x28)
                    {
                        void* rax_17 = *(i_1 + 8);
                        
                        if (rax_17)
                        {
                            void* rcx_9;
                            
                            if (*(i_1 + 0x18) - rax_17 < 0x1000)
                                rcx_9 = rax_17;
                            else
                            {
                                rcx_9 = *(rax_17 - 8);
                                
                                if (rax_17 - rcx_9 - 8 > 0x1f)
                                    goto label_18000d333;
                            }
                            
                            j_sub_180021340(rcx_9);
                            __builtin_memset(i_1 + 8, 0, 0x18);
                        }
                    }
                    
                    void* r8_1 = *arg1;
                    int64_t rax_20;
                    int64_t rdx_19;
                    rdx_19 = HIGHQ(0x6666666666666667 * (arg1[2] - r8_1));
                    rax_20 = LOWQ(0x6666666666666667 * (arg1[2] - r8_1));
                    int64_t rdx_20 = rdx_19 >> 4;
                    void* rcx_12;
                    
                    if ((rdx_20 + (rdx_20 >> 0x3f)) * 0x28 < 0x1000)
                    {
                        rcx_12 = r8_1;
                    label_18000d338:
                        result = j_sub_180021340(rcx_12);
                        __builtin_memset(arg1, 0, 0x18);
                        return result;
                    }
                    
                    rcx_12 = *(r8_1 - 8);
                    
                    if (r8_1 - rcx_12 - 8 <= 0x1f)
                        goto label_18000d338;
                }
                else
                {
                    rax_16 = *(rcx_4 - 8);
                    
                    if (rcx_4 - rax_16 - 8 <= 0x1f)
                        goto label_18000d261;
                }
            }
            else
            {
                rcx_3 = *(rax_10 - 8);
                
                if (rax_10 - rcx_3 - 8 <= 0x1f)
                    goto label_18000d20f;
            }
        }
        else
        {
            rcx_2 = *(rax_7 - 8);
            
            if (rax_7 - rcx_2 - 8 <= 0x1f)
                goto label_18000d1c1;
        }
    }
    else
    {
        rcx_1 = *(rax_4 - 8);
        
        if (rax_4 - rcx_1 - 8 <= 0x1f)
            goto label_18000d16d;
    }
label_18000d333:
    trap(0xd);
}

