
  char* sub_18002a090(char* arg1, char* arg2)

{
    uint64_t r10_1 = arg2 & 0xf;
    int128_t* rbx_1 = arg2 - r10_1;
    char* result = arg1;
    uint128_t zmm1 = *rbx_1;
    
    if (r10_1 - 1 <= 0xe)
        switch (r10_1)
        {
            case 1:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 1);
                break;
            }
            case 2:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 2);
                break;
            }
            case 3:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 3);
                break;
            }
            case 4:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 4);
                break;
            }
            case 5:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 5);
                break;
            }
            case 6:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 6);
                break;
            }
            case 7:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 7);
                break;
            }
            case 8:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 8);
                break;
            }
            case 9:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 9);
                break;
            }
            case 0xa:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 0xa);
                break;
            }
            case 0xb:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 0xb);
                break;
            }
            case 0xc:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 0xc);
                break;
            }
            case 0xd:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 0xd);
                break;
            }
            case 0xe:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 0xe);
                break;
            }
            case 0xf:
            {
                zmm1 = _mm_bsrli_si128(zmm1, 0xf);
                break;
            }
        }
    
    uint32_t temp0_17 = _mm_movemask_epi8(_mm_cmpeq_epi8({0}, zmm1));
    
    if (temp0_17)
    {
        uint64_t rflags_1;
        int32_t temp0_18;
        temp0_18 = _bit_scan_forward(temp0_17);
        int32_t rdi;
        
        if (r10_1)
            rdi = temp0_18 < 0x10 - r10_1;
        else
            rdi = 1;
        
        uint64_t rax_5 = 0xf - temp0_18;
        
        if (rax_5 <= 0xf)
            switch (rax_5)
            {
                case 0:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 1), 1);
                    break;
                }
                case 1:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 2), 2);
                    break;
                }
                case 2:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 3), 3);
                    break;
                }
                case 3:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 4), 4);
                    break;
                }
                case 4:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 5), 5);
                    break;
                }
                case 5:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 6), 6);
                    break;
                }
                case 6:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 7), 7);
                    break;
                }
                case 7:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 8), 8);
                    break;
                }
                case 8:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 9), 9);
                    break;
                }
                case 9:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 0xa), 0xa);
                    break;
                }
                case 0xa:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 0xb), 0xb);
                    break;
                }
                case 0xb:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 0xc), 0xc);
                    break;
                }
                case 0xc:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 0xd), 0xd);
                    break;
                }
                case 0xd:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 0xe), 0xe);
                    break;
                }
                case 0xe:
                {
                    zmm1 = _mm_bsrli_si128(_mm_slli_si128(zmm1, 0xf), 0xf);
                    break;
                }
                case 0xf:
                {
                    zmm1 = {0};
                    break;
                }
            }
        
        if (!rdi)
            goto label_18002a258;
    }
    else if (r10_1)
    {
    label_18002a258:
        char zmm2[0x10] = rbx_1[1];
        uint32_t temp0_50 = _mm_movemask_epi8(_mm_cmpeq_epi8(zmm2, {0}));
        int32_t temp0_51;
        uint64_t rflags_2;
        
        if (temp0_50)
            temp0_51 = _bit_scan_forward(temp0_50);
        
        if (!temp0_50 || temp0_51 - r10_1 + 0x10 > 0x10)
            /* tailcall */
            return sub_180029ff0(result, arg2);
        
        uint64_t r9_1 = 0xf - temp0_51;
        
        if (r9_1 <= 0xf)
            switch (r9_1)
            {
                case 0:
                {
                    zmm2 = _mm_slli_si128(zmm2, 1);
                    break;
                }
                case 1:
                {
                    zmm2 = _mm_slli_si128(zmm2, 2);
                    break;
                }
                case 2:
                {
                    zmm2 = _mm_slli_si128(zmm2, 3);
                    break;
                }
                case 3:
                {
                    zmm2 = _mm_slli_si128(zmm2, 4);
                    break;
                }
                case 4:
                {
                    zmm2 = _mm_slli_si128(zmm2, 5);
                    break;
                }
                case 5:
                {
                    zmm2 = _mm_slli_si128(zmm2, 6);
                    break;
                }
                case 6:
                {
                    zmm2 = _mm_slli_si128(zmm2, 7);
                    break;
                }
                case 7:
                {
                    zmm2 = _mm_slli_si128(zmm2, 8);
                    break;
                }
                case 8:
                {
                    zmm2 = _mm_slli_si128(zmm2, 9);
                    break;
                }
                case 9:
                {
                    zmm2 = _mm_slli_si128(zmm2, 0xa);
                    break;
                }
                case 0xa:
                {
                    zmm2 = _mm_slli_si128(zmm2, 0xb);
                    break;
                }
                case 0xb:
                {
                    zmm2 = _mm_slli_si128(zmm2, 0xc);
                    break;
                }
                case 0xc:
                {
                    zmm2 = _mm_slli_si128(zmm2, 0xd);
                    break;
                }
                case 0xd:
                {
                    zmm2 = _mm_slli_si128(zmm2, 0xe);
                    break;
                }
                case 0xe:
                {
                    zmm2 = _mm_slli_si128(zmm2, 0xf);
                    break;
                }
                case 0xf:
                {
                    zmm2 = {0};
                    break;
                }
            }
        
        zmm1 = _mm_or_ps(zmm1, zmm2);
    }
    else if (*(rbx_1 + 1))
        /* tailcall */
        return sub_180029ff0(arg1, arg2);
    
    char i = *result;
    
    while (i)
    {
        char zmm0[0x10] = i;
        zmm0 = _mm_unpacklo_epi8(zmm0, zmm0[0]);
        
        if (_mm_movemask_epi8(_mm_cmpeq_epi8(
                _mm_shuffle_epi32(_mm_unpacklo_epi8(zmm0, zmm0[0]), 0), zmm1)))
            return result;
        
        i = result[1];
        result = &result[1];
    }
    
    return 0;
}

