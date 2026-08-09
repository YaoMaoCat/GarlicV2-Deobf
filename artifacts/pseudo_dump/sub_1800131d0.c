
  int64_t sub_1800131d0(int64_t arg1, int64_t arg2, char arg3, int64_t arg4, int32_t arg5)

{
    int64_t* rcx = data_180047468;
    int32_t rbx = 0;
    int32_t var_68 = 0;
    int64_t var_58 = 0;
    
    if ((*(*rcx + 0x198))(rcx, arg1, &var_68, &var_58))
        return 0;
    
    int64_t i = 0;
    int32_t r15 = 0;
    
    if (var_68 > 0)
    {
        while (!i)
        {
            int64_t* rcx_1 = data_180047468;
            int64_t rdx_1 = var_58;
            char* var_50 = nullptr;
            char* var_60 = nullptr;
            int64_t var_48 = 0;
            int64_t r12_1 = r15;
            
            if ((*(*rcx_1 + 0x1f8))(rcx_1, *(rdx_1 + (r12_1 << 3)), &var_50, &var_60, &var_48))
                i = 0;
            else
            {
                int64_t* rcx_2 = data_180047468;
                int64_t rdx_3 = var_58;
                int32_t var_64 = 0;
                (*(*rcx_2 + 0x208))(rcx_2, *(rdx_3 + (r12_1 << 3)), &var_64);
                char* rdi_1 = var_50;
                char* rbx_1;
                
                if (!rdi_1)
                {
                label_1800132de:
                    rbx_1 = var_60;
                    
                    if (rbx_1 && !strcmp(rbx_1, arg2) && (var_64 >> 3 & 1) == arg3)
                    {
                        i = *(var_58 + (r12_1 << 3));
                        sub_1800023a0("  findMethodByDescExcl(%s): '%s'", arg2);
                        rdi_1 = var_50;
                        rbx_1 = var_60;
                    }
                }
                else
                {
                    while (true)
                    {
                        if (rbx >= arg5)
                            goto label_1800132de;
                        
                        if (!strcmp(rdi_1, *(arg4 + (rbx << 3))))
                            break;
                        
                        rbx += 1;
                    }
                    
                    rbx_1 = var_60;
                }
                
                if (rdi_1)
                {
                    int64_t* rcx_5 = data_180047468;
                    (*(*rcx_5 + 0x170))(rcx_5, rdi_1);
                    rbx_1 = var_60;
                }
                
                if (rbx_1)
                {
                    int64_t* rcx_6 = data_180047468;
                    (*(*rcx_6 + 0x170))(rcx_6, rbx_1);
                }
                
                int64_t rdx_11 = var_48;
                
                if (rdx_11)
                {
                    int64_t* rcx_7 = data_180047468;
                    (*(*rcx_7 + 0x170))(rcx_7, rdx_11);
                }
                
                rbx = 0;
            }
            
            r15 += 1;
            
            if (r15 >= var_68)
                break;
        }
    }
    
    int64_t* rcx_8 = data_180047468;
    int64_t r8_5 = *rcx_8;
    (*(r8_5 + 0x170))(rcx_8, var_58, r8_5);
    return i;
}

