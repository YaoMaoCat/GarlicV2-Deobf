
  int32_t* std::error_category::equivalent(int64_t* arg1, int32_t arg2, int32_t* arg3, int512_t arg4 @ zmm0)

{
    void var_18;
    int32_t* result = (*(*arg1 + 0x18))(arg4, &var_18, arg2);
    
    if (*(*(result + 8) + 8) == *(*(arg3 + 8) + 8) && *result == *arg3)
    {
        result = 1;
        return result;
    }
    
    result = 0;
    return result;
}

