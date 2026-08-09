
🌐  uint64_t memcmp(char* arg1, int64_t arg2, int64_t arg3)

{
    int64_t* rdx = arg2 - arg1;
    uint64_t rax;
    bool c_1;
    
    if (arg3 >= 8)
    {
        while (arg1 & 7)
        {
            rax = *arg1;
            char temp4_1 = *(arg1 + rdx);
            c_1 = rax < temp4_1;
            
            if (rax != temp4_1)
                goto label_18002dd93;
            
            arg1 = &arg1[1];
            arg3 -= 1;
        }
        
        uint64_t r9_2 = arg3 >> 3;
        
        if (r9_2)
        {
            uint64_t i_2 = r9_2 >> 2;
            
            if (i_2)
            {
                uint64_t i;
                
                do
                {
                    rax = *arg1;
                    
                    if (rax != *(arg1 + rdx))
                        goto label_18002de04;
                    
                    rax = *(arg1 + 8);
                    
                    if (rax != *(arg1 + rdx + 8))
                        goto label_18002de00;
                    
                    rax = *(arg1 + 0x10);
                    
                    if (rax != *(arg1 + rdx + 0x10))
                        goto label_18002ddfc;
                    
                    rax = *(arg1 + 0x18);
                    
                    if (rax != *(arg1 + rdx + 0x18))
                    {
                        arg1 = &arg1[8];
                    label_18002ddfc:
                        arg1 = &arg1[8];
                    label_18002de00:
                        arg1 = &arg1[8];
                    label_18002de04:
                        uint64_t rcx = *(rdx + arg1);
                        uint64_t rax_4 = _bswap(rax);
🚫🚫                        int32_t rax_5 = rax_4 - rax_4;
                        bool c_4 = /* bool c_4 = unimplemented  {sbb eax, eax} */;
                        return rax_5 + 1;
                    }
                    
                    arg1 = &arg1[0x20];
                    i = i_2;
                    i_2 -= 1;
                } while (i != 1);
                arg3 &= 0x1f;
            }
            
            uint64_t i_3 = arg3 >> 3;
            
            if (i_3)
            {
                uint64_t i_1;
                
                do
                {
                    rax = *arg1;
                    
                    if (rax != *(arg1 + rdx))
                        goto label_18002de04;
                    
                    arg1 = &arg1[8];
                    i_1 = i_3;
                    i_3 -= 1;
                } while (i_1 != 1);
                arg3 &= 7;
            }
        }
    }
    
    if (!arg3)
        return 0;
    
    while (true)
    {
        rax = *arg1;
        char temp0_1 = *(arg1 + rdx);
        c_1 = rax < temp0_1;
        
        if (rax != temp0_1)
            break;
        
        arg1 = &arg1[1];
        int64_t temp3_1 = arg3;
        arg3 -= 1;
        
        if (temp3_1 == 1)
            return 0;
    }
    
🚫🚫label_18002dd93:
    bool c_2 = /* bool c_2 = unimplemented  {sbb eax, eax} */;
    return rax - rax + 1;
}

