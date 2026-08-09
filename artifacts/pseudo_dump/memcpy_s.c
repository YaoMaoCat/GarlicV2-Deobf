
🌐  uint64_t memcpy_s(int128_t* arg1, void* arg2, int32_t* arg3, void* arg4)

{
    if (arg4)
    {
        int32_t* rax;
        int32_t rbx_1;
        
        if (!arg1)
        {
        label_180028af2:
            rax = sub_18002131c();
            rbx_1 = 0x16;
        label_180028afc:
            *rax = rbx_1;
            _invalid_parameter_noinfo();
            return rbx_1;
        }
        
        if (!arg3 || arg2 < arg4)
        {
            sub_18002de50(arg1, 0, arg2);
            
            if (!arg3)
                goto label_180028af2;
            
            if (arg2 >= arg4)
                return 0x16;
            
            rax = sub_18002131c();
            rbx_1 = 0x22;
            goto label_180028afc;
        }
        
        memcpy(arg1, arg3, arg4);
    }
    
    return 0;
}

