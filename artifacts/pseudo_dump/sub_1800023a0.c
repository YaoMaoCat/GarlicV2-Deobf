
  int64_t sub_1800023a0(int64_t arg1, int64_t arg2)

{
    int64_t arg_10 = arg2;
    int64_t r8;
    int64_t arg_18 = r8;
    int64_t r9;
    int64_t arg_20 = r9;
    void var_648;
    int64_t rax_1 = __security_cookie ^ &var_648;
    
    if (!data_180047498)
    {
        InitializeCriticalSection(&data_180047470);
        data_180047498 = 1;
    }
    
    EnterCriticalSection(&data_180047470);
    HANDLE rax_8;
    
    if (data_180047499)
    {
        rax_8 = data_180046000;
    label_1800025a4:
        
        if (rax_8 != -1)
            goto label_1800025e0;
    }
    else
    {
        bool cond:0_1 = data_180046000 != -1;
        data_180047499 = 1;
        uint8_t var_4e8;
        
        if (!cond:0_1)
        {
            PSTR lpString2 = j_common_getenv<char>("APPDATA");
            HANDLE rbx_1 = -ffffffffffffffff;
            void* rax_3;
            
            if (lpString2)
                rax_3 = strlen(lpString2) + 0x20;
            
            HANDLE rax_4;
            
            if (!lpString2 || rax_3 >= 0x104)
                rax_4 = data_180046000;
            else
            {
                uint8_t var_5f8[0x110];
                lstrcpynA(&var_5f8, lpString2, 0x104);
                lstrcatA(&var_5f8, "\.minecraft\proxy.log");
                
                if (!var_5f8[0])
                {
                    rax_4 = -ffffffffffffffff;
                    data_180046000 = -1;
                }
                else
                {
                    rax_4 = CreateFileA(&var_5f8, 4, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, 
                        OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
                    data_180046000 = rax_4;
                }
            }
            
            if (rax_4 != -1)
                goto label_1800025e0;
            
            if (GetTempPathA(0x104, &var_4e8) - 1 > 0xea)
                rbx_1 = data_180046000;
            else
            {
                lstrcatA(&var_4e8, "MinecraftProxy.log");
                
                if (var_4e8)
                    rbx_1 = CreateFileA(&var_4e8, 4, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, 
                        OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
                
                data_180046000 = rbx_1;
            }
            
            if (rbx_1 != -1)
                goto label_1800025e0;
            
            rax_8 = CreateFileA("C:\MinecraftProxy.log", 4, FILE_SHARE_READ | FILE_SHARE_WRITE, 
                nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
            data_180046000 = rax_8;
            goto label_1800025a4;
        }
        
    label_1800025e0:
        int64_t rcx_7 = sub_180001c70(&var_4e8, 0x4b0, "[%08lu] ", GetTickCount());
        __stdio_common_vsprintf(data_180047458 | 2, &(&var_4e8)[rcx_7], 0x4ae - rcx_7, arg1, 
            nullptr, &arg_10);
        void* rax_11 = strlen(&var_4e8);
        
        if (rax_11 < 0x4ae)
        {
            *(&var_4e8 + rax_11) = 0xa0d;
            rax_11 += 2;
        }
        
        HANDLE hFile = data_180046000;
        uint32_t numberOfBytesWritten[0x4];
        numberOfBytesWritten[0] = 0;
        WriteFile(hFile, &var_4e8, rax_11, &numberOfBytesWritten, nullptr);
    }
    int64_t result = LeaveCriticalSection(&data_180047470);
    __security_check_cookie(rax_1 ^ &var_648);
    return result;
}

