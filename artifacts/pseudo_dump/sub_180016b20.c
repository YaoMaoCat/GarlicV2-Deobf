
  uint64_t sub_180016b20(HMODULE arg1, int32_t arg2, int64_t* arg3)

{
    int64_t* arg_18 = arg3;
    int32_t arg_10 = arg2;
    HMODULE arg_8 = arg1;
    
    if (!arg2 && data_180047568 <= arg2)
        return 0;
    
    int32_t rbx_1;
    
    if (arg2 - 1 > 1)
    {
    label_180016bb1:
        int32_t rax_4 = sub_180001ba0(arg1, arg2, arg3);
        rbx_1 = rax_4;
        int32_t var_28_3 = rax_4;
        
        if (arg2 == 1 && !rax_4)
        {
            sub_180001ba0(arg1, 0, arg3);
            sub_180016a80(arg3);
        }
        
        if (!arg2 || arg2 == 3)
        {
            int32_t rax_5 = sub_180016910(arg1, arg2, arg3);
            rbx_1 = rax_5;
            int32_t var_28_4 = rax_5;
            
            if (rax_5)
            {
                rbx_1 = 1;
⚠️                int32_t var_28_5 = rbx_1;
            }
        }
    }
    else
    {
⚠️        rbx_1 = 1;
        int32_t var_28_1 = rbx_1;
        
        if (rbx_1)
        {
            int32_t rax_3 = sub_180016910(arg1, arg2, arg3);
            rbx_1 = rax_3;
            int32_t var_28_2 = rax_3;
            
            if (rax_3)
                goto label_180016bb1;
        }
    }
    
    return rbx_1;
}

