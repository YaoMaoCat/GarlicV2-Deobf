
  char* sub_180024e98(void* arg1)

{
    void var_788;
    int64_t rax_1 = __security_cookie ^ &var_788;
    uint32_t CodePage = *(arg1 + 4);
    CPINFO cPInfo;
    cPInfo.LeadByte[0xa] = 0;
    cPInfo.LeadByte[0xb] = 0;
    cPInfo.MaxCharSize = 0;
    cPInfo.DefaultChar[0] = 0;
    cPInfo.DefaultChar[1] = 0;
    cPInfo.LeadByte[0] = 0;
    cPInfo.LeadByte[1] = 0;
    cPInfo.LeadByte[2] = 0;
    cPInfo.LeadByte[3] = 0;
    cPInfo.LeadByte[4] = 0;
    cPInfo.LeadByte[5] = 0;
    cPInfo.LeadByte[6] = 0;
    cPInfo.LeadByte[7] = 0;
    cPInfo.LeadByte[8] = 0;
    cPInfo.LeadByte[9] = 0;
    BOOL rax_2;
    
    if (CodePage != 0xfde9)
        rax_2 = GetCPInfo(CodePage, &cPInfo);
    
    char* result;
    
    if (CodePage == 0xfde9 || !rax_2)
    {
        int32_t i = 0;
        char* rcx_3 = arg1 + 0x19;
        
        do
        {
            if (i - 0x41 <= 0x19)
            {
                *rcx_3 |= 0x10;
                result = i + 0x20;
            }
            else if (i - 0x61 > 0x19)
                result = 0;
            else
            {
                *rcx_3 |= 0x20;
                result = i - 0x20;
            }
            
            rcx_3[0x100] = result;
            i += 1;
            rcx_3 = &rcx_3[1];
        } while (i < 0x100);
    }
    else
    {
        int32_t i_1 = 0;
        char var_718[0x90];
        char (* rcx)[0x90] = &var_718;
        int64_t i_4 = 0x100;
        
        do
        {
            *rcx = i_1;
            i_1 += 1;
            rcx = &(*rcx)[1];
        } while (i_1 < 0x100);
        
        i_1 = cPInfo.LeadByte[0];
        BYTE (* rdx_2)[0xc] = &cPInfo.LeadByte;
        var_718[0] = 0x20;
        
        while (i_1)
        {
            uint32_t i_2 = (*rdx_2)[1];
            uint64_t rcx_1 = i_1;
            
            while (rcx_1 <= i_2)
            {
                if (rcx_1 >= 0x100)
                    break;
                
                var_718[rcx_1] = 0x20;
                rcx_1 = rcx_1 + 1;
            }
            
            rdx_2 = &(*rdx_2)[2];
            i_1 = *rdx_2;
        }
        
        uint16_t var_418[0x200];
        __acrt_GetStringTypeA(nullptr, 1, &var_718, 0x100, &var_418, *(arg1 + 4), 0);
        uint32_t var_760_1;
        void var_618;
        var_760_1 = &var_618;
        uint16_t* var_768_1;
        var_768_1 = 0x100;
        __acrt_LCMapStringA(nullptr, *(arg1 + 0x220), 0x100, &var_718, var_768_1, var_760_1, 0x100, 
            *(arg1 + 4), 0);
        void var_518;
        var_760_1 = &var_518;
        var_768_1 = 0x100;
        __acrt_LCMapStringA(nullptr, *(arg1 + 0x220), 0x200, &var_718, var_768_1, var_760_1, 0x100, 
            *(arg1 + 4), 0);
        uint16_t (* rdx_5)[0x200] = &var_418;
        result = arg1 + 0x19;
        int64_t i_3;
        
        do
        {
            char rcx_2;
            
            if (*rdx_5 & 1)
            {
                *result |= 0x10;
                rcx_2 = result[&var_618 - arg1 - 0x19];
            }
            else if (!(*rdx_5 & 2))
                rcx_2 = 0;
            else
            {
                *result |= 0x20;
                rcx_2 = result[&var_518 - arg1 - 0x19];
            }
            
            result[0x100] = rcx_2;
            rdx_5 = &(*rdx_5)[1];
            result = &result[1];
            i_3 = i_4;
            i_4 -= 1;
        } while (i_3 != 1);
    }
    
    __security_check_cookie(rax_1 ^ &var_788);
    return result;
}

