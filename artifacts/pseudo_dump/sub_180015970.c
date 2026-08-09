
  void sub_180015970(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, int512_t arg5 @ zmm2)

{
    if (!arg2 || !arg3)
        return;
    
    int64_t var_48;
    
    if (data_180046288)
    {
        var_48 = arg3;
        arg4 = sub_180015890(arg1, arg2, arg5, data_180046270, var_48);
    }
    
    if (data_180046398)
    {
        arg4 = data_180046390;
        
        if (arg4)
        {
            var_48 = arg3;
            arg4 = sub_180015890(arg1, arg2, arg5, arg4, var_48);
        }
    }
    
    data_180046318;
    int64_t rax_1 = sub_180001cd0(arg1, arg2, arg5, arg4);
    
    if (rax_1)
    {
        int64_t rdx_2 = *arg1;
        
        if (!(*(rdx_2 + 0x720))(arg1, rdx_2))
        {
            char const* const var_38;
            int64_t* i = &var_38;
            var_38 = "encoder";
            char const* const var_30 = "decoder";
            int64_t __saved_r15;
            
            do
            {
                int64_t r15_1 = *i;
                int64_t rax_4 = (*(*arg1 + 0x538))(arg1, r15_1);
                data_180046378;
                int64_t rax_5 = sub_180001cd0(arg1, rax_1, arg5, rax_4);
                int64_t r8_4 = *arg1;
                (*(r8_4 + 0xb8))(arg1, rax_4, r8_4);
                char rax_6;
                
                if (rax_5)
                {
                    int64_t rdx_6 = *arg1;
                    rax_6 = (*(rdx_6 + 0x720))(arg1, rdx_6);
                }
                
                if (!rax_5 || rax_6)
                    (*(*arg1 + 0x88))(arg1);
                else
                {
                    int64_t rax_8 = (*(*arg1 + 0xf8))(arg1, rax_5);
                    int64_t rax_9;
                    rax_9 =
                        sub_180012ff0(rax_8, "(Lnet/minecraft/network/ConnectionProtocol;)V", 0);
                    int64_t rdi_3;
                    
                    if (!rax_9)
                    {
                        rdi_3 = (*(*arg1 + 0x108))(arg1, rax_8, "setProtocol", 
                            "(Lnet/minecraft/network/ConnectionProtocol;)V", var_48);
                        
                        if ((*(*arg1 + 0x720))(arg1))
                            (*(*arg1 + 0x88))(arg1);
                    }
                    
                    if (rax_9 || rdi_3)
                    {
                        sub_180001d00(arg1, rax_5, arg5, arg3);
                        
                        if (!(*(*arg1 + 0x720))(arg1))
                            arg5 = sub_1800023a0("setProtocolState: called %s.setProtocol(PLAY)", 
                                r15_1);
                        else
                            (*(*arg1 + 0x88))(arg1);
                    }
                    
                    (*(*arg1 + 0xb8))(arg1, rax_8);
                    (*(*arg1 + 0xb8))(arg1, rax_5);
                }
                
                i = &i[1];
            } while (i != &__saved_r15);
            
❓            /* jump -> *(*arg1 + 0xb8) */
        }
    }
    
    (*(*arg1 + 0x88))(arg1);
}

