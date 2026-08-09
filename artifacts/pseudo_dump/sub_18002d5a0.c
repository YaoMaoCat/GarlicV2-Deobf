
  char* sub_18002d5a0(int64_t arg1, char arg2)

{
    uint32_t rdx_2 = arg2;
    int128_t* rax_1 = arg1 & 0xfffffffffffffff0;
    uint32_t r9_2 = rdx_2 << 8 | rdx_2;
    uint128_t zmm2 = *rax_1;
    uint128_t zmm0 = zmm2;
    uint32_t temp0_1[0x4] = _mm_shuffle_epi32(_mm_shufflelo_epi16(r9_2, 0), 0);
    zmm2 = _mm_cmpeq_epi8(zmm2, {0});
    int32_t i;
    uint32_t zmm1[0x4];
    
    for (i = _mm_movemask_epi8(_mm_or_ps(_mm_cmpeq_epi8(zmm0, temp0_1), zmm2))
        & 0xffffffff << (arg1 & 0xf); !i; 
        i = _mm_movemask_epi8(_mm_or_ps(_mm_cmpeq_epi8(zmm1, temp0_1), zmm0)))
    {
        zmm0 = rax_1[1];
        rax_1 = &rax_1[1];
        zmm1 = zmm0;
        zmm0 = _mm_cmpeq_epi8(zmm0, {0});
    }
    
    uint64_t rflags;
    int32_t temp0_10;
    temp0_10 = _bit_scan_forward(i);
    char* result = temp0_10 + rax_1;
    
    if (*result == r9_2)
        return result;
    
    return nullptr;
}

