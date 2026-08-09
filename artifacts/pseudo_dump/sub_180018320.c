
  uint64_t sub_180018320(void* arg1, void* arg2, uint32_t arg3)

{
    *(arg2 + 0x4c) -= 1;
    *(arg2 + 0x48) = 0xffffffff;
    int32_t rbx = 2;
    
    if (SleepConditionVariableSRW(arg1 + 8, arg2 + 0x10, arg3, 0))
        rbx = 0;
    
    uint32_t rax_1 = GetCurrentThreadId();
    *(arg2 + 0x4c) += 1;
    *(arg2 + 0x48) = rax_1;
    return rbx;
}

