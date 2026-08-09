
🌐  uint64_t __acrt_has_user_matherr()

{
    uint64_t __security_cookie_1 = __security_cookie;
    __security_cookie_1 = RORQ(data_180047fe0 ^ __security_cookie_1, __security_cookie_1 & 0x3f);
    return __security_cookie_1;
}

