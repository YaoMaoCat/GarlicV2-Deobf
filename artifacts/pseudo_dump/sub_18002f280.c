
  void sub_18002f280()

{
    void* rcx = data_1800474a8;
    
    if (!rcx)
        return;
    
    void* rax_4;
    
    if ((data_1800474b8 - rcx) >> 3 << 3 < 0x1000)
        rax_4 = rcx;
    else
    {
        rax_4 = *(rcx - 8);
        
        if (rcx - rax_4 - 8 > 0x1f)
            trap(0xd);
    }
    
    j_sub_180021340(rax_4);
    __builtin_memset(&data_1800474a8, 0, 0x18);
}

