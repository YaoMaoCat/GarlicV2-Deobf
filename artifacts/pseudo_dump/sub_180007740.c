
  void sub_180007740(int64_t* arg1)

{
    void* rdx = *arg1;
    
    if (!rdx)
        return;
    
    void* rcx;
    
    if (((arg1[2] - rdx) >> 1) * 2 < 0x1000)
        rcx = rdx;
    else
    {
        rcx = *(rdx - 8);
        
        if (rdx - rcx - 8 > 0x1f)
            trap(0xd);
    }
    
    j_sub_180021340(rcx);
    __builtin_memset(arg1, 0, 0x18);
}

