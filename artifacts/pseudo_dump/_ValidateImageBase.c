
🌐  int64_t _ValidateImageBase(int16_t* arg1)

{
    if (*arg1 == 0x5a4d)
    {
        int32_t* rdx_2 = *(arg1 + 0x3c) + arg1;
        
        if (*rdx_2 == 0x4550)
        {
            int64_t result;
            result = rdx_2[6] == 0x20b;
            return result;
        }
    }
    
    return 0;
}

