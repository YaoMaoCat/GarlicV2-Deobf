
  uint64_t sub_18001a190(void* arg1, void* arg2, int64_t arg3)

{
    int64_t rax = *(arg1 + 0x10);
    
    if (rax)
    {
        void* rsi_1 = *(arg2 + 8);
        uint64_t rcx_1 = *(rsi_1 + rax) & 0xf;
        char* r9_2 = rsi_1 + rax - *(rcx_1 + 0x180038880);
        uint32_t rdi_2 = *(r9_2 - 4) >> *(rcx_1 + 0x180038890);
        
        if (rdi_2)
        {
            int32_t r10 = 0;
            int32_t r11 = 0;
            int32_t rdx = -1;
            
            do
            {
                uint64_t rcx_4 = *r9_2 & 0xf;
                char* r9_3 = r9_2 - *(rcx_4 + 0x180038880);
                r11 += *(r9_3 - 4) >> *(rcx_4 + 0x180038890);
                
                if (arg3 < r11 + **(arg2 + 0x10) + rsi_1)
                    break;
                
                r10 += 1;
                uint64_t rcx_7 = *r9_3 & 0xf;
                r9_2 = r9_3 - *(rcx_7 + 0x180038880);
                rdx = (*(r9_2 - 4) >> *(rcx_7 + 0x180038890)) - 1;
            } while (r10 < rdi_2);
            
            if (!r10)
                rdx = -1;
            
            return rdx;
        }
    }
    
    return 0xffffffff;
}

