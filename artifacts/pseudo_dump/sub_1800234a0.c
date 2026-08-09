
  int64_t __crt_seh_guarded_call<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a>,void>::operator()<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a> >(int64_t arg1, int32_t* arg2, int64_t arg3, int32_t* arg4)

{
    int32_t* arg_20 = arg4;
    sub_1800239bc(*arg2);
    int64_t* rbx = &data_180047838;
    
    while (true)
    {
        int64_t* var_18_1 = rbx;
        
        if (rbx == &data_180047840)
            break;
        
        if (*rbx != &data_1800469d0)
            *rbx = _updatetlocinfoEx_nolock(rbx, &data_1800469d0);
        
        rbx = &rbx[1];
    }
    
    return sub_180023a10(*arg4);
}

