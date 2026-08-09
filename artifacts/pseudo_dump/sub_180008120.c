
  int64_t sub_180008120(int64_t* arg1, int128_t* arg2)

{
    int128_t var_58 = *arg2;
    int16_t rax = sub_1800083b0(arg1, &var_58);
    
    if (rax)
        return rax;
    
    int128_t var_38;
    __builtin_memset(&var_38, 0, 0x18);
    int128_t* rbx_1 = *(arg2 + 8);
    sub_180006670(&var_38, rbx_1 + 2);
    char arg_10 = (rbx_1 >> 8);
    sub_180006510(&var_38, &arg_10);
    arg_10 = rbx_1;
    sub_180006510(&var_38, &arg_10);
    sub_1800045a0(&var_38, *(&var_38 + 8), *arg2, rbx_1);
    int64_t rcx_4 = *(&var_38 + 8);
    int64_t rax_2 = var_38;
    __builtin_memset(&var_38, 0, 0x18);
    var_58 = rax_2;
    *(&var_58 + 8) = rcx_4;
    int64_t var_28;
    int64_t var_48_1 = var_28;
    int64_t rdx_5;
    rdx_5 = 1;
    int16_t rax_3 = sub_180007f00(arg1, rdx_5, &var_58, 0);
    void* rcx_6 = var_38;
    
    if (rcx_6)
    {
        int64_t var_28_1;
        void* r8_3;
        
        if (var_28_1 - rcx_6 < 0x1000)
            r8_3 = rcx_6;
        else
        {
            r8_3 = *(rcx_6 - 8);
            
            if (rcx_6 - r8_3 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(r8_3);
    }
    
    return rax_3;
}

