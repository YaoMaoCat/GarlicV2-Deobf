
  int64_t sub_180016d00(int64_t arg1 @ xcr0)

{
    int32_t temp0;
    int32_t temp1;
    int32_t temp2;
    int32_t temp3;
    temp0 = __cpuid(0, 0);
    int32_t temp0_1;
    int32_t temp1_1;
    int32_t temp2_1;
    int32_t temp3_1;
    temp0_1 = __cpuid(1, 0);
    int32_t rax_2;
    uint64_t rax_3;
    
    if (!((temp3 ^ 0x49656e69) | (temp2 ^ 0x6c65746e) | (temp1 ^ 0x756e6547)))
    {
        rax_2 = temp0_1 & 0xfff3ff0;
        data_180046860 = 0x8000;
        data_180046868 = -1;
        
        if (rax_2 != 0x106c0 && rax_2 != 0x20660 && rax_2 != 0x20670)
            rax_3 = rax_2 - 0x30650;
    }
    
    int32_t r8_1;
    
    if ((temp3 ^ 0x49656e69) | (temp2 ^ 0x6c65746e) | (temp1 ^ 0x756e6547) || (rax_2 != 0x106c0
            && rax_2 != 0x20660 && rax_2 != 0x20670
            && (rax_3 > 0x20 || !TEST_BITQ(0x100010001, rax_3))))
        r8_1 = data_18004756c;
    else
    {
        r8_1 = data_18004756c | 1;
        data_18004756c = r8_1;
    }
    
    int32_t r10 = 0;
    char r14 = 0;
    char rsi = 0;
    int32_t rbp;
    int32_t r9;
    
    if (temp0 < 7)
    {
        r9 = 0;
        rbp = 0;
    }
    else
    {
        int32_t temp0_2;
        int32_t temp1_2;
        int32_t temp2_2;
        int32_t temp3_2;
        temp0_2 = __cpuid(7, 0);
        rbp = temp3_2;
        r9 = temp1_2;
        
        if (TEST_BITD(temp1_2, 9))
            data_18004756c = r8_1 | 2;
        
        if (temp0_2 >= 1)
        {
            int32_t temp0_3;
            int32_t temp1_3;
            int32_t temp2_3;
            int32_t temp3_3;
            temp0_3 = __cpuid(7, 1);
            r10 = temp3_3;
        }
        
        if (temp0 >= 0x24)
        {
            int32_t temp0_4;
            char temp1_4;
            int32_t temp2_4;
            int32_t temp3_4;
            temp0_4 = __cpuid(0x24, 0);
            r14 = temp1_4;
        }
        
        if (temp0 >= 0x29)
        {
            int32_t temp0_5;
            char temp1_5;
            int32_t temp2_5;
            int32_t temp3_5;
            temp0_5 = __cpuid(0x29, 0);
            rsi = temp1_5;
        }
    }
    
    int64_t rax_9 = data_180046870 & 0xfffffffffffffffe;
    data_180046858 = 1;
    data_18004685c = 2;
    data_180046870 = rax_9;
    
    if (TEST_BITD(temp2_1, 0x14))
    {
        data_180046858 = 2;
        data_180046870 = rax_9 & 0xffffffffffffffef;
        data_18004685c = 6;
    }
    
    if (TEST_BITD(temp2_1, 0x1b))
    {
        int32_t temp0_6;
        int32_t temp1_6;
        temp0_6 = _xgetbv(0, arg1);
        uint64_t rdx_11 = temp0_6 << 0x20 | temp1_6;
        
        if (TEST_BITD(temp2_1, 0x1c) && (rdx_11 & 6) == 6)
        {
            int32_t rax_14 = data_18004685c | 8;
            data_180046858 = 3;
            data_18004685c = rax_14;
            int64_t rax_17;
            
            if (!(r9 & 0x20))
                rax_17 = data_180046870;
            else
            {
                data_180046858 = 5;
                data_18004685c = rax_14 | 0x20;
                rax_17 = data_180046870 & 0xfffffffffffffffd;
                data_180046870 = rax_17;
                
                if ((r9 & 0xd0030000) == 0xd0030000)
                {
                    if ((rdx_11 & 0xe0) != 0xe0)
                        rax_17 = data_180046870;
                    else
                    {
                        int64_t rax_19 = data_180046870;
                        data_18004685c |= 0x40;
                        rax_17 = rax_19 & 0xffffffffffffffdb;
                        data_180046858 = 6;
                        data_180046870 = rax_17;
                    }
                }
            }
            
            if (TEST_BITD(rbp, 0x17))
                data_180046870 = rax_17 & 0xfffffffffeffffff;
            
            if (TEST_BITD(r10, 0x13) && (rdx_11 & 0xe0) == 0xe0)
            {
                int64_t rcx_8 = data_180046870 & 0xfffffffffeffffd0;
                uint32_t rax_22 = r14;
                data_180047570 = rax_22;
                data_180046870 = rcx_8;
                
                if (rax_22 > 1)
                    data_180046870 = rcx_8 & 0xffffffffffffffbf;
            }
        }
        
        if (TEST_BITD(r10, 0x15) && rsi & 1 && TEST_BITQ(rdx_11, 0x13))
            data_180046870 &= 0xffffffffffffff7f;
    }
    
    return 0;
}

