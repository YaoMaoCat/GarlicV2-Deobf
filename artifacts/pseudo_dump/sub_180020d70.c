
  int64_t sub_180020d70(char* arg1, int64_t arg2, int64_t arg3)

{
    char* r9 = arg1;
    
    if (arg1 && arg2)
    {
        if (arg3)
        {
            while (true)
            {
                char rax_3 = *(arg3 - r9 + arg1);
                *arg1 = rax_3;
                arg1 = &arg1[1];
                
                if (!rax_3)
                    break;
                
                int64_t temp0_1 = arg2;
                arg2 -= 1;
                
                if (temp0_1 == 1)
                {
                    if (arg2)
                        break;
                    
                    *r9 = arg2;
                    *sub_18002131c() = 0x22;
                    _invalid_parameter_noinfo();
                    return 0x22;
                }
            }
            
            return 0;
        }
        
        *arg1 = arg3;
    }
    
    *sub_18002131c() = 0x16;
    _invalid_parameter_noinfo();
    return 0x16;
}

