
  int16_t* sub_180004820(int16_t* arg1, int64_t arg2, int16_t* arg3)

{
    int16_t* result = arg3;
    
    while (arg1 != arg2)
    {
        *result = *arg1;
        result[1] = arg1[1];
        result[2] = arg1[2];
        int64_t r9_1 = *(arg1 + 0x18);
        int64_t r8 = *(arg1 + 0x10);
        int64_t rdx = *(arg1 + 8);
        __builtin_memset(&arg1[4], 0, 0x18);
        arg1 = &arg1[0x10];
        *(result + 8) = rdx;
        *(result + 0x10) = r8;
        *(result + 0x18) = r9_1;
        result = &result[0x10];
    }
    
    sub_180003f30(result, result);
    return result;
}

