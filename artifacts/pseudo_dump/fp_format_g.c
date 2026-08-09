
🌐  int64_t fp_format_g(int64_t* arg1, char* arg2, void* arg3, char* arg4, int64_t arg5, int32_t arg6, char arg7, int32_t arg8, int32_t arg9, int64_t* arg10)

{
    int64_t rcx = *arg1;
    int128_t var_18 = {0};
    int32_t rax_1 = sub_18002784c(rcx, arg6, 0, &var_18, arg4, arg5);
    void* r8;
    r8 = var_18 == 0x2d;
    void* rdx_2 = arg3 - r8;
    int64_t var_30;
    var_30 = arg9;
    int32_t r15_1 = *(&var_18 + 4) - 1;
    char* var_38;
    var_38 = rax_1;
    char* rbx = r8 + arg2;
    
    if (arg3 == -1)
        rdx_2 = arg3;
    
    int32_t result = __acrt_fp_strflt_to_string(rbx, rdx_2, arg6, &var_18, var_38, var_30, arg10);
    
    if (result)
    {
        *arg2 = 0;
        return result;
    }
    
    if (*(&var_18 + 4) - 1 < 0xfffffffc || *(&var_18 + 4) - 1 >= arg6)
    {
        var_38 = arg8;
        return fp_format_e_internal(arg2, arg3, arg6, arg7, var_38, &var_18, 1, arg10);
    }
    
    if (r15_1 < *(&var_18 + 4) - 1)
    {
        int32_t rax_4;
        
        do
        {
            rax_4 = *rbx;
            rbx = &rbx[1];
        } while (rax_4);
        
        rbx[-2] = rax_4;
    }
    
    return sub_180021fc4(arg2, arg3, arg6, &var_18, 1, arg10);
}

