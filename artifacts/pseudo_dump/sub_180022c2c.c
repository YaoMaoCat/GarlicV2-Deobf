
  int64_t sub_180022c2c(int16_t* arg1, char* arg2, int64_t arg3, uint32_t* arg4, void* arg5)

{
    int32_t var_18 = 0;
    int64_t r14;
    int64_t result = sub_1800229c8(&var_18, arg2, arg3, arg4, r14, arg5);
    
    if (result <= 4)
    {
        int32_t rcx_1 = var_18;
        
        if (rcx_1 > 0xffff)
            rcx_1 = 0xfffd;
        
        if (arg1)
            *arg1 = rcx_1;
    }
    
    return result;
}

