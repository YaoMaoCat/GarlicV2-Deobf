
  uint64_t sub_18001cec0(void* arg1, int32_t* arg2)

{
    void* rsi = arg1;
    
    if (!arg2)
    {
        abort();
        /* no return */
    }
    
    int64_t rdi;
    rdi = 0;
    int32_t i = 0;
    char arg_10 = 0;
    
    if (*arg2 > 0)
    {
        do
        {
            int32_t* r14_2 = *(*(rsi + 0x30) + 0xc) + _GetThrowImageBase() + 4;
            int32_t rbx_2 = *(_GetThrowImageBase() + *(*(rsi + 0x30) + 0xc));
            
            if (rbx_2 > 0)
            {
                while (true)
                {
                    int64_t rbp_1 = *r14_2;
                    int64_t rax_7 = _GetThrowImageBase();
                    int32_t rax_9 = sub_18001b900(_GetImageBase() + i * 0x14 + arg2[1], 
                        rbp_1 + rax_7, *(rsi + 0x30));
                    rsi = arg1;
                    
                    if (rax_9)
                    {
                        rdi = 1;
                        arg_10 = 1;
                        break;
                    }
                    
                    rbx_2 -= 1;
                    r14_2 = &r14_2[1];
                    
                    if (rbx_2 <= 0)
                    {
                        rdi = arg_10;
                        break;
                    }
                }
            }
            
            i += 1;
        } while (i < *arg2);
    }
    
    return rdi;
}

