
  uint64_t sub_180004f30(int64_t arg1, int64_t* arg2, int64_t* arg3)

{
    int64_t* r9 = arg3;
    int64_t rdi = arg3[2];
    int64_t* rax = arg2;
    
    if (arg3[3] > 0xf)
        r9 = *arg3;
    
    int64_t rbx = arg2[2];
    
    if (arg2[3] > 0xf)
        rax = *arg2;
    
    int64_t r8 = rbx;
    
    if (rdi < rbx)
        r8 = rdi;
    
    int32_t rax_1 = memcmp(rax, r9, r8);
    
    if (!rax_1)
    {
        if (rbx < rdi)
            return 1;
        
        rax_1 = rbx > rdi;
    }
    
    return rax_1 >> 0x1f;
}

