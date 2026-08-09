
  uint64_t sub_18000e2f0(int32_t arg1)

{
    int64_t rdi = arg1;
    int32_t rax = sub_180017bf0(&data_180046780);
    
    if (rax)
    {
        std::_Throw_Cpp_error(5);
        /* no return */
    }
    
    if (data_1800467cc == 0x7fffffff)
    {
        data_1800467cc = 0x7ffffffe;
        std::_Throw_Cpp_error(6);
        /* no return */
    }
    
    if (data_180047518 != rax)
        rdi = 1;
    else if (rdi >= 0)
    {
        int64_t arg_10;
        sub_180014a30(&arg_10);
        int64_t rbx_1 = arg_10;
        
        if (rdi > 0)
        {
            int64_t rcx_1 = rdi * 0xf4240;
            
            rbx_1 = rbx_1 >= 0x7fffffffffffffff - rcx_1 ? 0x7fffffffffffffff : rbx_1 + rcx_1;
        }
        
        rdi = data_180047518;
        
        if (!rdi)
        {
            while (true)
            {
                int64_t rax_3 = _Query_perf_frequency();
                int64_t rax_4 = sub_180018260();
                int64_t rax_5;
                
                if (rax_3 != 0x989680)
                {
                    int64_t rax_9;
                    int64_t rcx_3;
                    
                    if (rax_3 != 0x16e3600)
                    {
                        int64_t rax_10;
                        int64_t rdx_2;
                        rdx_2 = HIGHQ(rax_4);
                        rax_10 = LOWQ(rax_4);
                        rax_9 = COMBINE(rdx_2, rax_10) % rax_3 * 0x3b9aca00 / rax_3;
                        rcx_3 = COMBINE(rdx_2, rax_10) / rax_3 * 0x3b9aca00;
                    }
                    else
                    {
                        rax_9 = rax_4 * 2 / 3;
                        rcx_3 = rax_4 * 0x29;
                    }
                    
                    rax_5 = rax_9 + rcx_3;
                }
                else
                    rax_5 = rax_4 * 0x64;
                
                if (rax_5 >= rbx_1)
                {
                    rdi = data_180047518;
                    break;
                }
                
                int64_t rcx_6 = rbx_1 - rax_5;
                int64_t rdx_6;
                
                if (rcx_6 <= 0x4e94914f0000)
                {
                    rdx_6 = rcx_6 / 0xf4240;
                    
                    if (rdx_6 * 0xf4240 < rcx_6)
                        rdx_6 += 1;
                }
                else
                    rdx_6 = 0x5265c00;
                
                if (!sub_180018320(&data_1800474d0, &data_180046780, rdx_6))
                {
                    rdi = data_180047518;
                    
                    if (rdi)
                        break;
                }
            }
        }
    }
    else
    {
        do
            sub_1800182d0(&data_1800474d0, &data_180046780);
         while (!data_180047518);
        
        rdi = 1;
    }
    
    sub_180017c80(&data_180046780);
    return rdi;
}

