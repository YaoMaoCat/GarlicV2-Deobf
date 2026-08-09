
  int64_t sub_180017c80(void* arg1)

{
    int32_t temp0 = *(arg1 + 0x4c);
    *(arg1 + 0x4c) -= 1;
    
    if (temp0 == 1)
    {
        *(arg1 + 0x48) = 0xffffffff;
        ReleaseSRWLockExclusive(arg1 + 0x10);
    }
    
    return 0;
}

