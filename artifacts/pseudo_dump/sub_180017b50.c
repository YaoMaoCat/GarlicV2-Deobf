
  int32_t sub_180017b50(int64_t* arg1, int32_t arg2)

{
    int32_t i = arg2;
    
    if (arg2)
    {
        int64_t* r15_1 = *arg1;
        int128_t* rbp_1 = *r15_1;
        
        do
        {
            uint64_t rflags_1;
            int32_t temp0_1;
            temp0_1 = _bit_scan_reverse(i);
            int128_t* rdi_1 = rbp_1;
            
            if (temp0_1)
                rdi_1 += temp0_1;
            
            if ((!temp0_1 || ((*rdi_1 ^ *(arg1 + 0x10)) == {0} ? 1 : 0))
                && !memcmp(&rdi_1[1], arg1[4], arg1[5] - 0x10))
            {
                *r15_1 = rdi_1;
                int32_t rax_2;
                rax_2 = 1;
                return rax_2;
            }
            
            i ^= 1 << temp0_1;
        } while (i);
    }
    
    int32_t rax;
    rax = 0;
    return rax;
}

