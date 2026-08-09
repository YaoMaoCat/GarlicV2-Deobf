
🌐  int64_t fp_format_f(int64_t* arg1, char* arg2, void* arg3, char* arg4, int64_t arg5, int32_t arg6, int32_t arg7, int64_t* arg8)

{
    int64_t rcx = *arg1;
    int128_t var_18 = {0};
    int32_t rax_1 = sub_18002784c(rcx, arg6, 0, &var_18, arg4, arg5);
    void* r9_1;
    r9_1 = var_18 == 0x2d;
    void* rdx_2 = arg3 - r9_1;
    int64_t var_30;
    var_30 = arg7;
    char* var_38;
    var_38 = rax_1;
    
    if (arg3 == -1)
        rdx_2 = arg3;
    
    int32_t result = __acrt_fp_strflt_to_string(r9_1 + arg2, rdx_2, *(&var_18 + 4) + arg6, &var_18, 
        var_38, var_30, arg8);
    
    if (!result)
        return sub_180021fc4(arg2, arg3, arg6, &var_18, 0, arg8);
    
    *arg2 = 0;
    return result;
}

