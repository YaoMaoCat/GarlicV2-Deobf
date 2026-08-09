
🌐  int64_t _set_new_handler()

{
    /* tailcall */
    return _set_new_handler(__security_cookie);
}

