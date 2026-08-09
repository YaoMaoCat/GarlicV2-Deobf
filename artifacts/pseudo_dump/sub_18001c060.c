
  uint32_t* sub_18001c060(uint32_t* arg1, void* arg2, void* arg3)

{
    __builtin_memset(&arg1[2], 0, 0x20);
    int64_t rax = *(arg2 + 0xc);
    
    if (!rax)
    {
        *arg1 = 0;
        return arg1;
    }
    
    char* rdx = arg3 + rax;
    *(arg1 + 8) = rdx;
    uint64_t rcx_1 = *rdx & 0xf;
    char* rdx_1 = rdx - *(rcx_1 + 0x180038880);
    uint32_t rax_3 = *(rdx_1 - 4) >> *(rcx_1 + 0x180038890);
    *(arg1 + 8) = rdx_1;
    *arg1 = rax_3;
    *(arg1 + 0x10) = rdx_1;
    uint64_t rcx_4 = *rdx_1 & 0xf;
    char* rdx_2 = rdx_1 - *(rcx_4 + 0x180038880);
    uint32_t rax_6 = *(rdx_2 - 4) >> *(rcx_4 + 0x180038890);
    *(arg1 + 8) = rdx_2;
    arg1[6] = rax_6;
    uint64_t rcx_7 = *rdx_2 & 0xf;
    char* rdx_3 = rdx_2 - *(rcx_7 + 0x180038880);
    arg1[7] = *(rdx_3 - 4) >> *(rcx_7 + 0x180038890);
    *(arg1 + 8) = rdx_3;
    uint64_t rcx_10 = *rdx_3 & 0xf;
    int32_t* rdx_4 = rdx_3 - *(rcx_10 + 0x180038880);
    arg1[8] = rdx_4[-1] >> *(rcx_10 + 0x180038890);
    *(arg1 + 8) = rdx_4;
    int32_t rcx_12 = *rdx_4;
    *(arg1 + 8) = &rdx_4[1];
    arg1[9] = rcx_12;
    return arg1;
}

