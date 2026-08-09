
  void* const sub_180019d20()

{
    if (data_180046890 == 0xffffffff)
        return 0;
    
    enum WIN32_ERROR dwErrCode = GetLastError();
    void* result_1 = FlsGetValue(data_180046890);
    void* const result = result_1;
    
    if (result_1 == -1)
        result = nullptr;
    else if (!result_1)
    {
        if (FlsSetValue(data_180046890, -ffffffffffffffff))
        {
            void* lpFlsData = calloc(1, 0x80);
            uint32_t dwFlsIndex = data_180046890;
            
            if (!lpFlsData)
                goto label_180019dc2;
            
            void* lpFlsData_1;
            
            if (!FlsSetValue(dwFlsIndex, lpFlsData))
            {
                dwFlsIndex = data_180046890;
            label_180019dc2:
                FlsSetValue(dwFlsIndex, nullptr);
                lpFlsData_1 = lpFlsData;
                result = nullptr;
            }
            else
            {
                *(lpFlsData + 0x78) = 0xfffffffe;
                lpFlsData_1 = nullptr;
                result = lpFlsData;
            }
            
            j_sub_180021340(lpFlsData_1);
        }
        else
            result = nullptr;
    }
    
    SetLastError(dwErrCode);
    return result;
}

