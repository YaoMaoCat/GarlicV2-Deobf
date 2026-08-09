
  uint64_t sub_18002a76c(int16_t* arg1)

{
    if (arg1)
    {
        int32_t rbx_1 = 0;
        int32_t rsi_1 = 0xe3;
        
        do
        {
            int32_t temp0_1;
            int32_t temp1_1;
            temp0_1 = HIGHD(rsi_1 + rbx_1);
            temp1_1 = LOWD(rsi_1 + rbx_1);
            int64_t rbp_1 = (temp1_1 - temp0_1) >> 1;
            int64_t r14_2 = rbp_1 * 2;
            int32_t rax_5 = sub_180029440(arg1, (&data_18003d660)[r14_2], 0x55);
            
            if (!rax_5)
            {
                int64_t rax_7 = *((r14_2 << 3) + 0x18003d668);
                
                if (rax_7 >= 0 && rax_7 < 0xe4)
                    return *(rax_7 * 0x10 + 0x18003bc00);
                
                break;
            }
            
            int32_t rcx_1 = rbp_1 - 1;
            
            if (rax_5 >= 0)
                rcx_1 = rsi_1;
            
            rsi_1 = rcx_1;
            
            if (rax_5 >= 0)
                rbx_1 = rbp_1 + 1;
        } while (rbx_1 <= rsi_1);
    }
    
    return 0;
}

