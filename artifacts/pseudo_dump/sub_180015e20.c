
  int64_t sub_180015e20(int64_t* arg1, int64_t arg2, char* arg3, int64_t arg4, int512_t arg5 @ zmm2)

{
    if (!arg2 || !data_180046590 || !data_180046598)
    {
        int64_t result;
        result = 0;
        return result;
    }
    
    int64_t rax = sub_18000e9c0(arg1, arg2, arg5, arg4);
    int64_t rdx = *arg1;
    char rax_1;
    int64_t r9;
    rax_1 = (*(rdx + 0x720))(arg1, rdx);
    int64_t* rcx_1 = arg1;
    int64_t rax_2;
    
    if (!rax_1)
    {
        data_180046598;
        int64_t rax_4 = sub_18000e9c0(rcx_1, arg2, arg5, r9);
        int64_t rdx_2 = *arg1;
        
        if (!(*(rdx_2 + 0x720))(arg1, rdx_2))
        {
            arg3[7] = rax;
            *arg3 = rax >> 0x38;
            arg3[1] = rax >> 0x30;
            arg3[2] = rax >> 0x28;
            arg3[3] = rax >> 0x20;
            arg3[4] = rax >> 0x18;
            arg3[5] = rax >> 0x10;
            arg3[6] = rax >> 8;
            arg3[8] = rax_4 >> 0x38;
            arg3[9] = rax_4 >> 0x30;
            arg3[0xa] = rax_4 >> 0x28;
            arg3[0xb] = rax_4 >> 0x20;
            arg3[0xc] = rax_4 >> 0x18;
            arg3[0xd] = rax_4 >> 0x10;
            arg3[0xe] = rax_4 >> 8;
            arg3[0xf] = rax_4;
            return 1;
        }
        
        rax_2 = *arg1;
        rcx_1 = arg1;
    }
    else
        rax_2 = *arg1;
    
    (*(rax_2 + 0x88))(rcx_1);
    return 0;
}

