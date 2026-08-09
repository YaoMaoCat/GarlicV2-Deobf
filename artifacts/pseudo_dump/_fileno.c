
🌐  uint64_t _fileno(void* arg1)

{
    if (arg1)
        return *(arg1 + 0x18);
    
    *sub_18002131c() = 0x16;
    _invalid_parameter_noinfo();
    return 0xffffffff;
}

