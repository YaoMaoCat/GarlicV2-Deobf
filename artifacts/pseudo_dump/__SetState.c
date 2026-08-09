
  int64_t __SetState(int64_t* arg1, int64_t arg2, void* arg3, int32_t arg4)

{
    int64_t result = *arg1;
    *(*(arg3 + 0x1c) + result) = arg4;
    return result;
}

