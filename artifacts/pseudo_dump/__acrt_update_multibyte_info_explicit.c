
  uint64_t __acrt_update_multibyte_info_explicit(void* arg1, int64_t* arg2, int64_t arg3)

{
    uint64_t result = (&data_180047ec0)[arg3];
    
    if (*arg2 != result)
    {
        result = *(arg1 + 0x3a8);
        
        if (!(data_180047080 & result))
        {
            result = __acrt_update_thread_multibyte_data();
            *arg2 = result;
        }
    }
    
    return result;
}

