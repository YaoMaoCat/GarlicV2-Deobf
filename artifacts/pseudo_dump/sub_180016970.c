
  int64_t sub_180016970(int64_t arg1, int64_t arg2)

{
    if (sub_180016690(0))
    {
        char rax_1 = sub_180016480();
        char arg_18 = rax_1;
        int64_t rdi;
        rdi = 1;
        
        if (data_180047520)
        {
            sub_180016fe0(7);
            /* no return */
        }
        
        data_180047520 = 1;
        
        if (sub_180016510())
        {
            _RTC_Initialize();
            sub_1800170c0();
            __scrt_initialize_default_local_stdio_options();
            
            if (!sub_180020afc(&data_180030350, &data_180030370) && sub_1800164d0())
            {
                sub_180020ac4(&data_180030318, &data_180030348);
                data_180047520 = 2;
                rdi = 0;
            }
        }
        
        sub_180016770(rax_1);
        
        if (!rdi)
        {
            if (data_180048000 && sub_1800166d0(&data_180048000))
                data_180048000(arg1, 2, arg2);
            
            data_180047568 += 1;
            return 1;
        }
    }
    
    return 0;
}

