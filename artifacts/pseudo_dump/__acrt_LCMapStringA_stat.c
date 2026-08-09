
🌐  int64_t __acrt_LCMapStringA_stat(int64_t* arg1, int64_t arg2, int32_t arg3, char* arg4, int32_t arg5, int64_t arg6, int32_t arg7, uint32_t arg8, int32_t arg9)

{
    int64_t __saved_rbp_1;
    int64_t __saved_rbp = __saved_rbp_1;
    int64_t __saved_r12_1;
    int64_t __saved_r12 = __saved_r12_1;
    int64_t __saved_r13_1;
    int64_t __saved_r13 = __saved_r13_1;
    int64_t __saved_r14_1;
    int64_t __saved_r14 = __saved_r14_1;
    int64_t __saved_r15_1;
    int64_t __saved_r15 = __saved_r15_1;
    void var_88;
    void* rsp_1 = &var_88;
    int64_t __saved_rbx_1;
    int64_t __saved_rbx = __saved_rbx_1;
    int64_t __saved_rsi_1;
    int64_t __saved_rsi = __saved_rsi_1;
    int64_t __saved_rdi_1;
    int64_t __saved_rdi = __saved_rdi_1;
    void var_38;
    int64_t rax_1 = __security_cookie ^ &var_38;
    int64_t rdi = arg5;
    uint8_t* rsi = arg4;
    int64_t r13 = arg2;
    
    if (rdi > 0)
    {
        arg2 = rdi;
        int32_t rax_2 = __strncnt(arg4, arg2);
        bool cond:0_1 = rax_2 < rdi;
        rdi = rax_2 + 1;
        
        if (!cond:0_1)
            rdi = rax_2;
    }
    
    uint32_t r14 = arg8;
    
    if (!r14)
        r14 = *(*arg1 + 0xc);
    
    int32_t temp0 = arg9;
    arg9 = -(arg9);
    int32_t var_60 = 0;
    int64_t var_68 = 0;
    int32_t result = __acrt_MultiByteToWideChar(r14, ((arg2 - arg2) & 8) + 1, rsi, rdi);
    int64_t result_1 = result;
    
    if (result)
    {
        int64_t rax_5 = result_1 * 2;
        uint64_t rax_7 = (rax_5 - rax_5) & (rax_5 + 0x10);
        int32_t* rbx_1;
        int64_t rsi_1;
        
        if (rax_7)
        {
            if (rax_7 > 0x400)
            {
                int32_t* rax_9 = _malloc_base(rax_7);
                rbx_1 = rax_9;
                
                if (rax_9)
                {
                    *rax_9 = 0xdddd;
                    rbx_1 = &rbx_1[4];
                }
            }
            else
            {
                int64_t rcx_3 = rax_7 + 0xf;
                
                if (rcx_3 <= rax_7)
                    rcx_3 = 0xffffffffffffff0;
                
                int64_t rcx_4 = rcx_3 & 0xfffffffffffffff0;
                __chkstk(rcx_4);
                rsp_1 = &var_88 - rcx_4;
                rbx_1 = rsp_1 + 0x50;
                
                if (!rbx_1)
                    goto label_180023d1d;
                
                *rbx_1 = 0xcccc;
                rbx_1 = &rbx_1[4];
            }
            
            if (!rbx_1)
                goto label_180023d1d;
            
            *(rsp_1 + 0x28) = result_1;
            *(rsp_1 + 0x20) = rbx_1;
            
            if (!__acrt_MultiByteToWideChar(r14, MB_PRECOMPOSED, rsi, rdi))
                goto label_180023d1d;
            
            __builtin_memset(rsp_1 + 0x30, 0, 0x18);
            *(rsp_1 + 0x28) = 0;
            *(rsp_1 + 0x20) = 0;
            int32_t rax_11 = sub_1800262b4(r13, arg3, rbx_1, result_1);
            rsi_1 = rax_11;
            
            if (!rax_11)
                goto label_180023d1d;
            
            if (0x400 & arg3)
            {
                if (!arg7)
                    goto label_180023d28;
                
                if (rsi_1 > arg7)
                    goto label_180023d1d;
                
                __builtin_memset(rsp_1 + 0x30, 0, 0x18);
                *(rsp_1 + 0x28) = arg7;
                *(rsp_1 + 0x20) = arg6;
                int32_t rax_14 = sub_1800262b4(r13, arg3, rbx_1, result_1);
                rsi_1 = rax_14;
                
                if (rax_14)
                    goto label_180023d28;
                
                goto label_180023d1d;
            }
            
            int64_t rcx_10 = rsi_1 * 2;
            uint64_t rcx_12 = (rcx_10 - rcx_10) & (rcx_10 + 0x10);
            int32_t* rdi_1;
            
            if (!rcx_12)
            {
                rdi_1 = nullptr;
            label_180023d00:
                
                if (!rdi_1 || rdi_1[-4] != 0xdddd)
                    rsi_1 = 0;
                else
                {
                    _free_base(&rdi_1[-4]);
                    rsi_1 = 0;
                }
            }
            else if (rcx_12 > 0x400)
            {
                int32_t* rax_18 = _malloc_base(rcx_12);
                rdi_1 = rax_18;
                
                if (rax_18)
                {
                    *rax_18 = 0xdddd;
                label_180023c66:
                    rdi_1 = &rdi_1[4];
                }
                
                if (!rdi_1)
                    rsi_1 = 0;
                else
                {
                    __builtin_memset(rsp_1 + 0x30, 0, 0x18);
                    *(rsp_1 + 0x28) = rsi_1;
                    *(rsp_1 + 0x20) = rdi_1;
                    int64_t rdx_6 = 0;
                    
                    if (!sub_1800262b4(r13, arg3, rbx_1, result_1))
                        goto label_180023d00;
                    
                    uint64_t r9_5 = rsi_1;
                    *(rsp_1 + 0x38) = 0;
                    *(rsp_1 + 0x30) = 0;
                    uint64_t rcx_14 = r14;
                    
                    if (!arg7)
                    {
                        *(rsp_1 + 0x28) = 0;
                        *(rsp_1 + 0x20) = 0;
                        int32_t rax_21 = __acrt_WideCharToMultiByte(rcx_14, rdx_6, rdi_1, r9_5);
                        rsi_1 = rax_21;
                        
                        if (rax_21)
                            goto label_180023cee;
                        
                        goto label_180023d00;
                    }
                    
                    *(rsp_1 + 0x28) = arg7;
                    *(rsp_1 + 0x20) = arg6;
                    int32_t rax_23 = __acrt_WideCharToMultiByte(rcx_14, rdx_6, rdi_1, r9_5);
                    rsi_1 = rax_23;
                    
                    if (rax_23)
                    {
                    label_180023cee:
                        
                        if (rdi_1[-4] == 0xdddd)
                            _free_base(&rdi_1[-4]);
                    }
                    else if (rdi_1[-4] != 0xdddd)
                        rsi_1 = 0;
                    else
                    {
                        _free_base(&rdi_1[-4]);
                        rsi_1 = 0;
                    }
                }
            }
            else
            {
                int64_t rax_16 = rcx_12 + 0xf;
                
                if (rax_16 <= rcx_12)
                    rax_16 = 0xffffffffffffff0;
                
                int64_t rax_17 = rax_16 & 0xfffffffffffffff0;
                __chkstk(rax_17);
                rsp_1 -= rax_17;
                rdi_1 = rsp_1 + 0x50;
                
                if (rdi_1)
                {
                    *rdi_1 = 0xcccc;
                    goto label_180023c66;
                }
                
                rsi_1 = 0;
            }
            goto label_180023d28;
        }
        
        rbx_1 = nullptr;
    label_180023d1d:
        rsi_1 = 0;
        
        if (rbx_1)
        {
        label_180023d28:
            
            if (rbx_1[-4] == 0xdddd)
                _free_base(&rbx_1[-4]);
        }
        
        result = rsi_1;
    }
    
    __security_check_cookie(rax_1 ^ &var_38);
    return result;
}

