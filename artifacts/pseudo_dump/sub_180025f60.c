
  int64_t sub_180025f60(int32_t arg1, PSTR arg2, int32_t* arg3, int64_t arg4)

{
    uint64_t r12 = arg1;
    int32_t* rsi = arg3;
    int64_t result;
    
    if (arg3 == arg4)
    {
    label_180026050:
        result = 0;
    }
    else
    {
        while (true)
        {
            uint64_t rdi_1 = *rsi;
            HMODULE rbx_1 = *((rdi_1 << 3) + &data_180047f00);
            
            if (!rbx_1)
            {
                int16_t* lpLibFileName = (&data_18003a500)[rdi_1];
                HMODULE rax_1 =
                    LoadLibraryExW(lpLibFileName, nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
                rbx_1 = rax_1;
                
                if (rax_1)
                {
                label_1800260e2:
                    int64_t temp0_2 = *((rdi_1 << 3) + &data_180047f00);
                    *((rdi_1 << 3) + &data_180047f00) = rbx_1;
                    
                    if (temp0_2)
                        FreeLibrary(rbx_1);
                    
                    result = GetProcAddress(rbx_1, arg2);
                    break;
                }
                
                enum WIN32_ERROR rax_2 = GetLastError();
                
                if (rax_2 != ERROR_INVALID_PARAMETER)
                    *((rdi_1 << 3) + &data_180047f00) = -1;
                else if (!sub_180028f50(lpLibFileName, u"api-ms-", rax_2 - 0x50))
                    *((rdi_1 << 3) + &data_180047f00) = -1;
                else if (!sub_180028f50(lpLibFileName, u"ext-ms-", rax_2 - 0x50))
                    *((rdi_1 << 3) + &data_180047f00) = -1;
                else
                {
                    HMODULE rax_5 = LoadLibraryExW(lpLibFileName, nullptr, 0);
                    rbx_1 = rax_5;
                    
                    if (rax_5)
                        goto label_1800260e2;
                    
                    *((rdi_1 << 3) + &data_180047f00) = -1;
                }
            }
            else if (rbx_1 != -1)
            {
                result = GetProcAddress(rbx_1, arg2);
                break;
            }
            
            rsi = &rsi[1];
            
            if (rsi == arg4)
                goto label_180026050;
        }
    }
    
    sub_1800239bc(0xe);
    enum PAGE_PROTECTION_FLAGS lpflOldProtect = 0;
    
    if (VirtualProtect(&data_18004c000, 0x100, PAGE_READWRITE, &lpflOldProtect))
    {
        int64_t result_1 = result;
        
        if (!result)
            result_1 = -1;
        
        (&data_18004c000)[r12];
        (&data_18004c000)[r12] = result_1;
        
        if (VirtualProtect(&data_18004c000, 0x100, PAGE_READONLY, &lpflOldProtect))
        {
            sub_180023a10(0xe);
            return result;
        }
    }
    
    abort();
    /* no return */
}

