
  int64_t fp_format_e(int64_t* arg1, char* arg2, void* arg3, char* arg4, int64_t arg5, int32_t arg6, char arg7, int32_t arg8, int32_t arg9, int64_t* arg10)

{
    int64_t rcx = *arg1;
    int128_t var_18 = {0};
    int32_t rax_1 = sub_18002784c(rcx, arg6 + 1, 1, &var_18, arg4, arg5);
    int64_t r9_1;
    r9_1 = var_18 == 0x2d;
    int64_t var_30;
    var_30 = arg9;
    char* var_38;
    var_38 = rax_1;
    void* rcx_1;
    rcx_1 = arg6 > 0;
    void* rdx_3 = arg3 - rcx_1 - r9_1;
    
    if (arg3 == -1)
        rdx_3 = arg3;
    
    int32_t result = __acrt_fp_strflt_to_string(rcx_1 + r9_1 + arg2, rdx_3, arg6 + 1, &var_18, 
        var_38, var_30, arg10);
    
    if (!result)
    {
        var_38 = arg8;
        return fp_format_e_internal(arg2, arg3, arg6, arg7, var_38, &var_18, 0, arg10);
    }
    
    *arg2 = 0;
    return result;
}

