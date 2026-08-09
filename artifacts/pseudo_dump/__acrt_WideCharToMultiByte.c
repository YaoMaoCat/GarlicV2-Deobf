
🌐  int64_t __acrt_WideCharToMultiByte(uint32_t arg1, int32_t arg2, wchar16* arg3, int32_t arg4, int64_t arg5, int32_t* arg6)

{
    bool cond:0 = arg1 - 0xfde8 <= 1;
    uint64_t rdx;
    int32_t rax_9;
    bool cond:3_1;
    
    if (arg1 > 0xdeac)
    {
        if (arg1 != 0xdead && arg1 != 0xdeae && arg1 != 0xdeaf && arg1 != 0xdeb0 && arg1 != 0xdeb1
            && arg1 != 0xdeb2 && arg1 != 0xdeb3)
        {
            rax_9 = arg1 - 0xfde8;
            cond:3_1 = arg1 == 0xfde8;
            goto label_1800258cd;
        }
        
        rdx = 0;
    }
    else if (arg1 == 0xdeac)
        rdx = 0;
    else
    {
        bool cond:7_1;
        
        if (arg1 <= 0xc433)
        {
            if (arg1 != 0xc433 && arg1 != 0x2a && arg1 != 0xc42c && arg1 != 0xc42d
                && arg1 != 0xc42e)
            {
                cond:7_1 = arg1 == 0xc431;
                goto label_1800258d2;
            }
            
            rdx = 0;
        }
        else if (arg1 == 0xc435 || arg1 == 0xd698)
            rdx = 0;
        else
        {
            rax_9 = arg1 - 0xdeaa;
            cond:3_1 = arg1 == 0xdeaa;
        label_1800258cd:
            
            if (cond:3_1)
                rdx = 0;
            else
            {
                cond:7_1 = rax_9 == 1;
            label_1800258d2:
                
                rdx = cond:7_1 ? 0 : arg2 & 0xffffff7f;
            }
        }
    }
    int64_t r9 = arg5;
    int32_t* r8 = arg6;
    
    if (cond:0)
        r8 = nullptr;
    
    if (cond:0)
        r9 = 0;
    
    if (cond:0 && arg6)
        *arg6 = 0;
    
    arg6 = r8;
    arg5 = r9;
    /* tailcall */
    return WideCharToMultiByte(arg1, rdx, arg3, arg4);
}

