
  uint64_t sub_18001a120(void* arg1, void* arg2, int64_t arg3)

{
    if (arg1)
    {
        int64_t rbx_1 = *(arg1 + 0x18);
        int64_t r10_1 = *(arg2 + 8);
        int64_t r11_1 = r10_1 + rbx_1;
        
        if (r11_1)
        {
            int32_t r9 = *(arg1 + 0x14);
            
            if (r9)
            {
                uint64_t rdx = 0;
                
                while (arg3 >= *(r11_1 + (rdx << 3)) + r10_1)
                {
                    rdx = rdx + 1;
                    
                    if (rdx >= r9)
                        break;
                }
                
                if (rdx)
                    return *(r10_1 + ((rdx - 1) << 3) + rbx_1 + 4);
            }
            
            return 0xffffffff;
        }
    }
    
    abort();
    /* no return */
}

