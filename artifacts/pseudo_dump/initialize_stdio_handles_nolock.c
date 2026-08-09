
🌐  uint64_t initialize_stdio_handles_nolock()

{
    int32_t i = 0;
    int64_t r14 = 0;
    uint64_t result;
    
    do
    {
        int64_t i_1 = i;
        uint64_t rbx_1 = (i_1 & 0x3f) * 9;
        int64_t rdi_1 = (&data_180047840)[i_1 >> 6];
        result = *(rdi_1 + (rbx_1 << 3) + 0x28) + 2;
        
        if (result <= 1)
        {
            *(rdi_1 + (rbx_1 << 3) + 0x38) = 0x81;
            enum STD_HANDLE nStdHandle;
            
            if (!i)
                nStdHandle = STD_INPUT_HANDLE;
            else if (i == 1)
                nStdHandle = STD_OUTPUT_HANDLE;
            else
                nStdHandle = STD_ERROR_HANDLE;
            
            HANDLE hFile = GetStdHandle(nStdHandle);
            enum FILE_TYPE rax_4;
            
            if (hFile + 1 > 1)
                rax_4 = GetFileType(hFile);
            
            if (hFile + 1 <= 1 || !rax_4)
            {
                *(rdi_1 + (rbx_1 << 3) + 0x38) |= 0x40;
                *(rdi_1 + (rbx_1 << 3) + 0x28) = -2;
                result = data_1800477f0;
                
                if (result)
                {
                    result = *(r14 + result);
                    *(result + 0x18) = 0xfffffffe;
                }
            }
            else
            {
                result = rax_4;
                *(rdi_1 + (rbx_1 << 3) + 0x28) = hFile;
                
                if (result == 2)
                    *(rdi_1 + (rbx_1 << 3) + 0x38) |= 0x40;
                else if (result == 3)
                    *(rdi_1 + (rbx_1 << 3) + 0x38) |= 8;
            }
        }
        else
            *(rdi_1 + (rbx_1 << 3) + 0x38) |= 0x80;
        
        i += 1;
        r14 += 8;
    } while (i != 3);
    
    return result;
}

