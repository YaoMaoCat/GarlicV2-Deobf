
🌐  uint64_t fclose(int32_t* arg1)

{
    void* var_48 = nullptr;
    char var_38 = 0;
    char var_20 = 0;
    char var_18 = 0;
    
    if (!data_180047834)
    {
        var_20 = 1;
        int128_t var_30_1 = *data_180046b28;
    }
    
    int32_t rax = _fclose_internal(arg1, &var_48);
    
    if (var_20 == 2)
    {
        void* rcx = var_48;
        *(rcx + 0x3a8) &= 0xfffffffd;
    }
    
    int32_t var_1c;
    
    if (var_18)
        *(sub_18001e310(&var_48) + 0x20) = var_1c;
    int32_t var_14;
    
    if (0)
        *(sub_18001e310(&var_48) + 0x24) = var_14;
    return rax;
}

