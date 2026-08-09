
🌐  void* __crt_cached_ptd_host::get_raw_ptd_noexit(int64_t* arg1)

{
    void* result = *arg1;
    int64_t rdi = 0;
    
    if (!result)
    {
        enum WIN32_ERROR dwErrCode_1 = GetLastError();
        
        if (arg1[2])
            rdi = arg1[1];
        else
        {
            arg1[1] = 0;
            arg1[2] = 1;
        }
        
        void* result_1 = sub_1800233dc(&dwErrCode_1, rdi);
        enum WIN32_ERROR dwErrCode = dwErrCode_1;
        result = result_1;
        *arg1 = result_1;
        SetLastError(dwErrCode);
    }
    
    return result;
}

