
🌐  void _invoke_watson() __noreturn

{
    if (IsProcessorFeaturePresent(0x17))
        trap(0xd);
    
    __acrt_call_reportfault(2, 0xc0000417);
    /* tailcall */
    return TerminateProcess(GetCurrentProcess(), 0xc0000417);
}

