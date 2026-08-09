
  uint8_t (*)[0x20] sub_1800172d0(uint8_t (* arg1)[0x20], uint8_t (* arg2)[0x20], int256_t* arg3, void* arg4)

{
    void var_128;
    int64_t rax_1 = __security_cookie ^ &var_128;
    int32_t rbx_1 = arg2 - arg1;
    int32_t* r13 = arg3;
    uint8_t (* rdi)[0x20] = arg1;
    uint8_t (* result)[0x20];
    int32_t* result_3;
    
    if (arg4 > 0x20)
    {
        char zmm1[0x20] = *arg3;
        result_3 = arg2 - arg4;
        uint8_t var_e0_1[0x20] = _mm256_broadcastb_epi8(zmm1[0]);
        bool z_4 = (zmm1 ^ *result_3) == {0} ? 1 : 0;
        _mm256_zeroupper();
        int32_t rax_9;
        
        if (z_4)
            rax_9 = memcmp(&result_3[8], &r13[8], arg4 - 0x20);
        
        if (z_4 && !rax_9)
        {
        label_1800173de:
            result = result_3;
        }
        else
        {
            uint64_t rbx_4 = (rbx_1 - arg4) & 0x1f;
            void* rax_10 = &(*rdi)[rbx_4];
            void* var_e8_1 = rax_10;
            uint8_t (* result_2)[0x20];
            
            if (result_3 == rax_10)
            {
            label_1800175d1:
                _mm256_zeroupper();
                
                if (!rbx_4)
                {
                labelid_1:
                    result = arg2;
                }
                else
                {
                    int32_t rax_14 =
                        _mm256_movemask_epi8(__vpcmpeqb_ymmqq_ymmqq_memqq(*rdi, var_e0_1));
                    _mm256_zeroupper();
                    
                    if (!rax_14)
                    {
                    label_1800174ba:
                        result = arg2;
                    }
                    else
                    {
                        uint32_t rbx_8 = ((1 << rbx_4) - 1) & rax_14;
                        
                        if (!rbx_8)
                        {
                        label_1800174ba_1:
                            result = arg2;
                        }
                        else
                        {
                            while (true)
                            {
                                uint64_t rsi_3 = 0x1f - _lzcnt_u32(rbx_8);
                                result_2 = &(*rdi)[rsi_3];
                                
                                if ((*result_2 ^ *r13) == {0} ? 1 : 0)
                                {
                                    _mm256_zeroupper();
                                    
                                    if (!memcmp(&result_2[1], &r13[8], arg4 - 0x20))
                                        break;
                                }
                                
                                rbx_8 ^= 1 << rsi_3;
                                _mm256_zeroupper();
                                
                                if (!rbx_8)
                                    goto label_1800174ba_2;
                                
                                rdi = arg1;
                            }
                            
                            result = result_2;
                        }
                    }
                }
            }
            else
            {
                while (true)
                {
                    zmm1 = __vpcmpeqb_ymmqq_ymmqq_memqq(*(result_3 - 0x20), var_e0_1);
                    result_3 = &result_3[-8];
                    uint32_t rbx_5 = _mm256_movemask_epi8(zmm1);
                    
                    if (rbx_5)
                    {
                        while (true)
                        {
                            int256_t* rcx_12 = 0x1f - _lzcnt_u32(rbx_5);
                            result_2 = rcx_12 + result_3;
                            
                            if ((*(rcx_12 + result_3) ^ *r13) == {0} ? 1 : 0)
                            {
                                _mm256_zeroupper();
                                
                                if (!memcmp(&result_2[1], &r13[8], arg4 - 0x20))
                                    break;
                            }
                            
                            rbx_5 ^= 1 << rcx_12;
                            
                            if (!rbx_5)
                            {
                                rax_10 = var_e8_1;
                                goto label_1800175c1;
                            }
                        }
                        
                        break;
                    }
                    
                label_1800175c1:
                    
                    if (result_3 == rax_10)
                    {
                        rdi = arg1;
                        goto label_1800175d1;
                    }
                }
                
                result = result_2;
            }
        }
    }
    else
    {
        int256_t zmm3 = *(&data_180037810 - arg4);
        _mm256_zeroupper();
        int256_t var_a0;
        memcpy(&var_a0, r13, arg4);
        uint8_t (* rdx_1)[0x20] = arg2;
        int256_t zmm2_1 = var_a0;
        uint8_t zmm4_1[0x20] = _mm256_broadcastb_epi8(zmm2_1);
        void* i_1 = &rdx_1[-1];
        uint8_t var_c0_1[0x20] = zmm4_1;
        uint32_t i = _mm256_movemask_epi8(__vpcmpeqb_ymmqq_ymmqq_memqq(zmm4_1, rdx_1[-1]))
            & ((1 << (0x21 - arg4)) - 1);
        int256_t zmm3_1;
        
        if (!i)
            zmm3_1 = zmm3;
        else
        {
            do
            {
                uint64_t rcx_2 = 0x1f - _lzcnt_u32(i);
                result_3 = rcx_2 + i_1;
                _mm256_zeroupper();
                int256_t var_80;
                memcpy(&var_80, result_3, rdx_1 - result_3);
                zmm2_1 = var_a0;
                zmm3_1 = *(&data_180037810 - arg4);
                
                if (((zmm2_1 ^ var_80) & zmm3_1) == {0} ? 1 : 0)
                {
                    _mm256_zeroupper();
                    goto label_1800173de;
                }
                
                rdx_1 = arg2;
                i ^= 1 << rcx_2;
            } while (i);
            
            zmm4_1 = var_c0_1;
        }
        
        uint64_t r8_4 = rbx_1 & 0x1f;
        
        while (i_1 != &(*arg1)[r8_4])
        {
            char zmm1_1[0x20] = __vpcmpeqb_ymmqq_ymmqq_memqq(zmm4_1, *(i_1 - 0x20));
            i_1 -= 0x20;
            uint64_t rdx_3;
            
            for (uint32_t j = _mm256_movemask_epi8(zmm1_1); j; j ^= 1 << rdx_3)
            {
                rdx_3 = 0x1f - _lzcnt_u32(j);
                uint8_t (* result_1)[0x20] = rdx_3 + i_1;
                
                if (((zmm2_1 ^ *result_1) & zmm3_1) == {0} ? 1 : 0)
                {
                    _mm256_zeroupper();
                    result = result_1;
                    goto label_1800174c8;
                }
            }
        }
        
        _mm256_zeroupper();
        
        if (r8_4)
        {
            int32_t rax_6 = _mm256_movemask_epi8(__vpcmpeqb_ymmqq_ymmqq_memqq(*arg1, var_c0_1));
            _mm256_zeroupper();
            
            if (rax_6)
            {
                uint32_t i_2 = ((1 << r8_4) - 1) & rax_6;
                
                if (i_2)
                {
                    zmm2_1 = var_a0;
                    
                    do
                    {
                        uint64_t rcx_8 = 0x1f - _lzcnt_u32(i_2);
                        result = &(*arg1)[rcx_8];
                        
                        if (((zmm2_1 ^ *(rcx_8 + arg1)) & zmm3) == {0} ? 1 : 0)
                        {
                            _mm256_zeroupper();
                            goto label_1800174c8;
                        }
                        
                        i_2 ^= 1 << rcx_8;
                    } while (i_2);
                    
                    _mm256_zeroupper();
                }
            }
        }
        
    label_1800174ba_2:
        result = arg2;
    }
label_1800174c8:
    __security_check_cookie(rax_1 ^ &var_128);
    return result;
}

