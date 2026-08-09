
  void sub_180013830(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2, int64_t arg4)

{
    if (!data_180046548 || !data_1800463e8 || !data_1800463f0)
        return;
    
    int64_t rdx = data_180046428;
    
    if (!rdx || !data_180046430 || !data_1800463f8 || !data_180046408 || !data_180046410
            || !data_180046400 || !data_180046440 || !data_180046448)
        return;
    
    int64_t rax_1 = sub_18000e9f0(arg1, rdx, arg3, arg4);
    char rax_2;
    
    if (rax_1)
    {
        int64_t rdx_1 = *arg1;
        rax_2 = (*(rdx_1 + 0x720))(arg1, rdx_1);
    }
    
    if (!rax_1 || rax_2)
❓        /* jump -> *(*arg1 + 0x88) */
    
    data_1800463f0;
    int64_t rax_3 = sub_18000bbf0(arg1, data_1800463e8, arg3, rax_1);
    int64_t r8_3 = *arg1;
    (*(r8_3 + 0xb8))(arg1, rax_1, r8_3);
    char rax_4;
    
    if (rax_3)
    {
        int64_t rdx_4 = *arg1;
        rax_4 = (*(rdx_4 + 0x720))(arg1, rdx_4);
    }
    
    if (!rax_3 || rax_4)
    {
        (*(*arg1 + 0x88))(arg1);
        return;
    }
    
    data_1800463f8;
    sub_180001cd0(arg1, rax_3, arg3, 8);
    data_180046408;
    sub_180001cd0(arg1, rax_3, arg3, 1);
    data_180046410;
    sub_180001cd0(arg1, rax_3, arg3, data_180046548);
    data_180046400;
    sub_180001cd0(arg1, rax_3, arg3, 0);
    
    if ((*(*arg1 + 0x720))(arg1))
    {
        (*(*arg1 + 0x88))(arg1);
        (*(*arg1 + 0xb8))(arg1, rax_3);
        return;
    }
    
    data_180046448;
    int64_t rax_9 = sub_18000bbf0(arg1, data_180046440, arg3, rax_3);
    int64_t r8_9 = *arg1;
    (*(r8_9 + 0xb8))(arg1, rax_3, r8_9);
    char rax_10;
    
    if (rax_9)
    {
        int64_t rdx_12 = *arg1;
        rax_10 = (*(rdx_12 + 0x720))(arg1, rdx_12);
    }
    
    if (!rax_9 || rax_10)
    {
        sub_180002210(arg1, "hide-A: ctor", arg3);
        return;
    }
    
    data_180046320;
    sub_180001cd0(arg1, arg2, arg3, rax_9);
    
    if ((*(*arg1 + 0x720))(arg1))
        sub_180002210(arg1, "hide-A: writeAndFlush", arg3);
    
    (*(*arg1 + 0xb8))(arg1, rax_9);
}

