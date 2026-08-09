
  int64_t sub_180026dcc(void* arg1)

{
    *(arg1 + 0x10) += 1;
    int32_t* rax = *(arg1 + 0xe0);
    
    if (rax)
        *rax += 1;
    
    int32_t* rax_1 = *(arg1 + 0xf0);
    
    if (rax_1)
        *rax_1 += 1;
    
    int32_t* rax_2 = *(arg1 + 0xe8);
    
    if (rax_2)
        *rax_2 += 1;
    
    int32_t* rax_3 = *(arg1 + 0x100);
    
    if (rax_3)
        *rax_3 += 1;
    
    int64_t* rax_4 = arg1 + 0x38;
    int64_t i_1 = 6;
    int64_t i;
    
    do
    {
        if (rax_4[-2] != &data_180046b38)
        {
            int32_t* rdx_1 = *rax_4;
            
            if (rdx_1)
                *rdx_1 += 1;
        }
        
        if (rax_4[-3])
        {
            int32_t* rdx_2 = rax_4[-1];
            
            if (rdx_2)
                *rdx_2 += 1;
        }
        
        rax_4 = &rax_4[4];
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    /* tailcall */
    return __acrt_locale_add_lc_time_reference(*(arg1 + 0x120));
}

