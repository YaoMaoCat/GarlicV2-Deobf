
  char* sub_180002cd0()

{
    void var_58;
    int64_t rax_1 = __security_cookie ^ &var_58;
    int128_t var_38;
    int128_t* rax_2 = sub_180002fd0(&var_38);
    char* result = &data_180046008;
    
    if (&data_180046008 == rax_2)
        goto label_180002d85;
    
    int64_t rdx_1 = data_180046020;
    
    if (rdx_1 > 0xf)
    {
        void* rcx_1 = *data_180046008;
        
        if (rdx_1 + 1 >= 0x1000)
        {
            void* rax_3 = *(rcx_1 - 8);
            
            if (rcx_1 - rax_3 - 8 > 0x1f)
                trap(0xd);
            
            rcx_1 = rax_3;
        }
        
        j_sub_180021340(rcx_1);
    }
    
    data_180046020 = 0xf;
    result = nullptr;
    data_180046018 = 0;
    data_180046008 = 0;
    *data_180046008 = *rax_2;
    *data_180046018 = rax_2[1];
    rax_2[1] = 0;
    *(rax_2 + 0x18) = 0xf;
    *rax_2 = 0;
label_180002d85:
    int64_t var_20;
    
    if (var_20 > 0xf)
    {
        void* rcx_4 = var_38;
        
        if (var_20 + 1 >= 0x1000)
        {
            void* rax_4 = *(rcx_4 - 8);
            
            if (rcx_4 - rax_4 - 8 > 0x1f)
                trap(0xd);
            
            rcx_4 = rax_4;
        }
        
        result = j_sub_180021340(rcx_4);
    }
    
    __security_check_cookie(rax_1 ^ &var_58);
    return result;
}

