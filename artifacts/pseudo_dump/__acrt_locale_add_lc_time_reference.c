
🌐  uint64_t __acrt_locale_add_lc_time_reference(void* arg1)

{
    if (!arg1 || arg1 == &data_180039e20)
        return 0x7fffffff;
    
    int32_t rax = *(arg1 + 0x15c);
    *(arg1 + 0x15c) += 1;
    return rax + 1;
}

