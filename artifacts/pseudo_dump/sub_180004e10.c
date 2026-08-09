
  void* const sub_180004e10(void* arg1)

{
    void* const result = *(arg1 + 8);
    
    if (result)
    {
        void* const result_1;
        
        if (*(arg1 + 0x18) - result < 0x1000)
            result_1 = result;
        else
        {
            result_1 = *(result - 8);
            
            if (result - result_1 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(result_1);
        result = nullptr;
        __builtin_memset(arg1 + 8, 0, 0x18);
    }
    
    return result;
}

