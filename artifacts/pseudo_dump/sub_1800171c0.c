
  struct std::exception::VTable** sub_1800171c0(struct std::exception::VTable** arg1, void* arg2)

{
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    sub_180019440(arg2 + 8, &arg1[1]);
    *arg1 = &std::length_error::`vftable'{for `std::logic_error'};
    return arg1;
}

