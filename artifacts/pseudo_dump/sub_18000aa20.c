
  char* sub_18000aa20(char* arg1, uint32_t arg2)

{
    void var_58;
    int64_t rax_1 = __security_cookie ^ &var_58;
    char* var_30 = arg1;
    char var_13;
    char* rcx = &var_13;
    int32_t* rdx_1;
    
    if (arg2 >= 0)
        rdx_1 = sub_1800073a0(rcx, arg2);
    else
    {
        char* rax_2 = sub_1800073a0(rcx, -(arg2));
        rax_2[-1] = 0x2d;
        rdx_1 = &rax_2[-1];
    }
    
    sub_180006aa0(arg1, rdx_1, &var_13);
    __security_check_cookie(rax_1 ^ &var_58);
    return arg1;
}

