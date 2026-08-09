
🌐  int64_t __FrameHandler3::SetUnwindTryBlock(int64_t* arg1, int64_t* arg2, void* arg3, int32_t arg4)

{
    int64_t arg_18;
    int64_t rcx = *sub_180018960(arg1, arg2, arg3, &arg_18);
    int64_t result = *(arg3 + 0x1c);
    arg_18 = rcx;
    
    if (arg4 > *(result + rcx + 4))
        *(result + rcx + 4) = arg4;
    
    return result;
}

