
  void** sub_180023438()

{
    data_180047830 = sub_18002643c();
    void** result = FlsAlloc(destroy_fls);
    data_1800469c8 = result;
    
    if (result != 0xffffffff)
    {
        if (sub_18002334c())
            result = 1;
        else
        {
            __vcrt_uninitialize_ptd();
            result = 0;
        }
    }
    else
        result = 0;
    
    return result;
}

