
  struct std::exception::VTable** std::_Parallelism_resources_exhausted::_Parallelism_resources_exhausted(struct std::exception::VTable** arg1, void* arg2)

{
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    sub_180019440(arg2 + 8, &arg1[1]);
    *arg1 = &std::bad_alloc::`vftable'{for `std::exception'};
    return arg1;
}

