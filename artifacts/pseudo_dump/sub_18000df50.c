
  int64_t sub_18000df50(int64_t* arg1, int64_t arg2)

{
    void* arg_18 = &data_180046630;
    
    if (sub_180017bf0(&data_180046630))
    {
        std::_Throw_Cpp_error(5);
        /* no return */
    }
    
    if (data_18004667c == 0x7fffffff)
    {
        data_18004667c = 0x7ffffffe;
        std::_Throw_Cpp_error(6);
        /* no return */
    }
    
    int64_t rdx = data_180046680;
    
    if (rdx)
        (*(*arg1 + 0xb0))(arg1, rdx);
    
    int64_t rax_3;
    
    if (!arg2)
        rax_3 = 0;
    else
        rax_3 = (*(*arg1 + 0xa8))(arg1, arg2);
    
    data_180046680 = rax_3;
    sub_1800023a0("BServer: target A connection = %p", rax_3);
    /* tailcall */
    return sub_180017c80(&data_180046630);
}

