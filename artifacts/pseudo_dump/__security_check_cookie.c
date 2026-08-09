
🌐  int64_t __security_check_cookie(int64_t arg1)

{
    if (arg1 == __security_cookie && !(ROLQ(arg1, 0x10) & 0xffff))
        return;
    
    /* tailcall */
    return sub_1800161f0();
}

