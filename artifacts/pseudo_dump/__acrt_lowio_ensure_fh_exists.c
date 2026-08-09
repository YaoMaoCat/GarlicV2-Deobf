
🌐  uint64_t __acrt_lowio_ensure_fh_exists(int32_t arg1)

{
    if (arg1 >= 0x2000)
    {
        *sub_18002131c() = 9;
        _invalid_parameter_noinfo();
        return 9;
    }
    
    int32_t rdi_1 = 0;
    sub_1800239bc(7);
    int64_t rbx_1 = 0;
    int32_t rax_2 = data_180047c40;
    
    while (true)
    {
        int64_t var_18_1 = rbx_1;
        
        if (arg1 < rax_2)
            break;
        
        if (!(&data_180047840)[rbx_1])
        {
            void* rax_3 = __acrt_lowio_create_handle_array();
            (&data_180047840)[rbx_1] = rax_3;
            
            if (!rax_3)
            {
                rdi_1 = rax_3 + 0xc;
                break;
            }
            
            rax_2 = data_180047c40 + 0x40;
            data_180047c40 = rax_2;
        }
        
        rbx_1 += 1;
    }
    
    sub_180023a10(7);
    return rdi_1;
}

