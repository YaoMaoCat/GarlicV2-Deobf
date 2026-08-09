
🌐  int64_t _query_new_handler()

{
    sub_1800239bc(0);
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t result = RORQ(data_180047668 ^ __security_cookie_1, __security_cookie_1 & 0x3f);
    sub_180023a10(0);
    return result;
}

