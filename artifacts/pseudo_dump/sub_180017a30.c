
  uint32_t (*)[0x8] sub_180017a30(int64_t arg1, uint32_t (* arg2)[0x8], char arg3)

{
    char rax = data_18004685c;
    void* r9_1 = arg2 - arg1;
    uint32_t (* rbx)[0x8] = arg2;
    void* r11_1 = r9_1 & 0xffffffffffffffe0;
    char zmm1[0x20];
    
    if (!r11_1 || !(rax & 0x20))
    {
        void* r9_3 = r9_1 & 0xfffffffffffffff0;
        
        if (r9_3 && rax & 4)
        {
            uint8_t zmm0[0x20];
            zmm0[0] = {0};
            void* rcx_4 = arg2 - r9_3;
            zmm1[0] = arg3;
            zmm1[0] = _mm_shuffle_epi8(zmm1[0], {0});
            
            do
            {
                zmm0[0] = *(arg2 - 0x10);
                arg2 -= 0x10;
                zmm0[0] = _mm_cmpeq_epi8(zmm0[0], zmm1[0]);
                uint32_t temp0_11 = _mm_movemask_epi8(zmm0[0]);
                
                if (temp0_11)
                {
                    uint64_t rflags;
                    int32_t temp0_12;
                    temp0_12 = _bit_scan_reverse(temp0_11);
                    return temp0_12 + arg2;
                }
            } while (arg2 != rcx_4);
        }
    }
    else
    {
        double zmm3[0x4];
        zmm3[0] = arg3;
        zmm3[0] = __vpshufb_xmmdq_xmmdq_xmmdq(zmm3[0], {0});
        zmm3 = _mm256_insertf128_ps(zmm3, zmm3[0], 1);
        void* rcx_1 = arg2 - r11_1;
        
        while (true)
        {
            zmm1 = __vpcmpeqb_ymmqq_ymmqq_memqq(zmm3, arg2[-1]);
            arg2 -= 0x20;
            uint32_t rax_2 = _mm256_movemask_epi8(zmm1);
            
            if (!rax_2)
            {
                if (arg2 != rcx_1)
                    continue;
                else
                {
                    uint64_t r9_2 = r9_1 & 0x1c;
                    
                    if (!r9_2)
                        break;
                    
                    arg2 -= r9_2;
                    uint32_t zmm2[0x8] = *(&data_180037810 - r9_2);
                    rax_2 = _mm256_movemask_epi8(
                        _mm256_cmpeq_epi8(_mm256_maskload_epi32(zmm2, *arg2), zmm3) & zmm2);
                    
                    if (!rax_2)
                        break;
                }
            }
            
            _mm256_zeroupper();
            return 0x1f - _lzcnt_u32(rax_2) + arg2;
        }
        
        _mm256_zeroupper();
    }
    
    while (arg2 != arg1)
    {
        arg2 -= 1;
        
        if (*arg2 == arg3)
            return arg2;
    }
    
    return rbx;
}

