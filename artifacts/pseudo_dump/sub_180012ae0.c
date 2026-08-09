
  int64_t sub_180012ae0(int64_t* arg1)

{
    void var_58;
    int64_t result = __security_cookie ^ &var_58;
    int64_t result_1 = result;
    
    if (!data_180046560 || !data_180046520)
    {
        int64_t rdx_1 = data_1800463d0;
        
        if (rdx_1 && data_1800463d8 && data_180046588)
        {
            int64_t entry_r9;
            int512_t entry_zmm2;
            int64_t rax_1 = sub_18000e9f0(arg1, rdx_1, entry_zmm2, entry_r9);
            char rax_2;
            int64_t r9;
            
            if (rax_1)
            {
                int64_t rdx_2 = *arg1;
                rax_2 = (*(rdx_2 + 0x720))(arg1, rdx_2);
            }
            
            if (!rax_1 || rax_2)
                result = (*(*arg1 + 0x88))(arg1);
            else
            {
                data_180046588;
                int64_t rax_3 = sub_180001cd0(arg1, rax_1, entry_zmm2, r9);
                int64_t r8_3 = *arg1;
                (*(r8_3 + 0xb8))(arg1, rax_1, r8_3);
                char rax_4;
                int64_t r9_1;
                
                if (rax_3)
                {
                    int64_t rdx_5 = *arg1;
                    rax_4 = (*(rdx_5 + 0x720))(arg1, rdx_5);
                }
                
                if (!rax_3 || rax_4)
                    result = (*(*arg1 + 0x88))(arg1);
                else
                {
                    if (data_180046560 == rax_4 && data_180046580)
                    {
                        int64_t rax_5 = sub_180001cd0(arg1, rax_3, entry_zmm2, r9_1);
                        char rax_6;
                        int64_t r9_2;
                        
                        if (rax_5)
                        {
                            int64_t rdx_7 = *arg1;
                            rax_6 = (*(rdx_7 + 0x720))(arg1, rdx_7);
                        }
                        
                        if (!rax_5 || rax_6)
                        {
                            char rax_12;
                            rax_12 = (*(*arg1 + 0x720))(arg1);
                            
                            if (rax_12)
                                r9_1 = (*(*arg1 + 0x88))(arg1);
                        }
                        else
                        {
                            int128_t var_38;
                            
                            if (sub_180015e20(arg1, rax_5, &var_38, r9_2, entry_zmm2))
                            {
                                int64_t rax_9;
                                int64_t rdx_10;
                                rax_9 = (*(*arg1 + 0xa8))(arg1, rax_5);
                                int128_t zmm0 = var_38;
                                data_180046548 = rax_9;
                                data_180046560 = 1;
                                data_180046550 = zmm0;
                                entry_zmm2 = sub_1800023a0(
                                    "mirror: cached A's real UUID for tab-list mirroring", rdx_10);
                            }
                            
                            r9_1 = (*(*arg1 + 0xb8))(arg1, rax_5);
                        }
                    }
                    
                    if (!data_180046520 && data_180046510 && data_180046518)
                    {
                        int64_t rax_14 = sub_180001cd0(arg1, rax_3, entry_zmm2, r9_1);
                        char rax_15;
                        int64_t r9_3;
                        
                        if (rax_14)
                        {
                            int64_t rdx_13 = *arg1;
                            rax_15 = (*(rdx_13 + 0x720))(arg1, rdx_13);
                        }
                        
                        if (!rax_14 || rax_15)
                        {
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                        }
                        else
                        {
                            data_180046518;
                            int64_t rax_16 = sub_180001cd0(arg1, rax_14, entry_zmm2, r9_3);
                            char rax_17;
                            
                            if (rax_16)
                            {
                                int64_t rdx_15 = *arg1;
                                rax_17 = (*(rdx_15 + 0x720))(arg1, rdx_15);
                            }
                            
                            if (!rax_16 || rax_17)
                            {
                                if ((*(*arg1 + 0x720))(arg1))
                                    (*(*arg1 + 0x88))(arg1);
                                
                                (*(*arg1 + 0xb8))(arg1, rax_14);
                            }
                            else
                            {
                                int64_t r8_8 = *arg1;
                                data_180046520 = (*(r8_8 + 0xa8))(arg1, rax_16, r8_8);
                                void* rax_20 = (*(*arg1 + 0x548))(arg1, rax_16, 0);
                                void* const rdx_18 = &data_1800321d8;
                                
                                if (rax_20)
                                    rdx_18 = rax_20;
                                
                                sub_1800023a0("team-mirror: cached A's name = '%s'", rdx_18);
                                
                                if (rax_20)
                                {
                                    int64_t r9_4 = *arg1;
                                    (*(r9_4 + 0x550))(arg1, rax_16, rax_20, r9_4);
                                }
                                
                                (*(*arg1 + 0xb8))(arg1, rax_16);
                                (*(*arg1 + 0xb8))(arg1, rax_14);
                            }
                        }
                    }
                    
                    result = (*(*arg1 + 0xb8))(arg1, rax_3);
                }
            }
        }
    }
    
    __security_check_cookie(result_1 ^ &var_58);
    return result;
}

