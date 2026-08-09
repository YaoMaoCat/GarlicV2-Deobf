
🌐  int64_t __acrt_uninitialize_lowio()

{
    for (int64_t i = 0; i < 0x400; i += 8)
    {
        CRITICAL_SECTION* rcx_1 = *(i + &data_180047840);
        
        if (rcx_1)
        {
            __acrt_lowio_destroy_handle_array(rcx_1);
            *(i + &data_180047840) = 0;
        }
    }
    
    int64_t result;
    result = 1;
    return result;
}

