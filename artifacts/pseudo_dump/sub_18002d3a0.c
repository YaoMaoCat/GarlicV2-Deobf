
  int64_t sub_18002d3a0(int32_t* arg1, int64_t arg2, void* arg3, int64_t* arg4)

{
    void* rbx = arg4[7];
    sub_180016220(arg2, arg4, rbx + 4);
    int32_t rax;
    rax = arg1[1] & 0x66;
    
    if (!(*(rbx + 4) & (rax + 1)))
        return 1;
    
    /* tailcall */
    return sub_180019300(arg1, arg2, arg3, arg4);
}

