
  void* std::_Uninitialized_move<uint64_t* __ptr64,class std::allocator<uint64_t> >(int32_t* arg1, int64_t arg2, int128_t* arg3)

{
    void* rbx_1 = arg2 - arg1;
    memcpy(arg3, arg1, rbx_1);
    return rbx_1 + arg3;
}

