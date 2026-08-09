
  uint64_t sub_1800211dc(int32_t arg1)

{
    if (arg1 >= 1)
    {
        if (arg1 <= 0xd)
            return *(((arg1 - 1) << 3) + 0x180039bd4);
        
        if (arg1 <= 0x718)
        {
            uint64_t rcx = 0x2d;
            int64_t r10_1 = 0;
            int64_t rdi_1 = 0x2c;
            
            while (true)
            {
                uint64_t r8_2 = rcx >> 1;
                int32_t* rax_3;
                
                if (!r8_2)
                {
                    if (!rcx)
                        break;
                    
                    rax_3 = &data_180039bd0 + (r10_1 << 3);
                    
                    if (arg1 != *rax_3)
                        rax_3 = nullptr;
                }
                else
                {
                    bool cond:1_1 = rcx & 1;
                    rcx = r8_2 - 1;
                    
                    if (cond:1_1)
                        rcx = r8_2;
                    
                    int64_t r11_1 = rcx + r10_1;
                    rax_3 = &data_180039bd0 + (r11_1 << 3);
                    int32_t temp0_1 = *rax_3;
                    
                    if (arg1 != temp0_1)
                    {
                        if (arg1 >= temp0_1)
                        {
                            r10_1 = r11_1 + 1;
                            rcx = r8_2;
                        }
                        
                        int64_t rax_4 = r11_1 - 1;
                        
                        if (arg1 >= temp0_1)
                            rax_4 = rdi_1;
                        
                        rdi_1 = rax_4;
                        
                        if (r10_1 > rax_4)
                            break;
                        
                        continue;
                    }
                }
                
                if (!rax_3)
                    break;
                
                return rax_3[1];
            }
        }
    }
    
    if (arg1 - 0x13 <= 0x11)
        return 0xd;
    
    if (arg1 - 0xbc <= 0xe)
        return 8;
    
    return 0x16;
}

