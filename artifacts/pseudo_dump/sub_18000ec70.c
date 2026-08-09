
  int64_t sub_18000ec70(int64_t* arg1, int64_t arg2, int64_t arg3)

{
    int64_t r9;
    int512_t zmm2;
    r9 = sub_1800023a0("BServer: initChannel for incoming ch=%p", arg3);
    
    if (data_180046330 && data_180046348 && data_180046350 && data_180046358)
    {
        int64_t rax_1 = sub_180001cd0(arg1, arg3, zmm2, r9);
        char rax_2;
        
        if (rax_1)
        {
            int64_t rdx_2 = *arg1;
            rax_2 = (*(rdx_2 + 0x720))(arg1, rdx_2);
        }
        
        if (!rax_1 || rax_2)
        {
            char rax_9;
            rax_9 = (*(*arg1 + 0x720))(arg1);
            
            if (rax_9)
                r9 = (*(*arg1 + 0x88))(arg1);
        }
        else
        {
            int64_t var_38_1 = data_180046358;
            data_180046348;
            sub_18000e930(arg1, rax_1, zmm2, data_180046350);
            char rax_4;
            int64_t rdx_4;
            rax_4 = (*(*arg1 + 0x720))(arg1);
            
            if (!rax_4)
            {
                zmm2 = sub_1800023a0("BServer: TCP_NODELAY set on B channel", rdx_4);
                r9 = (*(*arg1 + 0xb8))(arg1, rax_1);
            }
            else
            {
                (*(*arg1 + 0x88))(arg1);
                r9 = (*(*arg1 + 0xb8))(arg1, rax_1);
            }
        }
    }
    
    data_180046318;
    int64_t rax_11 = sub_180001cd0(arg1, arg3, zmm2, r9);
    char rax_13;
    int64_t r9_2;
    rax_13 = (*(*arg1 + 0x720))(arg1);
    char const* const rcx_32;
    int64_t rdx_24;
    
    if (rax_13 || !rax_11)
    {
        rdx_24 = (*(*arg1 + 0x88))(arg1);
        rcx_32 = "  pipeline() failed";
    }
    else
    {
        sub_180015970(arg1, arg3, data_180046290, r9_2, zmm2);
        int64_t var_38_2 = data_180046300;
        data_180046278;
        sub_180001710(arg1, data_180046270, zmm2, rax_11);
        char rax_16;
        int64_t rdx_10;
        rax_16 = (*(*arg1 + 0x720))(arg1);
        
        if (rax_16)
            rdx_10 = sub_180002210(arg1, "  configureSerialization", zmm2);
        
        char const* const rcx_16;
        
        if (!data_180046398 || !data_180046390)
        {
            char const* const var_28 = "unbundler";
            char const* const var_20_1 = "bundler";
            char const* const* i = &var_28;
            int64_t __saved_r14;
            
            do
            {
                int64_t rax_18 = (*(*arg1 + 0x538))(arg1, *i);
                data_180046370;
                sub_180001cd0(arg1, rax_11, zmm2, rax_18);
                int64_t rdx_13 = *arg1;
                
                if ((*(rdx_13 + 0x720))(arg1, rdx_13))
                {
                    int64_t rdx_14 = *arg1;
                    (*(rdx_14 + 0x88))(arg1, rdx_14);
                }
                
                rdx_10 = (*(*arg1 + 0xb8))(arg1, rax_18);
                i = &i[1];
            } while (i != &__saved_r14);
            
            rcx_16 = "  bundle handlers removed (no BundlerInfo)";
        }
        else
            rcx_16 = "  bundle handlers kept (BundlerInfo available)";
        
        int64_t r9_5;
        int512_t zmm2_1;
        r9_5 = sub_1800023a0(rcx_16, rdx_10);
        data_180046258;
        int64_t rax_21 = sub_18000bbf0(arg1, data_180046250, zmm2_1, r9_5);
        int64_t r8_7 = *arg1;
        int64_t rax_22 = (*(r8_7 + 0x538))(arg1, "bside", r8_7);
        int64_t var_38_3 = rax_21;
        data_180046368;
        sub_180001cd0(arg1, rax_11, zmm2_1, rax_22);
        int64_t rdx_18 = *arg1;
        
        if ((*(rdx_18 + 0x720))(arg1, rdx_18))
            sub_180002210(arg1, "  addLast(bside)", zmm2_1);
        
        (*(*arg1 + 0xb8))(arg1, rax_22);
        (*(*arg1 + 0xb8))(arg1, rax_21);
        (*(*arg1 + 0xb8))(arg1, rax_11);
        void* arg_8 = &data_180046688;
        
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
        
        int64_t rdx_22 = data_1800466d8;
        
        if (rdx_22)
            (*(*arg1 + 0xb0))(arg1, rdx_22);
        
        data_1800466d8 = (*(*arg1 + 0xa8))(arg1, arg3);
        data_1800466e0 = 0;
        rdx_24 = sub_180017c80(&data_180046688);
        rcx_32 = "  B channel captured, state=AwaitHandshake";
    }
    
    /* tailcall */
    return sub_1800023a0(rcx_32, rdx_24);
}

