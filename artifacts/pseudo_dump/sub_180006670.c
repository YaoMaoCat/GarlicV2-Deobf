
  void* sub_180006670(int64_t* arg1, uint64_t arg2)

{
    int64_t r14 = *arg1;
    void* result = arg1[2] - r14;
    
    if (arg2 > result)
    {
        if (arg2 > 0x7fffffffffffffff)
        {
            sub_1800052a0();
            /* no return */
        }
        
        int64_t rbp_1 = arg1[1];
        int128_t* rsi_1;
        
        if (!arg2)
            rsi_1 = nullptr;
        else if (arg2 < 0x1000)
            rsi_1 = sub_180016420(arg2);
        else
        {
            if (arg2 + 0x27 <= arg2)
            {
                stdext::threads::_Throw_lock_error();
                /* no return */
            }
            
            int64_t rax_1 = sub_180016420(arg2 + 0x27);
            
            if (!rax_1)
                trap(0xd);
            
            rsi_1 = (rax_1 + 0x27) & 0xffffffffffffffe0;
            *(rsi_1 - 8) = rax_1;
        }
        
        int32_t* rdx = *arg1;
        memcpy(rsi_1, rdx, arg1[1] - rdx);
        void* rcx_3 = *arg1;
        
        if (rcx_3)
        {
            void* rax_3;
            
            if (arg1[2] - rcx_3 < 0x1000)
                rax_3 = rcx_3;
            else
            {
                rax_3 = *(rcx_3 - 8);
                
                if (rcx_3 - rax_3 - 8 > 0x1f)
                    trap(0xd);
            }
            
            j_sub_180021340(rax_3);
        }
        
        *arg1 = rsi_1;
        arg1[1] = rsi_1 + rbp_1 - r14;
        result = arg2 + rsi_1;
        arg1[2] = result;
    }
    
    return result;
}

