
  int64_t sub_1800229c8(uint64_t arg1, char* arg2, int64_t arg3, uint32_t* arg4, int64_t arg5 @ r14, void* arg6)

{
    int64_t var_30 = arg5;
    void var_78;
    int64_t rax_1 = __security_cookie ^ &var_78;
    uint32_t* rbx = &data_180047808;
    char* rdi = &data_180034db8;
    
    if (arg4)
        rbx = arg4;
    
    uint64_t i_1 = 1;
    
    if (arg2)
        i_1 = arg3;
    
    if (arg2)
        rdi = arg2;
    
    uint32_t* r14_1 = (arg5 - arg5) & arg1;
    int64_t result;
    
    if (!i_1)
        result = -2;
    else
    {
        uint32_t rdx_3;
        
        if (*(rbx + 6))
        {
            arg3 = rbx[1];
            rdx_3 = *rbx;
            arg4 = *(rbx + 6);
            
            if (arg3 - 2 <= 2 && arg4 >= 1 && arg4 < arg3)
                goto label_180022ab5;
            
        labelid_8:
            result = __crt_mbstring::return_illegal_sequence(rbx, arg6);
        }
        else
        {
            arg3 = sub_180022990(rdi);
            uint32_t rax_5 = *rdi;
            rdi = &rdi[1];
            
            if (arg3 <= 1)
            {
                if (r14_1)
                    *r14_1 = rax_5;
                
                result = arg3;
            }
            else if (arg3 - 2 > 2)
            {
            label_180022b64:
                result = __crt_mbstring::return_illegal_sequence(rbx, arg6);
            }
            else
            {
                arg1 = 7 - arg3;
                arg4 = arg3;
                rdx_3 = ((1 << arg1) - 1) & rax_5;
            label_180022ab5:
                uint64_t r11_1 = arg4;
                uint64_t i = r11_1;
                
                if (r11_1 >= i_1)
                    i = i_1;
                
                while (rdi - arg2 < i)
                {
                    uint32_t rcx_2 = *rdi;
                    rdi = &rdi[1];
                    void* rax_7;
                    rax_7 = rcx_2;
                    rax_7 &= 0xc0;
                    
                    if (rax_7 != 0x80)
                        goto label_180022b64_2;
                    
                    arg1 = rcx_2 & 0x3f;
                    rdx_3 = arg1 | rdx_3 << 6;
                }
                
                if (i < r11_1)
                {
                    arg4 -= i;
                    rbx[1] = arg3;
                    *(rbx + 6) = arg4;
                    *rbx = rdx_3;
                    result = -2;
                }
                else if (rdx_3 - 0xd800 <= 0x7ff || rdx_3 >= 0x110000)
                {
                label_180022b64_1:
                    result = __crt_mbstring::return_illegal_sequence(rbx, arg6);
                }
                else
                {
                    int32_t var_58_1 = 0x80;
                    int32_t var_54_1 = 0x800;
                    int32_t var_50_1 = 0x10000;
                    int32_t var_60[0x2];
                    
                    if (rdx_3 < var_60[arg3])
                    {
                    label_180022b64_2:
                        result = __crt_mbstring::return_illegal_sequence(rbx, arg6);
                    }
                    else
                    {
                        if (r14_1)
                            *r14_1 = rdx_3;
                        
                        result = __crt_mbstring::reset_and_return((arg1 - arg1) & r11_1, rbx);
                    }
                }
            }
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_78);
    return result;
}

