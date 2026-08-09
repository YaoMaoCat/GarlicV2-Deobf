
🌐  uint64_t __dcrt_lowio_ensure_console_output_initialized()

{
    HANDLE rax = data_180047240;
    
    if (rax == -2)
    {
        rax = CreateFileW(u"CONOUT$", 0x40000000, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, 
            OPEN_EXISTING, SECURITY_ANONYMOUS, nullptr);
        data_180047240 = rax;
    }
    
    int32_t rbx;
    rbx = rax != -1;
    return rbx;
}

