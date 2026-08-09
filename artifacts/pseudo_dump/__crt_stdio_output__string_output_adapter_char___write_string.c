
  void __crt_stdio_output::string_output_adapter<char>::write_string(int64_t* arg1, int32_t* arg2, int32_t arg3, int32_t* arg4)

{
    if (!arg3)
        return;
    
    int64_t rdi_1 = arg3;
    int64_t* rcx = *arg1;
    void* rax = rcx[1];
    
    if (rcx[2] != rax)
    {
        void* rax_1 = rax - rcx[2];
        int64_t rsi_1 = rdi_1;
        
        if (rax_1 < rdi_1)
            rsi_1 = rax_1;
        
        memcpy(*rcx, arg2, rsi_1);
        int64_t* rax_2 = *arg1;
        *rax_2 += rsi_1;
        void* rax_3 = *arg1;
        *(rax_3 + 0x10) += rsi_1;
        
        if (*(*arg1 + 0x18))
            *arg4 += rdi_1;
        else if (rsi_1 == rdi_1)
            *arg4 += rsi_1;
        else
            *arg4 = 0xffffffff;
    }
    else if (!rcx[3])
        *arg4 = 0xffffffff;
    else
        *arg4 += rdi_1;
}

