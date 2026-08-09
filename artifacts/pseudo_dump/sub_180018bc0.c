
  int32_t** sub_180018bc0(int32_t** arg1, int32_t* arg2, int32_t arg3)

{
    int32_t* var_38 = arg2;
    int32_t rsi = 0;
    int32_t var_30 = 0;
    int32_t r13 = 0;
    sub_180018ff0(arg2, &var_38);
    int32_t r12 = *arg2;
    
    if (r12)
    {
        uint32_t r11_1 = arg2[6];
        int32_t r10_1 = 0;
        char* r15_1 = *(arg2 + 8);
        
        do
        {
            if (arg3 >= r11_1 && arg3 <= arg2[7])
            {
                int32_t rax_1 = r10_1;
                r13 = r10_1;
                
                if (!rsi)
                    rax_1 = rsi;
                
                rsi = rax_1;
            }
            
            uint64_t rcx_2 = *r15_1 & 0xf;
            r10_1 += 1;
            int64_t r9_1 = *(rcx_2 + 0x180038880);
            char rcx_3 = *(rcx_2 + 0x180038890);
            char* rax_3 = r15_1 - r9_1;
            int32_t r11_2 = *(rax_3 - 4);
            *(arg2 + 8) = rax_3;
            r11_1 = r11_2 >> rcx_3;
            arg2[6] = r11_1;
            uint64_t rcx_5 = *rax_3 & 0xf;
            int64_t r8 = *(rcx_5 + 0x180038880);
            char* rdx_3 = r15_1 - r8 - r9_1;
            uint32_t rax_5 = *(rdx_3 - 4) >> *(rcx_5 + 0x180038890);
            *(arg2 + 8) = rdx_3;
            arg2[7] = rax_5;
            uint64_t rcx_8 = *rdx_3 & 0xf;
            int32_t* r15_4 = r15_1 - *(rcx_8 + 0x180038880) - r8 - r9_1;
            uint32_t rax_8 = r15_4[-1] >> *(rcx_8 + 0x180038890);
            *(arg2 + 8) = r15_4;
            arg2[8] = rax_8;
            int32_t rax_9 = *r15_4;
            r15_1 = &r15_4[1];
            *(arg2 + 8) = r15_1;
            arg2[9] = rax_9;
        } while (r10_1 != r12);
    }
    
    var_38 = arg2;
    int32_t var_30_1 = rsi;
    sub_180018ff0(arg2, &var_38);
    arg1[3] = r13 + 1;
    int32_t var_2c;
    *(arg1 + 0x1c) = var_2c;
    *(arg1 + 0xc) = var_2c;
    *arg1 = arg2;
    arg1[1] = rsi;
    arg1[2] = arg2;
    return arg1;
}

