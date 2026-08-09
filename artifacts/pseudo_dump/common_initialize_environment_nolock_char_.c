
🌐  uint64_t common_initialize_environment_nolock<char>()

{
    int32_t rdi = 0;
    
    if (data_180047798)
        return 0;
    
    __acrt_initialize_multibyte();
    char* rax_1 = __dcrt_get_narrow_environment_from_os();
    
    if (!rax_1)
    {
        _free_base(0);
        return 0xffffffff;
    }
    
    char** rax_2 = sub_180020218(rax_1);
    
    if (rax_2)
    {
        data_1800477b0 = rax_2;
        data_180047798 = rax_2;
    }
    else
        rdi = -1;
    
    _free_base(0);
    _free_base(rax_1);
    return rdi;
}

