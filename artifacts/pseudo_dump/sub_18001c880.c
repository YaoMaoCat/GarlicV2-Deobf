
  int64_t sub_18001c880(int64_t* arg1, int64_t* arg2, void* arg3, int32_t arg4)

{
    int32_t arg_20 = arg4;
    void* arg_18 = arg3;
    int64_t* arg_8 = arg1;
    int64_t rax = _GetImageBase();
    int64_t var_48 = rax;
    int32_t i = sub_180019ea0(arg1, arg2, arg3);
    void* rax_2 = sub_180019c40();
    *(rax_2 + 0x30) += 1;
    
    while (i != 0xffffffff)
    {
        if (i <= arg4)
            break;
        
        if (i <= 0xffffffff || i >= *(arg3 + 4))
        {
            abort();
            /* no return */
        }
        
        int64_t rax_3 = _GetImageBase();
        int64_t r14_2 = i << 3;
        i = *(*(arg3 + 8) + r14_2 + rax_3);
        int32_t i_1 = i;
        int32_t i_2 = i;
        
        if (*(_GetImageBase() + *(arg3 + 8) + r14_2 + 4))
        {
            int64_t rbx_3 = *(_GetImageBase() + *(arg3 + 8) + r14_2 + 4);
            
            if (_GetImageBase() != -(rbx_3))
            {
                __SetState(arg1, arg2, arg3, i);
                int64_t rbx_4 = *(arg3 + 8);
                int64_t rax_10;
                int512_t zmm0_1;
                rax_10 = _GetImageBase();
                int64_t rax_15;
                
                if (!*(rax_10 + rbx_4 + r14_2 + 4))
                    rax_15 = 0;
                else
                {
                    int64_t rbx_6 = *(_GetImageBase() + *(arg3 + 8) + r14_2 + 4);
                    int64_t rax_14;
                    rax_14 = _GetImageBase();
                    rax_15 = rax_14 + rbx_6;
                }
                
                _CallSettingFrame(rax_15, arg1, zmm0_1);
                _SetImageBase(rax);
            }
        }
        
        int32_t i_3 = i;
    }
    
    if (*(sub_180019c40() + 0x30) > 0)
    {
        void* rax_17 = sub_180019c40();
        *(rax_17 + 0x30) -= 1;
    }
    
    if (i == 0xffffffff || i <= arg4)
        /* tailcall */
        return __SetState(arg1, arg2, arg3, i);
    
    abort();
    /* no return */
}

