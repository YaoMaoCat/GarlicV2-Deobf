
  uint64_t sub_18001ce80(void* arg1, void* arg2)

{
    int64_t rax_4 = *(arg2 + 8);
    
    if (!rax_4)
        return 0;
    
    char* r8_1 = *(arg1 + 8) + rax_4;
    uint64_t rcx_1 = *r8_1 & 0xf;
    return *(r8_1 - *(rcx_1 + 0x180038880) - 4) >> *(rcx_1 + 0x180038890);
}

