
🌐  void* const _updatetlocinfoEx_nolock(int64_t* arg1, void* arg2)

{
    if (!arg2 || !arg1)
        return nullptr;
    
    void* rbx_1 = *arg1;
    
    if (rbx_1 != arg2)
    {
        *arg1 = arg2;
        sub_180026dcc(arg2);
        
        if (rbx_1)
        {
            __acrt_release_locale_ref(rbx_1);
            
            if (!*(rbx_1 + 0x10) && rbx_1 != &data_1800469d0)
                __acrt_free_locale(rbx_1);
        }
    }
    
    return arg2;
}

