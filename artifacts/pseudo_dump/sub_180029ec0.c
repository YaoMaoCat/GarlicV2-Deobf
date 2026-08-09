
  uint64_t sub_180029ec0(char* arg1, int64_t arg2, int64_t arg3, int64_t arg4)

{
    int64_t rbx = arg2;
    char* r11 = arg1;
    
    if (!arg4)
    {
        if (arg1)
            goto label_180029ef7;
        
        if (!arg2)
            return 0;
    }
    else if (r11)
    {
    label_180029ef7:
        
        if (rbx)
        {
            if (!arg4)
            {
                *arg1 = arg4;
                return 0;
            }
            
            if (arg3)
            {
                char* r10_1 = arg3 - r11;
                int64_t i_2 = arg4;
                
                if (arg4 != -1)
                {
                    int64_t i_3;
                    int64_t i;
                    
                    do
                    {
                        char rax_6 = *(r10_1 + arg1);
                        i_3 = i_2;
                        *arg1 = rax_6;
                        arg1 = &arg1[1];
                        
                        if (!rax_6)
                            return 0;
                        
                        int64_t temp0_1 = arg2;
                        arg2 -= 1;
                        
                        if (temp0_1 == 1)
                            break;
                        
                        i = i_2;
                        i_2 -= 1;
                    } while (i != 1);
                    int64_t i_4 = i_3 - 1;
                    
                    if (!arg2)
                        i_4 = i_3;
                    
                    if (!i_4)
                        *arg1 = i_4;
                }
                else
                {
                    int64_t i_1;
                    
                    do
                    {
                        char rax_5 = *(r10_1 + arg1);
                        *arg1 = rax_5;
                        arg1 = &arg1[1];
                        
                        if (!rax_5)
                            return 0;
                        
                        i_1 = arg2;
                        arg2 -= 1;
                    } while (i_1 != 1);
                }
                
                if (arg2)
                    return 0;
                
                if (arg4 == -1)
                {
                    r11[rbx - 1] = arg2;
                    return arg2 + 0x50;
                }
                
                *r11 = 0;
                *sub_18002131c() = 0x22;
                _invalid_parameter_noinfo();
                return 0x22;
            }
            
            *arg1 = arg3;
        }
    }
    
    *sub_18002131c() = 0x16;
    _invalid_parameter_noinfo();
    return 0x16;
}

