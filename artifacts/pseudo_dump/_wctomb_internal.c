
🌐  uint64_t _wctomb_internal(int32_t* arg1, char* arg2, void* arg3, wchar16 arg4, int64_t* arg5)

{
    wchar16 arg_20 = arg4;
    int32_t rbx = 0;
    
    if (!arg2 && arg3)
    {
        if (arg1)
            *arg1 = 0;
        
        return 0;
    }
    
    if (arg1)
        *arg1 = 0xffffffff;
    
    int32_t rsi_1;
    
    if (arg3 <= 0x7fffffff)
    {
        if (!arg5[5])
        {
            __crt_cached_ptd_host::update_locale_slow(arg5);
            arg4 = arg_20;
        }
        
        void* rax_1 = arg5[3];
        uint32_t rcx_1 = *(rax_1 + 0xc);
        int64_t arg_10;
        
        if (rcx_1 == 0xfde9)
        {
            arg_10 = 0;
            int32_t rax_2 = __crt_mbstring::__c32rtomb_utf8(arg2, arg4, &arg_10, arg5);
            
            if (arg1)
                *arg1 = rax_2;
            
            if (rax_2 <= 4)
                return 0;
            
            if (arg5[6])
                rbx = *(arg5 + 0x2c);
            
            return rbx;
        }
        
        if (*(rax_1 + 0x138))
        {
            arg_10 = 0;
            int64_t* var_20_1 = &arg_10;
            int64_t var_28_1 = 0;
            int32_t* var_30;
            var_30 = arg3;
            int32_t rax_4 = __acrt_WideCharToMultiByte(rcx_1, 0, &arg_20, 1, arg2, var_30);
            
            if (rax_4)
            {
                if (arg_10)
                    goto label_18002274a;
                
                if (arg1)
                    *arg1 = rax_4;
                
                return 0;
            }
            
            if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
            {
            label_18002274a:
                *(arg5 + 0x2c) = 0x2a;
                arg5[6] = 1;
                return 0x2a;
            }
            
            if (arg2 && arg3)
                sub_18002de50(arg2, 0, arg3);
        }
        else
        {
            if (arg4 > 0xff)
            {
                if (arg2 && arg3)
                    sub_18002de50(arg2, 0, arg3);
                
                goto label_18002274a;
            }
            
            if (!arg2)
                goto label_180022776;
            
            if (arg3)
            {
                *arg2 = arg4;
            label_180022776:
                
                if (!arg1)
                    return 0;
                
                *arg1 = 1;
                return 0;
            }
        }
        
        rsi_1 = 0x22;
    }
    else
        rsi_1 = 0x16;
    
    *(arg5 + 0x2c) = rsi_1;
    arg5[6] = 1;
    _invalid_parameter_internal(0, 0, 0, 0, 0, arg5);
    return rsi_1;
}

