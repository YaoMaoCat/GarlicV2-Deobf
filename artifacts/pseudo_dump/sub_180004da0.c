
  void sub_180004da0(int64_t* arg1)

{
    void* rcx = *arg1;
    
    if (!rcx)
        return;
    
    sub_180003f30(rcx, arg1[1]);
    void* rax_1 = *arg1;
    void* rcx_1;
    
    if (((arg1[2] - rax_1) & 0xffffffffffffffe0) < 0x1000)
        rcx_1 = rax_1;
    else
    {
        rcx_1 = *(rax_1 - 8);
        
        if (rax_1 - rcx_1 - 8 > 0x1f)
            trap(0xd);
    }
    
    j_sub_180021340(rcx_1);
    __builtin_memset(arg1, 0, 0x18);
}

