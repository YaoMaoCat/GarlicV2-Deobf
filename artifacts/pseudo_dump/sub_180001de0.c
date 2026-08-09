
  int64_t sub_180001de0(int64_t* arg1, int64_t* arg2, int512_t arg3 @ zmm2)

{
    if (arg1 && arg2)
    {
        int64_t rax_1 = *arg2;
        int32_t arg_18 = 0;
        int64_t arg_20 = 0;
        
        if (!(*(rax_1 + 0x18))(arg2, &arg_18, &arg_20))
        {
            int32_t rax_3 = data_18004749c;
            data_18004749c = rax_3 + 1;
            char arg_8;
            uint64_t r13;
            
            if (rax_3 >= 3)
            {
                r13 = 0;
                arg_8 = 0;
            }
            else
            {
                r13 = 1;
                arg_8 = 1;
                arg3 = sub_1800023a0("GetMinecraftClassLoader: enumerating %d threads", arg_18);
            }
            
            int64_t result = 0;
            int32_t r12 = 0;
            
            if (arg_18 > 0)
            {
                int64_t r14;
                int64_t var_38_1 = r14;
                
                do
                {
                    int64_t rdx_2 = arg_20;
                    int64_t r9_1 = *arg2;
                    int128_t var_58;
                    __builtin_memset(&var_58, 0, 0x20);
                    int128_t var_48;
                    
                    if (!(*(r9_1 + 0x40))(arg2, *(rdx_2 + (r12 << 3)), &var_58, r9_1, var_58, 
                        var_48))
                    {
                        int64_t rbp_1 = *(&var_48 + 8);
                        r14 = rbp_1;
                        
                        if (r13)
                        {
                            arg3 = sub_1800023a0("  thread[%d] name='%s' has_loader=%d", r12);
                            rbp_1 = *(&var_48 + 8);
                        }
                        
                        char* rdi_1 = var_58;
                        
                        if (rdi_1)
                        {
                            int32_t rax_8;
                            
                            if (r14)
                                rax_8 = strcmp(rdi_1, "Render thread");
                            
                            if (r14 && !rax_8)
                            {
                            label_180002000:
                                result = (*(*arg1 + 0xa8))(arg1, rbp_1);
                            label_180002003:
                                rdi_1 = var_58;
                            label_180002008:
                                
                                if (rdi_1)
                                    (*(*arg2 + 0x170))(arg2, rdi_1);
                            }
                            else if (rdi_1)
                            {
                                if (!r14)
                                    goto label_180002008;
                                
                                int64_t rdi_3;
                                
                                if (!rbp_1)
                                    rdi_3 = 0;
                                else
                                {
                                    int64_t rax_10 = (*(*arg1 + 0xf8))(arg1, rbp_1);
                                    int64_t rax_11 = (*(*arg1 + 0x108))(arg1, rax_10, "loadClass", 
                                        "(Ljava/lang/String;)Ljava/lang/Class;");
                                    int64_t r8_5 = *arg1;
                                    
                                    if (rax_11)
                                    {
                                        int64_t rax_21 = (*(r8_5 + 0x538))(arg1, 
                                            "net.minecraft.network.Connection", r8_5);
                                        int64_t rax_22 = sub_180001cd0(arg1, rbp_1, arg3, rax_21);
                                        int64_t rdx_14 = *arg1;
                                        rdi_3 = rax_22;
                                        
                                        if ((*(rdx_14 + 0x720))(arg1, rdx_14))
                                        {
                                            int64_t rdx_15 = *arg1;
                                            (*(rdx_15 + 0x88))(arg1, rdx_15);
                                            rdi_3 = 0;
                                        }
                                        
                                        (*(*arg1 + 0xb8))(arg1, rax_21);
                                        (*(*arg1 + 0xb8))(arg1, rax_10);
                                        r13 = arg_8;
                                    }
                                    else
                                    {
                                        (*(r8_5 + 0x88))(arg1);
                                        int64_t r8_6 = *arg1;
                                        (*(r8_6 + 0xb8))(arg1, rax_10, r8_6);
                                        rdi_3 = 0;
                                    }
                                }
                                
                                char rax_13;
                                int64_t rdx_8;
                                rax_13 = (*(*arg1 + 0x720))(arg1);
                                
                                if (rax_13)
                                    rdx_8 = (*(*arg1 + 0x88))(arg1);
                                
                                if (!rdi_3)
                                    goto label_180002003;
                                
                                if (r13)
                                    arg3 = sub_1800023a0("     -> can load MC.Connection, PICKED", 
                                        rdx_8);
                                
                                (*(*arg1 + 0xb8))(arg1, rdi_3);
                                rbp_1 = *(&var_48 + 8);
                                goto label_180002000;
                            }
                        }
                        
                        if (result)
                            break;
                    }
                    
                    r12 += 1;
                } while (r12 < arg_18);
            }
            
            (*(*arg2 + 0x170))(arg2, arg_20);
            return result;
        }
    }
    
    return 0;
}

