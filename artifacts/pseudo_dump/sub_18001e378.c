
  void* sub_18001e378(void* arg1, int32_t* arg2)

{
    int64_t* rbp = *(arg1 + 8);
    void* result_2 = *(arg1 + 0x10) - 1;
    void* result_1;
    int64_t* var_10 = &result_1;
    int64_t rbx = *(rbp + 0x2c);
    result_1 = result_2;
    void* result_3 = result_2;
    *arg2 = sub_18001d6a0(rbp, &result_3, 0xa, 1);
    char rcx_1 = 0;
    void* result = *(arg1 + 8);
    
    if (!*(result + 0x30) || *(result + 0x2c) != 0x22)
    {
        result = result_1;
        
        if (result >= *(arg1 + 0x10))
        {
            *(arg1 + 0x10) = result;
            rcx_1 = 1;
        }
    }
    
    result = rcx_1;
    *(rbp + 0x2c) = rbx;
    return result;
}

