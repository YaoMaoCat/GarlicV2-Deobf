
  void sub_18000bc20(int64_t* arg1, int64_t arg2)

{
    if (!arg1 || !arg2)
        return;
    
    int64_t rax = (*(*arg1 + 0xa8))();
    int64_t arg_8 = rax;
    
    if (!rax)
        return;
    
    void* arg_18 = &data_180046130;
    
    if (sub_180017bf0(&data_180046130))
    {
        std::_Throw_Cpp_error(5);
        /* no return */
    }
    
    if (data_18004617c == 0x7fffffff)
    {
        data_18004617c = 0x7ffffffe;
        std::_Throw_Cpp_error(6);
        /* no return */
    }
    
    int64_t* rdx = data_1800474b0;
    int64_t* rcx = data_1800474a8;
    
    if ((rdx - rcx) >> 3 > 0x100)
    {
        (*(*arg1 + 0xb0))(arg1, *rcx);
        int128_t* rcx_2 = data_1800474a8;
        memcpy(rcx_2, rcx_2 + 8, data_1800474b0 - (rcx_2 + 8));
        rdx = data_1800474b0 - 8;
        data_1800474b0 = rdx;
    }
    
    if (rdx == data_1800474b8)
        sub_18000b540(&data_1800474a8, rdx, &arg_8);
    else
    {
        *rdx = rax;
        data_1800474b0 += 8;
    }
    
    sub_180017c80(&data_180046130);
}

