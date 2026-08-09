
  void* sub_180019c40()

{
    if (data_180046890 != 0xffffffff)
    {
        enum WIN32_ERROR dwErrCode = GetLastError();
        void* rax_1 = FlsGetValue(data_180046890);
        
        if (rax_1 != -1)
        {
            if (rax_1)
            {
                SetLastError(dwErrCode);
                return rax_1;
            }
            
            if (FlsSetValue(data_180046890, -ffffffffffffffff))
            {
                void* lpFlsData = calloc(1, 0x80);
                uint32_t dwFlsIndex = data_180046890;
                
                if (lpFlsData)
                {
                    if (FlsSetValue(dwFlsIndex, lpFlsData))
                    {
                        *(lpFlsData + 0x78) = 0xfffffffe;
                        j_sub_180021340(0);
                        SetLastError(dwErrCode);
                        return lpFlsData;
                    }
                    
                    FlsSetValue(data_180046890, nullptr);
                    j_sub_180021340(lpFlsData);
                }
                else
                {
                    FlsSetValue(dwFlsIndex, nullptr);
                    j_sub_180021340(nullptr);
                }
            }
        }
        
        SetLastError(dwErrCode);
    }
    
    abort();
    /* no return */
}

