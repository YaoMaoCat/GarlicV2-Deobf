
  int64_t* sub_180005940(int64_t* arg1, int64_t* arg2)

{
    int64_t* arg_10 = arg2;
    int64_t* arg_8 = arg1;
    int64_t* rsi = arg1;
    int32_t var_64 = 0;
    void** rax;
    
    if (arg1[3] <= 0xf)
        rax = rsi;
    else
        rax = *arg1;
    
    void** var_58 = rax;
    int64_t var_50 = arg1[2];
    uint16_t rax_2 = sub_180005e90(arg1, &var_58);
    uint16_t r14 = rax_2;
    void** rcx = &rsi[4];
    
    if (rsi[7] > 0xf)
        rcx = *rcx;
    
    var_58 = rcx;
    int64_t var_50_1 = rsi[6];
    uint16_t rax_4 = sub_180005e90(rsi, &var_58);
    uint16_t r15 = rax_4;
    __builtin_memset(arg2, 0, 0x18);
    int32_t var_64_1 = 1;
    int128_t* rax_5 = sub_180016420(0x100);
    int32_t* rdx_2 = *arg2;
    memcpy(rax_5, rdx_2, arg2[1] - rdx_2);
    void* rcx_3 = *arg2;
    
    if (rcx_3)
    {
        void* rax_6;
        
        if (arg2[2] - rcx_3 < 0x1000)
            rax_6 = rcx_3;
        else
        {
            rax_6 = *(rcx_3 - 8);
            
            if (rcx_3 - rax_6 - 8 > 0x1f)
            {
            label_180005e0b:
                trap(0xd);
            }
        }
        
        j_sub_180021340(rax_6);
    }
    
    *arg2 = rax_5;
    arg2[1] = rax_5;
    arg2[2] = &rax_5[0x10];
    char arg_18 = 0xca;
    sub_180006510(arg2, &arg_18);
    arg_18 = 0xfe;
    sub_180006510(arg2, &arg_18);
    arg_18 = 0xba;
    sub_180006510(arg2, &arg_18);
    arg_18 = 0xbe;
    sub_180006510(arg2, &arg_18);
    arg_18 = 0;
    sub_180006510(arg2, &arg_18);
    arg_18 = 0;
    sub_180006510(arg2, &arg_18);
    uint16_t rbx_1 = rsi[8];
    arg_18 = (rbx_1 >> 8);
    sub_180006510(arg2, &arg_18);
    arg_18 = rbx_1;
    sub_180006510(arg2, &arg_18);
    int16_t rbx_4 = ((rsi[0xa] - rsi[9]) >> 5) + 1;
    arg_18 = (rbx_4 >> 8);
    sub_180006510(arg2, &arg_18);
    arg_18 = rbx_4;
    sub_180006510(arg2, &arg_18);
    char* i = rsi[9];
    int64_t rax_10 = rsi[0xa];
    arg_18 = rax_10;
    
    if (i != rax_10)
    {
        do
        {
            char* r14_1 = arg2[1];
            int64_t rcx_17 = arg2[2];
            
            if (r14_1 == rcx_17)
            {
                int64_t rax_12 = *arg2;
                void* r15_2 = r14_1 - rax_12;
                
                if (r15_2 == 0x7fffffffffffffff)
                {
                    sub_1800052a0();
                    /* no return */
                }
                
                int64_t rcx_18 = rcx_17 - rax_12;
                uint64_t rdx_17 = rcx_18 >> 1;
                void* rbx_5;
                char* rsi_1;
                uint64_t rcx_19;
                
                if (rcx_18 <= 0x7fffffffffffffff - rdx_17)
                {
                    void* rax_14 = rdx_17 + rcx_18;
                    rbx_5 = r15_2 + 1;
                    
                    if (rax_14 >= r15_2 + 1)
                        rbx_5 = rax_14;
                    
                    if (rbx_5)
                    {
                        if (rbx_5 >= 0x1000)
                        {
                            rcx_19 = rbx_5 + 0x27;
                            
                            if (rcx_19 > rbx_5)
                                goto label_180005ba4;
                            
                            stdext::threads::_Throw_lock_error();
                            /* no return */
                        }
                        
                        rsi_1 = sub_180016420(rbx_5);
                    }
                    else
                        rsi_1 = nullptr;
                }
                else
                {
                    rbx_5 = 0x7fffffffffffffff;
                    rcx_19 = -0x7fffffffffffffda;
                label_180005ba4:
                    int64_t rax_15 = sub_180016420(rcx_19);
                    
                    if (!rax_15)
                        goto label_180005e0b;
                    
                    rsi_1 = (rax_15 + 0x27) & 0xffffffffffffffe0;
                    *(rsi_1 - 8) = rax_15;
                }
                *(rsi_1 + r15_2) = *i;
                int64_t r8_2 = arg2[1];
                char* rdx_18 = *arg2;
                int128_t* rcx_22 = rsi_1;
                void* r8_3;
                
                if (r14_1 != r8_2)
                {
                    memcpy(rcx_22, rdx_18, r14_1 - rdx_18);
                    rcx_22 = r15_2 + 1 + rsi_1;
                    r8_3 = arg2[1] - r14_1;
                    rdx_18 = r14_1;
                }
                else
                    r8_3 = r8_2 - rdx_18;
                
                memcpy(rcx_22, rdx_18, r8_3);
                sub_180004fa0(arg2, rsi_1, r15_2 + 1, rbx_5);
            }
            else
            {
                *r14_1 = *i;
                arg2[1] += 1;
            }
            
            int32_t* r8_8 = *(i + 8);
            sub_1800045a0(arg2, arg2[1], r8_8, *(i + 0x10) - r8_8);
            i = &i[0x20];
        } while (i != arg_18);
        
        rsi = arg_8;
        r14 = rax_2;
        r15 = rax_4;
    }
    
    uint16_t rbx_6 = *(rsi + 0x42);
    arg_8 = (rbx_6 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = rbx_6;
    sub_180006510(arg2, &arg_8);
    arg_8 = (r14 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = r14;
    sub_180006510(arg2, &arg_8);
    arg_8 = (r15 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = r15;
    sub_180006510(arg2, &arg_8);
    arg_8 = 0;
    sub_180006510(arg2, &arg_8);
    arg_8 = 0;
    sub_180006510(arg2, &arg_8);
    arg_8 = 0;
    sub_180006510(arg2, &arg_8);
    arg_8 = 0;
    sub_180006510(arg2, &arg_8);
    int16_t rbx_9 = (rsi[0x15] - rsi[0x14]) >> 5;
    arg_8 = (rbx_9 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = rbx_9;
    sub_180006510(arg2, &arg_8);
    int64_t r14_2 = rsi[0x15];
    
    for (int16_t* i_1 = rsi[0x14]; i_1 != r14_2; i_1 = &i_1[0x10])
    {
        uint16_t rbx_10 = *i_1;
        arg_8 = (rbx_10 >> 8);
        sub_180006510(arg2, &arg_8);
        arg_8 = rbx_10;
        sub_180006510(arg2, &arg_8);
        uint16_t rbx_11 = i_1[1];
        arg_8 = (rbx_11 >> 8);
        sub_180006510(arg2, &arg_8);
        arg_8 = rbx_11;
        sub_180006510(arg2, &arg_8);
        uint16_t rbx_12 = i_1[2];
        arg_8 = (rbx_12 >> 8);
        sub_180006510(arg2, &arg_8);
        arg_8 = rbx_12;
        sub_180006510(arg2, &arg_8);
        arg_8 = 0;
        int64_t** rdx_39 = &arg_8;
        
        if (*(i_1 + 8) != *(i_1 + 0x10))
        {
            sub_180006510(arg2, rdx_39);
            arg_8 = 1;
            sub_180006510(arg2, &arg_8);
            int32_t* r8_9 = *(i_1 + 8);
            sub_1800045a0(arg2, arg2[1], r8_9, *(i_1 + 0x10) - r8_9);
        }
        else
        {
            sub_180006510(arg2, rdx_39);
            arg_8 = 0;
            sub_180006510(arg2, &arg_8);
        }
    }
    
    arg_8 = 0;
    sub_180006510(arg2, &arg_8);
    arg_8 = 0;
    sub_180006510(arg2, &arg_8);
    return arg2;
}

