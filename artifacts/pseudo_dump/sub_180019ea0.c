
  int64_t sub_180019ea0(int64_t* arg1, int64_t* arg2, void* arg3)

{
    int32_t result = *(*(arg3 + 0x1c) + *arg1);
    
    if (result != 0xfffffffe)
        return result;
    
    int64_t r9_1 = arg2[1];
    int64_t rbx_1 = *(arg3 + 0x18);
    int64_t r10_1 = r9_1 + rbx_1;
    
    if (!r10_1)
    {
        abort();
        /* no return */
    }
    
    int32_t r8 = *(arg3 + 0x14);
    
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

