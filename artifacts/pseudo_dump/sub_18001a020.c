
  uint64_t sub_18001a020(void* arg1, int64_t* arg2)

{
    int64_t rax = *(arg1 + 0x10);
    
    if (!rax)
        return 0xffffffff;
    
    void* rdi = arg2[1];
    uint64_t rcx_1 = *(rdi + rax) & 0xf;
    char* rdx_1 = rdi + rax - *(rcx_1 + 0x180038880);
    uint32_t rbx_1 = *(rdx_1 - 4) >> *(rcx_1 + 0x180038890);
    
    if (rbx_1)
    {
        int32_t r9_1 = 0;
        int32_t r10_1 = 0;
        int32_t r8_1 = -1;
        
        do
        {
            uint64_t rcx_4 = *rdx_1 & 0xf;
            char* rdx_2 = rdx_1 - *(rcx_4 + 0x180038880);
            r10_1 += *(rdx_2 - 4) >> *(rcx_4 + 0x180038890);
            
            if (*arg2 < r10_1 + *arg2[2] + rdi)
                break;
            
            r9_1 += 1;
            uint64_t rcx_7 = *rdx_2 & 0xf;
            rdx_1 = rdx_2 - *(rcx_7 + 0x180038880);
            r8_1 = (*(rdx_1 - 4) >> *(rcx_7 + 0x180038890)) - 1;
        } while (r9_1 < rbx_1);
        
        if (r9_1)
            return r8_1;
    }
    
    return 0xffffffff;
}

