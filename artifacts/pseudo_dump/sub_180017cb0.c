
  struct std::runtime_error::std::_System_error::VTable** sub_180017cb0(struct std::runtime_error::std::_System_error::VTable** arg1, int128_t* arg2, void** arg3)

{
    void var_c8;
    int64_t rax_1 = __security_cookie ^ &var_c8;
    int128_t* var_a8 = arg1;
    void var_98;
    int128_t* rax_2 = sub_1800029d0(&var_98, arg3);
    var_a8 = rax_2;
    int64_t* r14 = *(arg2 + 8);
    
    if (rax_2[1])
        sub_1800026b0(rax_2, &data_180037970, 2);
    
    int64_t* var_58;
    (*(*r14 + 0x10))(r14, &var_58, *arg2);
    int64_t* rdx_2 = &var_58;
    int64_t var_40;
    
    if (var_40 > 0xf)
        rdx_2 = var_58;
    
    void* var_48;
    sub_1800026b0(rax_2, rdx_2, var_48);
    j_sub_180003a30(&var_58);
    int128_t var_78 = {0};
    int64_t var_68 = 0;
    int64_t var_60 = 0;
    
    if (*(rax_2 + 0x18) <= 0xf)
        memcpy(&var_78, rax_2, rax_2[1] + 1);
    else
        var_78 = *rax_2;
    
    void* rax_6 = *(rax_2 + 0x18);
    rax_2[1];
    *(rax_2 + 0x18) = 0xf;
    *rax_2 = 0;
    rax_2[1] = 0;
    *(rax_2 + 0x18) = 0xf;
    *rax_2 = 0;
    int128_t* rax_8 = &var_78;
    
    if (rax_6 > 0xf)
        rax_8 = var_78;
    
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    var_a8 = rax_8;
    char var_a0 = 1;
    sub_180019440(&var_a8, &arg1[1]);
    *arg1 = &std::runtime_error::`vftable'{for `std::exception'};
    
    if (rax_6 > 0xf)
    {
        void* rax_9 = var_78;
        void* rcx_8;
        
        if (rax_6 + 1 < 0x1000)
            rcx_8 = rax_9;
        else
        {
            rcx_8 = *(rax_9 - 8);
            
            if (rax_9 - rcx_8 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_8);
    }
    
    *arg1 = &std::_System_error::`vftable'{for `std::runtime_error'};
    *(arg1 + 0x18) = *arg2;
    __security_check_cookie(rax_1 ^ &var_c8);
    return arg1;
}

