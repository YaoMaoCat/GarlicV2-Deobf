
  void* sub_180018660(char* arg1, char* arg2, int64_t arg3, int32_t arg4, char arg5)

{
    char rbx = *arg1;
    int32_t* r10 = &arg1[1];
    *arg2 = rbx;
    
    if (rbx & 4)
    {
        uint64_t rcx_1 = *r10 & 0xf;
        r10 -= *(rcx_1 + 0x180038880);
        *(arg2 + 4) = r10[-1] >> *(rcx_1 + 0x180038890);
    }
    
    if (rbx & 8)
    {
        int32_t rax_4 = *r10;
        r10 = &r10[1];
        *(arg2 + 8) = rax_4;
    }
    
    if (rbx & 0x10)
    {
        int32_t rax_5 = *r10;
        r10 = &r10[1];
        *(arg2 + 0xc) = rax_5;
    }
    
    char* r8 = &r10[1];
    
    if (arg5 || !(rbx & 2))
        *(arg2 + 0x10) = *r10;
    else
    {
        *(arg2 + 0x10) = 0;
        int64_t rax_6 = *r10;
        
        if (!rax_6)
            trap(0xd);
        
        char* rax_7 = rax_6 + arg3;
        uint64_t rcx_4 = *rax_7 & 0xf;
        int32_t* rax_8 = rax_7 - *(rcx_4 + 0x180038880);
        int32_t rdx_1 = 0;
        uint32_t r10_2 = rax_8[-1] >> *(rcx_4 + 0x180038890);
        
        if (r10_2)
        {
            do
            {
                if (*rax_8 == arg4)
                {
                    *(arg2 + 0x10) = rax_8[1];
                    break;
                }
                
                rax_8 = &rax_8[2];
                rdx_1 += 1;
            } while (rdx_1 < r10_2);
        }
    }
    
    if (rbx & 1)
    {
        uint64_t rcx_8 = *r8 & 0xf;
        r8 -= *(rcx_8 + 0x180038880);
        *(arg2 + 0x14) = *(r8 - 4) >> *(rcx_8 + 0x180038890);
    }
    
    return r8 - arg1;
}

