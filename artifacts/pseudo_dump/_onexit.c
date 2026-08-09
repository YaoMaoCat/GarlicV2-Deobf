
  uint64_t _onexit(int64_t arg1)

{
    int32_t rax;
    
    if (*data_180047538 != -1)
        rax = _register_onexit_function(&data_180047538, arg1);
    else
        rax = sub_180020850(arg1);
    
    int64_t rdx_2 = 0;
    
    if (!rax)
        rdx_2 = arg1;
    
    return -((rax - rax)) - 1;
}

