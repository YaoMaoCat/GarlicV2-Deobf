
  void sub_180019520(int64_t* arg1, char* arg2) __noreturn

{
    char* PcValue = arg2;
    uint64_t arguments_1 = 0x19930520;
    
    if (arg2 && *arg2 & 0x10)
    {
        void* rax_1 = *(*arg1 - 8);
        PcValue = *(rax_1 + 0x30);
        (*(rax_1 + 0x40))();
    }
    
    int64_t BaseOfImage_1 = 0;
    int64_t BaseOfImage = 0;
    
    if (PcValue)
    {
        BaseOfImage_1 = RtlPcToFileHeader(PcValue, &BaseOfImage);
        BaseOfImage = BaseOfImage_1;
        
        if (*PcValue & 8 || !BaseOfImage_1)
            arguments_1 = 0x1994000;
    }
    
    uint64_t arguments = arguments_1;
    int64_t* var_28 = arg1;
    char* PcValue_1 = PcValue;
    int64_t BaseOfImage_2 = BaseOfImage_1;
    RaiseException(0xe06d7363, 1, 4, &arguments);
    /* no return */
}

