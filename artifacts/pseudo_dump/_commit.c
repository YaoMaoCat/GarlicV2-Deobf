
🌐  uint64_t _commit(int32_t arg1)

{
    int32_t arg_8 = arg1;
    int64_t rdx = arg1;
    
    if (rdx != 0xfffffffe)
    {
        if (arg1 >= 0 && rdx < data_180047c40
            && *((&data_180047840)[rdx >> 6] + (rdx & 0x3f) * 0x48 + 0x38) & 1)
        {
            int32_t arg_18 = rdx;
            int32_t arg_20 = rdx;
            int32_t* var_18 = &arg_8;
            void arg_10;
            return __crt_seh_guarded_call<class <lambda_a37b2b86f63e897a80ea819b0eb08c01>,class <lambda_38ce7e780aa69e748d6df282ebc68efe>& __ptr64,class <lambda_99fb1378e971ab6e7edea83e3a7a83a2>,int32_t>::operator()<class <lambda_a37b2b86f63e897a80ea819b0eb08c01>,class <lambda_38ce7e780aa69e748d6df282ebc68efe>& __ptr64,class <lambda_99fb1378e971ab6e7edea83e3a7a83a2> >(
                &arg_10, &arg_20, &var_18, &arg_18);
        }
        
        *sub_18002131c() = 9;
        _invalid_parameter_noinfo();
    }
    else
        *sub_18002131c() = 9;
    
    return 0xffffffff;
}

