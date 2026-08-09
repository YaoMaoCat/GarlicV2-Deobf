
🌐  uint64_t common_flush_all(char arg1, int512_t arg2 @ zmm1)

{
    char arg_8 = arg1;
    int32_t arg_20 = 0;
    int32_t arg_18 = 0;
    int32_t* var_20 = &arg_20;
    char* var_18 = &arg_8;
    int32_t* var_10 = &arg_18;
    int32_t var_28 = 8;
    int32_t var_24 = 8;
    void arg_10;
    __crt_seh_guarded_call<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752>,void>::operator()<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752> >(
        &arg_10, &var_24, &var_20, &var_28, arg2);
    
    if (arg_8)
        return arg_20;
    
    return arg_18;
}

