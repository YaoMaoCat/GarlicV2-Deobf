
🌐  int64_t destroy_ptd_array(int64_t* arg1)

{
    int64_t* var_20 = arg1;
    int64_t* var_18 = &var_20;
    int32_t arg_18 = 5;
    int32_t arg_20 = 5;
    int64_t* var_10 = &var_20;
    int32_t var_28 = 4;
    int32_t var_24 = 4;
    int64_t rax = *arg1;
    
    if (rax != &data_180039930)
    {
        _free_base(rax);
        arg1 = var_20;
    }
    
    _free_base(arg1[0xe]);
    _free_base(var_20[0xb]);
    _free_base(var_20[0xc]);
    _free_base(var_20[0xd]);
    _free_base(var_20[9]);
    _free_base(var_20[0xa]);
    _free_base(var_20[0xf]);
    _free_base(var_20[0x10]);
    _free_base(var_20[0x78]);
    void arg_10;
    __crt_seh_guarded_call<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff>,void>::operator()<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff> >(
        &arg_10, &arg_20, &var_18, &arg_18);
    return __crt_seh_guarded_call<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707>,void>::operator()<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707> >(
        &arg_10, &var_24, &var_10, &var_28);
}

