
🌐  int64_t __crt_cached_ptd_host::update_locale_slow(int64_t* arg1)

{
    void* rax = sub_18001e310(arg1);
    arg1[3] = *(rax + 0x90);
    arg1[4] = *(rax + 0x88);
    __acrt_update_locale_info_explicit(rax, &arg1[3], arg1[1]);
    __acrt_update_multibyte_info_explicit(rax, &arg1[4], arg1[1]);
    int32_t result = *(rax + 0x3a8);
    
    if (!(result & 2))
    {
        result |= 2;
        *(rax + 0x3a8) = result;
        arg1[5] = 2;
    }
    
    return result;
}

