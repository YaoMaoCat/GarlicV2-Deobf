
  uint64_t sub_180016910(int64_t arg1, int32_t arg2, int64_t arg3)

{
    if (!arg2)
    {
        arg1 = arg3;
        /* tailcall */
        return sub_180016a80(arg1);
    }
    
    if (arg2 == 1)
        /* tailcall */
        return sub_180016970(arg1, arg3);
    
    if (arg2 == 2)
        return sub_180016590();
    
    if (arg2 == 3)
        return __scrt_dllmain_crt_thread_detach();
    
    return 1;
}

