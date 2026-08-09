
  uint64_t sub_18000b770(int64_t* arg1)

{
    int64_t result;
    
    if (data_180046090)
    {
        result = 1;
        return result;
    }
    
    if (arg1)
    {
        int512_t entry_zmm2;
        result = sub_180001de0(arg1, data_180047468, entry_zmm2);
        
        if (result)
        {
            char rax;
            int512_t zmm2;
            rax = sub_18000c550(arg1, result);
            char rax_1;
            
            if (rax)
                rax_1 = sub_18000c2f0(arg1, result, zmm2);
            
            int64_t rsi;
            
            if (!rax || !rax_1)
                rsi = 0;
            else
                rsi = 1;
            
            int64_t r8 = *arg1;
            (*(r8 + 0xb0))(arg1, result, r8);
            return rsi;
        }
    }
    
    result = 0;
    return result;
}

