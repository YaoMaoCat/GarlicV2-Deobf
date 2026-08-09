
  int64_t sub_18002668c(int32_t arg1)

{
    int64_t* r15 = nullptr;
    int32_t arg_10 = 0;
    int64_t r14;
    r14 = 1;
    char arg_8 = 1;
    int64_t* rdi_1;
    
    if (arg1 != 2)
    {
        if (arg1 == 4)
        {
        label_180026713:
            int64_t* rax_1 = sub_18002334c();
            r15 = rax_1;
            
            if (!rax_1)
                return 0xffffffff;
            
            void* rax_3 = *rax_1;
            void* rcx_4 = 0xc0 + rax_3;
            
            while (true)
            {
                if (rax_3 == rcx_4)
                {
                    rax_3 = nullptr;
                    break;
                }
                
                if (*(rax_3 + 4) == arg1)
                    break;
                
                rax_3 += 0x10;
            }
            
            if (!rax_3)
                goto label_18002676a;
            
            rdi_1 = rax_3 + 8;
            r14 = 0;
            arg_8 = 0;
            goto label_1800267a7;
        }
        
        if (arg1 == 6)
            goto label_1800266e3;
        
        if (arg1 == 8 || arg1 == 0xb)
            goto label_180026713;
        
        if (arg1 != 0xf && arg1 != 0x15 && arg1 != 0x16)
        {
        label_18002676a:
            *sub_18002131c() = 0x16;
            _invalid_parameter_noinfo();
            return 0xffffffff;
        }
    }
    
label_1800266e3:
    
    if (arg1 != 2)
    {
        if (arg1 == 6)
            rdi_1 = &data_180047fd0;
        else if (arg1 == 0xf)
            rdi_1 = &data_180047fd8;
        else if (arg1 == 0x15)
            rdi_1 = &data_180047fc8;
        else if (arg1 == 0x16)
            rdi_1 = &data_180047fd0;
        else
            rdi_1 = nullptr;
        
        goto label_1800267a7;
    }
    
    rdi_1 = &data_180047fc0;
label_1800267a7:
    int64_t r13_1 = 0;
    
    if (r14)
        sub_1800239bc(3);
    
    int64_t rsi_1 = *rdi_1;
    
    if (r14)
    {
        uint64_t __security_cookie_1 = __security_cookie;
        rsi_1 = RORQ(rsi_1 ^ __security_cookie_1, __security_cookie_1 & 0x3f);
    }
    
    if (rsi_1 != 1)
    {
        if (!rsi_1)
        {
            if (r14)
                sub_180023a10(rsi_1 + 3);
            
            sub_18001fdf0(3);
            breakpoint();
        }
        
        if (arg1 > 0xb || !TEST_BITD(0x910, arg1))
            goto label_180026826;
        
        r13_1 = r15[1];
        int64_t var_38_1 = r13_1;
        r15[1] = 0;
        
        if (arg1 != 8)
            *rdi_1 = __security_cookie;
        else
        {
            int32_t rax_6 = __vcrt_getptd()[2];
            arg_10 = rax_6;
            int32_t var_48_1 = rax_6;
            __vcrt_getptd()[2] = 0x8c;
        label_180026826:
            
            if (arg1 != 8)
                *rdi_1 = __security_cookie;
            else
            {
                void* rax_8 = 0x30 + *r15;
                void* rcx_7 = 0x90 + rax_8;
                
                while (true)
                {
                    void* var_40_1 = rax_8;
                    
                    if (rax_8 == rcx_7)
                        break;
                    
                    *(rax_8 + 8) = 0;
                    rax_8 += 0x10;
                }
            }
        }
    }
    
    if (r14)
        sub_180023a10(3);
    
    if (rsi_1 != 1)
    {
        if (arg1 != 8)
            sub_18002d680();
        else
        {
            __vcrt_getptd()[2];
            sub_18002d680();
        }
        
        if (arg1 <= 0xb && TEST_BITD(0x910, arg1))
        {
            r15[1] = r13_1;
            
            if (arg1 == 8)
                __vcrt_getptd()[2] = arg_10;
        }
    }
    
    return 0;
}

