
  struct std::exception::VTable** sub_180004b60(struct std::exception::VTable** arg1, void* arg2)

{
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    sub_180019440(arg2 + 8, &arg1[1]);
    *arg1 = &std::runtime_error::`vftable'{for `std::exception'};
    return arg1;
}

