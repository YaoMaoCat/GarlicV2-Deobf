
  uint64_t sub_1800296dc(int64_t* arg1, int64_t arg2, int32_t arg3, char* arg4, int32_t arg5, char* arg6, int32_t arg7, uint32_t arg8)

{
    int64_t __saved_rbp_1;
    int64_t __saved_rbp = __saved_rbp_1;
    int64_t __saved_rbx_1;
    int64_t __saved_rbx = __saved_rbx_1;
    int64_t __saved_rsi_1;
    int64_t __saved_rsi = __saved_rsi_1;
    int64_t __saved_rdi_1;
    int64_t __saved_rdi = __saved_rdi_1;
    int64_t __saved_r12_1;
    int64_t __saved_r12 = __saved_r12_1;
    int64_t __saved_r13_1;
    int64_t __saved_r13 = __saved_r13_1;
    int64_t __saved_r14_1;
    int64_t __saved_r14 = __saved_r14_1;
    int64_t __saved_r15_1;
    int64_t __saved_r15 = __saved_r15_1;
    void var_d8;
    void* rsp_1 = &var_d8;
    int32_t var_88;
    int64_t rax_1 = __security_cookie ^ &var_88;
    int64_t rdi = arg5;
    uint8_t* r14 = arg4;
    var_88 = arg3;
    uint64_t result;
    
    if (rdi <= 0)
    {
        if (rdi >= 0xffffffff)
            goto label_180029743;
        
        result = 0;
    }
    else
    {
        rdi = __strncnt(arg4, rdi);
    label_180029743:
        int64_t rsi = arg7;
        
        if (rsi <= 0)
        {
            if (rsi >= 0xffffffff)
                goto label_180029767;
            
            result = 0;
        }
        else
        {
            rsi = __strncnt(arg6, rsi);
        label_180029767:
            uint32_t CodePage = arg8;
            
            if (!CodePage)
                CodePage = *(*arg1 + 0xc);
            
            if (!rdi || !rsi)
            {
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
                
                if (rdi == rsi)
                {
                label_180029a64:
                    result = 2;
                }
                else if (rsi > 1)
                    result = 1;
                else if (rdi > 1)
                    result = 3;
                else if (!GetCPInfo(CodePage, &cPInfo))
                    result = 0;
                else
                {
                    uint8_t rcx_3;
                    
                    if (rdi <= 0)
                    {
                        if (rsi <= 0)
                            goto label_180029838;
                        
                        if (cPInfo.MaxCharSize >= 2)
                        {
                            BYTE (* rax_7)[0xc] = &cPInfo.LeadByte;
                            
                            if (cPInfo.LeadByte[0])
                            {
                                while ((*rax_7)[1])
                                {
                                    rcx_3 = *arg6;
                                    
                                    if (rcx_3 >= *rax_7 && rcx_3 <= (*rax_7)[1])
                                        goto label_180029a64;
                                    
                                    rax_7 = &(*rax_7)[2];
                                    
                                    if (!*rax_7)
                                        break;
                                }
                            }
                        }
                        
                        result = 1;
                    }
                    else
                    {
                        if (cPInfo.MaxCharSize >= 2)
                        {
                            BYTE (* rax_6)[0xc] = &cPInfo.LeadByte;
                            
                            if (cPInfo.LeadByte[0])
                            {
                                while ((*rax_6)[1])
                                {
                                    rcx_3 = *r14;
                                    
                                    if (rcx_3 >= *rax_6 && rcx_3 <= (*rax_6)[1])
                                        goto label_180029a64;
                                    
                                    rax_6 = &(*rax_6)[2];
                                    
                                    if (!*rax_6)
                                        break;
                                }
                            }
                        }
                        
                        result = 3;
                    }
                }
            }
            else
            {
            label_180029838:
                int32_t var_b0_1 = 0;
                int64_t var_b8_1 = 0;
                int32_t rax_8 = __acrt_MultiByteToWideChar(CodePage, 
                    MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, r14, rdi);
                int64_t r13 = rax_8;
                
                if (!rax_8)
                    result = 0;
                else
                {
                    int64_t rdx_4 = r13 * 2;
                    uint64_t rdx_6 = (rdx_4 - rdx_4) & (rdx_4 + 0x10);
                    
                    if (!rdx_6)
                        result = 0;
                    else
                    {
                        int32_t* rbx_1;
                        
                        if (rdx_6 > 0x400)
                        {
                            int32_t* rax_11 = _malloc_base(rdx_6);
                            rbx_1 = rax_11;
                            
                            if (rax_11)
                            {
                                *rax_11 = 0xdddd;
                            label_1800298d0:
                                rbx_1 = &rbx_1[4];
                            }
                            
                            if (!rbx_1)
                                result = 0;
                            else
                            {
                                *(rsp_1 + 0x28) = r13;
                                *(rsp_1 + 0x20) = rbx_1;
                                void* rcx_18;
                                bool cond:0_1;
                                
                                if (!__acrt_MultiByteToWideChar(CodePage, MB_PRECOMPOSED, r14, rdi))
                                {
                                label_180029a34:
                                    rcx_18 = &rbx_1[-4];
                                    cond:0_1 = *rcx_18 != 0xdddd;
                                label_180029a3e:
                                    
                                    if (cond:0_1)
                                        result = 0;
                                    else
                                    {
                                        _free_base(rcx_18);
                                        result = 0;
                                    }
                                }
                                else
                                {
                                    *(rsp_1 + 0x28) = 0;
                                    *(rsp_1 + 0x20) = 0;
                                    int32_t rax_13 = __acrt_MultiByteToWideChar(CodePage, 
                                        MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, arg6, rsi);
                                    int64_t r12_1 = rax_13;
                                    
                                    if (!rax_13)
                                        goto label_180029a34;
                                    
                                    int64_t rcx_10 = r12_1 * 2;
                                    uint64_t rcx_12 = (rcx_10 - rcx_10) & (rcx_10 + 0x10);
                                    
                                    if (!rcx_12)
                                        goto label_180029a34;
                                    
                                    int32_t* rdi_1;
                                    
                                    if (rcx_12 > 0x400)
                                    {
                                        int32_t* rax_17 = _malloc_base(rcx_12);
                                        rdi_1 = rax_17;
                                        
                                        if (rax_17)
                                        {
                                            *rax_17 = 0xdddd;
                                            rdi_1 = &rdi_1[4];
                                        }
                                    }
                                    else
                                    {
                                        int64_t rax_15 = rcx_12 + 0xf;
                                        
                                        if (rax_15 <= rcx_12)
                                            rax_15 = 0xffffffffffffff0;
                                        
                                        int64_t rax_16 = rax_15 & 0xfffffffffffffff0;
                                        __chkstk(rax_16);
                                        rsp_1 -= rax_16;
                                        rdi_1 = rsp_1 + 0x50;
                                        
                                        if (!rdi_1)
                                            goto label_180029a34;
                                        
                                        *rdi_1 = 0xcccc;
                                        rdi_1 = &rdi_1[4];
                                    }
                                    
                                    if (!rdi_1)
                                        goto label_180029a34;
                                    
                                    *(rsp_1 + 0x28) = r12_1;
                                    *(rsp_1 + 0x20) = rdi_1;
                                    
                                    if (!__acrt_MultiByteToWideChar(CodePage, MB_PRECOMPOSED, arg6, 
                                        rsi))
                                    {
                                        if (rdi_1[-4] == 0xdddd)
                                            _free_base(&rdi_1[-4]);
                                        
                                        rcx_18 = &rbx_1[-4];
                                        cond:0_1 = *rcx_18 != 0xdddd;
                                        goto label_180029a3e;
                                    }
                                    
                                    uint64_t rdx_7 = var_88;
                                    __builtin_memset(rsp_1 + 0x30, 0, 0x18);
                                    *(rsp_1 + 0x28) = r12_1;
                                    *(rsp_1 + 0x20) = rdi_1;
                                    int32_t result_1 = sub_1800261bc(arg2, rdx_7, rbx_1, r13);
                                    
                                    if (rdi_1[-4] == 0xdddd)
                                        _free_base(&rdi_1[-4]);
                                    
                                    if (rbx_1[-4] == 0xdddd)
                                        _free_base(&rbx_1[-4]);
                                    
                                    result = result_1;
                                }
                            }
                        }
                        else
                        {
                            int64_t rax_9 = rdx_6 + 0xf;
                            
                            if (rax_9 <= rdx_6)
                                rax_9 = 0xffffffffffffff0;
                            
                            int64_t rax_10 = rax_9 & 0xfffffffffffffff0;
                            __chkstk(rax_10);
                            rsp_1 = &var_d8 - rax_10;
                            rbx_1 = rsp_1 + 0x50;
                            
                            if (rbx_1)
                            {
                                *rbx_1 = 0xcccc;
                                goto label_1800298d0;
                            }
                            
                            result = 0;
                        }
                    }
                }
            }
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_88);
    return result;
}

