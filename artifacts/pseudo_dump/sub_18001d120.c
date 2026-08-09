
  uint64_t sub_18001d120(int64_t* arg1, int32_t arg2, void* arg3, int32_t arg4, int64_t* arg5)

{
    int64_t r11 = *(arg3 + 8);
    int32_t rbx = arg2;
    int64_t r10 = arg5[1];
    
    if (r10 <= r11)
    {
        int64_t r8 = arg1[1];
        
        if (r8 <= r10)
        {
            int64_t var_10;
            
            if (r10 - r8 >= r11 - r10)
            {
                void* rcx_1 = *arg5;
                rbx = arg4;
                void* var_18_1 = rcx_1;
                var_10 = r10;
                
                if (r11 > r10)
                {
                    while (true)
                    {
                        FH4::UWMap4::ReadEntry(rcx_1, &var_10);
                        rbx -= 1;
                        
                        if (*(arg3 + 8) <= var_10)
                            break;
                        
                        rcx_1 = var_18_1;
                    }
                }
            }
            else
            {
                void* rcx = *arg1;
                void* var_18 = rcx;
                var_10 = r8;
                
                if (r10 > r8)
                {
                    while (true)
                    {
                        FH4::UWMap4::ReadEntry(rcx, &var_10);
                        rbx += 1;
                        
                        if (arg5[1] <= var_10)
                            break;
                        
                        rcx = var_18;
                    }
                }
            }
            return rbx;
        }
    }
    
    return 0xffffffff;
}

