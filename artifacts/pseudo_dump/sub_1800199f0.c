
  int64_t sub_1800199f0(int64_t arg1, int32_t* arg2)

{
    int64_t rax = arg2[1];
    int64_t result = *arg2 + arg1;
    
    if (rax < 0)
        return result;
    
    return *(arg2[2] + *(rax + arg1)) + rax + result;
}

