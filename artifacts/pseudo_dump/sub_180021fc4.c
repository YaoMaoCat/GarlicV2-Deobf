
  int64_t sub_180021fc4(char* arg1, int64_t arg2, int32_t arg3, int32_t* arg4, char arg5, int64_t* arg6)

{
    char* rbx = arg1;
    int64_t rcx = arg4[1];
    int32_t rsi = arg3;
    
    if (arg5 && rcx - 1 == arg3)
    {
        void* rax_2;
        rax_2 = *arg4 == 0x2d;
        *(rcx + rax_2 + rbx - 1) = 0x30;
    }
    
    if (*arg4 == 0x2d)
    {
        *rbx = 0x2d;
        rbx = &rbx[1];
    }
    
    int64_t rax_4 = arg4[1];
    void* rdi = -ffffffffffffffff;
    int32_t temp0 = rax_4;
    char* rbx_1;
    
    if (temp0 > 0)
        rbx_1 = &rbx[rax_4];
    else
    {
        if (temp0 || **(arg4 + 8) != 0x30)
            rax_4 = 0;
        else
            rax_4 = 1;
        
        if (!arg5 || !rax_4)
        {
            void* r8 = -ffffffffffffffff;
            
            do
                r8 += 1;
             while (*(rbx + r8));
            
            memcpy(&rbx[1], rbx, r8 + 1);
        }
        
        *rbx = 0x30;
        rbx_1 = &rbx[1];
    }
    
    if (rsi > 0)
    {
        void* r8_2 = -ffffffffffffffff;
        
        do
            r8_2 += 1;
         while (*(rbx_1 + r8_2));
        
        memcpy(&rbx_1[1], rbx_1, r8_2 + 1);
        
        if (!arg6[5])
            __crt_cached_ptd_host::update_locale_slow(arg6);
        
        int64_t* rcx_4;
        rcx_4 = ***(arg6[3] + 0xf8);
        *rbx_1 = rcx_4;
        int32_t rax_7 = arg4[1];
        
        if (rax_7 < 0)
        {
            int32_t rax_8 = -(rax_7);
            
            if (arg5 || rax_8 < rsi)
                rsi = rax_8;
            
            int64_t rbx_2 = rsi;
            
            do
                rdi += 1;
             while (*(&rbx_1[1] + rdi));
            
            memcpy(&rbx_1[1 + rbx_2], &rbx_1[1], rdi + 1);
            sub_18002de50(&rbx_1[1], 0x30, rbx_2);
        }
    }
    
    return 0;
}

