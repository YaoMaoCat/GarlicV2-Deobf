
🌐  uint64_t __acrt_SetEnvironmentVariableA(char* arg1, char* arg2)

{
    int64_t var_48;
    __builtin_memset(&var_48, 0, 0x29);
    PWSTR lpValue = nullptr;
    int64_t var_78;
    __builtin_memset(&var_78, 0, 0x29);
    void* var_98;
    _LocaleUpdate::_LocaleUpdate(&var_98, nullptr);
    uint32_t rbx = 0xfde9;
    void* var_90;
    char var_80;
    uint32_t r9;
    
    if (*(var_90 + 0xc) != 0xfde9)
    {
        if (sub_180026170())
        {
            if (var_80)
            {
                void* rax_4 = var_98;
                *(rax_4 + 0x3a8) &= 0xfffffffd;
            }
            
            r9 = 0;
        }
        else
        {
            if (var_80)
            {
                void* rax_3 = var_98;
                *(rax_3 + 0x3a8) &= 0xfffffffd;
            }
            
            r9 = 1;
        }
    }
    else
    {
        if (var_80)
        {
            void* rax_1 = var_98;
            *(rax_1 + 0x3a8) &= 0xfffffffd;
        }
        
        r9 = 0xfde9;
    }
    
    void arg_18;
    int32_t rax_5 = sub_180023efc(arg1, &var_48, &arg_18, r9);
    int32_t rax_11;
    
    if (!rax_5)
    {
        _LocaleUpdate::_LocaleUpdate(&var_98, nullptr);
        
        if (*(var_90 + 0xc) != 0xfde9)
        {
            if (sub_180026170())
            {
                if (var_80)
                {
                    void* rax_10 = var_98;
                    *(rax_10 + 0x3a8) &= 0xfffffffd;
                }
                
                rbx = 0;
            }
            else
            {
                if (var_80)
                {
                    void* rax_9 = var_98;
                    *(rax_9 + 0x3a8) &= 0xfffffffd;
                }
                
                rbx = 1;
            }
        }
        else if (var_80)
        {
            void* rax_7 = var_98;
            *(rax_7 + 0x3a8) &= 0xfffffffd;
        }
        
        rax_11 = sub_180023efc(arg2, &var_78, &arg_18, rbx);
        PWSTR lpValue_1;
        lpValue = lpValue_1;
    }
    
    PWSTR lpName;
    BOOL rbx_1;
    
    if (rax_5 || rax_11)
        rbx_1 = 0;
    else
        rbx_1 = SetEnvironmentVariableW(lpName, lpValue);
    
    char var_50;
    
    if (var_50)
        _free_base(lpValue);
    
    char var_20;
    
    if (var_20)
        _free_base(lpName);
    
    return rbx_1;
}

