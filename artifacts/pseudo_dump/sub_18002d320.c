
  int64_t sub_18002d320(int32_t* arg1, int64_t arg2, void* arg3, int64_t* arg4)

{
    int32_t* r10 = arg4[7];
    void* rbx_2 = &r10[*r10 * 4];
    sub_180016220(arg2, arg4, rbx_2 + 4);
    int32_t rax;
    rax = arg1[1] & 0x66;
    
    if (!(*(rbx_2 + 4) & (rax + 1)))
        return 1;
    
    /* tailcall */
    return sub_1800183a0(arg1, arg2, arg3, arg4);
}

