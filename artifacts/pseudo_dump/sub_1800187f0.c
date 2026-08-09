
  int64_t sub_1800187f0(int64_t* arg1, int64_t* arg2, void* arg3)

{
    uint64_t rdi = *(arg3 + 0xc);
    int32_t rax = sub_180019fb0(arg3, arg2);
    int64_t arg_8 = *arg1;
    
    while (rdi)
    {
        rdi = rdi - 1;
        void* rbx_2 = *(arg3 + 0x10) + rdi * 0x14 + arg2[1];
        
        if (rax > *(rbx_2 + 4) && rax <= *(rbx_2 + 8))
        {
            int64_t ImageBase;
            IMAGE_RUNTIME_FUNCTION_ENTRY* rax_2 =
                RtlLookupFunctionEntry(*arg2, &ImageBase, nullptr);
            int64_t r9_2 = *(rbx_2 + 0x10) + ImageBase;
            int32_t i = *(rbx_2 + 0xc);
            uint64_t rax_3 = 0;
            
            if (i)
            {
                do
                {
                    if (*(r9_2 + rax_3 * 0x14 + 0xc) == rax_2->BeginAddress)
                        goto label_1800188b0;
                    
                    rax_3 = rax_3 + 1;
                } while (rax_3 < i);
            }
            
            if (rax_3 < i)
            {
            label_1800188b0:
                arg_8 = *(*(r9_2 + rax_3 * 0x14 + 0x10) + *arg1);
                break;
            }
        }
    }
    
    int32_t rax_6 = sub_180019fb0(arg3, arg2);
    uint64_t rbx_3 = *(arg3 + 0xc);
    
    while (rbx_3)
    {
        void* rax_7 = sub_180019c40();
        rbx_3 = rbx_3 - 1;
        int64_t rcx_7 = *(arg3 + 0x10) + *(rax_7 + 0x60);
        uint64_t rdx_4 = rbx_3 * 5;
        int32_t r9_3 = *(rcx_7 + (rdx_4 << 2) + 4);
        
        if (rax_6 > r9_3 && rax_6 <= *(rcx_7 + (rdx_4 << 2) + 8))
            return sub_18001c880(&arg_8, arg2, arg3, r9_3);
    }
    
    return sub_18001c880(&arg_8, arg2, arg3, -1);
}

