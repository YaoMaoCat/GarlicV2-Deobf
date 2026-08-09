
  void sub_18002e4e0(int64_t arg1, void* arg2) __noreturn

{
    void* arg_10 = arg2;
    int128_t* r8 = *(arg2 + 0x98);
    *(arg2 + 0x38) = r8;
    int64_t rdi = *(arg2 + 0x20);
    *(arg2 + 0x40) = rdi;
    int32_t* rcx = *(arg2 + 0xa8);
    *(arg2 + 0x48) = rcx;
    *(arg2 + 0x90);
    int64_t* rbx = *(arg2 + 0x28);
    std::_Uninitialized_move<uint64_t* __ptr64,class std::allocator<uint64_t> >(rcx, *rbx, r8);
    *(arg2 + 0x30) = 0;
    *rbx = rdi;
    sub_180019520(nullptr, nullptr);
    /* no return */
}

