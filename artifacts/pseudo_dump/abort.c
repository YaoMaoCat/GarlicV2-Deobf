
🌐  void abort() __noreturn

{
    if (__acrt_get_sigabrt_handler())
        sub_18002668c(0x16);
    
    if (data_1800468a0 & 2)
    {
        if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
            trap(0xd);
        
        __acrt_call_reportfault(3, 0x40000015);
    }
    
    sub_18001fdf0(3);
    breakpoint();
}

