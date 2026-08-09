
  int64_t sub_18000eb10(int64_t* arg1, int64_t arg2)

{
    sub_1800023a0("BServer: B channelInactive", arg2);
    void* arg_20 = &data_180046688;
    
    if (!sub_180017bf0(&data_180046688))
    {
        if (data_1800466d4 == 0x7fffffff)
        {
            data_1800466d4 = 0x7ffffffe;
            std::_Throw_Cpp_error(6);
            /* no return */
        }
        
        int64_t rdx = data_1800466d8;
        
        if (rdx)
        {
            (*(*arg1 + 0xb0))(arg1, rdx);
            data_1800466d8 = 0;
        }
        
        data_1800466e0 = 0;
        sub_180017c80(&data_180046688);
        int32_t rax_2 = sub_180017bf0(&data_180046780);
        
        if (!rax_2)
        {
            if (data_1800467cc == 0x7fffffff)
            {
                data_1800467cc = 0x7ffffffe;
                std::_Throw_Cpp_error(6);
                /* no return */
            }
            
            data_180047518 = rax_2;
            int64_t rdx_1 = sub_180017c80(&data_180046780);
            
            if (!data_1800466e5)
                /* tailcall */
                return sub_180011440(arg1);
            
            /* tailcall */
            return sub_1800023a0("BServer: B gone; mid-session ", rdx_1);
        }
    }
    
    std::_Throw_Cpp_error(5);
    /* no return */
}

