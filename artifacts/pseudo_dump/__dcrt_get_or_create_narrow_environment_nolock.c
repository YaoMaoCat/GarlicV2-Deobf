
🌐  int64_t __dcrt_get_or_create_narrow_environment_nolock()

{
    int64_t result = data_180047798;
    
    if (result)
        return result;
    
    if (data_1800477a0 != result)
    {
        int32_t rax = common_initialize_environment_nolock<char>();
        int32_t rax_1;
        
        if (rax)
            rax_1 = sub_180020370();
        
        if (!rax || !rax_1)
            return data_180047798;
    }
    
    return 0;
}

