
🌐  uint64_t __acrt_GetStringTypeA(int128_t* arg1, uint32_t arg2, uint8_t* arg3, int32_t arg4, uint16_t* arg5, uint32_t arg6, int32_t arg7)

{
    void var_88;
    void* rsp = &var_88;
    void var_58;
    int64_t rax_1 = __security_cookie ^ &var_58;
    void* var_50;
    int32_t rdx_1 = _LocaleUpdate::_LocaleUpdate(&var_50, arg1);
    uint32_t rdi = arg6;
    void* var_48;
    
    if (!rdi)
        rdi = *(var_48 + 0xc);
    int32_t temp0 = arg7;
    arg7 = -(arg7);
    int32_t var_60 = 0;
    int64_t var_68 = 0;
    int32_t rax_3;
    int64_t rcx_2;
    rax_3 = __acrt_MultiByteToWideChar(rdi, ((rdx_1 - rdx_1) & 8) + 1, arg3, arg4);
    int64_t r14 = rax_3;
    BOOL rdi_1;
    
    if (rax_3)
    {
        int64_t rsi_2 = r14 * 2;
        uint64_t rcx_4 = (rcx_2 - rcx_2) & (rsi_2 + 0x10);
        int128_t* lpSrcStr;
        
        if (!rcx_4)
        {
            lpSrcStr = nullptr;
        label_1800290c2:
            rdi_1 = 0;
            
            if (lpSrcStr)
                goto label_1800290cd;
        }
        else
        {
            if (rcx_4 > 0x400)
            {
                int128_t* lpSrcStr_1 = _malloc_base(rcx_4);
                lpSrcStr = lpSrcStr_1;
                
                if (lpSrcStr_1)
                {
                    *lpSrcStr_1 = 0xdddd;
                    lpSrcStr = &lpSrcStr[1];
                }
            }
            else
            {
                int64_t rax_5 = rcx_4 + 0xf;
                
                if (rax_5 <= rcx_4)
                    rax_5 = 0xffffffffffffff0;
                
                int64_t rax_6 = rax_5 & 0xfffffffffffffff0;
                __chkstk(rax_6);
                rsp = &var_88 - rax_6;
                lpSrcStr = rsp + 0x30;
                
                if (!lpSrcStr)
                    goto label_1800290c2;
                
                *lpSrcStr = 0xcccc;
                lpSrcStr = &lpSrcStr[1];
            }
            
            if (!lpSrcStr)
                goto label_1800290c2;
            
            sub_18002de50(lpSrcStr, 0, rsi_2);
            *(rsp + 0x28) = r14;
            *(rsp + 0x20) = lpSrcStr;
            int32_t cchSrc = __acrt_MultiByteToWideChar(rdi, MB_PRECOMPOSED, arg3, arg4);
            
            if (!cchSrc)
                goto label_1800290c2;
            
            rdi_1 = GetStringTypeW(arg2, lpSrcStr, cchSrc, arg5);
        label_1800290cd:
            
            if (lpSrcStr[-1] == 0xdddd)
                _free_base(&lpSrcStr[-1]);
        }
    }
    else
        rdi_1 = 0;
    
    char var_38;
    
    if (var_38)
    {
        void* rax_8 = var_50;
        *(rax_8 + 0x3a8) &= 0xfffffffd;
    }
    
    __security_check_cookie(rax_1 ^ &var_58);
    return rdi_1;
}

