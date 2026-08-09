
  uint128_t* sub_1800195d0(uint128_t* arg1, char* arg2)

{
    uint32_t rbp = *arg2;
    char* rsi = arg2;
    uint128_t* r9 = arg1;
    
    if (!rbp)
        return arg1;
    
    uint128_t zmm0;
    uint32_t zmm2[0x4];
    
    if (data_180046858 >= 2)
    {
        if ((rsi & 0xfff) > 0xff0)
        {
            zmm2 = {0};
            char rcx_9 = rbp;
            int32_t i_1 = 4;
            int32_t i;
            
            do
            {
                char r10_1 = rcx_9;
                char* r8_2 = &arg2[1];
                zmm2 = _mm_insert_epi8(_mm_bsrli_si128(zmm2, 1), rcx_9, 0xf);
                
                if (rcx_9)
                    rcx_9 = *r8_2;
                
                zmm2 = _mm_bsrli_si128(zmm2, 1);
                char rbx_1 = rcx_9;
                
                if (!r10_1)
                    r8_2 = arg2;
                
                zmm2 = _mm_insert_epi8(zmm2, rcx_9, 0xf);
                char* rdx_1 = &r8_2[1];
                
                if (rcx_9)
                    rcx_9 = *rdx_1;
                
                zmm2 = _mm_bsrli_si128(zmm2, 1);
                char rdi_1 = rcx_9;
                
                if (!rbx_1)
                    rdx_1 = r8_2;
                
                zmm2 = _mm_insert_epi8(zmm2, rcx_9, 0xf);
                char* r8_3 = &rdx_1[1];
                
                if (rcx_9)
                    rcx_9 = *r8_3;
                
                zmm2 = _mm_bsrli_si128(zmm2, 1);
                char r10_2 = rcx_9;
                
                if (!rdi_1)
                    r8_3 = rdx_1;
                
                zmm2 = _mm_insert_epi8(zmm2, rcx_9, 0xf);
                arg2 = &r8_3[1];
                
                if (rcx_9)
                    rcx_9 = *arg2;
                
                if (!r10_2)
                    arg2 = r8_3;
                
                i = i_1;
                i_1 -= 1;
            } while (i != 1);
        }
        else
            zmm2 = *arg2;
        
        while (true)
        {
            uint64_t rax_16 = r9 & 0xfff;
            
            if (rax_16 <= 0xff0)
            {
                zmm0 = *r9;
                int64_t rflags_3;
                int32_t temp0_22;
                temp0_22 = _mm_cmpistri(zmm2, zmm0, 0xc);
                
                if (rax_16 <= 0xff0)
                {
                    if (rax_16 >= 0xff0)
                        break;
                    
                    int64_t rflags_4;
                    int32_t temp0_23;
                    temp0_23 = _mm_cmpistri(zmm2, zmm0, 0xc);
                    r9 += temp0_23;
                }
                else
                {
                    r9 = &r9[1];
                    continue;
                }
                
                goto label_180019815;
            }
            
            char rax_22 = *r9;
            
            if (!rax_22)
                break;
            
            if (rax_22 == rbp)
            {
            label_180019815:
                uint128_t* rdx_2 = r9;
                char* r8_4 = rsi;
                
                while (true)
                {
                    uint64_t rax_21;
                    
                    if ((rdx_2 & 0xfff) <= 0xff0)
                        rax_21 = r8_4 & 0xfff;
                    
                    if ((rdx_2 & 0xfff) > 0xff0 || (rax_21 != 0xff0 && rax_21 >= 0xff0))
                    {
                        char rax_23 = *r8_4;
                        
                        if (rax_23)
                        {
                            if (*rdx_2 != rax_23)
                                break;
                            
                            rdx_2 += 1;
                            r8_4 = &r8_4[1];
                            continue;
                        }
                    }
                    else
                    {
                        int64_t rflags_5;
                        int32_t temp0_24;
                        temp0_24 = _mm_cmpistri(*r8_4, *rdx_2, 0xc);
                        
                        if (!(rax_21 - 0xff0))
                            break;
                        
                        if (rax_21 - 0xff0 >= 0)
                        {
                            rdx_2 = &rdx_2[1];
                            r8_4 = &r8_4[0x10];
                            continue;
                        }
                    }
                    
                    return r9;
                }
            }
            
            r9 += 1;
        }
    }
    else
    {
        uint32_t temp0_2[0x4] = _mm_shuffle_epi32(_mm_shufflelo_epi16(rbp << 8 | rbp, 0), 0);
        
        while (true)
        {
            int32_t zmm1[0x4];
            
            if ((r9 & 0xfff) <= 0xff0)
            {
                zmm0 = *r9;
                zmm1 = zmm0;
                zmm0 = _mm_cmpeq_epi8(zmm0, temp0_2);
                uint32_t temp0_6 = _mm_movemask_epi8(_mm_or_ps(_mm_cmpeq_epi8(zmm1, {0}), zmm0));
                
                if (temp0_6)
                {
                    uint64_t rflags_1;
                    int32_t temp0_7;
                    temp0_7 = _bit_scan_forward(temp0_6);
                    r9 += temp0_7;
                }
                else
                {
                    r9 = &r9[1];
                    continue;
                }
            }
            
            char rax_6 = *r9;
            
            if (!rax_6)
                break;
            
            if (rbp == rax_6)
            {
                uint128_t* r8_1 = r9;
                char* rax_7 = rsi;
                
                while (true)
                {
                    if ((rax_7 & 0xfff) <= 0xff0 && (r8_1 & 0xfff) <= 0xff0)
                    {
                        zmm1 = *rax_7;
                        zmm0 = *r8_1;
                        zmm2 = zmm1;
                        zmm1 = _mm_cmpeq_epi8(zmm1, {0});
                        uint32_t temp0_12 = _mm_movemask_epi8(_mm_or_ps(
                            _mm_cmpeq_epi8(_mm_cmpeq_epi8(zmm2, zmm0), {0}), zmm1));
                        
                        if (temp0_12)
                        {
                            uint64_t rflags_2;
                            int32_t temp0_13;
                            temp0_13 = _bit_scan_forward(temp0_12);
                            uint64_t rdx = temp0_13;
                            r8_1 += rdx;
                            rax_7 = &rax_7[rdx];
                        }
                        else
                        {
                            r8_1 = &r8_1[1];
                            rax_7 = &rax_7[0x10];
                            continue;
                        }
                    }
                    
                    char rcx_8 = *rax_7;
                    
                    if (!rcx_8)
                        return r9;
                    
                    if (*r8_1 != rcx_8)
                        break;
                    
                    r8_1 += 1;
                    rax_7 = &rax_7[1];
                }
            }
            
            r9 += 1;
        }
    }
    return 0;
}

