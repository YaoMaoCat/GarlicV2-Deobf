
🌐  int64_t _initialize_onexit_table(int64_t* arg1)

{
    if (!arg1)
        return 0xffffffff;
    
    if (*arg1 == arg1[2])
    {
        uint64_t __security_cookie_1 = __security_cookie;
        *arg1 = __security_cookie_1;
        arg1[1] = __security_cookie_1;
        arg1[2] = __security_cookie_1;
    }
    
    return 0;
}

