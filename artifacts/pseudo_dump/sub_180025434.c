
  int64_t sub_180025434(uint32_t arg1, void* arg2)

{
    void var_68;
    int64_t rax_1 = __security_cookie ^ &var_68;
    CPINFO cPInfo;
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
    cPInfo.LeadByte[0xa] = 0;
    cPInfo.LeadByte[0xb] = 0;
    uint32_t CodePage = getSystemCP(arg1);
    wchar16 const* const rbx = nullptr;
    int64_t result;
    
    if (!CodePage)
    {
        setSBCS(arg2);
        result = 0;
    }
    else
    {
        int32_t i = 0;
        int32_t* rax_2 = &data_180046f90;
        int32_t rbp_1 = 1;
        
        do
        {
            if (*rax_2 == CodePage)
            {
                sub_18002de50(arg2 + 0x18, 0, 0x101);
                char* r15_1 = &data_180046f80;
                int64_t j_3 = 4;
                uint64_t r11_2 = i * 0x30;
                char* r9_1 = &data_180046fa0 + r11_2;
                int64_t j;
                
                do
                {
                    char* rdx_2 = r9_1;
                    
                    if (*r9_1)
                    {
                        while (rdx_2[1])
                        {
                            uint32_t r8_1 = *rdx_2;
                            
                            if (r8_1 <= rdx_2[1])
                            {
                                uint64_t r10_1 = r8_1 + 1;
                                
                                while (r10_1 < 0x101)
                                {
                                    uint32_t rax_10;
                                    rax_10 = *r15_1;
                                    r8_1 += 1;
                                    *(r10_1 + arg2 + 0x18) |= rax_10;
                                    r10_1 = r10_1 + 1;
                                    
                                    if (r8_1 > rdx_2[1])
                                        break;
                                }
                            }
                            
                            rdx_2 = &rdx_2[2];
                            
                            if (!*rdx_2)
                                break;
                        }
                    }
                    
                    r9_1 = &r9_1[8];
                    r15_1 = &r15_1[1];
                    j = j_3;
                    j_3 -= 1;
                } while (j != 1);
                *(arg2 + 4) = CodePage;
                *(arg2 + 8) = 1;
                
                if (CodePage == 0x3a4)
                    rbx = u"ja-JP";
                else if (CodePage == 0x3a8)
                    rbx = u"zh-CN";
                else if (CodePage == 0x3b5)
                    rbx = u"ko-KR";
                else if (CodePage == 0x3b6)
                    rbx = u"zh-TW";
                
                *(arg2 + 0x220) = rbx;
                int16_t* rdx_3 = arg2 + 0xc;
                int64_t j_2 = 6;
                int64_t j_1;
                
                do
                {
                    *rdx_3 = *(r11_2 - arg2 + &data_180046f90 + rdx_3 - 8);
                    rdx_3 = &rdx_3[1];
                    j_1 = j_2;
                    j_2 -= 1;
                } while (j_1 != 1);
                goto label_1800256c5;
            }
            
            i += 1;
            rax_2 = &rax_2[0xc];
        } while (i < 5);
        
        if (CodePage == 0xfde8)
            result = 0xffffffff;
        else if (!IsValidCodePage(CodePage))
            result = 0xffffffff;
        else if (CodePage != 0xfde9)
        {
            if (GetCPInfo(CodePage, &cPInfo))
            {
                sub_18002de50(arg2 + 0x18, 0, 0x101);
                bool cond:0_1 = cPInfo.MaxCharSize != 2;
                *(arg2 + 4) = CodePage;
                *(arg2 + 0x220) = 0;
                
                if (cond:0_1)
                    rbp_1 = 0;
                else
                {
                    BYTE (* rcx_3)[0xc] = &cPInfo.LeadByte;
                    
                    if (cPInfo.LeadByte[0])
                    {
                        while ((*rcx_3)[1])
                        {
                            uint32_t rax_5 = (*rcx_3)[1];
                            uint32_t rdx_1 = *rcx_3;
                            
                            if (rdx_1 <= rax_5)
                            {
                                uint64_t rdi_2 = rdx_1 + 1;
                                uint64_t i_4 = rax_5 - rdx_1 + 1;
                                uint64_t i_1;
                                
                                do
                                {
                                    *(rdi_2 + arg2 + 0x18) |= 4;
                                    rdi_2 = rdi_2 + 1;
                                    i_1 = i_4;
                                    i_4 -= 1;
                                } while (i_1 != 1);
                            }
                            
                            rcx_3 = &(*rcx_3)[2];
                            
                            if (!*rcx_3)
                                break;
                        }
                    }
                    
                    char* rax_7 = arg2 + 0x1a;
                    int64_t i_3 = 0xfe;
                    int64_t i_2;
                    
                    do
                    {
                        *rax_7 |= 8;
                        rax_7 = &rax_7[1];
                        i_2 = i_3;
                        i_3 -= 1;
                    } while (i_2 != 1);
                    int32_t rcx_4 = *(arg2 + 4);
                    wchar16 const* const rax_8;
                    
                    if (rcx_4 == 0x3a4)
                        rax_8 = u"ja-JP";
                    else if (rcx_4 == 0x3a8)
                        rax_8 = u"zh-CN";
                    else if (rcx_4 == 0x3b5)
                        rax_8 = u"ko-KR";
                    else if (rcx_4 == 0x3b6)
                        rax_8 = u"zh-TW";
                    else
                        rax_8 = nullptr;
                    
                    *(arg2 + 0x220) = rax_8;
                }
                
                *(arg2 + 8) = rbp_1;
                goto label_1800254e4;
            }
            
            if (data_180047ec8)
            {
                setSBCS(arg2);
                result = 0;
            }
            else
                result = 0xffffffff;
        }
        else
        {
            *(arg2 + 4) = 0xfde9;
            *(arg2 + 0x220) = 0;
            *(arg2 + 0x18) = 0;
            *(arg2 + 0x1c) = 0;
        label_1800254e4:
            __builtin_memset(arg2 + 0xc, 0, 0xc);
        label_1800256c5:
            sub_180024e98(arg2);
            result = 0;
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_68);
    return result;
}

