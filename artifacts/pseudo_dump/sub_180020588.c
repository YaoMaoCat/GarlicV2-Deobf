
  int64_t sub_180020588(int64_t* arg1)

{
    int64_t rdx = **arg1;
    
    if (rdx)
    {
        uint64_t __security_cookie_4 = __security_cookie;
        char rcx_1 = __security_cookie_4 & 0x3f;
        int64_t rsi_3 = RORQ(__security_cookie_4 ^ *rdx, rcx_1);
        int64_t r9_3 = RORQ(__security_cookie_4 ^ *(rdx + 8), rcx_1);
        int64_t rbx_3 = RORQ(__security_cookie_4 ^ *(rdx + 0x10), rcx_1);
        
        if (r9_3 != rbx_3)
        {
        label_1800206b3:
            *r9_3 = RORQ(*arg1[1], 0x40 - (__security_cookie_4 & 0x3f)) ^ __security_cookie_4;
            uint64_t __security_cookie_1 = __security_cookie;
            ***arg1 = RORQ(rsi_3, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
            uint64_t __security_cookie_2 = __security_cookie;
            *(**arg1 + 8) =
                RORQ(r9_3 + 8, 0x40 - (__security_cookie_2 & 0x3f)) ^ __security_cookie_2;
            uint64_t __security_cookie_3 = __security_cookie;
            *(**arg1 + 0x10) =
                RORQ(rbx_3, 0x40 - (__security_cookie_3 & 0x3f)) ^ __security_cookie_3;
            return 0;
        }
        
        int64_t rbx_5 = (rbx_3 - rsi_3) >> 3;
        int64_t rdi_1 = rbx_5;
        
        if (rbx_5 > 0x200)
            rdi_1 = 0x200;
        
        int64_t rdi_2 = rdi_1 + rbx_5;
        
        if (rdi_1 == -(rbx_5))
            rdi_2 = 0x20;
        
        int64_t r14_1;
        
        if (rdi_2 >= rbx_5)
        {
            r14_1 = _recalloc_base(rsi_3, rdi_2, 8);
            _free_base(0);
        }
        
        if (rdi_2 >= rbx_5 && r14_1)
        {
        label_180020652:
            __security_cookie_4 = __security_cookie;
            r9_3 = r14_1 + (rbx_5 << 3);
            rbx_3 = r14_1 + (rdi_2 << 3);
            rsi_3 = r14_1;
            uint64_t rcx_7 = (rbx_3 - r9_3 + 7) >> 3;
            
            if (r9_3 > rbx_3)
                rcx_7 = 0;
            
            if (rcx_7)
            {
                int64_t rcx_8;
                int64_t rdi_4;
                rdi_4 = __memfill_u64(r9_3, __security_cookie_4, rcx_7);
                __security_cookie_4 = __security_cookie;
            }
            
            goto label_1800206b3;
        }
        
        rdi_2 = rbx_5 + 4;
        r14_1 = _recalloc_base(rsi_3, rdi_2, 8);
        _free_base(0);
        
        if (r14_1)
            goto label_180020652;
    }
    
    return 0xffffffff;
}

