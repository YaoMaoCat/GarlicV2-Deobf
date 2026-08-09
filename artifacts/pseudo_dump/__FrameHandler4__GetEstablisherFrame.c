
  int64_t* __FrameHandler4::GetEstablisherFrame(int64_t* arg1, int64_t arg2, char* arg3, int64_t* arg4)

{
    *arg4 = *arg1;
    
    if (*arg3 & 1)
        *arg4 = *(*(arg3 + 0x14) + *arg1);
    
    return arg4;
}

