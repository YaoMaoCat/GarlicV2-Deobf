
🌐  int64_t _free_osfhnd(int32_t arg1)

{
    int64_t rbx = arg1;
    
    if (arg1 >= 0 && rbx < data_180047c40)
    {
        uint64_t rsi_2 = rbx >> 6;
        uint64_t rdi_1 = (rbx & 0x3f) * 9;
        int64_t rax_3 = (&data_180047840)[rsi_2];
        
        if (*(rax_3 + (rdi_1 << 3) + 0x38) & 1 && *(rax_3 + (rdi_1 << 3) + 0x28) != -1)
        {
            int32_t rax_4 = sub_18002c304();
            
            if (rax_4 == 1)
            {
                if (!rbx)
                    SetStdHandle(STD_INPUT_HANDLE, nullptr);
                else if (rbx == rax_4)
                    SetStdHandle(STD_OUTPUT_HANDLE, nullptr);
                else if (rbx - rax_4 == rax_4)
                    SetStdHandle(STD_ERROR_HANDLE, nullptr);
            }
            
            *((&data_180047840)[rsi_2] + (rdi_1 << 3) + 0x28) = -1;
            return 0;
        }
    }
    
    *sub_18002131c() = 9;
    *sub_1800212f8() = 0;
    return 0xffffffff;
}

