
  uint64_t __acrt_update_locale_info(void* arg1, int64_t* arg2)

{
    uint64_t result = data_180047838;
    
    if (*arg2 != result)
    {
        result = *(arg1 + 0x3a8);
        
        if (!(data_180047080 & result))
        {
            result = sub_180027100();
            *arg2 = result;
        }
    }
    
    return result;
}

