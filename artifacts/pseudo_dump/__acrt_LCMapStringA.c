
🌐  int64_t __acrt_LCMapStringA(int128_t* arg1, int64_t arg2, int32_t arg3, char* arg4, int32_t arg5, int64_t arg6, int32_t arg7, uint32_t arg8, int32_t arg9)

{
    void* var_28;
    _LocaleUpdate::_LocaleUpdate(&var_28, arg1);
    void var_20;
    int64_t result =
        __acrt_LCMapStringA_stat(&var_20, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    char var_10;
    
    if (var_10)
    {
        void* rcx_2 = var_28;
        *(rcx_2 + 0x3a8) &= 0xfffffffd;
    }
    
    return result;
}

