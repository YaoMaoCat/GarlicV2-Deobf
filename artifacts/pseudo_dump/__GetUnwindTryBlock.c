
  uint64_t __GetUnwindTryBlock(int64_t* arg1, int64_t* arg2, void* arg3)

{
    int64_t arg_18;
    int64_t rcx = *sub_180018960(arg1, arg2, arg3, &arg_18);
    int64_t rax_1 = *(arg3 + 0x1c);
    arg_18 = rcx;
    return *(rax_1 + rcx + 4);
}

