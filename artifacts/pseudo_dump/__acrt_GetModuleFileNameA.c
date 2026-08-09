
🌐  uint64_t __acrt_GetModuleFileNameA(HMODULE arg1, int64_t arg2, int32_t arg3)

{
    void var_2a8;
    int64_t rax_1 = __security_cookie ^ &var_2a8;
    uint64_t rdi = arg3;
    void filename;
    uint64_t result;
    
    if (GetModuleFileNameW(arg1, &filename, 0x105))
    {
        int32_t result_1 = 0;
        int64_t var_260 = arg2;
        uint64_t var_258_1 = rdi;
        uint64_t var_248_1 = rdi;
        int64_t var_250_1 = arg2;
        char var_238_1 = 0;
        void* var_280;
        _LocaleUpdate::_LocaleUpdate(&var_280, nullptr);
        uint32_t r9_1 = 0xfde9;
        void* var_278;
        char var_268;
        
        if (*(var_278 + 0xc) != 0xfde9)
        {
            int32_t rax_7 = sub_180026170();
            
            if (rax_7)
            {
                if (var_268)
                {
                    void* rax_9 = var_280;
                    *(rax_9 + 0x3a8) &= 0xfffffffd;
                }
                
                r9_1 = 0;
            }
            else
            {
                if (var_268 != rax_7)
                {
                    void* rax_8 = var_280;
                    *(rax_8 + 0x3a8) &= 0xfffffffd;
                }
                
                r9_1 = 1;
            }
        }
        else if (var_268)
        {
            void* rax_6 = var_280;
            *(rax_6 + 0x3a8) &= 0xfffffffd;
        }
        void var_288;
        __acrt_convert_wcs_mbs_cp<wchar_t,char,class <lambda_f788ae46380686e8b737efdd8c720d07>,struct __crt_win32_buffer_no_resizing>(
            &filename, &var_260, &var_288, r9_1);
        result = result_1;
    }
    else
    {
        sub_1800212ac(GetLastError());
        result = 0;
    }
    
    __security_check_cookie(rax_1 ^ &var_2a8);
    return result;
}

