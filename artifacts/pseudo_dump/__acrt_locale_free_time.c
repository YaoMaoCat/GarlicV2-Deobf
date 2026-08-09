
🌐  void __acrt_locale_free_time(int64_t* arg1)

{
    if (!arg1)
        return;
    
    free_crt_array_internal(arg1, 7);
    free_crt_array_internal(&arg1[7], 7);
    free_crt_array_internal(&arg1[0xe], 0xc);
    free_crt_array_internal(&arg1[0x1a], 0xc);
    free_crt_array_internal(&arg1[0x26], 2);
    _free_base(arg1[0x28]);
    _free_base(arg1[0x29]);
    _free_base(arg1[0x2a]);
    free_crt_array_internal(&arg1[0x2c], 7);
    free_crt_array_internal(&arg1[0x33], 7);
    free_crt_array_internal(&arg1[0x3a], 0xc);
    free_crt_array_internal(&arg1[0x46], 0xc);
    free_crt_array_internal(&arg1[0x52], 2);
    _free_base(arg1[0x54]);
    _free_base(arg1[0x55]);
    _free_base(arg1[0x56]);
    _free_base(arg1[0x57]);
}

