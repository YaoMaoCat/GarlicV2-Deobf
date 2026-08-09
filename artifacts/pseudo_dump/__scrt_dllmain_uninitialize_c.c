
  int64_t __scrt_dllmain_uninitialize_c()

{
    if (sub_180016fc0())
        /* tailcall */
        return _execute_onexit_table(&data_180047538);
    
    int32_t result = sub_18001fdfc();
    
    if (result)
        return result;
    
    /* tailcall */
    return _cexit();
}

