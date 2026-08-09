
  uint64_t sub_180019aa0(void* arg1, int64_t arg2)

{
    if (arg1 != arg2)
    {
        char* rax_1 = arg1 + 9;
        void* rdx_1 = arg2 + 9 - rax_1;
        char i;
        
        do
        {
            i = *rax_1;
            char temp0_1 = *(rax_1 + rdx_1);
            
            if (i != temp0_1)
                return (rax_1 - rax_1) | 1;
            
            rax_1 = &rax_1[1];
        } while (i);
    }
    
    return 0;
}

