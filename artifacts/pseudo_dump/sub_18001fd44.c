
  void sub_18001fd44(uint32_t arg1, char arg2) __noreturn

{
    if (arg2)
    {
        TerminateProcess(GetCurrentProcess(), arg1);
        /* no return */
    }
    
    sub_18001fd74(arg1);
    ExitProcess(arg1);
    /* no return */
}

