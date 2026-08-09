
  uint64_t sub_180024608(char* arg1, char* arg2, int64_t* arg3, int64_t arg4 @ r13)

{
    int64_t var_30 = arg4;
    void var_378;
    int64_t var_48 = __security_cookie ^ &var_378;
    int64_t* r12 = arg3;
    int64_t rax_1;
    
    if (arg2 != arg1)
    {
        do
        {
            rax_1 = *arg2;
            rax_1 -= 0x2f;
            
            if (rax_1 <= 0x2d && TEST_BITQ(0x200000000801, rax_1))
                break;
            
            rax_1 = _mbsdec(arg1, arg2);
            arg2 = rax_1;
        } while (rax_1 != arg1);
    }
    
    arg3 = *arg2;
    uint64_t result;
    
    if (arg3 != 0x3a || arg2 == &arg1[1])
    {
        arg3 -= 0x2f;
        
        if (arg3 <= 0x2d)
            rax_1 = 1;
        
        if (arg3 > 0x2d || !TEST_BITQ(0x200000000801, arg3))
            rax_1 = 0;
        
        char temp0_1 = rax_1;
        rax_1 = -(rax_1);
        void* r13_1 = (arg4 - arg4) & (arg2 - arg1 + 1);
        void* var_340_1 = r13_1;
        void findFileData;
        sub_18002de50(&findFileData, 0, 0x250);
        int64_t var_338;
        __builtin_memset(&var_338, 0, 0x29);
        void* var_308;
        _LocaleUpdate::_LocaleUpdate(&var_308, nullptr);
        void* var_300;
        uint32_t r9_1;
        char var_2f0;
        
        if (*(var_300 + 0xc) != 0xfde9)
        {
            if (sub_180026170())
            {
                if (var_2f0)
                {
                    void* rax_6 = var_308;
                    *(rax_6 + 0x3a8) &= 0xfffffffd;
                }
                
                r9_1 = 0;
            }
            else
            {
                if (var_2f0)
                {
                    void* rax_5 = var_308;
                    *(rax_5 + 0x3a8) &= 0xfffffffd;
                }
                
                r9_1 = 1;
            }
        }
        else
        {
            if (var_2f0)
            {
                void* rax_3 = var_308;
                *(rax_3 + 0x3a8) &= 0xfffffffd;
            }
            
            r9_1 = 0xfde9;
        }
        PWSTR lpFileName_1;
        PWSTR lpFileName = lpFileName_1;
        void var_348;
        
        if (sub_180023efc(arg1, &var_338, &var_348, r9_1))
            lpFileName = nullptr;
        
        HANDLE hFindFile = FindFirstFileExW(lpFileName, FindExInfoStandard, &findFileData, 
            FindExSearchNameMatch, 0, 0);
        char var_310;
        
        if (hFindFile != -1)
        {
            int64_t rsi_3 = (r12[1] - *r12) >> 3;
            
            while (true)
            {
                int64_t var_2c8;
                __builtin_memset(&var_2c8, 0, 0x29);
                void* var_2e8;
                _LocaleUpdate::_LocaleUpdate(&var_2e8, nullptr);
                void* var_2e0;
                uint32_t r9_3;
                char var_2d0;
                
                if (*(var_2e0 + 0xc) != 0xfde9)
                {
                    if (sub_180026170())
                    {
                        if (var_2d0)
                        {
                            void* rax_12 = var_2e8;
                            *(rax_12 + 0x3a8) &= 0xfffffffd;
                        }
                        
                        r9_3 = 0;
                    }
                    else
                    {
                        if (var_2d0)
                        {
                            void* rax_11 = var_2e8;
                            *(rax_11 + 0x3a8) &= 0xfffffffd;
                        }
                        
                        r9_3 = 1;
                    }
                }
                else
                {
                    if (var_2d0)
                    {
                        void* rax_9 = var_2e8;
                        *(rax_9 + 0x3a8) &= 0xfffffffd;
                    }
                    
                    r9_3 = 0xfde9;
                }
                char* var_2b8;
                char* rcx_9 = var_2b8;
                int16_t var_26c[0x112];
                
                if (sub_18002409c(&var_26c, &var_2c8, &var_348, r9_3))
                    rcx_9 = nullptr;
                
                int32_t rax_13;
                
                if (*rcx_9 == 0x2e)
                    rax_13 = rcx_9[1];
                
                char var_2a0;
                
                if (*rcx_9 != 0x2e || (rax_13 && (rax_13 != 0x2e || rcx_9[2])))
                {
                    int32_t result_2 = sub_180024484(rcx_9, arg1, r13_1, r12);
                    
                    if (result_2)
                    {
                        if (var_2a0)
                            _free_base(var_2b8);
                        
                        FindClose(hFindFile);
                        
                        if (var_310)
                            _free_base(lpFileName_1);
                        
                        result = result_2;
                        break;
                    }
                    
                    if (var_2a0 != result_2)
                        _free_base(var_2b8);
                    
                    r13_1 = var_340_1;
                }
                else if (var_2a0)
                    _free_base(var_2b8);
                
                if (!FindNextFileW(hFindFile, &findFileData))
                {
                    int64_t rax_15 = *r12;
                    int64_t rdx_8 = (r12[1] - rax_15) >> 3;
                    
                    if (rsi_3 != rdx_8)
                        sub_180029b20(rax_15 + (rsi_3 << 3), rdx_8 - rsi_3, 8, 
                            <lambda_2feae5270eb4d0d5532525f423405775>::<helper_func_cdecl>);
                    
                    FindClose(hFindFile);
                    
                    if (var_310)
                        _free_base(lpFileName_1);
                    
                    result = 0;
                    break;
                }
            }
        }
        else
        {
            int32_t result_1 = sub_180024484(arg1, 0, 0, r12);
            
            if (var_310)
                _free_base(lpFileName_1);
            
            result = result_1;
        }
    }
    else
        result = sub_180024484(arg1, 0, 0, r12);
    
    __security_check_cookie(var_48 ^ &var_378);
    return result;
}

