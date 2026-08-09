
  uint64_t sub_180026c98()

{
    int32_t var_18 = 0;
    sub_1800239bc(8);
    int32_t rbx = 3;
    
    while (true)
    {
        int32_t var_14_1 = rbx;
        
        if (rbx == data_1800477e8)
            break;
        
        int64_t rdi_1 = rbx;
        void* rax_2 = *(data_1800477f0 + (rdi_1 << 3));
        
        if (rax_2)
        {
            if (*(rax_2 + 0x14) >> 0xd & 1
                    && fclose(*(data_1800477f0 + (rdi_1 << 3))) != 0xffffffff)
                var_18 += 1;
            
            DeleteCriticalSection(*(data_1800477f0 + (rdi_1 << 3)) + 0x30);
            _free_base(*(data_1800477f0 + (rdi_1 << 3)));
            *(data_1800477f0 + (rdi_1 << 3)) = 0;
        }
        
        rbx += 1;
    }
    
    sub_180023a10(8);
    return var_18;
}

