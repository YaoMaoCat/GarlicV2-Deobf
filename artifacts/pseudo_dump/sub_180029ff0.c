
  char* sub_180029ff0(char* arg1, char* arg2)

{
    int128_t var_38;
    int64_t rax_1 = __security_cookie ^ &var_38;
    char i = *arg2;
    char* result = arg1;
    __builtin_memset(&var_38, 0, 0x20);
    
    while (i)
    {
        var_38 |= 1 << (i % 0x20);
        i = arg2[1];
        arg2 = &arg2[1];
    }
    
    char i_1 = *result;
    
    while (i_1)
    {
        if (*(&var_38 + (i_1 >> 3)) >> (i_1 & 7) & 1)
        {
            __security_check_cookie(rax_1 ^ &var_38);
            return result;
        }
        
        i_1 = result[1];
        result = &result[1];
    }
    
    __security_check_cookie(rax_1 ^ &var_38);
    return 0;
}

