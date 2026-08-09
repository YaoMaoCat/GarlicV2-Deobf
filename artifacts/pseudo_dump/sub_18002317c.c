
  void** sub_18002317c()

{
    enum WIN32_ERROR dwErrCode = GetLastError();
    void** result = nullptr;
    
    if (FlsSetValue(data_1800469c8, -ffffffffffffffff))
    {
        void** lpFlsData = _calloc_base(1, 0x3c8);
        uint32_t dwFlsIndex = data_1800469c8;
        
        if (lpFlsData)
        {
            if (FlsSetValue(dwFlsIndex, lpFlsData))
            {
                construct_ptd_array(lpFlsData);
                _free_base(0);
                result = lpFlsData;
            }
            else
            {
                FlsSetValue(data_1800469c8, nullptr);
                _free_base(lpFlsData);
            }
            
            SetLastError(dwErrCode);
            return result;
        }
        
        FlsSetValue(dwFlsIndex, nullptr);
        _free_base(0);
    }
    
    SetLastError(dwErrCode);
    return nullptr;
}

