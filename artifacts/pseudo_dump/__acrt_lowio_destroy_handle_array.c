
🌐  void __acrt_lowio_destroy_handle_array(CRITICAL_SECTION* arg1)

{
    if (!arg1)
        return;
    
    CRITICAL_SECTION* lpCriticalSection = arg1;
    
    if (arg1 != arg1 + 0x1200)
    {
        do
        {
            DeleteCriticalSection(lpCriticalSection);
            lpCriticalSection += 0x48;
        } while (lpCriticalSection != arg1 + 0x1200);
    }
    
    _free_base(arg1);
}

