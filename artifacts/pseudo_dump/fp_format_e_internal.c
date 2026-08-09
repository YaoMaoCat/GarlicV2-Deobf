
  int64_t fp_format_e_internal(char* arg1, int64_t arg2, int32_t arg3, char arg4, int32_t arg5, int32_t* arg6, char arg7, int64_t* arg8)

{
    int32_t rax = 0;
    int64_t rbp = arg3;
    int64_t r13;
    r13 = arg4;
    
    if (arg3 > 0)
        rax = rbp;
    
    if (arg2 <= rax + 9)
    {
        arg8[6] = 1;
        *(arg8 + 0x2c) = 0x22;
        _invalid_parameter_internal(0, 0, 0, 0, 0, arg8);
        return 0x22;
    }
    
    if (arg7)
    {
        void* rdx;
        rdx = *arg6 == 0x2d;
        char* rdx_1 = rdx + arg1;
        
        if (arg3 > 0)
        {
            void* r8 = -ffffffffffffffff;
            
            do
                r8 += 1;
             while (*(rdx_1 + r8));
            
            memcpy(&rdx_1[1], rdx_1, r8 + 1);
        }
    }
    
    char* rbx_1 = arg1;
    
    if (*arg6 == 0x2d)
    {
        *arg1 = 0x2d;
        rbx_1 = &arg1[1];
    }
    
    if (rbp > 0)
    {
        int64_t rax_2;
        rax_2 = rbx_1[1];
        *rbx_1 = rax_2;
        rbx_1 = &rbx_1[1];
        
        if (!arg8[5])
            __crt_cached_ptd_host::update_locale_slow(arg8);
        
        int64_t* rcx_3;
        rcx_3 = ***(arg8[3] + 0xf8);
        *rbx_1 = rcx_3;
    }
    
    char* rbx_3 = &rbx_1[rbp + (arg7 ^ 1)];
    int64_t rdx_2 = arg2 + arg1 - rbx_3;
    
    if (arg2 == -1)
        rdx_2 = arg2;
    
    if (sub_180020d70(rbx_3, rdx_2, "e+000"))
    {
        int64_t var_28 = 0;
        _invoke_watson();
        /* no return */
    }
    
    if (r13)
        *rbx_3 = 0x45;
    
    if (**(arg6 + 8) != 0x30)
    {
        int32_t r8_2 = arg6[1];
        int32_t r8_3 = r8_2 - 1;
        
        if (r8_2 - 1 < 0)
        {
            r8_3 = -(r8_3);
            rbx_3[1] = 0x2d;
        }
        
        if (r8_3 >= 0x64)
        {
            int32_t rdx_5 = r8_3 / 0x64;
            rbx_3[2] += rdx_5;
            r8_3 += rdx_5 * 0xffffff9c;
        }
        
        if (r8_3 >= 0xa)
        {
            int32_t rdx_8 = r8_3 / 0xa;
            rbx_3[3] += rdx_8;
            r8_3 += rdx_8 * 0xfffffff6;
        }
        
        rbx_3[4] += r8_3;
    }
    
    if (arg5 == 2 && rbx_3[2] == 0x30)
        memcpy(&rbx_3[2], &rbx_3[3], 3);
    
    return 0;
}

