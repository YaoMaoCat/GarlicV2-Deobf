
  uint64_t sub_180018770(int64_t* arg1, void* arg2)

{
    uint64_t result = sub_180019fb0(arg2, arg1);
    uint64_t rbx = *(arg2 + 0xc);
    int32_t rdi = result;
    void* const rcx_3;
    
    while (rbx)
    {
        rbx = rbx - 1;
        int64_t r8_1 = *(sub_180019c40() + 0x60) + rbx * 0x14;
        rcx_3 = *(arg2 + 0x10) + r8_1;
        
        if (rdi > *(rcx_3 + 4) && rdi <= *(rcx_3 + 8))
            goto label_1800187cd;
    }
    
    rcx_3 = nullptr;
label_1800187cd:
    result = rcx_3;
    return result;
}

