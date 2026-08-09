
🌐  int64_t __crt_mbstring::__c16rtomb_utf8(char* arg1, int16_t arg2, int32_t* arg3, void* arg4)

{
    int32_t* rbx = &data_180047810;
    
    if (arg3)
        rbx = arg3;
    
    if (*rbx)
    {
        if (0x2400 + arg2 <= 0x3ff)
        {
            int64_t arg_18 = 0;
            return __crt_mbstring::reset_and_return(
                __crt_mbstring::__c32rtomb_utf8(arg1, (arg2 & 0xffff23ff) + *rbx, &arg_18, arg4), 
                rbx);
        }
    }
    else if (0x2400 + arg2 > 0x3ff)
    {
        if (0x2800 + arg2 > 0x3ff)
            /* tailcall */
            return __crt_mbstring::__c32rtomb_utf8(arg1, arg2, rbx, arg4);
        
        *rbx = (arg2 << 0xa & 0xfc9ffc00) + 0x10000;
        return 0;
    }
    
    return __crt_mbstring::return_illegal_sequence(rbx, arg4);
}

