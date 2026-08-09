
  void __acrt_locale_free_numeric(int64_t* arg1)

{
    if (!arg1)
        return;
    
    int64_t rcx = *arg1;
    
    if (rcx != data_180047090)
        _free_base(rcx);
    
    int64_t rcx_1 = arg1[1];
    
    if (rcx_1 != data_180047098)
        _free_base(rcx_1);
    
    int64_t rcx_2 = arg1[2];
    
    if (rcx_2 != data_1800470a0)
        _free_base(rcx_2);
    
    int64_t rcx_3 = arg1[0xb];
    
    if (rcx_3 != data_1800470e8)
        _free_base(rcx_3);
    
    int64_t rcx_4 = arg1[0xc];
    
    if (rcx_4 != data_1800470f0)
        _free_base(rcx_4);
}

