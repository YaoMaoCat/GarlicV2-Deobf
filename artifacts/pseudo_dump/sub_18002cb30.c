
  int64_t sub_18002cb30(int64_t arg1 @ xcr0)

{
    int32_t r8 = 0;
    data_180047ffc = 0;
    int32_t temp0;
    int32_t temp1;
    int32_t temp2;
    int32_t temp3;
    temp0 = __cpuid(1, 0);
    int32_t var_10 = temp2;
    int32_t var_18 = temp0;
    int32_t var_14 = temp1;
    int32_t var_c = temp3;
    
    if ((temp2 & 0x18001000) == 0x18001000)
    {
        int32_t temp0_1;
        char temp1_1;
        temp0_1 = _xgetbv(0, arg1);
        
        if (((temp0_1 << 0x20 | temp1_1) & 6) != 6)
            r8 = data_180047ffc;
        else
        {
            r8 = 1;
            data_180047ffc = 1;
        }
    }
    
    if (r8 & 1)
    {
        int32_t temp0_2;
        int32_t temp1_2;
        int32_t temp2_1;
        int32_t temp3_1;
        temp0_2 = __cpuid(0, 0);
        
        if (temp0_2 >= 7)
        {
            int32_t temp0_3;
            char temp1_3;
            int32_t temp2_2;
            int32_t temp3_2;
            temp0_3 = __cpuid(7, 0);
            
            if (temp1_3 & 0x20)
            {
                data_180047ffc = 3;
                data_180047ff8 = 3;
                return 0;
            }
        }
    }
    
    data_180047ff8 = r8;
    return 0;
}

