
  int64_t sub_180020738(int64_t* arg1)

{
    int64_t rdx = **arg1;
    
    if (!rdx)
        return 0xffffffff;
    
    uint64_t __security_cookie_1 = __security_cookie;
    char rcx_1 = __security_cookie_1 & 0x3f;
    int64_t rdi_3 = RORQ(__security_cookie_1 ^ *rdx, rcx_1);
    int64_t rbx_3 = RORQ(__security_cookie_1 ^ *(rdx + 8), rcx_1);
    
    if (rdi_3 - 1 <= -3)
    {
        uint64_t __security_cookie_2 = __security_cookie_1;
        int64_t r15_1 = rdi_3;
        int64_t rbp_1 = rbx_3;
        
        while (true)
        {
            rbx_3 -= 8;
            
            if (rbx_3 < rdi_3)
                break;
            
            if (*rbx_3 != __security_cookie_2)
            {
                *rbx_3 = __security_cookie_2;
                sub_18002d680();
                __security_cookie_1 = __security_cookie;
                char rcx_3 = __security_cookie_1 & 0x3f;
                int64_t rdx_1 = **arg1;
                int64_t r9_3 = RORQ(__security_cookie_1 ^ *rdx_1, rcx_3);
                int64_t rax_9 = RORQ(__security_cookie_1 ^ *(rdx_1 + 8), rcx_3);
                
                if (r9_3 == r15_1 && rax_9 == rbp_1)
                    continue;
                
                r15_1 = r9_3;
                rdi_3 = r9_3;
                rbp_1 = rax_9;
                rbx_3 = rax_9;
            }
        }
        
        if (rdi_3 != -1)
        {
            _free_base(rdi_3);
            __security_cookie_1 = __security_cookie;
        }
        
        ***arg1 = __security_cookie_1;
        *(**arg1 + 8) = __security_cookie_1;
        *(**arg1 + 0x10) = __security_cookie_1;
    }
    
    return 0;
}

