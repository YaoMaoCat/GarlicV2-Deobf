
  int64_t sub_18001fd74(int32_t arg1)

{
    int64_t var_18 = -2;
    HMODULE phModule = nullptr;
    int64_t result = GetModuleHandleExW(0, u"mscoree.dll", &phModule);
    HMODULE phModule_1 = phModule;
    
    if (result)
    {
        result = GetProcAddress(phModule_1, "CorExitProcess");
        
        if (result)
            result = sub_18002d680();
        
        phModule_1 = phModule;
    }
    
    if (!phModule_1)
        return result;
    
    return FreeLibrary(phModule_1);
}

