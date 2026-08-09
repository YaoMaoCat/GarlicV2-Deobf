
  void** sub_180005010(int64_t* arg1, int64_t* arg2, void** arg3)

{
    arg1[1] += 1;
    void** r10 = arg3;
    void** r11 = *arg1;
    void** rax = *arg2;
    arg3[1] = rax;
    
    if (rax == r11)
    {
        *r11 = arg3;
        r11[1] = arg3;
        r11[2] = arg3;
        arg3[3] = 1;
        return arg3;
    }
    
    if (arg2[1])
    {
        *rax = r10;
        
        if (rax == *r11)
            *r11 = r10;
    }
    else
    {
        rax[2] = r10;
        
        if (rax == r11[2])
            r11[2] = r10;
    }
    
    while (!*(arg3[1] + 0x18))
    {
        void** rax_5 = arg3[1];
        int64_t* rdx = rax_5[1];
        void* rcx = *rdx;
        int64_t* rcx_9;
        int64_t** rdx_2;
        
        if (rax_5 == rcx)
        {
            void* rcx_1 = rdx[2];
            
            if (*(rcx_1 + 0x18))
            {
                void** rdx_1 = rax_5[2];
                
                if (arg3 == rdx_1)
                {
                    arg3 = rax_5;
                    rax_5[2] = *rdx_1;
                    void* rcx_4 = *rdx_1;
                    
                    if (!*(rcx_4 + 0x19))
                        *(rcx_4 + 8) = rax_5;
                    
                    rdx_1[1] = rax_5[1];
                    void* rcx_6 = *arg1;
                    
                    if (rax_5 != *(rcx_6 + 8))
                    {
                        int64_t* rcx_7 = rax_5[1];
                        
                        if (rax_5 != *rcx_7)
                            rcx_7[2] = rdx_1;
                        else
                            *rcx_7 = rdx_1;
                    }
                    else
                        *(rcx_6 + 8) = rdx_1;
                    
                    *rdx_1 = rax_5;
                    rax_5[1] = rdx_1;
                    rax_5 = rdx_1;
                }
                
                rax_5[3] = 1;
                *(*(arg3[1] + 8) + 0x18) = 0;
                rcx_9 = *(arg3[1] + 8);
                rdx_2 = *rcx_9;
                *rcx_9 = rdx_2[2];
                void* rax_9 = rdx_2[2];
                
                if (!*(rax_9 + 0x19))
                    *(rax_9 + 8) = rcx_9;
                
                rdx_2[1] = rcx_9[1];
                void* rax_11 = *arg1;
                
                if (rcx_9 != *(rax_11 + 8))
                {
                    int64_t*** rax_12 = rcx_9[1];
                    
                    if (rcx_9 != rax_12[2])
                    {
                        *rax_12 = rdx_2;
                        rdx_2[2] = rcx_9;
                    }
                    else
                    {
                        rax_12[2] = rdx_2;
                        rdx_2[2] = rcx_9;
                    }
                }
                else
                {
                    *(rax_11 + 8) = rdx_2;
                    rdx_2[2] = rcx_9;
                }
                
                rcx_9[1] = rdx_2;
            }
            else
            {
                rax_5[3] = 1;
                *(rcx_1 + 0x18) = 1;
                *(*(arg3[1] + 8) + 0x18) = 0;
                arg3 = *(arg3[1] + 8);
            }
        }
        else if (*(rcx + 0x18))
        {
            void** rdx_3 = *rax_5;
            
            if (arg3 != rdx_3)
                rdx_3 = rax_5;
            else
            {
                arg3 = rax_5;
                *rax_5 = rdx_3[2];
                void* rcx_12 = rdx_3[2];
                
                if (!*(rcx_12 + 0x19))
                    *(rcx_12 + 8) = rax_5;
                
                rdx_3[1] = rax_5[1];
                void* rcx_14 = *arg1;
                
                if (rax_5 != *(rcx_14 + 8))
                {
                    void** rcx_15 = rax_5[1];
                    
                    if (rax_5 != rcx_15[2])
                    {
                        *rcx_15 = rdx_3;
                        rdx_3[2] = rax_5;
                        rax_5[1] = rdx_3;
                    }
                    else
                    {
                        rcx_15[2] = rdx_3;
                        rdx_3[2] = rax_5;
                        rax_5[1] = rdx_3;
                    }
                }
                else
                {
                    *(rcx_14 + 8) = rdx_3;
                    rdx_3[2] = rax_5;
                    rax_5[1] = rdx_3;
                }
            }
            
            rdx_3[3] = 1;
            *(*(arg3[1] + 8) + 0x18) = 0;
            rcx_9 = *(arg3[1] + 8);
            rdx_2 = rcx_9[2];
            rcx_9[2] = *rdx_2;
            int64_t* rax_18 = *rdx_2;
            
            if (!*(rax_18 + 0x19))
                rax_18[1] = rcx_9;
            
            rdx_2[1] = rcx_9[1];
            void* rax_20 = *arg1;
            
            if (rcx_9 != *(rax_20 + 8))
            {
                int64_t*** rax_21 = rcx_9[1];
                
                if (rcx_9 != *rax_21)
                    rax_21[2] = rdx_2;
                else
                    *rax_21 = rdx_2;
            }
            else
                *(rax_20 + 8) = rdx_2;
            
            *rdx_2 = rcx_9;
            rcx_9[1] = rdx_2;
        }
        else
        {
            rax_5[3] = 1;
            *(rcx + 0x18) = 1;
            *(*(arg3[1] + 8) + 0x18) = 0;
            arg3 = *(arg3[1] + 8);
        }
    }
    
    *(r11[1] + 0x18) = 1;
    return r10;
}

