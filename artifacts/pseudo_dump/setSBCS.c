
🌐  int64_t setSBCS(void* arg1)

{
    sub_18002de50(arg1 + 0x18, 0, 0x101);
    int64_t i_1 = 0;
    *(arg1 + 4) = 0;
    *(arg1 + 0x220) = 0;
    __builtin_memset(arg1 + 0xc, 0, 0xc);
    
    for (int64_t i = 0; i < 0x101; )
    {
        void* rcx_1 = i + &data_180046b40;
        i += 1;
        *(arg1 - &data_180046b58 + rcx_1 + 0x30) = *(rcx_1 + 0x18);
    }
    
    char result;
    
    do
    {
        void* rcx_2 = i_1 + &data_180046b40;
        i_1 += 1;
        result = *(rcx_2 + 0x119);
        *(arg1 - &data_180046c59 + rcx_2 + 0x232) = result;
    } while (i_1 < 0x100);
    
    return result;
}

