
  int64_t* sub_18000a130(int64_t* arg1, int64_t* arg2)

{
    int64_t* arg_10 = arg2;
    int64_t* arg_8 = arg1;
    int64_t* r12 = arg1;
    int32_t var_58 = 0;
    __builtin_memset(arg2, 0, 0x18);
    int32_t rsi = 1;
    int32_t arg_20 = 1;
    int32_t var_58_1 = 1;
    sub_180006670(arg2, 0x1000);
    sub_18000aa90(arg2, r12[3]);
    uint16_t rbx = *(r12 + 0x1c);
    char arg_18 = (rbx >> 8);
    sub_180006510(arg2, &arg_18);
    arg_18 = rbx;
    sub_180006510(arg2, &arg_18);
    uint16_t rbx_1 = *(r12 + 0x1e);
    arg_18 = (rbx_1 >> 8);
    sub_180006510(arg2, &arg_18);
    arg_18 = rbx_1;
    sub_180006510(arg2, &arg_18);
    int64_t rax_2;
    int64_t rdx_5;
    rdx_5 = HIGHQ(0x6666666666666667 * (r12[1] - *r12));
    rax_2 = LOWQ(0x6666666666666667 * (r12[1] - *r12));
    int64_t rbx_3 = rdx_5 >> 4;
    uint16_t rbx_4 = rbx_3 + (rbx_3 >> 0x3f);
    arg_18 = (rbx_4 >> 8);
    sub_180006510(arg2, &arg_18);
    arg_18 = rbx_4;
    sub_180006510(arg2, &arg_18);
    int64_t r15 = *r12;
    int64_t rax_6;
    int64_t rdx_8;
    rdx_8 = HIGHQ(0x6666666666666667 * (r12[1] - r15));
    rax_6 = LOWQ(0x6666666666666667 * (r12[1] - r15));
    int64_t rdx_9 = rdx_8 >> 4;
    
    if (rdx_9 + (rdx_9 >> 0x3f) > 1)
    {
        int64_t rdx_18;
        
        do
        {
            uint64_t r13_1 = rsi * 5;
            char rax_10 = *(r15 + (r13_1 << 3));
            
            if (rax_10)
            {
                char* r14_1 = arg2[1];
                int64_t rcx_12 = arg2[2];
                
                if (r14_1 == rcx_12)
                {
                    int64_t rdx_11 = *arg2;
                    arg_18 = rdx_11;
                    void* rax_12 = r14_1 - rdx_11;
                    
                    if (rax_12 == 0x7fffffffffffffff)
                    {
                        sub_1800052a0();
                        /* no return */
                    }
                    
                    int64_t rcx_13 = rcx_12 - rdx_11;
                    uint64_t rdx_13 = rcx_13 >> 1;
                    uint64_t rbx_5;
                    char* rsi_1;
                    uint64_t rcx_14;
                    
                    if (rcx_13 <= 0x7fffffffffffffff - rdx_13)
                    {
                        uint64_t rax_14 = rdx_13 + rcx_13;
                        rbx_5 = rax_12 + 1;
                        
                        if (rax_14 >= rax_12 + 1)
                            rbx_5 = rax_14;
                        
                        if (rbx_5)
                        {
                            if (rbx_5 >= 0x1000)
                            {
                                rcx_14 = rbx_5 + 0x27;
                                
                                if (rcx_14 > rbx_5)
                                    goto label_18000a305;
                                
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
                        rcx_14 = -0x7fffffffffffffda;
                    label_18000a305:
                        int64_t rax_15 = sub_180016420(rcx_14);
                        
                        if (!rax_15)
                            trap(0xd);
                        
                        rsi_1 = (rax_15 + 0x27) & 0xffffffffffffffe0;
                        *(rsi_1 - 8) = rax_15;
                    }
                    void* r12_2 = r14_1 - arg_18;
                    *(rsi_1 + r12_2) = *(r15 + (r13_1 << 3));
                    int64_t r8_2 = arg2[1];
                    char* rdx_14 = *arg2;
                    int128_t* rcx_17 = rsi_1;
                    void* r8_3;
                    
                    if (r14_1 != r8_2)
                    {
                        memcpy(rcx_17, rdx_14, r14_1 - rdx_14);
                        rcx_17 = r12_2 + 1 + rsi_1;
                        r8_3 = arg2[1] - r14_1;
                        rdx_14 = r14_1;
                    }
                    else
                        r8_3 = r8_2 - rdx_14;
                    
                    memcpy(rcx_17, rdx_14, r8_3);
                    sub_180004fa0(arg2, rsi_1, rax_12 + 1, rbx_5);
                    r12 = arg_8;
                    rsi = arg_20;
                }
                else
                {
                    *r14_1 = rax_10;
                    arg2[1] += 1;
                }
                
                int32_t* r8_8 = *(r15 + (r13_1 << 3) + 8);
                sub_1800045a0(arg2, arg2[1], r8_8, *(r15 + (r13_1 << 3) + 0x10) - r8_8);
            }
            
            rsi += 1;
            arg_20 = rsi;
            r15 = *r12;
            int64_t rax_17;
            int64_t rdx_17;
            rdx_17 = HIGHQ(0x6666666666666667 * (r12[1] - r15));
            rax_17 = LOWQ(0x6666666666666667 * (r12[1] - r15));
            rdx_18 = rdx_17 >> 4;
        } while (rsi < rdx_18 + (rdx_18 >> 0x3f));
    }
    
    uint16_t rbx_6 = r12[4];
    arg_8 = (rbx_6 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = rbx_6;
    sub_180006510(arg2, &arg_8);
    uint16_t rbx_7 = *(r12 + 0x22);
    arg_8 = (rbx_7 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = rbx_7;
    sub_180006510(arg2, &arg_8);
    uint16_t rbx_8 = *(r12 + 0x24);
    arg_8 = (rbx_8 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = rbx_8;
    sub_180006510(arg2, &arg_8);
    int16_t rbx_11 = (r12[0xa] - r12[9]) >> 1;
    arg_8 = (rbx_11 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = rbx_11;
    sub_180006510(arg2, &arg_8);
    int64_t r14_2 = r12[0xa];
    
    for (int16_t* i = r12[9]; i != r14_2; i = &i[1])
    {
        uint16_t rbx_12 = *i;
        arg_8 = (rbx_12 >> 8);
        sub_180006510(arg2, &arg_8);
        arg_8 = rbx_12;
        sub_180006510(arg2, &arg_8);
    }
    
    int32_t* r8_9 = r12[0xc];
    sub_1800045a0(arg2, arg2[1], r8_9, r12[0xd] - r8_9);
    int16_t rbx_15 = (r12[0x13] - r12[0x12]) >> 5;
    arg_8 = (rbx_15 >> 8);
    sub_180006510(arg2, &arg_8);
    arg_8 = rbx_15;
    sub_180006510(arg2, &arg_8);
    int64_t r14_3 = r12[0x13];
    
    for (int16_t* i_1 = r12[0x12]; i_1 != r14_3; i_1 = &i_1[0x10])
    {
        uint16_t rbx_16 = *i_1;
        arg_8 = (rbx_16 >> 8);
        sub_180006510(arg2, &arg_8);
        arg_8 = rbx_16;
        sub_180006510(arg2, &arg_8);
        uint16_t rbx_17 = i_1[1];
        arg_8 = (rbx_17 >> 8);
        sub_180006510(arg2, &arg_8);
        arg_8 = rbx_17;
        sub_180006510(arg2, &arg_8);
        uint16_t rbx_18 = i_1[2];
        arg_8 = (rbx_18 >> 8);
        sub_180006510(arg2, &arg_8);
        arg_8 = rbx_18;
        sub_180006510(arg2, &arg_8);
        int32_t* r8_10 = *(i_1 + 8);
        sub_1800045a0(arg2, arg2[1], r8_10, *(i_1 + 0x10) - r8_10);
    }
    
    int32_t* r8_11 = r12[0xf];
    sub_1800045a0(arg2, arg2[1], r8_11, r12[0x10] - r8_11);
    return arg2;
}

