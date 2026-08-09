
🌐  int64_t __acrt_get_process_end_policy()

{
    int32_t arg_8 = 0;
    
    if (!__acrt_is_secure_process())
        sub_180026114();
    
    return 1;
}

