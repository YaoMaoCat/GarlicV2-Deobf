
  uint8_t common_exit(uint32_t arg1, int32_t arg2, int32_t arg3)

{
    int32_t arg_18 = arg3;
    int32_t arg_10 = arg2;
    int64_t var_28 = -2;
    
    if (!arg3)
    {
        HMODULE rax_1 = GetModuleHandleW(nullptr);
        
        if (rax_1 && rax_1->unused == 0x5a4d)
        {
            int32_t* rcx_1 = *(rax_1 + 0x3c) + rax_1;
            
            if (*rcx_1 == 0x4550 && rcx_1[6] == 0x20b && rcx_1[0x21] > 0xe && rcx_1[0x3e])
                sub_18001fd74(arg1);
        }
    }
    
    char arg_20 = 0;
    int32_t* var_20 = &arg_10;
    int32_t* var_18 = &arg_18;
    char* var_10 = &arg_20;
    int32_t var_34 = 2;
    int32_t var_30 = 2;
    void var_38;
    uint8_t result = __crt_seh_guarded_call<class <lambda_99476a1ad63dd22509b5d3e65b0ffc95>,class <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c>& __ptr64,class <lambda_f7424dd8d45958661754dc4f2697e9c3>,void>::operator()<class <lambda_99476a1ad63dd22509b5d3e65b0ffc95>,class <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c>& __ptr64,class <lambda_f7424dd8d45958661754dc4f2697e9c3> >(
        &var_38, &var_30, &var_20, &var_34);
    
    if (!arg_18)
    {
        result = __acrt_get_process_end_policy();
        
        if (!arg_18)
        {
            sub_18001fd44(arg1, false);
            /* no return */
        }
    }
    
    return result;
}

