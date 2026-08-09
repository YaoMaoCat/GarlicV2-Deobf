
  void* sub_18002d250(void* arg1, int64_t arg2)

{
    int32_t r9 = 0;
    void* r8 = *(arg1 + 0x3c) + arg1;
    uint32_t r10 = *(r8 + 6);
    void* result = *(r8 + 0x14) + 0x18 + r8;
    
    if (r10)
    {
        do
        {
            uint64_t r8_1 = *(result + 0xc);
            
            if (arg2 >= r8_1 && arg2 < *(result + 8) + r8_1)
                return result;
            
            r9 += 1;
            result += 0x28;
        } while (r9 < r10);
    }
    
    return nullptr;
}

