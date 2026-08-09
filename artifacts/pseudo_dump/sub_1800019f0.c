
  HANDLE sub_1800019f0(char* arg1)

{
    HANDLE result = CreateFileA("D:\.minecraft\proxy.log", 4, FILE_SHARE_READ | FILE_SHARE_WRITE, 
        nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    
    if (result == -1)
        return result;
    
    SetFilePointer(result, 0, nullptr, FILE_END);
    uint64_t r8_1 = 0;
    
    if (*arg1)
    {
        do
            r8_1 = r8_1 + 1;
         while (arg1[r8_1]);
    }
    
    void numberOfBytesWritten;
    WriteFile(result, arg1, r8_1, &numberOfBytesWritten, nullptr);
    WriteFile(result, &data_180030630, 2, &numberOfBytesWritten, nullptr);
    FlushFileBuffers(result);
    return CloseHandle(result);
}

