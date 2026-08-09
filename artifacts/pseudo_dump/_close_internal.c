
🌐  uint64_t _close_internal(int32_t arg1, int64_t* arg2)

{
    int32_t arg_8 = arg1;
    int64_t r8 = arg1;
    
    if (r8 != 0xfffffffe)
    {
        if (arg1 >= 0 && r8 < data_180047c40
            && *((&data_180047840)[r8 >> 6] + (r8 & 0x3f) * 0x48 + 0x38) & 1)
        {
            int64_t* var_18_1 = arg2;
            int32_t arg_20 = r8;
            int32_t var_28 = r8;
            int32_t* var_20 = &arg_8;
            void arg_18;
            return __crt_seh_guarded_call<class <lambda_ad8af0d99a0adf03d037d7dffe354bb5>,class <lambda_c9ba49e555ba839a7b07aa3fbecb7617>& __ptr64,class <lambda_2f1ebd5d68526518146ae959c9e734c8>,int32_t>::operator()<class <lambda_ad8af0d99a0adf03d037d7dffe354bb5>,class <lambda_c9ba49e555ba839a7b07aa3fbecb7617>& __ptr64,class <lambda_2f1ebd5d68526518146ae959c9e734c8> >(
                &arg_18, &var_28, &var_20, &arg_20);
        }
        
        arg2[7] = 1;
        *(arg2 + 0x34) = 0;
        arg2[6] = 1;
        *(arg2 + 0x2c) = 9;
        _invalid_parameter_internal(0, 0, 0, 0, 0, arg2);
    }
    else
    {
        arg2[7] = 1;
        *(arg2 + 0x34) = 0;
        arg2[6] = 1;
        *(arg2 + 0x2c) = 9;
    }
    
    return 0xffffffff;
}

