
  char* sub_1800048b0(char* arg1, int64_t arg2, char* arg3)

{
    char* result = arg3;
    
    while (arg1 != arg2)
    {
        *result = *arg1;
        int64_t r9_1 = *(arg1 + 0x18);
        int64_t r8 = *(arg1 + 0x10);
        int64_t rdx = *(arg1 + 8);
        __builtin_memset(&arg1[8], 0, 0x18);
        arg1 = &arg1[0x20];
        *(result + 8) = rdx;
        *(result + 0x10) = r8;
        *(result + 0x18) = r9_1;
        result = &result[0x20];
    }
    
    sub_180003f30(result, result);
    return result;
}

