
  int64_t __crt_seh_guarded_call<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff>,void>::operator()<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)

{
    int32_t* arg_20 = arg4;
    sub_1800239bc(*arg2);
    int32_t* rcx_2 = *(**arg3 + 0x88);
    
    if (rcx_2)
    {
        int32_t rax_1 = *rcx_2;
        *rcx_2 -= 1;
        
        if (rax_1 == 1 && rcx_2 != &data_180046b40)
            _free_base(rcx_2);
    }
    
    return sub_180023a10(*arg4);
}

