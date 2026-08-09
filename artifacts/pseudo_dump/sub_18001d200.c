
  uint64_t sub_18001d200(void* arg1, int32_t arg2)

{
    *(arg1 + 8) = *(arg1 + 0x10);
    uint64_t result = sub_18001c630(arg1);
    int32_t r11 = 0;
    
    if (arg2)
    {
        do
        {
            *(arg1 + 0x18) = 0;
            *(arg1 + 0x1c) = 0;
            *(arg1 + 0x24) = 0;
            *(arg1 + 0x30) = {0};
            char* rax_1 = *(arg1 + 8);
            char r8_1 = *rax_1;
            char* rdx = &rax_1[1];
            *(arg1 + 0x18) = r8_1;
            *(arg1 + 8) = rdx;
            
            if (r8_1 & 1)
            {
                uint64_t rcx_1 = *rdx & 0xf;
                rdx -= *(rcx_1 + 0x180038880);
                *(arg1 + 0x1c) = *(rdx - 4) >> *(rcx_1 + 0x180038890);
                *(arg1 + 8) = rdx;
            }
            
            if (r8_1 & 2)
            {
                int32_t rax_5 = *rdx;
                rdx = &rdx[4];
                *(arg1 + 8) = rdx;
                *(arg1 + 0x20) = rax_5;
            }
            
            if (r8_1 & 4)
            {
                uint64_t rcx_4 = *rdx & 0xf;
                rdx -= *(rcx_4 + 0x180038880);
                *(arg1 + 0x24) = *(rdx - 4) >> *(rcx_4 + 0x180038890);
                *(arg1 + 8) = rdx;
            }
            
            *(arg1 + 0x28) = *rdx;
            result = r8_1 & 0x30;
            *(arg1 + 8) = &rdx[4];
            
            if (!(r8_1 & 8))
            {
                if (result == 0x10)
                {
                    uint64_t rcx_9 = rdx[4] & 0xf;
                    void* r10_2 = &rdx[4] - *(rcx_9 + 0x180038880);
                    result = *(arg1 + 0x48) + (*(r10_2 - 4) >> *(rcx_9 + 0x180038890));
                    *(arg1 + 8) = r10_2;
                    *(arg1 + 0x30) = result;
                }
                else if (result == 0x20)
                {
                    int32_t r8_2 = *(arg1 + 0x48);
                    uint64_t rcx_12 = rdx[4] & 0xf;
                    int64_t r9_1 = *(rcx_12 + 0x180038880);
                    char* rdx_5 = &rdx[4] - r9_1;
                    uint32_t rax_14 = *(rdx_5 - 4) >> *(rcx_12 + 0x180038890);
                    *(arg1 + 8) = rdx_5;
                    *(arg1 + 0x30) = r8_2 + rax_14;
                    uint64_t rcx_16 = *rdx_5 & 0xf;
                    void* r10_4 = &rdx[4] - *(rcx_16 + 0x180038880) - r9_1;
                    result = *(r10_4 - 4) >> *(rcx_16 + 0x180038890);
                    *(arg1 + 8) = r10_4;
                    *(arg1 + 0x38) = r8_2 + result;
                }
            }
            else if (result == 0x10)
            {
                int64_t rcx_6 = *(rdx + 4);
                result = &rdx[8];
                *(arg1 + 8) = result;
                *(arg1 + 0x30) = rcx_6;
            }
            else if (result == 0x20)
            {
                int64_t rax_10 = *(rdx + 4);
                *(arg1 + 8) = &rdx[8];
                *(arg1 + 0x30) = rax_10;
                result = &rdx[0xc];
                int64_t rcx_7 = *(rdx + 8);
                *(arg1 + 8) = result;
                *(arg1 + 0x38) = rcx_7;
            }
            
            r11 += 1;
        } while (r11 < arg2);
    }
    
    return result;
}

