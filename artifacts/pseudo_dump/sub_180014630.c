
  void sub_180014630(int64_t* arg1, int64_t arg2, int64_t arg3, int512_t arg4 @ zmm2)

{
    if (!data_1800464e0 || !data_1800464e8 || !data_1800464f0 || !data_1800464f8 || !data_180046500
            || !data_180046508 || !data_1800463e8 || !data_1800463f0 || !data_1800463f8
            || !data_180046408 || !data_180046418 || !data_180046428 || !data_180046430
            || !data_180046520 || !data_180046528 || !(*(*arg1 + 0x100))(arg1, arg3))
        return;
    
    int64_t rax = (*(*arg1 + 0x320))(arg1, arg3, data_1800464f0);
    int32_t rdi_1 = rax;
    
    if (rax && rax - 3 > 1)
        return;
    
    int64_t r9_1 = *arg1;
    rax = (*(r9_1 + 0x2f8))(arg1, arg3, data_180046500, r9_1);
    
    if (!rax)
        return;
    
    data_180046508;
    char rax_3 = sub_18000e930(arg1, rax, arg4, data_180046520);
    int64_t r8_4 = *arg1;
    (*(r8_4 + 0xb8))(arg1, rax, r8_4);
    int64_t rdx_5 = *arg1;
    
    if ((*(rdx_5 + 0x720))(arg1, rdx_5) || !rax_3)
    {
        (*(*arg1 + 0x88))(arg1);
        return;
    }
    
    int64_t r9_3;
    rax = (*(*arg1 + 0x2f8))(arg1, arg3, data_1800464f8);
    
    if (!rax)
        return;
    
    data_180046430;
    int32_t r14_2;
    r14_2 = rdi_1 == 4;
    int64_t rax_6 = sub_18000e9f0(arg1, data_180046428, arg4, r9_3);
    
    if (!rax_6)
    {
    label_180014a08:
        (*(*arg1 + 0x88))(arg1);
        (*(*arg1 + 0xb8))(arg1, rax);
        return;
    }
    
    int64_t rdx_8 = *arg1;
    
    if ((*(rdx_8 + 0x720))(arg1, rdx_8))
        goto label_180014a08;
    
    data_1800463f0;
    int64_t rax_8 = sub_18000bbf0(arg1, data_1800463e8, arg4, rax_6);
    int64_t r8_8 = *arg1;
    (*(r8_8 + 0xb8))(arg1, rax_6, r8_8);
    
    if (!rax_8)
        goto label_180014a08;
    
    int64_t rdx_11 = *arg1;
    
    if ((*(rdx_11 + 0x720))(arg1, rdx_11))
        goto label_180014a08;
    
    data_180046418;
    int32_t var_28_1 = 0x7fff;
    sub_180001cd0(arg1, rax_8, arg4, rax);
    data_1800463f8;
    sub_180001cd0(arg1, rax_8, arg4, r14_2 + 3);
    data_180046408;
    sub_180001cd0(arg1, rax_8, arg4, 1);
    data_180046418;
    int32_t var_28_2 = 0x7fff;
    sub_180001cd0(arg1, rax_8, arg4, data_180046528);
    (*(*arg1 + 0xb8))(arg1, rax);
    
    if ((*(*arg1 + 0x720))(arg1))
    {
        sub_180002210(arg1, "team-mirror: buffer build", arg4);
        (*(*arg1 + 0xb8))(arg1, rax_8);
        return;
    }
    
    data_1800464e8;
    int64_t rax_14 = sub_18000bbf0(arg1, data_1800464e0, arg4, rax_8);
    int64_t r8_14 = *arg1;
    (*(r8_14 + 0xb8))(arg1, rax_8, r8_14);
    char rax_15;
    
    if (rax_14)
    {
        int64_t rdx_20 = *arg1;
        rax_15 = (*(rdx_20 + 0x720))(arg1, rdx_20);
    }
    
    if (!rax_14 || rax_15)
    {
        sub_180002210(arg1, "team-mirror: packet ctor", arg4);
        return;
    }
    
    data_180046320;
    sub_180001cd0(arg1, arg2, arg4, rax_14);
    
    if ((*(*arg1 + 0x720))(arg1))
        sub_180002210(arg1, "team-mirror: writeAndFlush", arg4);
    
    (*(*arg1 + 0xb8))(arg1, rax_14);
    char const* const rdx_23 = "LEAVE";
    
    if (rdi_1 != 4)
        rdx_23 = "JOIN";
    
    sub_1800023a0("team-mirror: synthesised %s for B (server method=%d)", rdx_23);
}

