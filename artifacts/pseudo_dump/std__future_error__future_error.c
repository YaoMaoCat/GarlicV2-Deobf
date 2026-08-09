
  struct std::exception::VTable** std::future_error::future_error(struct std::exception::VTable** arg1, void* arg2)

{
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    sub_180019440(arg2 + 8, &arg1[1]);
    *arg1 = &std::_System_error::`vftable'{for `std::runtime_error'};
    *(arg1 + 0x18) = *(arg2 + 0x18);
    return arg1;
}

