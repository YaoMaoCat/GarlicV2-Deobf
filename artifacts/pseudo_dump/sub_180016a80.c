
  uint64_t sub_180016a80(char arg1)

{
    int32_t rax = data_180047568;
    
    if (rax <= 0)
        return 0;
    
    data_180047568 = rax - 1;
    char rax_3 = sub_180016480();
    char var_18 = rax_3;
    
    if (data_180047520 != 2)
    {
        sub_180016fe0(7);
        /* no return */
    }
    
    __scrt_dllmain_uninitialize_c();
    sub_1800170d0();
    _RTC_Terminate();
    data_180047520 = 0;
    sub_180016770(rax_3);
    uint32_t rbx_1 = sub_1800167a0(arg1, 0);
    __scrt_dllmain_uninitialize_critical();
    return rbx_1;
}

