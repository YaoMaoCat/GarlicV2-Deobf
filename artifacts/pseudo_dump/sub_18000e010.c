
  int64_t sub_18000e010(int64_t* arg1)

{
    if (arg1)
    {
        int64_t rdx_1 = data_1800463d0;
        char const* const rcx_18;
        
        if (!rdx_1 || !data_1800463d8 || !data_1800466e8 || !data_1800466f8 || !data_180046340
                || !data_180046318)
            rcx_18 = "mid-session: refs missing, cannot capture live connection";
        else
        {
            int64_t entry_r9;
            int512_t entry_zmm2;
            int64_t rax_1 = sub_18000e9f0(arg1, rdx_1, entry_zmm2, entry_r9);
            
            if (!rax_1)
            {
            label_18000e28d:
                (*(*arg1 + 0x88))(arg1);
                int64_t rax_21;
                rax_21 = 0;
                return rax_21;
            }
            
            int64_t rdx_2 = *arg1;
            char rax_2;
            int64_t r9;
            rax_2 = (*(rdx_2 + 0x720))(arg1, rdx_2);
            
            if (rax_2)
                goto label_18000e28d;
            
            data_1800466e8;
            int64_t rax_3 = sub_180001cd0(arg1, rax_1, entry_zmm2, r9);
            int64_t r8_3 = *arg1;
            (*(r8_3 + 0xb8))(arg1, rax_1, r8_3);
            
            if (!rax_3)
                goto label_18000e28d;
            
            int64_t rdx_5 = *arg1;
            char rax_4;
            int64_t r9_1;
            rax_4 = (*(rdx_5 + 0x720))(arg1, rdx_5);
            
            if (rax_4)
                goto label_18000e28d;
            
            data_1800466f8;
            int64_t rax_5 = sub_180001cd0(arg1, rax_3, entry_zmm2, r9_1);
            int64_t r8_5 = *arg1;
            (*(r8_5 + 0xb8))(arg1, rax_3, r8_5);
            
            if (!rax_5)
                goto label_18000e28d;
            
            int64_t rdx_8 = *arg1;
            
            if ((*(rdx_8 + 0x720))(arg1, rdx_8))
                goto label_18000e28d;
            
            void* arg_8 = &data_180046630;
            
            if (sub_180017bf0(&data_180046630))
            {
                std::_Throw_Cpp_error(5);
                /* no return */
            }
            
            if (data_18004667c == 0x7fffffff)
            {
                data_18004667c = 0x7ffffffe;
                std::_Throw_Cpp_error(6);
                /* no return */
            }
            
            int64_t rdx_9 = data_180046680;
            
            if (rdx_9)
                (*(*arg1 + 0xb0))(arg1, rdx_9);
            
            int64_t rax_10 = (*(*arg1 + 0xa8))(arg1, rax_5);
            data_180046680 = rax_10;
            int512_t zmm2 = sub_1800023a0("BServer: target A connection = %p", rax_10);
            sub_180017c80(&data_180046630);
            int64_t rax_12 = (*(*arg1 + 0x2f8))(arg1, rax_5, data_180046340);
            int64_t r8_7 = *arg1;
            (*(r8_7 + 0xb8))(arg1, rax_5, r8_7);
            char rax_13;
            int64_t r9_2;
            
            if (rax_12)
            {
                int64_t rdx_14 = *arg1;
                rax_13 = (*(rdx_14 + 0x720))(arg1, rdx_14);
            }
            
            if (!rax_12 || rax_13)
            {
                rdx_1 = (*(*arg1 + 0x88))(arg1);
                rcx_18 = "mid-session: connection.channel null";
            }
            else
            {
                data_180046318;
                int64_t rax_14 = sub_180001cd0(arg1, rax_12, zmm2, r9_2);
                int64_t r8_9 = *arg1;
                (*(r8_9 + 0xb8))(arg1, rax_12, r8_9);
                
                if (rax_14)
                {
                    int64_t rdx_17 = *arg1;
                    
                    if (!(*(rdx_17 + 0x720))(arg1, rdx_17))
                    {
                        sub_18000beb0(arg1, rax_14, zmm2);
                        int64_t rdx_20 = (*(*arg1 + 0xb8))(arg1, rax_14);
                        data_1800466e5 = 1;
                        sub_1800023a0(
                            "mid-session: captured A's live Connection + attached relay (A already "
                        "in-game)", 
                            rdx_20);
                        int64_t rax_17;
                        rax_17 = 1;
                        return rax_17;
                    }
                }
                
                rdx_1 = (*(*arg1 + 0x88))(arg1);
                rcx_18 = "mid-session: channel.pipeline() null";
            }
        }
        
        sub_1800023a0(rcx_18, rdx_1);
    }
    
    int64_t rax;
    rax = 0;
    return rax;
}

