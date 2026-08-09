
  int64_t sub_180013ac0(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, int512_t arg5 @ zmm2)

{
    int64_t rax = sub_1800020f0(arg1, arg2, arg3, arg5);
    
    if (rax)
        return rax;
    
    int64_t* rcx = data_180047468;
    int32_t var_48 = 0;
    int64_t var_40 = 0;
    int32_t rax_2 = (*(*rcx + 0x268))(rcx, &var_48, &var_40);
    int64_t rbp_1 = 0;
    
    if (!rax_2)
    {
        int32_t rax_3 = var_48;
        int32_t rbx_1 = 0;
        
        if (rax_3 > 0)
        {
            do
            {
                int64_t* rcx_1 = data_180047468;
                int64_t rdx_1 = var_40;
                char* var_38 = nullptr;
                int64_t r14_1 = rbx_1;
                
                if (!(*(*rcx_1 + 0x178))(rcx_1, *(rdx_1 + (r14_1 << 3)), &var_38, 0))
                {
                    char* rdi_1 = var_38;
                    
                    if (rdi_1)
                    {
                        if (!strcmp(rdi_1, arg4))
                        {
                            int64_t rax_9 = (*(*arg1 + 0xc8))(arg1, *(var_40 + (r14_1 << 3)));
                            int64_t* rcx_5 = data_180047468;
                            rbp_1 = rax_9;
                            (*(*rcx_5 + 0x170))(rcx_5, var_38);
                            rax_3 = var_48;
                            break;
                        }
                        
                        int64_t* rcx_3 = data_180047468;
                        (*(*rcx_3 + 0x170))(rcx_3, rdi_1);
                    }
                }
                
                rax_3 = var_48;
                rbx_1 += 1;
            } while (rbx_1 < rax_3);
        }
        
        int32_t rbx_2 = 0;
        
        if (rax_3 > 0)
        {
            do
            {
                int64_t r8_2 = *arg1;
                (*(r8_2 + 0xb8))(arg1, *(var_40 + (rbx_2 << 3)), r8_2);
                rbx_2 += 1;
            } while (rbx_2 < var_48);
        }
        
        int64_t* rcx_7 = data_180047468;
        int64_t r8_3 = *rcx_7;
        (*(r8_3 + 0x170))(rcx_7, var_40, r8_3);
    }
    
    if (rax_2 || !rbp_1)
        sub_1800023a0("BServer: cannot find class %s", arg3);
    
    return rbp_1;
}

