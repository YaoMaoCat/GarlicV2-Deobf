
🌐  uint64_t __acrt_initialize_multibyte()

{
    if (!data_180047ecc)
    {
        data_180047eb8 = &data_180046e80;
        data_180047ec0 = &data_180046b40;
        data_180047eb0 = &data_180046d70;
        setmbcp_internal(0xfffffffd, 1, sub_180023308(), &data_180047ec0);
        data_180047ecc = 1;
    }
    
    uint64_t result;
    result = 1;
    return result;
}

