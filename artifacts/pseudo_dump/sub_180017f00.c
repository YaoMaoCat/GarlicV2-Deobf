
  struct std::exception::VTable** sub_180017f00(struct std::exception::VTable** arg1, void* arg2)

{
    *arg1 = &std::exception::`vftable';
    *(arg1 + 8) = {0};
    sub_180019440(arg2 + 8, &arg1[1]);
    *arg1 = &std::_System_error::`vftable'{for `std::runtime_error'};
    int128_t zmm0 = *(arg2 + 0x18);
    *arg1 = &std::system_error::`vftable'{for `std::_System_error'};
    *(arg1 + 0x18) = zmm0;
    return arg1;
}

