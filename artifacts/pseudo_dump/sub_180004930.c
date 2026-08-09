
  int128_t* sub_180004930(int128_t* arg1, int128_t* arg2, int128_t* arg3, int16_t arg4)

{
    void var_78;
    int64_t rax_1 = __security_cookie ^ &var_78;
    int64_t* rsi = arg2;
    int128_t* var_50 = arg1;
    int128_t* var_48 = arg2;
    int128_t* var_40 = arg3;
    __builtin_memset(arg1, 0, 0x20);
    *arg1 = *arg2;
    arg1[1] = arg2[1];
    arg2[1] = 0;
    *(arg2 + 0x18) = 0xf;
    *arg2 = 0;
    __builtin_memset(&arg1[2], 0, 0x20);
    arg1[2] = *arg3;
    arg1[3] = arg3[1];
    arg3[1] = 0;
    *(arg3 + 0x18) = 0xf;
    *arg3 = 0;
    arg1[4] = arg4;
    *(arg1 + 0x42) = 0x21;
    __builtin_memset(arg1 + 0x48, 0, 0x28);
    int64_t* rax_2 = sub_180016420(0x48);
    *rax_2 = rax_2;
    rax_2[1] = rax_2;
    rax_2[2] = rax_2;
    rax_2[3] = 0x101;
    arg1[6] = rax_2;
    arg1[7] = 0;
    *(arg1 + 0x78) = 0;
    int64_t* rax_3 = sub_180016420(0x20);
    *rax_3 = rax_3;
    rax_3[1] = rax_3;
    rax_3[2] = rax_3;
    rax_3[3] = 0x101;
    arg1[7] = rax_3;
    arg1[8] = 0;
    *(arg1 + 0x88) = 0;
    int64_t* rax_4 = sub_180016420(0x30);
    *rax_4 = rax_4;
    rax_4[1] = rax_4;
    rax_4[2] = rax_4;
    rax_4[3] = 0x101;
    arg1[8] = rax_4;
    arg1[9] = 0;
    *(arg1 + 0x98) = 0;
    int64_t* rax_5 = sub_180016420(0x30);
    *rax_5 = rax_5;
    rax_5[1] = rax_5;
    rax_5[2] = rax_5;
    rax_5[3] = 0x101;
    arg1[9] = rax_5;
    __builtin_memset(&arg1[0xa], 0, 0x1a);
    int64_t r8 = rsi[3];
    
    if (r8 > 0xf)
    {
        void* rax_6 = *rsi;
        void* rcx;
        
        if (r8 + 1 < 0x1000)
            rcx = rax_6;
        else
        {
            rcx = *(rax_6 - 8);
            
            if (rax_6 - rcx - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx);
    }
    
    rsi[2] = 0;
    rsi[3] = 0xf;
    *rsi = 0;
    int64_t r8_1 = *(arg3 + 0x18);
    
    if (r8_1 > 0xf)
    {
        void* rax_9 = *arg3;
        void* rcx_2;
        
        if (r8_1 + 1 < 0x1000)
            rcx_2 = rax_9;
        else
        {
            rcx_2 = *(rax_9 - 8);
            
            if (rax_9 - rcx_2 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_2);
    }
    
    arg3[1] = 0;
    *(arg3 + 0x18) = 0xf;
    *arg3 = 0;
    __security_check_cookie(rax_1 ^ &var_78);
    return arg1;
}

