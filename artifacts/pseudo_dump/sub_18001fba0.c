
  void sub_18001fba0(int64_t* arg1)

{
    if (data_180047680)
        return;
    
    data_180047670 = 1;
    int32_t rcx = **arg1;
    
    if (!rcx)
    {
        if (data_180047678 != __security_cookie)
            sub_18002d680();
        
        _execute_onexit_table(&data_1800477b8);
    }
    else if (rcx == 1)
        _execute_onexit_table(&data_1800477d0);
    
    if (!**arg1)
        sub_180020ac4(&data_180030378, &data_180030398);
    
    sub_180020ac4(&data_1800303a0, &data_1800303a8);
    
    if (!*arg1[1])
    {
        data_180047680 = 1;
        *arg1[2] = 1;
    }
}

