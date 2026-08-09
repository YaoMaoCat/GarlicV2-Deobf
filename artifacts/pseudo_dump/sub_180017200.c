
  struct std::exception::VTable** sub_180017200(struct std::exception::VTable** arg1, int64_t arg2)

{
    char var_10 = 1;
    int64_t var_18 = arg2;
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    sub_180019440(&var_18, &arg1[1]);
    *arg1 = &std::length_error::`vftable'{for `std::logic_error'};
    return arg1;
}

