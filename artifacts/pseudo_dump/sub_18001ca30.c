
  void* sub_18001ca30(int64_t* arg1, int64_t* arg2, uint64_t arg3, int32_t arg4, int512_t arg5 @ zmm1)

{
    void var_138;
    int64_t rax_1 = __security_cookie ^ &var_138;
    int64_t* r15 = arg2;
    int64_t* var_a0 = arg1;
    int64_t* var_98 = arg2;
    int32_t var_d8 = arg4;
    int64_t rax_3 = _GetImageBase();
    int32_t r12 = sub_18001ce10(arg1, r15, arg3);
    void* rax_5;
    int512_t zmm0;
    rax_5 = sub_180019c40();
    *(rax_5 + 0x30) += 1;
    int32_t* r9 = nullptr;
    int32_t* var_d0 = nullptr;
    int32_t* var_60_1;
    __builtin_memset(&var_60_1, 0, 0x18);
    zmm0 = {0};
    int64_t rax_6 = *(arg3 + 8);
    uint32_t rax_8;
    uint32_t r13_1;
    
    if (!rax_6)
    {
        r13_1 = 0;
        rax_8 = 0;
    }
    else
    {
        char* r9_2 = r15[1] + rax_6;
        uint64_t rcx_2 = *r9_2 & 0xf;
        r9 = r9_2 - *(rcx_2 + 0x180038880);
        var_d0 = r9;
        r13_1 = r9[-1] >> *(rcx_2 + 0x180038890);
        var_60_1 = r9;
        rax_8 = r13_1;
    }
    
    uint32_t var_68 = r13_1;
    uint32_t* rcx_4 = &var_68;
    uint32_t* var_f8 = &var_68;
    uint32_t* var_88 = &var_68;
    int64_t var_a8 = rax_3;
    int32_t* rsi_1 = r9 - 1;
    int32_t* r14_1 = rsi_1;
    int32_t* r8_1 = r9;
    uint64_t rbx;
    rbx = 0;
    char r11 = 0;
    int32_t r10 = 0;
    
    if (rax_8 > 0)
    {
        do
        {
            rbx = rbx;
            
            if (r10 == r12)
                rbx = 1;
            
            int32_t* rax_9 = r8_1;
            
            if (r10 != r12)
                rax_9 = rsi_1;
            
            rsi_1 = rax_9;
            
            if (r10 == arg4)
                r11 = 1;
            
            int32_t* rax_10 = r8_1;
            
            if (r10 != arg4)
                rax_10 = r14_1;
            
            r14_1 = rax_10;
            
            if (rbx && r11)
                break;
            
            uint64_t rcx_6 = *r8_1 & 0xf;
            r8_1 -= *(rcx_6 + 0x180038880);
            int32_t* rdx_1 = r8_1;
            uint32_t rax_13 = r8_1[-1] >> *(rcx_6 + 0x180038890);
            int32_t rcx_9 = rax_13 & 3;
            int128_t var_58_1;
            *(&var_58_1 + 4) = rcx_9;
            var_58_1 = rax_13 >> 2;
            
            if (rcx_9 - 1 <= 1)
            {
                *(&var_58_1 + 8) = *r8_1;
                uint64_t rcx_11 = r8_1[1] & 0xf;
                r8_1 = &r8_1[1] - *(rcx_11 + 0x180038880);
                *(&var_58_1 + 0xc) = r8_1[-1] >> *(rcx_11 + 0x180038890);
            }
            else if (rcx_9 == 3)
            {
                r8_1 = &r8_1[1];
                *(&var_58_1 + 8) = *rdx_1;
            }
            
            r10 += 1;
        } while (r10 < r13_1);
        
        r9 = var_d0;
        r15 = arg2;
        rcx_4 = var_f8;
    }
    
    int32_t* var_f0 = rsi_1;
    int32_t* var_80 = r14_1;
    int32_t* var_90 = r14_1;
    
    while (true)
    {
        uint32_t* var_d0_1 = &var_68;
        int32_t* var_c8_1 = r9;
        
        if (rsi_1 < r9)
            break;
        
        if (rsi_1 <= r14_1)
            break;
        
        FH4::UWMap4::ReadEntry(rcx_4, &var_f0);
        var_f0 = rsi_1;
        uint32_t* rbx_1 = var_f8;
        int32_t r13_2 = rbx_1[5];
        int32_t rdi_1 = rbx_1[6];
        int64_t* var_e0;
        var_e0 = rbx_1[7];
        zmm0 = var_f8;
        int128_t var_78 = zmm0;
        FH4::UWMap4::ReadEntry(rbx_1, &var_f0);
        rsi_1 -= rbx_1[4];
        var_f0 = rsi_1;
        int32_t rax_23 = sub_18001d120(&var_88, arg4, &var_78, r12, &var_f8);
        r12 = rax_23;
        var_d0_1 = rax_23;
        int32_t var_e8_1 = 0;
        int32_t r9_4 = 0;
        
        if (r13_2)
            r9_4 = rdi_1;
        
        int32_t var_e8_2 = r9_4;
        
        if (r9_4)
        {
            r15[9] = rax_23 + 2;
            
            if (r13_2 - 1 <= 1)
            {
                int64_t* r8_6 = var_e0 + *arg1;
                
                if (r13_2 == 2)
                    r8_6 = *r8_6;
                
                _CallSettingFrameEncoded(r15[1] + r9_4, arg5, r8_6, 0x103);
            }
            else
                _CallSettingFrame(r15[1] + r9_4, arg1, zmm0);
            
            _SetImageBase(rax_3);
        }
        
        r9 = var_60_1;
        rcx_4 = var_f8;
    }
    
    void* result = sub_180019c40();
    
    if (*(result + 0x30) > 0)
    {
        result = sub_180019c40();
        *(result + 0x30) -= 1;
    }
    
    __security_check_cookie(rax_1 ^ &var_138);
    return result;
}

