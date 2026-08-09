
  void sub_18002e460(int64_t arg1, void* arg2) __noreturn

{
    void* arg_10 = arg2;
    int128_t* rbx = *(arg2 + 0x98);
    *(arg2 + 0x38) = rbx;
    int64_t rsi = *(arg2 + 0x20);
    *(arg2 + 0x40) = rsi;
    int64_t rdi = *(arg2 + 0xa8);
    *(arg2 + 0x48) = rbx + rdi;
    *(arg2 + 0x90);
    std::_Uninitialized_move<uint64_t* __ptr64,class std::allocator<uint64_t> >(rbx + rdi, 
        rbx + (rdi << 1), rbx);
    *(arg2 + 0x30) = 0;
    int64_t* rbx_1 = *(arg2 + 0x28);
    std::_Uninitialized_move<uint64_t* __ptr64,class std::allocator<uint64_t> >(rbx + (rdi << 1), 
        *rbx_1, rbx + rdi);
    *rbx_1 = rsi;
    sub_180019520(nullptr, nullptr);
    /* no return */
}

