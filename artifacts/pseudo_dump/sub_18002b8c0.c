
  uint64_t sub_18002b8c0(int32_t* arg1)

{
    int64_t arg_8 = 0;
    fegetenv(&arg_8);
    
    if (*arg1 != arg_8)
        return 1;
    
    int32_t rdi;
    rdi = arg1[1] != *(&arg_8 + 4);
    return rdi;
}

