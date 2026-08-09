
🌐  char* should_round_up(int64_t arg1, char* arg2, int32_t arg3, int32_t arg4, int32_t arg5)

{
    char* rbx = arg2;
    char* result;
    
    if (arg5)
    {
        result = __scrt_wide_argv_policy::configure_argv();
        uint64_t rcx;
        
        if (!result)
        {
            char temp0_1 = *rbx;
            rcx = &result[1];
            
            if (temp0_1 > 0x35)
                result = rcx;
            else if (temp0_1 < 0x35)
                result = 0;
            else
            {
                result = &rbx[1];
                
                if (arg4)
                {
                    char rdx;
                    
                    while (true)
                    {
                        rdx = *result;
                        
                        if (rdx != 0x30)
                            break;
                        
                        result = &result[rcx];
                    }
                    
                    if (rdx)
                        result = rcx;
                    else if (rbx == arg1)
                        result = 0;
                    else
                    {
                        result = rbx[-1];
                        result &= rcx;
                    }
                }
                else
                    result = rcx;
            }
        }
        else if (result == 0x200)
        {
            rcx = 1;
            
            if (arg4)
            {
                while (true)
                {
                    result = *rbx;
                    
                    if (result != 0x30)
                        break;
                    
                    rbx = &rbx[1];
                }
                
                if (!result || arg3 == 0x2d)
                {
                    rcx = 0;
                    result = rcx;
                }
                else
                    result = rcx;
            }
            else if (arg3 != 0x2d)
                result = rcx;
            else
            {
                rcx = 0;
                result = rcx;
            }
        }
        else if (result != 0x100)
            result = 0;
        else
        {
            rcx = 1;
            
            if (arg4)
            {
                while (true)
                {
                    result = *rbx;
                    
                    if (result != 0x30)
                        break;
                    
                    rbx = &rbx[1];
                }
                
                if (!result || arg3 != 0x2d)
                {
                    rcx = 0;
                    result = rcx;
                }
                else
                    result = rcx;
            }
            else if (arg3 == 0x2d)
                result = rcx;
            else
            {
                rcx = 0;
                result = rcx;
            }
        }
    }
    else
        result = *arg2 >= 0x35;
    
    return result;
}

