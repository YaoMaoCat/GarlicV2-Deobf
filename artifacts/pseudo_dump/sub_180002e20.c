
  int128_t* sub_180002e20(int128_t* arg1, int32_t arg2, int32_t arg3)

{
    __chkstk(0x13e0);
    void var_13f8;
    int64_t rax_1 = __security_cookie ^ &var_13f8;
    int32_t rbx = arg3;
    int128_t* var_13c8 = arg1;
    int32_t var_13d0 = 0;
    int32_t rbp = 1;
    
    if (arg2 >= 1)
        rbp = arg2;
    
    if (arg3 < rbp)
        rbx = rbp;
    
    void var_13b8;
    int64_t rdx = sub_180003ac0(&var_13b8);
    void* var_13d8 = &var_13b8;
    int32_t rbp_1 = rbp ^ 0x80000000;
    int32_t rbx_2 = (rbx ^ 0x80000000) - rbp_1;
    void** rcx_1 = &var_13d8;
    int32_t rcx_2;
    
    if (rbx_2 != 0xffffffff)
    {
        uint64_t rbx_3 = rbx_2 + 1;
        int64_t rax_5;
        int32_t rdx_1;
        rdx_1 = HIGHQ(rbx_3 * sub_180003530(rcx_1, rdx));
        rax_5 = LOWQ(rbx_3 * sub_180003530(rcx_1, rdx));
        rcx_2 = rdx_1;
        
        if (rax_5 < rbx_3)
        {
            uint64_t rdx_3 = COMBINE(0, -(rbx_3)) % rbx_3;
            uint64_t rdi_1 = rdx_3;
            
            if (rax_5 < rdx_3)
            {
                int64_t rax_11;
                
                do
                {
                    rdx_3 = HIGHQ(rbx_3 * sub_180003530(&var_13d8, rdx_3));
                    rax_11 = LOWQ(rbx_3 * sub_180003530(&var_13d8, rdx_3));
                    rcx_2 = rdx_3;
                } while (rax_11 < rdi_1);
            }
        }
    }
    else
        rcx_2 = sub_180003530(rcx_1, rdx);
    
    int32_t i_1 = (rcx_2 + rbp_1) ^ 0x80000000;
    *arg1 = {0};
    arg1[1] = 0;
    *(arg1 + 0x18) = 0xf;
    *arg1 = 0;
    int32_t var_13d0_1 = 1;
    int64_t rdx_4 = sub_180003d30(arg1, 0x30);
    
    if (i_1 > 0)
    {
        int32_t i;
        
        do
        {
            var_13d8 = &var_13b8;
            int64_t rax_13;
            int64_t rdx_5;
            rdx_5 = HIGHQ(0x60 * sub_180003530(&var_13d8, rdx_4));
            rax_13 = LOWQ(0x60 * sub_180003530(&var_13d8, rdx_4));
            
            if (rax_13 < 0x60 && rax_13 < 0x40)
            {
                int64_t rax_15;
                
                do
                    rdx_5 = HIGHQ(0x60 * sub_180003530(&var_13d8, rdx_5));
                    rax_15 = LOWQ(0x60 * sub_180003530(&var_13d8, rdx_5));
                 while (!(rax_15 & 0xffffffffffffffc0));
            }
            
            char* rbx_4 = (&data_180030d20)[rdx_5];
            rdx_4 = sub_1800026b0(arg1, rbx_4, strlen(rbx_4));
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
    }
    
    __security_check_cookie(rax_1 ^ &var_13f8);
    return arg1;
}

