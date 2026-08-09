
  void sub_18002f1f0()

{
    int64_t rdx = data_180046020;
    
    if (rdx > 0xf)
    {
        void* rcx_1 = *data_180046008;
        
        if (rdx + 1 >= 0x1000)
        {
            void* rax_1 = *(rcx_1 - 8);
            
            if (rcx_1 - rax_1 - 8 > 0x1f)
                trap(0xd);
            
            rcx_1 = rax_1;
        }
        
        j_sub_180021340(rcx_1);
    }
    
    data_180046018 = 0;
    data_180046020 = 0xf;
    data_180046008 = 0;
}

