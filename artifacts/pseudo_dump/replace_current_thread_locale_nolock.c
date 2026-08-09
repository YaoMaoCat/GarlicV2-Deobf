
🌐  void replace_current_thread_locale_nolock(void* arg1, void* arg2)

{
    void* rcx = *(arg1 + 0x90);
    
    if (rcx)
    {
        __acrt_release_locale_ref(rcx);
        void* rcx_1 = *(arg1 + 0x90);
        
        if (rcx_1 != data_180047838 && rcx_1 != &data_1800469d0 && !*(rcx_1 + 0x10))
            __acrt_free_locale(rcx_1);
    }
    
    *(arg1 + 0x90) = arg2;
    
    if (arg2)
        sub_180026dcc(arg2);
}

