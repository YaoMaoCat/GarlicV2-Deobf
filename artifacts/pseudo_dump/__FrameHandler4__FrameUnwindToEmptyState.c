
  void* __FrameHandler4::FrameUnwindToEmptyState(int64_t* arg1, int64_t* arg2, uint64_t arg3, int512_t arg4 @ zmm1)

{
    bool cond:0 = !(*arg3 & 1);
    int64_t rcx = *arg1;
    int64_t arg_8 = rcx;
    
    if (!cond:0)
        arg_8 = *(*(arg3 + 0x14) + rcx);
    
    return sub_18001ca30(&arg_8, arg2, arg3, 0xffffffff, arg4);
}

