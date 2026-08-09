
  int64_t sub_18001a650(void* arg1, int64_t* arg2, int32_t* arg3, char* arg4)

{
    int64_t* rbx;
    
    if (*arg3 >= 0)
        rbx = arg3[2] + *arg2;
    else
        rbx = arg2;
    
    int32_t rax = sub_18001a280(arg1, arg2, arg3, arg4);
    int32_t result = rax - 1;
    
    if (rax == 1)
    {
        int64_t rax_4 = sub_1800199f0(*(arg1 + 0x28), &arg4[8]);
        int64_t rdi_2 = *(arg4 + 0x18);
        int64_t rax_6;
        
        if (!rdi_2)
            rax_6 = 0;
        else
            rax_6 = _GetThrowImageBase() + rdi_2;
        
        return _CallMemberFunction1(rbx, rax_6, rax_4);
    }
    
    if (result != 1)
        return result;
    
    int64_t rax_1 = sub_1800199f0(*(arg1 + 0x28), &arg4[8]);
    int64_t rdi_1 = *(arg4 + 0x18);
    int64_t rax_3;
    
    if (!rdi_1)
        rax_3 = 0;
    else
        rax_3 = _GetThrowImageBase() + rdi_1;
    
    return _CallMemberFunction2(rbx, rax_3, rax_1, 1);
}

