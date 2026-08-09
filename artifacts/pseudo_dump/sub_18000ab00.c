
  int64_t sub_18000ab00(int64_t* arg1)

{
    void* i = arg1[0x14];
    
    if (!i)
        goto label_18000abde;
    
    for (int64_t rsi_1 = arg1[0x15]; i != rsi_1; i += 0x20)
    {
        void* rax_1 = *(i + 8);
        
        if (rax_1)
        {
            void* rcx;
            
            if (*(i + 0x18) - rax_1 < 0x1000)
                rcx = rax_1;
            else
            {
                rcx = *(rax_1 - 8);
                
                if (rax_1 - rcx - 8 > 0x1f)
                    goto label_18000ad81;
            }
            
            j_sub_180021340(rcx);
            __builtin_memset(i + 8, 0, 0x18);
        }
    }
    
    void* rax_4 = arg1[0x14];
    void* rcx_1;
    
    if (((arg1[0x16] - rax_4) & 0xffffffffffffffe0) < 0x1000)
    {
        rcx_1 = rax_4;
    label_18000abbd:
        j_sub_180021340(rcx_1);
        __builtin_memset(&arg1[0x14], 0, 0x18);
    label_18000abde:
        void** rbx = *(arg1[0x12] + 8);
        
        while (!*(rbx + 0x19))
        {
            sub_180004470(&arg1[0x12], &arg1[0x12], rbx[2]);
            void** rcx_3 = rbx;
            rbx = *rbx;
            j_sub_180021340(rcx_3);
        }
        
        j_sub_180021340(arg1[0x12]);
        void** rbx_1 = *(arg1[0x10] + 8);
        
        while (!*(rbx_1 + 0x19))
        {
            sub_180004470(&arg1[0x10], &arg1[0x10], rbx_1[2]);
            void** rcx_6 = rbx_1;
            rbx_1 = *rbx_1;
            j_sub_180021340(rcx_6);
        }
        
        j_sub_180021340(arg1[0x10]);
        void** rbx_2 = *(arg1[0xe] + 8);
        
        while (!*(rbx_2 + 0x19))
        {
            sub_180004390(&arg1[0xe], &arg1[0xe], rbx_2[2]);
            void** rcx_9 = rbx_2;
            rbx_2 = *rbx_2;
            j_sub_180021340(rcx_9);
        }
        
        j_sub_180021340(arg1[0xe]);
        sub_1800043f0(&arg1[0xc], &arg1[0xc], *(arg1[0xc] + 8));
        j_sub_180021340(arg1[0xc]);
        void* i_1 = arg1[9];
        
        if (!i_1)
        {
            sub_180003a30(&arg1[4]);
            /* tailcall */
            return sub_180003a30(arg1);
        }
        
        for (int64_t rsi_2 = arg1[0xa]; i_1 != rsi_2; i_1 += 0x20)
        {
            void* rax_10 = *(i_1 + 8);
            
            if (rax_10)
            {
                void* rcx_13;
                
                if (*(i_1 + 0x18) - rax_10 < 0x1000)
                    rcx_13 = rax_10;
                else
                {
                    rcx_13 = *(rax_10 - 8);
                    
                    if (rax_10 - rcx_13 - 8 > 0x1f)
                        goto label_18000ad81;
                }
                
                j_sub_180021340(rcx_13);
                __builtin_memset(i_1 + 8, 0, 0x18);
            }
        }
        
        void* rax_13 = arg1[9];
        void* rcx_14;
        
        if (((arg1[0xb] - rax_13) & 0xffffffffffffffe0) < 0x1000)
        {
            rcx_14 = rax_13;
        label_18000ad86:
            j_sub_180021340(rcx_14);
            __builtin_memset(&arg1[9], 0, 0x18);
            sub_180003a30(&arg1[4]);
            /* tailcall */
            return sub_180003a30(arg1);
        }
        
        rcx_14 = *(rax_13 - 8);
        
        if (rax_13 - rcx_14 - 8 <= 0x1f)
            goto label_18000ad86;
    }
    else
    {
        rcx_1 = *(rax_4 - 8);
        
        if (rax_4 - rcx_1 - 8 <= 0x1f)
            goto label_18000abbd;
    }
label_18000ad81:
    trap(0xd);
}

