
  int128_t* sub_180018200(int64_t arg1, int128_t* arg2, int32_t arg3)

{
    char* rax = sub_180018370(arg3);
    void* r8 = -ffffffffffffffff;
    __builtin_memset(arg2, 0, 0x20);
    
    do
        r8 += 1;
     while (*(rax + r8));
    
    sub_180002740(arg2, rax, r8);
    return arg2;
}

