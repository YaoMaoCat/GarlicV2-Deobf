
  void* const sub_180004d40(int64_t* arg1)

{
    void* const result = *arg1;
    
    if (result)
    {
        void* const result_1;
        
        if (arg1[2] - result < 0x1000)
            result_1 = result;
        else
        {
            result_1 = *(result - 8);
            
            if (result - result_1 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(result_1);
        result = nullptr;
        __builtin_memset(arg1, 0, 0x18);
    }
    
    return result;
}

