
🌐  char* __crt_stdio_output::crop_zeroes(char* arg1, int64_t* arg2)

{
    char r9 = ***(*arg2 + 0xf8);
    char* result;
    result = *arg1;
    
    if (result)
    {
        int64_t* rdx;
        rdx = result;
        
        do
        {
            result = rdx;
            
            if (rdx == r9)
                break;
            
            arg1 = &arg1[1];
            result = *arg1;
            rdx = result;
        } while (result);
    }
    
    char* rcx = &arg1[1];
    
    if (result)
    {
        while (true)
        {
            result = *rcx;
            
            if (!result)
                break;
            
            result -= 0x45;
            
            if (!(result & 0xdf))
                break;
            
            rcx = &rcx[1];
        }
        
        char* r8_1 = rcx;
        
        do
        {
            rcx -= 1;
            result = *rcx;
        } while (result == 0x30);
        
        char* rdx_1 = &rcx[-1];
        
        if (result != r9)
            rdx_1 = rcx;
        
        char* r8_2 = r8_1 - rdx_1;
        
        do
        {
            result = *(r8_2 + rdx_1);
            rdx_1 = &rdx_1[1];
            *rdx_1 = result;
        } while (result);
    }
    
    return result;
}

