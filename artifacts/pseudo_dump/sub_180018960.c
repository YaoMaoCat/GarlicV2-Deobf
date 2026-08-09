
  int64_t* sub_180018960(int64_t* arg1, int64_t* arg2, void* arg3, int64_t* arg4)

{
    uint64_t rdi = *(arg3 + 0xc);
    int32_t rax = sub_180019fb0(arg3, arg2);
    *arg4 = *arg1;
    
    if (!rdi)
        return arg4;
    
    do
    {
        rdi = rdi - 1;
        void* rbx_2 = *(arg3 + 0x10) + rdi * 0x14 + arg2[1];
        
        if (rax > *(rbx_2 + 4) && rax <= *(rbx_2 + 8))
        {
            uint64_t ImageBase;
            IMAGE_RUNTIME_FUNCTION_ENTRY* rax_2 =
                RtlLookupFunctionEntry(*arg2, &ImageBase, nullptr);
            int64_t r9_1 = *(rbx_2 + 0x10) + ImageBase;
            int32_t i = *(rbx_2 + 0xc);
            uint64_t rax_3 = 0;
            
            if (i)
            {
                do
                {
                    if (*(r9_1 + rax_3 * 0x14 + 0xc) == rax_2->BeginAddress)
                        goto label_180018a21;
                    
                    rax_3 = rax_3 + 1;
                } while (rax_3 < i);
            }
            
            if (rax_3 < i)
            {
            label_180018a21:
                *arg4 = *(*(r9_1 + rax_3 * 0x14 + 0x10) + *arg1);
                break;
            }
        }
    } while (rdi);
    
    return arg4;
}

