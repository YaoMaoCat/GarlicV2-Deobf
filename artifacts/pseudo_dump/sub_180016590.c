
  int64_t sub_180016590()

{
    if (__vcrt_thread_attach())
    {
        if (__acrt_thread_attach())
            return 1;
        
        __vcrt_uninitialize_critical();
    }
    
    return 0;
}

