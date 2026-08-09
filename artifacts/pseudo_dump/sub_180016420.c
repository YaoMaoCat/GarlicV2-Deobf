
  int64_t sub_180016420(uint64_t arg1)

{
    int64_t i;
    
    for (i = j_sub_1800213a0(arg1); !i; i = j_sub_1800213a0(arg1))
    {
        if (!sub_18001f8e0())
        {
            if (arg1 == -1)
            {
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            __scrt_throw_std_bad_alloc();
            /* no return */
        }
    }
    
    return i;
}

