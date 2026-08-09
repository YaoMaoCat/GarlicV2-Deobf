
🌐  int64_t __acrt_initialize_lowio()

{
    sub_1800239bc(7);
    char rbx = 0;
    
    if (!__acrt_lowio_ensure_fh_exists(0))
    {
        sub_18002354c();
        initialize_stdio_handles_nolock();
        rbx = 1;
    }
    
    sub_180023a10(7);
    int64_t result;
    result = rbx;
    return result;
}

