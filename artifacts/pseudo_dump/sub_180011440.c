
  void sub_180011440(int64_t* arg1)

{
    if (!data_180046340 || !data_180046338)
        return;
    
    void* arg_10 = &data_180046630;
    
    if (sub_180017bf0(&data_180046630))
    {
        std::_Throw_Cpp_error(5);
        /* no return */
    }
    
    if (data_18004667c == 0x7fffffff)
    {
    label_1800115f2:
        data_18004667c = 0x7ffffffe;
        std::_Throw_Cpp_error(6);
        /* no return */
    }
    
    int64_t rdx_1 = data_180046680;
    
    if (!rdx_1)
        /* tailcall */
        return sub_1800023a0("[A-CLOSE] no target A connection cached; nothing to close", 
            sub_180017c80(&data_180046630));
    
    int64_t rax_3 = (*(*arg1 + 0xc8))(arg1, rdx_1);
    int64_t rdx_2 = sub_180017c80(&data_180046630);
    
    if (!rax_3)
        /* tailcall */
        return sub_1800023a0("[A-CLOSE] no target A connection cached; nothing to close", rdx_2);
    
    int64_t r9_1 = *arg1;
    int64_t rax_4 = (*(r9_1 + 0x2f8))(arg1, rax_3, data_180046340, r9_1);
    int64_t r8_2 = *arg1;
    int64_t r9_2 = (*(r8_2 + 0xb8))(arg1, rax_3, r8_2);
    
    if (rax_4)
    {
        data_180046338;
        int512_t entry_zmm2;
        int64_t rax_8 = sub_180001cd0(arg1, rax_4, entry_zmm2, r9_2);
        int64_t rdx_7 = *arg1;
        char rax_9;
        int64_t rdx_8;
        rax_9 = (*(rdx_7 + 0x720))(arg1, rdx_7);
        
        if (!rax_9)
            sub_1800023a0("[A-CLOSE] A's netty channel to remote server closed directly", rdx_8);
        else
            sub_180002210(arg1, "[A-CLOSE] channel.close", entry_zmm2);
        
        if (rax_8)
            (*(*arg1 + 0xb8))(arg1, rax_8);
        
        (*(*arg1 + 0xb8))(arg1, rax_4);
        arg_10 = &data_180046630;
        
        if (sub_180017bf0(&data_180046630))
        {
            std::_Throw_Cpp_error(5);
            /* no return */
        }
        
        if (data_18004667c == 0x7fffffff)
            goto label_1800115f2;
        
        int64_t rdx_11 = data_180046680;
        
        if (rdx_11)
        {
            (*(*arg1 + 0xb0))(arg1, rdx_11);
            data_180046680 = 0;
        }
        
        /* tailcall */
        return sub_180017c80(&data_180046630);
    }
    
    char rax_6;
    int64_t rdx_5;
    rax_6 = (*(*arg1 + 0x720))(arg1);
    
    if (rax_6)
        rdx_5 = (*(*arg1 + 0x88))(arg1);
    
    sub_1800023a0("[A-CLOSE] Connection.channel is null (not yet channelActive?)", rdx_5);
}

