
  struct std::exception::VTable** sub_180004ba0(struct std::exception::VTable** arg1, int64_t arg2)

{
    char var_10 = 1;
    int64_t var_18 = arg2;
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    sub_180019440(&var_18, &arg1[1]);
    *arg1 = &std::runtime_error::`vftable'{for `std::exception'};
    return arg1;
}

