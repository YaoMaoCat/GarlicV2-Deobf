
🌐  void* __acrt_lowio_create_handle_array()

{
    void* result_1 = _calloc_base(0x40, 0x48);
    void* result = nullptr;
    
    if (result_1)
    {
        if (result_1 != result_1 + 0x1200)
        {
            int64_t* rdi_1 = result_1 + 0x30;
            
            do
            {
                InitializeCriticalSectionEx(&rdi_1[-6], 0xfa0, 0);
                rdi_1[-1] = -1;
                char* rcx_2 = rdi_1 + 0xe;
                *(rdi_1 + 0xd) &= 0xf8;
                int32_t i = 0;
                *rdi_1 = 0;
                rdi_1[1] = 0xa0a0000;
                *(rdi_1 + 0xc) = 0xa;
                
                do
                {
                    *rcx_2 = 0;
                    i += 1;
                    rcx_2 = &rcx_2[1];
                } while (i < 5);
                
                rdi_1 = &rdi_1[9];
            } while (&rdi_1[-6] != result_1 + 0x1200);
        }
        
        result = result_1;
    }
    
    _free_base(0);
    return result;
}

