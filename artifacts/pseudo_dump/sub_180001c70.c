
  int64_t sub_180001c70(char* arg1, int64_t arg2, int64_t arg3, int64_t arg4)

{
    int64_t arg_18 = arg3;
    int64_t arg_20 = arg4;
    int32_t result =
        __stdio_common_vsprintf(data_180047458 | 2, arg1, arg2, arg3, nullptr, &arg_20);
    
    if (result < 0)
        return -1;
    
    return result;
}

