
  int64_t* sub_1800026b0(int64_t* arg1, int32_t* arg2, void* arg3)

{
    void* rcx = arg1[2];
    int64_t r8 = arg1[3];
    
    if (arg3 > r8 - rcx)
        return sub_180002840(arg1, arg3, 0, arg2, arg3);
    
    arg1[2] = rcx + arg3;
    int64_t* rax_3;
    
    if (r8 <= 0xf)
        rax_3 = arg1;
    else
        rax_3 = *arg1;
    
    char* rbx = rax_3 + rcx;
    memcpy(rbx, arg2, arg3);
    *(rbx + arg3) = 0;
    return arg1;
}

