
  int64_t sub_1800182d0(void* arg1, void* arg2)

{
    *(arg2 + 0x4c) -= 1;
    *(arg2 + 0x48) = 0xffffffff;
    
    if (!SleepConditionVariableSRW(arg1 + 8, arg2 + 0x10, 0xffffffff, 0))
    {
        abort();
        /* no return */
    }
    
    uint32_t rax_1 = GetCurrentThreadId();
    *(arg2 + 0x4c) += 1;
    *(arg2 + 0x48) = rax_1;
    return 0;
}

