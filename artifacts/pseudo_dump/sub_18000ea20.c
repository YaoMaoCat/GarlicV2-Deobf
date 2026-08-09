
  int64_t sub_18000ea20(int64_t* arg1)

{
    if (data_1800466e4)
    {
        int64_t rax;
        rax = 1;
        return rax;
    }
    
    int512_t entry_zmm2;
    int64_t rax_1 = sub_180001de0(arg1, data_180047468, entry_zmm2);
    
    if (!rax_1)
        return rax_1;
    
    if (sub_180012180(arg1, rax_1))
    {
        char rax_3;
        int512_t zmm2;
        rax_3 = sub_180011c10(arg1, rax_1);
        
        if (rax_3)
        {
            char rax_4;
            int512_t zmm2_1;
            rax_4 = sub_18000f390(arg1, rax_1, zmm2);
            
            if (rax_4 && sub_18000f010(arg1, rax_1, zmm2_1))
            {
                (*(*arg1 + 0xb0))(arg1, rax_1);
                data_1800466e4 = 1;
                return 1;
            }
        }
    }
    
    int64_t r8 = *arg1;
    (*(r8 + 0xb0))(arg1, rax_1, r8);
    return 0;
}

