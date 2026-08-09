
  int64_t sub_18001e310(int64_t* arg1)

{
    if (!*arg1)
    {
        enum WIN32_ERROR dwErrCode_2 = GetLastError();
        bool cond:1_1 = arg1[2];
        enum WIN32_ERROR dwErrCode_1 = dwErrCode_2;
        int64_t rdx_1;
        
        if (cond:1_1)
            rdx_1 = arg1[1];
        else
        {
            rdx_1 = 0;
            arg1[2] = 1;
            arg1[1] = 0;
        }
        
        void* rax_1 = sub_1800233dc(&dwErrCode_1, rdx_1);
        enum WIN32_ERROR dwErrCode = dwErrCode_1;
        *arg1 = rax_1;
        SetLastError(dwErrCode);
        
        if (!rax_1)
        {
            abort();
            /* no return */
        }
    }
    
    return *arg1;
}

