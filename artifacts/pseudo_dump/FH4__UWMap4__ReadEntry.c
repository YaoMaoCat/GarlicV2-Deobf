
  uint32_t FH4::UWMap4::ReadEntry(void* arg1, int64_t* arg2)

{
    char* r8_1 = *arg2;
    uint64_t rcx_1 = *r8_1 & 0xf;
    void* r8 = r8_1 - *(rcx_1 + 0x180038880);
    uint32_t rax_2 = *(r8 - 4) >> *(rcx_1 + 0x180038890);
    *arg2 = r8;
    int32_t rcx_4 = rax_2 & 3;
    *(arg1 + 0x10) = rax_2 >> 2;
    *(arg1 + 0x14) = rcx_4;
    uint32_t result = rcx_4 - 1;
    
    if (result <= 1)
    {
        int32_t* rax_6 = *arg2;
        int32_t rcx_6 = *rax_6;
        *arg2 = &rax_6[1];
        *(arg1 + 0x18) = rcx_6;
        char* rdx = *arg2;
        uint64_t rcx_8 = *rdx & 0xf;
        void* rdx_1 = rdx - *(rcx_8 + 0x180038880);
        result = *(rdx_1 - 4) >> *(rcx_8 + 0x180038890);
        *arg2 = rdx_1;
        *(arg1 + 0x1c) = result;
    }
    else if (rcx_4 == 3)
    {
        int32_t* rax_4 = *arg2;
        int32_t rcx_5 = *rax_4;
        *arg2 = &rax_4[1];
        *(arg1 + 0x18) = rcx_5;
        return &rax_4[1];
    }
    
    return result;
}

