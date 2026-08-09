
  int64_t sub_1800154b0(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, int512_t arg5 @ zmm2)

{
    int64_t rdx = data_1800463d0;
    
    if (!rdx || !data_1800463d8 || !data_1800463e0 || !data_1800463e8 || !data_1800463f0
            || !data_1800463f8 || !data_180046400 || !data_180046408 || !data_180046410
            || !data_180046418 || !data_180046420 || !data_180046428 || !data_180046430
            || !data_180046440 || !data_180046448)
        /* tailcall */
        return sub_1800023a0("self-info: missing refs, skipping push", rdx);
    
    int64_t rax = sub_18000e9f0(arg1, rdx, arg5, arg4);
    
    if (rax)
    {
        int64_t rdx_1 = *arg1;
        char rax_1;
        int64_t r9;
        rax_1 = (*(rdx_1 + 0x720))(arg1, rdx_1);
        
        if (!rax_1)
        {
            data_1800463e0;
            int64_t rax_2 = sub_180001cd0(arg1, rax, arg5, r9);
            int64_t r8_2 = *arg1;
            (*(r8_2 + 0xb8))(arg1, rax, r8_2);
            
            if (rax_2)
            {
                int64_t rdx_4 = *arg1;
                char rax_3;
                int64_t r9_1;
                rax_3 = (*(rdx_4 + 0x720))(arg1, rdx_4);
                
                if (!rax_3)
                {
                    data_180046430;
                    int64_t rax_4 = sub_18000e9f0(arg1, data_180046428, arg5, r9_1);
                    int64_t rax_11;
                    int64_t rdx_19;
                    
                    if (!rax_4)
                    {
                    label_18001581d:
                        (*(*arg1 + 0x88))(arg1);
                        rax_11 = *arg1;
                        rdx_19 = rax_2;
                    }
                    else
                    {
                        int64_t rdx_6 = *arg1;
                        
                        if ((*(rdx_6 + 0x720))(arg1, rdx_6))
                            goto label_18001581d;
                        
                        data_1800463f0;
                        int64_t rax_6 = sub_18000bbf0(arg1, data_1800463e8, arg5, rax_4);
                        int64_t r8_5 = *arg1;
                        (*(r8_5 + 0xb8))(arg1, rax_4, r8_5);
                        
                        if (!rax_6)
                            goto label_18001581d;
                        
                        int64_t rdx_9 = *arg1;
                        
                        if ((*(rdx_9 + 0x720))(arg1, rdx_9))
                            goto label_18001581d;
                        
                        data_1800463f8;
                        sub_180001cd0(arg1, rax_6, arg5, 0x1d);
                        data_1800463f8;
                        sub_180001cd0(arg1, rax_6, arg5, 1);
                        data_180046410;
                        sub_180001cd0(arg1, rax_6, arg5, arg2);
                        data_180046418;
                        int32_t var_28_1 = 0x10;
                        sub_180001cd0(arg1, rax_6, arg5, arg3);
                        data_180046420;
                        sub_180001d00(arg1, rax_6, arg5, rax_2);
                        data_180046408;
                        sub_180001cd0(arg1, rax_6, arg5, 0);
                        data_180046400;
                        sub_180001cd0(arg1, rax_6, arg5, 1);
                        data_180046408;
                        sub_180001cd0(arg1, rax_6, arg5, 0);
                        (*(*arg1 + 0xb8))(arg1, rax_2);
                        
                        if (!(*(*arg1 + 0x720))(arg1))
                        {
                            data_180046448;
                            int64_t rax_13 = sub_18000bbf0(arg1, data_180046440, arg5, rax_6);
                            int64_t r8_15 = *arg1;
                            (*(r8_15 + 0xb8))(arg1, rax_6, r8_15);
                            
                            if (rax_13)
                            {
                                int64_t rdx_22 = *arg1;
                                
                                if (!(*(rdx_22 + 0x720))(arg1, rdx_22))
                                {
                                    sub_180016110(arg1, rax_13, arg5);
                                    return sub_1800023a0(
                                        "self-info: pushed B's own player-info to B "
                                    "(ADD_PLAYER+LISTED+GAME_MODE+LATENCY, A's skin)", 
                                        (*(*arg1 + 0xb8))(arg1, rax_13));
                                }
                            }
                            
                            return sub_180002210(arg1, "self-info: packet ctor", arg5);
                        }
                        
                        sub_180002210(arg1, "self-info: buffer build", arg5);
                        rax_11 = *arg1;
                        rdx_19 = rax_6;
                    }
                    
                    return (*(rax_11 + 0xb8))(arg1, rdx_19);
                }
            }
            
            return sub_1800023a0("self-info: no profile props", (*(*arg1 + 0x88))(arg1));
        }
    }
    
    /* tailcall */
    return sub_1800023a0("self-info: no Minecraft", (*(*arg1 + 0x88))(arg1));
}

