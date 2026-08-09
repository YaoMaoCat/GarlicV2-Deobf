
  void* sub_18002d460(char (* arg1)[0x10], char arg2)

{
    char (* result_1)[0x10] = arg1;
    
    if (!arg2)
    {
        char (* rdx_1)[0x10] = arg1 & 0xfffffffffffffff0;
        int32_t i;
        
        for (i = _mm_movemask_epi8(__pcmpeqb_xmmdq_memdq({0}, *rdx_1))
                & 0xffffffff << (result_1 & 0xf); !i; 
                i = _mm_movemask_epi8(__pcmpeqb_xmmdq_memdq({0}, *rdx_1)))
            rdx_1 = &rdx_1[1];
        
        uint64_t rflags_1;
        int32_t temp0_5;
        temp0_5 = _bit_scan_forward(i);
        return &(*rdx_1)[temp0_5];
    }
    
    char (* result)[0x10] = nullptr;
    int32_t zmm1[0x4];
    
    if (data_180046858 >= 2)
    {
        bool c_1 = false;
        bool z_1;
        
        for (z_1 = !(result_1 & 0xf); !z_1; z_1 = !(result_1 & 0xf))
        {
            char rcx_7 = *result_1;
            
            if (rcx_7 == arg2)
                result = result_1;
            
            if (!rcx_7)
                return result;
            
            result_1 = &(*result_1)[1];
            c_1 = false;
        }
        
        zmm1 = arg2;
        
        while (true)
        {
            char zmm0[0x10] = *result_1;
            int64_t rflags_4;
            int32_t temp0_18;
            temp0_18 = _mm_cmpistri(zmm1, zmm0, 0x40);
            
            if (c_1)
            {
                int64_t r8_1 = temp0_18;
                result = &(*result_1)[r8_1];
                z_1 = r8_1 == -(result_1);
                int64_t rflags_5;
                int32_t temp0_20;
                temp0_20 = _mm_cmpistri(zmm1, zmm0, 0x40);
            }
            
            if (z_1)
                break;
            
            char (* result_2)[0x10] = result_1;
            result_1 = &result_1[1];
            c_1 = result_2 >= -0x10;
            z_1 = result_2 == -0x10;
        }
    }
    else
    {
        uint32_t rcx_1 = arg2;
        int128_t* r9_2 = result_1 & 0xfffffffffffffff0;
        int32_t r11_2 = 0xffffffff << (result_1 & 0xf);
        char zmm2[0x10] = *r9_2;
        uint32_t temp0_7[0x4] = _mm_shuffle_epi32(_mm_shufflelo_epi16(rcx_1 << 8 | rcx_1, 0), 0);
        char temp0_8[0x10] = _mm_cmpeq_epi8(zmm2, {0});
        char temp0_9[0x10] = _mm_cmpeq_epi8(zmm2, temp0_7);
        uint32_t temp0_10 = _mm_movemask_epi8(temp0_8);
        int32_t r10_2 = _mm_movemask_epi8(temp0_9) & r11_2;
        int32_t i_1 = temp0_10 & r11_2;
        
        while (!i_1)
        {
            zmm1 = r9_2[1];
            uint64_t rflags_2;
            int32_t temp0_12;
            temp0_12 = _bit_scan_reverse(r10_2);
            i_1 = _mm_movemask_epi8(_mm_cmpeq_epi8(zmm1, {0}));
            bool cond:1_1 = r10_2;
            r10_2 = _mm_movemask_epi8(_mm_cmpeq_epi8(zmm1, temp0_7));
            
            if (cond:1_1)
                result = temp0_12 + r9_2;
            
            r9_2 = &r9_2[1];
        }
        
        int32_t rdx_9 = ((-(i_1) & i_1) - 1) & r10_2;
        uint64_t rflags_3;
        int32_t temp0_17;
        temp0_17 = _bit_scan_reverse(rdx_9);
        
        if (rdx_9)
            return temp0_17 + r9_2;
    }
    return result;
}

