
  int64_t* sub_18000a650(int64_t* arg1, int64_t* arg2, int32_t arg3)

{
    uint64_t rbx_1 = arg2[1] - *arg2;
    
    if (rbx_1 < 2)
    {
        sub_1800075d0(arg1, arg2);
        return arg1;
    }
    
    int128_t var_50;
    __builtin_memset(&var_50, 0, 0x18);
    
    if (rbx_1 > 0x7fffffffffffffff)
    {
        sub_1800052a0();
        /* no return */
    }
    
    int128_t* rdi_2;
    
    if (rbx_1 < 0x1000)
    {
        rdi_2 = sub_180016420(rbx_1);
    label_18000a6ea:
        var_50 = rdi_2;
        void* rbp_1 = rdi_2 + rbx_1;
        void* var_40_1 = rbp_1;
        int32_t* rdx = *arg2;
        void* rbx_3 = arg2[1] - rdx;
        memcpy(rdi_2, rdx, rbx_3);
        void* r11_1 = rbx_3 + rdi_2;
        *(&var_50 + 8) = r11_1;
        char* rdx_1 = *arg2;
        uint16_t r10_1 = rdx_1[1] | *rdx_1 << 8;
        
        if ((r10_1 << 2 | 2) <= arg2[1] - rdx_1)
        {
            int16_t r9_1 = 0;
            
            if (0 < r10_1)
            {
                do
                {
                    uint64_t r8_1 = r9_1;
                    int32_t rdx_8 =
                        (*(rdi_2 + (r8_1 << 2) + 2) << 8 | *(rdi_2 + (r8_1 << 2) + 3)) + arg3;
                    *(rdi_2 + (r8_1 << 2) + 2) = rdx_8 >> 8;
                    *(rdi_2 + (r8_1 << 2) + 3) = rdx_8;
                    r9_1 += 1;
                } while (r9_1 < r10_1);
            }
            
            *arg1 = rdi_2;
            arg1[1] = r11_1;
            arg1[2] = rbp_1;
            return arg1;
        }
        
        sub_1800075d0(arg1, arg2);
        
        if (!rdi_2)
            return arg1;
        
        if (rbp_1 - rdi_2 < 0x1000)
        {
            j_sub_180021340(rdi_2);
            return arg1;
        }
        
        int64_t rcx_6 = *(rdi_2 - 8);
        
        if (rdi_2 - rcx_6 - 8 <= 0x1f)
        {
            j_sub_180021340(rcx_6);
            return arg1;
        }
    }
    else
    {
        if (rbx_1 + 0x27 <= rbx_1)
        {
            stdext::threads::_Throw_lock_error();
            /* no return */
        }
        
        int64_t rax_1 = sub_180016420(rbx_1 + 0x27);
        
        if (rax_1)
        {
            rdi_2 = (rax_1 + 0x27) & 0xffffffffffffffe0;
            *(rdi_2 - 8) = rax_1;
            goto label_18000a6ea;
        }
    }
    trap(0xd);
}

