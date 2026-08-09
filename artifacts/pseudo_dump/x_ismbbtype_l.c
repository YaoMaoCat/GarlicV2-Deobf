
🌐  int64_t x_ismbbtype_l(int128_t* arg1, char arg2, int32_t arg3, char arg4)

{
    void* var_28;
    _LocaleUpdate::_LocaleUpdate(&var_28, arg1);
    uint64_t rdx_1 = arg2;
    int64_t* var_20;
    int64_t var_18;
    int64_t result;
    
    if (*(rdx_1 + var_18 + 0x19) & arg4 || (arg3 && arg3 & *(*var_20 + (rdx_1 << 1))))
        result = 1;
    else
        result = 0;
    
    char var_10;
    
    if (var_10)
    {
        void* rcx_2 = var_28;
        *(rcx_2 + 0x3a8) &= 0xfffffffd;
    }
    
    return result;
}

