
🌐  int64_t __crt_seh_guarded_call<class <lambda_450d765d439847d4c735a33c368b5fc0>,class <lambda_44731a7d0e6d81c3e6aa82d741081786>& __ptr64,class <lambda_601a2a7da3b7a96e9554ac7215c4b07c>,void (__cdecl*)(int32_t)>::operator()<class <lambda_450d765d439847d4c735a33c368b5fc0>,class <lambda_44731a7d0e6d81c3e6aa82d741081786>& __ptr64,class <lambda_601a2a7da3b7a96e9554ac7215c4b07c> >(int64_t arg1, int32_t* arg2, int64_t arg3, int32_t* arg4)

{
    int32_t* arg_20 = arg4;
    sub_1800239bc(*arg2);
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t result = RORQ(data_180047fd0 ^ __security_cookie_1, __security_cookie_1 & 0x3f);
    sub_180023a10(*arg4);
    return result;
}

