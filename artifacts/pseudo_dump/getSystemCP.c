
🌐  uint64_t getSystemCP(uint32_t arg1)

{
    uint32_t rbx = arg1;
    void* var_28;
    _LocaleUpdate::_LocaleUpdate(&var_28, nullptr);
    data_180047ec8 = 0;
    
    if (rbx == 0xfffffffe)
    {
        data_180047ec8 = 1;
        rbx = GetOEMCP();
    }
    else if (rbx == 0xfffffffd)
    {
        data_180047ec8 = 1;
        rbx = GetACP();
    }
    else if (rbx == 0xfffffffc)
    {
        data_180047ec8 = 1;
        void* var_20;
        rbx = *(var_20 + 0xc);
    }
    
    char var_10;
    
    if (var_10)
    {
        void* rcx_1 = var_28;
        *(rcx_1 + 0x3a8) &= 0xfffffffd;
    }
    
    return rbx;
}

