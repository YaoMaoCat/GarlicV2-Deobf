
  int128_t* sub_180003410(int128_t* arg1, void** arg2, void** arg3)

{
    void var_98;
    int64_t rax_1 = __security_cookie ^ &var_98;
    void** rsi = arg3;
    int128_t* var_60 = arg1;
    
    if (arg2[2])
    {
        int64_t* var_58;
        sub_1800029d0(&var_58, arg2);
        int64_t* rax_2 = &var_58;
        int64_t* rdx_1 = var_58;
        int64_t var_40;
        int64_t rcx_1 = var_40;
        
        if (rcx_1 > 0xf)
            rax_2 = rdx_1;
        
        void* var_48;
        void* rbp_1 = var_48;
        
        if (*(rax_2 + rbp_1 - 1) != 0x2f)
        {
            rdx_1 = 0x2f;
            sub_180003b90(&var_58, rdx_1);
            rcx_1 = var_40;
            rbp_1 = var_48;
            rdx_1 = var_58;
        }
        
        void* r14_1 = rsi[2];
        
        if (rsi[3] > 0xf)
            rsi = *rsi;
        
        if (r14_1 > rcx_1 - rbp_1)
            sub_180002840(&var_58, r14_1, 0, rsi, r14_1);
        else
        {
            var_48 = r14_1 + rbp_1;
            int64_t* rbx_1 = &var_58;
            
            if (rcx_1 > 0xf)
                rbx_1 = rdx_1;
            
            memcpy(rbx_1 + rbp_1, rsi, r14_1);
            *(r14_1 + rbx_1 + rbp_1) = 0;
        }
        
        arg1[1] = 0;
        *(arg1 + 0x18) = 0;
        *arg1 = var_58;
        arg1[1] = var_48;
    }
    else
        sub_1800029d0(arg1, arg3);
    
    __security_check_cookie(rax_1 ^ &var_98);
    return arg1;
}

