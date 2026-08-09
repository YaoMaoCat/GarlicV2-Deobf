
  int64_t sub_180016110(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2)

{
    void* arg_18 = &data_180046688;
    
    if (sub_180017bf0(&data_180046688))
    {
        std::_Throw_Cpp_error(5);
        /* no return */
    }
    
    if (data_1800466d4 == 0x7fffffff)
    {
        data_1800466d4 = 0x7ffffffe;
        std::_Throw_Cpp_error(6);
        /* no return */
    }
    
    int64_t rdx = data_1800466d8;
    
    if (!rdx)
        sub_180017c80(&data_180046688);
    else
    {
        int64_t rax_2 = (*(*arg1 + 0xc8))(arg1, rdx);
        sub_180017c80(&data_180046688);
        
        if (rax_2)
        {
            data_180046320;
            sub_180001cd0(arg1, rax_2, arg3, arg2);
            int64_t rdx_2 = *arg1;
            
            if ((*(rdx_2 + 0x720))(arg1, rdx_2))
                sub_180002210(arg1, "writeAndFlush", arg3);
            
❓            /* jump -> *(*arg1 + 0xb8) */
        }
    }
    
    return 0;
}

