
  uint32_t sub_18001fe04(char* arg1, int64_t* arg2, char* arg3, int64_t* arg4, int64_t* arg5)

{
    uint64_t rsi;
    uint64_t arg_18 = rsi;
    char* rbx = arg3;
    int64_t* r14 = arg2;
    char* rdi = arg1;
    *arg5 = 0;
    *arg4 = 1;
    
    if (arg2)
    {
        *arg2 = rbx;
        r14 = &r14[1];
    }
    
    int64_t rbp;
    rbp = 0;
    uint32_t i;
    
    while (true)
    {
        if (*rdi != 0x22)
        {
            *arg5 += 1;
            
            if (rbx)
            {
                i = *rdi;
                *rbx = i;
                rbx = &rbx[1];
            }
            
            rsi = *rdi;
            rdi = &rdi[1];
            i = _ismbblead(rsi);
            
            if (i)
            {
                *arg5 += 1;
                
                if (rbx)
                {
                    i = *rdi;
                    *rbx = i;
                    rbx = &rbx[1];
                }
                
                rdi = &rdi[1];
            }
            
            if (!rsi)
            {
                rdi -= 1;
                break;
            }
        }
        else
        {
            rsi = 0x22;
            rbp = !rbp;
            rdi = &rdi[1];
        }
        
        if (!rbp)
        {
            if (rsi != 0x20 && rsi != 9)
                continue;
            
            if (!rbx)
                break;
            
            rbx[-1] = 0;
            break;
        }
    }
    
    rsi = 0;
    
    while (true)
    {
        i = *rdi;
        
        if (!i)
            break;
        
        while (i == 0x20 || i == 9)
        {
            rdi = &rdi[1];
            i = *rdi;
        }
        
        if (!i)
            break;
        
        if (r14)
        {
            *r14 = rbx;
            r14 = &r14[1];
        }
        
        *arg4 += 1;
        
        while (true)
        {
            int32_t rdx = 1;
            i = 0;
            
            while (true)
            {
                arg1 = *rdi;
                
                if (arg1 != 0x5c)
                    break;
                
                rdi = &rdi[1];
                i += 1;
            }
            
            if (arg1 == 0x22)
            {
                if (!(1 & i))
                {
                    if (!rsi || rdi[1] != arg1)
                    {
                        rdx = 0;
                        rsi = !rsi;
                    }
                    else
                        rdi = &rdi[1];
                }
                
                i u>>= 1;
            }
            
            while (i)
            {
                i -= 1;
                
                if (rbx)
                {
                    *rbx = 0x5c;
                    rbx = &rbx[1];
                }
                
                *arg5 += 1;
            }
            
            i = *rdi;
            
            if (!i)
                break;
            
            if (!rsi)
            {
                if (i == 0x20)
                    break;
                
                if (i == 9)
                    break;
            }
            
            if (rdx)
            {
                if (rbx)
                {
                    *rbx = i;
                    rbx = &rbx[1];
                }
                
                int32_t rax;
                rax = _ismbblead(*rdi);
                
                if (rax)
                {
                    *arg5 += 1;
                    rdi = &rdi[1];
                    
                    if (rbx)
                    {
                        rax = *rdi;
                        *rbx = rax;
                        rbx = &rbx[1];
                    }
                }
                
                *arg5 += 1;
            }
            
            rdi = &rdi[1];
        }
        
        if (rbx)
        {
            *rbx = 0;
            rbx = &rbx[1];
        }
        
        *arg5 += 1;
    }
    
    if (r14)
        *r14 = 0;
    
    *arg4 += 1;
    return i;
}

