
🌐  int64_t construct_ptd_array(void** arg1)

{
    void** var_30 = arg1;
    int64_t* var_20 = &var_30;
    int32_t arg_18 = 5;
    int32_t arg_20 = 5;
    int64_t* var_18 = &var_30;
    int64_t* var_28;
    int64_t* var_10 = &var_28;
    int32_t var_38 = 4;
    int32_t var_34 = 4;
    var_28 = &data_180047838;
    arg1[5] = 1;
    *var_30 = &data_180039930;
    var_30[0x75] = 1;
    var_30[0x11] = &data_180046b40;
    *(var_30 + 0xbc) = 0x43;
    *(var_30 + 0x1c2) = 0x43;
    var_30[0x74] = 0;
    void arg_10;
    sub_180022e6c(&arg_10, &arg_20, &var_20, &arg_18);
    return __crt_seh_guarded_call<class <lambda_5e887d1dcbef67a5eb4283622ba103bf>,class <lambda_4466841279450cc726390878d4a41900>& __ptr64,class <lambda_341c25c0346d94847f1f3c463c57e077>,void>::operator()<class <lambda_5e887d1dcbef67a5eb4283622ba103bf>,class <lambda_4466841279450cc726390878d4a41900>& __ptr64,class <lambda_341c25c0346d94847f1f3c463c57e077> >(
        &arg_10, &var_34, &var_18, &var_38);
}

