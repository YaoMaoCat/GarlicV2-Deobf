
  int64_t sub_180001ac0(int64_t* arg1)

{
    int64_t result;
    
    if (arg1 && *arg1 == 0x4741524c49434155)
    {
        int64_t rax = 0x14650fb0739d0383;
        int64_t var_20_1 = 0x14650fb0739d0383;
        int64_t rcx = 0;
        int64_t var_18_1 = 0;
        
        while (true)
        {
            int64_t rdx_1 = rcx + 1;
            
            if (rdx_1 >= 0x19)
                break;
            
            int64_t rax_1 = rax ^ data_180030488[rcx];
            int64_t var_20_2 = rax_1;
            rax = rax_1 * 0x100000001b3;
            int64_t var_20_3 = rax;
            rcx = rdx_1;
            int64_t var_18_2 = rdx_1;
        }
        
        uint64_t r8_1 = 0;
        
        while (true)
        {
            int32_t var_28_1 = r8_1;
            
            if (r8_1 >= 8)
                break;
            
            int64_t rax_2 = rax ^ arg1[1] >> r8_1 << 3;
            int64_t var_20_4 = rax_2;
            rax = rax_2 * 0x100000001b3;
            int64_t var_20_5 = rax;
            r8_1 = r8_1 + 1;
        }
        
        int64_t rax_3 = rax ^ 0x4741524c49434155;
        int64_t var_20_6 = rax_3;
        result = rax_3 * 0x100000001b3;
        int64_t result_1 = result;
    }
    
    if (!arg1 || *arg1 != 0x4741524c49434155 || arg1[2] != result)
        result = 0;
    else
        result = 1;
    
    return result;
}

