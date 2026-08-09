
  uint64_t sub_180007d30(int64_t* arg1, int128_t* arg2, int128_t* arg3)

{
    int128_t var_58 = *arg2;
    uint16_t rax = sub_180008120(arg1, &var_58);
    var_58 = *arg3;
    uint16_t rax_1 = sub_180008120(arg1, &var_58);
    int64_t r9 = *arg1;
    int64_t rax_2;
    int64_t rdx_2;
    rdx_2 = HIGHQ(0x6666666666666667 * (arg1[1] - r9));
    rax_2 = LOWQ(0x6666666666666667 * (arg1[1] - r9));
    int64_t r10_1 = rdx_2 >> 4;
    int64_t i = r10_1 + (r10_1 >> 0x3f);
    
    if (i > 1)
    {
        int16_t r8 = 1;
        
        do
        {
            uint64_t rcx_5 = r8 * 5;
            
            if (*(r9 + (rcx_5 << 3)) == 0xc)
            {
                char* rax_4 = *(r9 + (rcx_5 << 3) + 8);
                
                if (*(r9 + (rcx_5 << 3) + 0x10) - rax_4 == 4 && (*rax_4 << 8 | rax_4[1]) == rax
                        && (rax_4[2] << 8 | rax_4[3]) == rax_1)
                    return r8;
            }
            
            r8 += 1;
        } while (r8 < i);
    }
    
    int128_t var_38;
    __builtin_memset(&var_38, 0, 0x18);
    char arg_8 = (rax >> 8);
    sub_180006510(&var_38, &arg_8);
    arg_8 = rax;
    sub_180006510(&var_38, &arg_8);
    arg_8 = (rax_1 >> 8);
    sub_180006510(&var_38, &arg_8);
    arg_8 = rax_1;
    sub_180006510(&var_38, &arg_8);
    int64_t rcx_14 = *(&var_38 + 8);
    int64_t rax_8 = var_38;
    __builtin_memset(&var_38, 0, 0x18);
    var_58 = rax_8;
    *(&var_58 + 8) = rcx_14;
    int64_t var_28;
    int64_t var_48_1 = var_28;
    int64_t rdx_9;
    rdx_9 = 0xc;
    int16_t rax_9 = sub_180007f00(arg1, rdx_9, &var_58, 0);
    void* rcx_16 = var_38;
    
    if (rcx_16)
    {
        int64_t var_28_1;
        void* r8_2;
        
        if (var_28_1 - rcx_16 < 0x1000)
            r8_2 = rcx_16;
        else
        {
            r8_2 = *(rcx_16 - 8);
            
            if (rcx_16 - r8_2 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(r8_2);
    }
    
    return rax_9;
}

