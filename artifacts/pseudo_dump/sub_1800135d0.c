
  int64_t sub_1800135d0(int64_t* arg1, int64_t arg2, int64_t arg3, int512_t arg4 @ zmm1, int512_t arg5 @ zmm2)

{
    if (data_180046608 && data_180046610 && data_180046618 && data_180046620 && data_180046628)
    {
        char rax;
        int64_t r9_1;
        rax = (*(*arg1 + 0x100))(arg1, arg3);
        
        if (rax)
        {
            data_180046610;
            int64_t rax_2 = sub_180001cd0(arg1, arg3, arg5, r9_1);
            int64_t rdx_2 = *arg1;
            char rax_3;
            int64_t r9_2;
            rax_3 = (*(rdx_2 + 0x720))(arg1, rdx_2);
            
            if (rax_3 || !rax_2)
            {
                sub_180002210(arg1, "bundle.subPackets", arg5);
                int64_t rax_19;
                rax_19 = 1;
                return rax_19;
            }
            
            data_180046618;
            int64_t rax_4 = sub_180001cd0(arg1, rax_2, arg5, r9_2);
            (*(*arg1 + 0xb8))(arg1, rax_2);
            char rax_7;
            int64_t r9_3;
            rax_7 = (*(*arg1 + 0x720))(arg1);
            
            if (rax_7 || !rax_4)
            {
                sub_180002210(arg1, "bundle.iterator", arg5);
                int64_t rax_18;
                rax_18 = 1;
                return rax_18;
            }
            
            data_180046620;
            int32_t rbp = 0;
            int32_t rsi = 0;
            char i_1 = sub_18000e930(arg1, rax_4, arg5, r9_3);
            int64_t rdx_6 = *arg1;
            char i = i_1;
            char rax_8;
            int64_t r9_4;
            rax_8 = (*(rdx_6 + 0x720))(arg1, rdx_6);
            char const* const rdx_13;
            
            if (rax_8)
            {
            label_180013785:
                rdx_13 = "bundle.iter.hasNext";
            label_18001378f:
                sub_180002210(arg1, rdx_13, arg5);
            }
            else
            {
                while (i)
                {
                    data_180046628;
                    int64_t rax_9 = sub_180001cd0(arg1, rax_4, arg5, r9_4);
                    int64_t rdx_8 = *arg1;
                    char rax_10;
                    int64_t r9_5;
                    rax_10 = (*(rdx_8 + 0x720))(arg1, rdx_8);
                    
                    if (rax_10)
                    {
                        rdx_13 = "bundle.iter.next";
                        goto label_18001378f;
                    }
                    
                    if (rax_9)
                    {
                        if (!sub_1800135d0(arg1, arg2, rax_9))
                            arg4 = sub_180015f80(arg1, arg2, rax_9, arg4, arg5);
                        
                        r9_5 = (*(*arg1 + 0xb8))(arg1, rax_9);
                        rbp += 1;
                    }
                    else
                        rsi += 1;
                    
                    data_180046620;
                    i = sub_18000e930(arg1, rax_4, arg5, r9_5);
                    char rax_15;
                    rax_15 = (*(*arg1 + 0x720))(arg1);
                    
                    if (rax_15)
                        goto label_180013785;
                }
            }
            (*(*arg1 + 0xb8))(arg1, rax_4);
            uint64_t rdx_15 = rbp;
            
            if (rsi <= 0)
                sub_1800023a0("bundle: forwarded=%d sub-packets", rdx_15);
            else
                sub_1800023a0("bundle: forwarded=%d, null-subs=%d (skipped)", rdx_15);
            
            int64_t rax_17;
            rax_17 = 1;
            return rax_17;
        }
    }
    
    return 0;
}

