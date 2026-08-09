
  uint64_t sub_18002cd1c(void* arg1, uint32_t arg2, uint32_t* arg3)

{
    BOOL rax = WriteConsoleW(data_180047240, arg1, arg2, arg3, nullptr);
    BOOL rbx = rax;
    
    if (!rax && GetLastError() == ERROR_INVALID_HANDLE)
    {
        HANDLE hObject = data_180047240;
        
        if (hObject <= -3)
            CloseHandle(hObject);
        
        HANDLE hConsoleOutput = CreateFileW(u"CONOUT$", 0x40000000, 
            FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, SECURITY_ANONYMOUS, 
            nullptr);
        data_180047240 = hConsoleOutput;
        rbx = WriteConsoleW(hConsoleOutput, arg1, arg2, arg3, nullptr);
    }
    
    return rbx;
}

