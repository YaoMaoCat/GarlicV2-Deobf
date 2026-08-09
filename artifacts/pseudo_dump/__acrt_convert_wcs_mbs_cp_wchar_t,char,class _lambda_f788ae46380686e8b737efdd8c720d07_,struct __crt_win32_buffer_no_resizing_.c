
🌐  uint64_t __acrt_convert_wcs_mbs_cp<wchar_t,char,class <lambda_f788ae46380686e8b737efdd8c720d07>,struct __crt_win32_buffer_no_resizing>(int16_t* arg1, void* arg2, int64_t arg3, uint32_t arg4)

{
    if (!arg1)
    {
        if (*(arg2 + 0x28))
            *(arg2 + 0x28) = 0;
        
        __builtin_memset(arg2 + 0x10, 0, 0x18);
    }
    else if (*arg1)
    {
        int64_t var_10_1 = 0;
        int64_t var_18_1 = 0;
        int32_t rax_4 = __acrt_WideCharToMultiByte(arg4, 0, arg1, 0xffffffff, 0, nullptr);
        
        if (!rax_4)
        {
            sub_1800212ac(GetLastError());
            return *sub_18002131c();
        }
        
        int64_t rcx_2 = *(arg2 + 0x18);
        
        if (rax_4 > rcx_2)
        {
            if (*(arg2 + 0x28))
                *(arg2 + 0x28) = 0;
            
        label_1800249ce:
            *sub_18002131c() = 0x22;
            *(arg2 + 0x28) = 0;
            *(arg2 + 0x18) = 0;
            return 0x22;
        }
        
        int64_t var_10_2 = 0;
        int64_t var_18_2 = 0;
        int64_t rax_9 =
            __acrt_WideCharToMultiByte(arg4, 0, arg1, 0xffffffff, *(arg2 + 0x10), rcx_2);
        
        if (!rax_9)
        {
            sub_1800212ac(GetLastError());
            return *sub_18002131c();
        }
        
        *(arg2 + 0x20) = rax_9 - 1;
    }
    else
    {
        if (!*(arg2 + 0x18))
        {
            if (*(arg2 + 0x28))
                *(arg2 + 0x28) = 0;
            
            goto label_1800249ce;
        }
        
        **(arg2 + 0x10) = 0;
    }
    
    return 0;
}

