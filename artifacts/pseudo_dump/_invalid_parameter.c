
🌐  void* _invalid_parameter(int64_t arg1, int64_t arg2, int64_t arg3, int32_t arg4, int64_t arg5)

{
    void* result_1 = nullptr;
    char var_38 = 0;
    char var_20 = 0;
    char var_18 = 0;
    
    if (!data_180047834)
    {
        var_20 = 1;
        int128_t var_30_1 = *data_180046b28;
    }
    
    void* result = _invalid_parameter_internal(arg1, arg2, arg3, arg4, arg5, &result_1);
    
    if (var_20 == 2)
    {
        result = result_1;
        *(result + 0x3a8) &= 0xfffffffd;
    }
    
    if (var_18)
    {
        result = sub_18001e310(&result_1);
        int32_t var_1c;
        *(result + 0x20) = var_1c;
    }
    
    if (0)
    {
        result = sub_18001e310(&result_1);
        int32_t var_14;
        *(result + 0x24) = var_14;
    }
    
    return result;
}

