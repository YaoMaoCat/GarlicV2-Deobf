
🌐  int64_t __acrt_MultiByteToWideChar(uint32_t arg1, enum MULTI_BYTE_TO_WIDE_CHAR_FLAGS arg2, uint8_t* arg3, int64_t arg4)

{
    if (arg1 > 0xdeac)
    {
        if (arg1 == 0xdead || arg1 == 0xdeae || arg1 == 0xdeaf || arg1 == 0xdeb0 || arg1 == 0xdeb1
                || arg1 == 0xdeb2 || arg1 == 0xdeb3 || arg1 == 0xfde8)
            arg2 = 0;
        else if (arg1 == 0xfde9)
            arg2 &= MB_ERR_INVALID_CHARS;
    }
    else if (arg1 == 0xdeac)
        arg2 = 0;
    else
    {
        bool cond:2_1;
        
        if (arg1 <= 0xc433)
        {
            if (arg1 != 0xc433 && arg1 != 0x2a && arg1 != 0xc42c && arg1 != 0xc42d
                && arg1 != 0xc42e)
            {
                cond:2_1 = arg1 != 0xc431;
                goto label_1800257f9;
            }
            
            arg2 = 0;
        }
        else if (arg1 == 0xc435)
            arg2 = 0;
        else if (arg1 == 0xd698)
            arg2 &= MB_ERR_INVALID_CHARS;
        else if (arg1 == 0xdeaa)
            arg2 = 0;
        else
        {
            cond:2_1 = arg1 != 0xdeab;
        label_1800257f9:
            
            if (!cond:2_1)
                arg2 = 0;
        }
    }
    
    /* tailcall */
    return MultiByteToWideChar(arg1, arg2, arg3, arg4);
}

