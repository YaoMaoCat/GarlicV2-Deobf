
  uint64_t sub_180028f50(int16_t* arg1, int16_t* arg2, int64_t arg3)

{
    if (!arg3)
        return 0;
    
    int64_t i_1 = arg3 - 1;
    
    if (arg3 != 1)
    {
        int64_t i;
        
        do
        {
            int16_t rax_2 = *arg1;
            
            if (!rax_2)
                break;
            
            if (rax_2 != *arg2)
                break;
            
            arg1 = &arg1[1];
            arg2 = &arg2[1];
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
    }
    
    return *arg1 - *arg2;
}

