
  void* __crt_stdio_output::output_processor<uint64_t,16,char,class __crt_stdio_output::console_output_adapter<char>,class __crt_stdio_output::format_validation_base<char,class __crt_stdio_output::console_output_adapter<char> > >::type_case_integer_parse_into_buffer<uint64_t,16>(void* arg1, uint64_t arg2, char arg3)

{
    void* r9 = arg1 + 0x50;
    void* rax = *(r9 + 0x408);
    uint64_t r10 = arg2;
    uint64_t rax_1;
    
    if (rax)
    {
        r9 = rax;
        rax_1 = *(arg1 + 0x450) >> 1;
    }
    else
        rax_1 = 0x200;
    
    char* rdx_1 = r9 - 1 + rax_1;
    *(arg1 + 0x40) = rdx_1;
    char* r8 = rdx_1;
    
    while (true)
    {
        int32_t rax_3 = *(arg1 + 0x30);
        
        if (rax_3 <= 0 && !r10)
        {
            *(arg1 + 0x48) = rdx_1 - *(arg1 + 0x40);
            *(arg1 + 0x40) = &r8[1];
            return &r8[1];
        }
        
        *(arg1 + 0x30) = rax_3 - 1;
        int32_t rax_4;
        rax_4 = r10;
        rax_4 &= 0xf;
        r10 u>>= 4;
        rax_4 += 0x30;
        r9 = rax_4;
        
        if (rax_4 > 0x39)
        {
            rax_4 = arg3;
            rax_4 ^= 1;
            rax_4 <<= 5;
            rax_4 += 7;
            rax_4 += r9;
        }
        
        *r8 = rax_4;
        *(arg1 + 0x40) -= 1;
        r8 = *(arg1 + 0x40);
    }
}

