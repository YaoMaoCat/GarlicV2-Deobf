
  int64_t sub_1800079d0(int64_t* arg1, int128_t* arg2)

{
    int128_t var_48 = *arg2;
    uint32_t rbx = sub_180008120(arg1, &var_48);
    int64_t r9 = *arg1;
    int64_t rax_1;
    int64_t rdx_3;
    rdx_3 = HIGHQ(0x6666666666666667 * (arg1[1] - r9));
    rax_1 = LOWQ(0x6666666666666667 * (arg1[1] - r9));
    int64_t r10_1 = rdx_3 >> 4;
    int64_t i = r10_1 + (r10_1 >> 0x3f);
    
    if (i > 1)
    {
        int16_t rax_2 = 1;
        
        do
        {
            uint64_t rcx_3 = rax_2 * 5;
            
            if (*(r9 + (rcx_3 << 3)) == 7)
            {
                char* r8_1 = *(r9 + (rcx_3 << 3) + 8);
                
                if (*(r9 + (rcx_3 << 3) + 0x10) - r8_1 == 2 && (*r8_1 << 8 | r8_1[1]) == rbx)
                    return rax_2;
            }
            
            rax_2 += 1;
        } while (rax_2 < i);
    }
    
    int128_t var_28;
    __builtin_memset(&var_28, 0, 0x18);
    char arg_8 = (rbx >> 8);
    sub_180006510(&var_28, &arg_8);
    arg_8 = rbx;
    sub_180006510(&var_28, &arg_8);
    int64_t rcx_10 = *(&var_28 + 8);
    int64_t rax_4 = var_28;
    __builtin_memset(&var_28, 0, 0x18);
    var_48 = rax_4;
    *(&var_48 + 8) = rcx_10;
    int64_t var_18;
    int64_t var_38_1 = var_18;
    int64_t rdx_9;
    rdx_9 = 7;
    int16_t rax_5 = sub_180007f00(arg1, rdx_9, &var_48, 0);
    void* rcx_12 = var_28;
    
    if (rcx_12)
    {
        int64_t var_18_1;
        void* r8_3;
        
        if (var_18_1 - rcx_12 < 0x1000)
            r8_3 = rcx_12;
        else
        {
            r8_3 = *(rcx_12 - 8);
            
            if (rcx_12 - r8_3 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(r8_3);
    }
    
    return rax_5;
}

