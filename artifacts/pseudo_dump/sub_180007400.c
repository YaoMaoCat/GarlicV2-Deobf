
  char* sub_180007400(char* arg1, int64_t arg2, char* arg3)

{
    char* result = arg3;
    
    while (arg1 != arg2)
    {
        *result = *arg1;
        int64_t rdx = *(arg1 + 0x10);
        int64_t r8 = *(arg1 + 0x18);
        int64_t rax_2 = *(arg1 + 8);
        __builtin_memset(&arg1[8], 0, 0x18);
        *(result + 8) = rax_2;
        *(result + 0x10) = rdx;
        *(result + 0x18) = r8;
        char rdx_1 = arg1[0x20];
        arg1 = &arg1[0x28];
        result[0x20] = rdx_1;
        result = &result[0x28];
    }
    
    sub_180006d00(result, result);
    return result;
}

