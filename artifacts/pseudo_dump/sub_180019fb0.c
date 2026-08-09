
  uint64_t sub_180019fb0(void* arg1, int64_t* arg2)

{
    if (arg1)
    {
        int64_t rbx_1 = *(arg1 + 0x18);
        int64_t r9_1 = arg2[1];
        int64_t r10_1 = r9_1 + rbx_1;
        
        if (r10_1)
        {
            int32_t r8 = *(arg1 + 0x14);
            
            if (r8)
            {
                uint64_t rdx = 0;
                
                while (*arg2 >= *(r10_1 + (rdx << 3)) + r9_1)
                {
                    rdx = rdx + 1;
                    
                    if (rdx >= r8)
                        break;
                }
                
                if (rdx)
                    return *(r9_1 + ((rdx - 1) << 3) + rbx_1 + 4);
            }
            
            return 0xffffffff;
        }
    }
    
    abort();
    /* no return */
}

