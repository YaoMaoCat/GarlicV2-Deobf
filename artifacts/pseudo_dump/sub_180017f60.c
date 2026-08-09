
  struct std::runtime_error::std::_System_error::VTable** sub_180017f60(struct std::runtime_error::std::_System_error::VTable** arg1, int32_t arg2, int64_t arg3, char* arg4)

{
    void var_68;
    int64_t rax_1 = __security_cookie ^ &var_68;
    struct std::runtime_error::std::_System_error::VTable** var_48 = arg1;
    int128_t var_38;
    __builtin_memset(&var_38, 0, 0x20);
    void* r8 = -ffffffffffffffff;
    
    do
        r8 += 1;
     while (*(arg4 + r8));
    
    sub_180002740(&var_38, arg4, r8);
    var_48 = arg2;
    *(&var_48 + 4) = *(&var_48 + 4);
    int64_t var_40 = arg3;
    sub_180017cb0(arg1, &var_48, &var_38);
    void* var_20;
    
    if (var_20 > 0xf)
    {
        void* rax_3 = var_38;
        void* rcx_3;
        
        if (var_20 + 1 < 0x1000)
            rcx_3 = rax_3;
        else
        {
            rcx_3 = *(rax_3 - 8);
            
            if (rax_3 - rcx_3 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_3);
    }
    
    *arg1 = &std::system_error::`vftable'{for `std::_System_error'};
    __security_check_cookie(rax_1 ^ &var_68);
    return arg1;
}

