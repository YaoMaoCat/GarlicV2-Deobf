
  struct std::exception::VTable** sub_1800076e0(struct std::exception::VTable** arg1, int64_t* arg2)

{
    int64_t* rax = arg2;
    
    if (arg2[3] > 0xf)
        rax = *arg2;
    
    int64_t* var_18 = rax;
    *arg1 = &std::exception::`vftable';
    char var_10 = 1;
    *(arg1 + 8) = {0};
    sub_180019440(&var_18, &arg1[1]);
    *arg1 = &std::runtime_error::`vftable'{for `std::exception'};
    return arg1;
}

