
  int64_t _invalid_parameter_internal(int64_t arg1, int64_t arg2, int64_t arg3, int32_t arg4, int64_t arg5, int64_t* arg6)

{
    void* rax = __crt_cached_ptd_host::get_raw_ptd_noexit(arg6);
    
    if (!rax || !*(rax + 0x3b8))
    {
        int64_t r10_1 = *__crt_state_management::dual_state_global<void (__cdecl*)(wchar_t const* __ptr64, wchar_t const* __ptr64, wchar_t const* __ptr64, uint32_t, uint64_t)>::value(
            &data_1800477f8, arg6);
        uint64_t __security_cookie_1 = __security_cookie;
        
        if (!RORQ(r10_1 ^ __security_cookie_1, __security_cookie_1 & 0x3f))
        {
            int64_t var_18_1 = arg5;
            _invoke_watson();
            /* no return */
        }
    }
    
    int64_t var_18 = arg5;
    return sub_18002d680();
}

