
  int64_t sub_180026920()

{
    uint64_t __security_cookie_1 = __security_cookie;
    
    if (RORQ(data_180047fe0 ^ __security_cookie_1, __security_cookie_1 & 0x3f))
        /* tailcall */
        return sub_18002d680();
    
    return 0;
}

