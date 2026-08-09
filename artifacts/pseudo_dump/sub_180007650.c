
  int64_t* sub_180007650(int64_t* arg1, char* arg2, void* arg3)

{
    int64_t* arg_8 = arg1;
    __builtin_memset(arg1, 0, 0x26);
    *(arg1 + 0x28) = {0};
    arg1[7] = 0;
    arg1[8] = 0xf;
    arg1[5] = 0;
    __builtin_memset(&arg1[9], 0, 0x60);
    sub_180008460(arg1, arg2, arg3 + arg2);
    return arg1;
}

