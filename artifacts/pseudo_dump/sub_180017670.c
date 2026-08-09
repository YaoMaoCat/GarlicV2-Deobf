
  uint32_t (*)[0x8] sub_180017670(uint8_t (* arg1)[0x20], uint32_t (* arg2)[0x8], char* arg3, void* arg4)

{
    int32_t zmm6[0x4];
    int32_t var_58[0x4] = zmm6;
    void var_d8;
    int64_t rax_1 = __security_cookie ^ &var_d8;
    int32_t (* var_b8)[0x4] = arg1;
    int32_t* r10 = arg3;
    int32_t (* rdi)[0x4] = arg1;
    uint32_t (* result)[0x8];
    
    if (!arg4)
        result = arg2;
    else if (arg4 != 1)
    {
        void* r13_2 = arg2 - rdi;
        
        if (r13_2 < arg4)
            result = arg2;
        else
        {
            char rax_2 = data_18004685c;
            
            if (rax_2 & 0x20 && r13_2 >= 0x20)
                result = sub_1800172d0(arg1, arg2, arg3, arg4);
            else if (!(rax_2 & 4) || r13_2 < 0x10)
            {
                uint32_t (* result_1)[0x8] = arg2 - arg4;
                
                while (true)
                {
                    if (*result_1 == *arg3)
                    {
                        char* rax_21 = 1;
                        
                        while (*(result_1 + rax_21) == *(rax_21 + r10))
                        {
                            rax_21 = &rax_21[1];
                            
                            if (rax_21 == arg4)
                            {
                                result = result_1;
                                goto label_180017a06;
                            }
                        }
                    }
                    
                    if (result_1 == rdi)
                        break;
                    
                    result_1 -= 1;
                }
                
                result = arg2;
            }
            else
            {
                int128_t var_78;
                
                if (arg4 > 0x10)
                {
                    zmm6 = *arg3;
                    void* var_80_1 = arg4;
                    uint32_t (* i)[0x8] = arg2 - arg4;
                    var_78 = i;
                    int128_t* var_a8 = &var_78;
                    int32_t var_98_1[0x4] = zmm6;
                    void* var_88_1 = &arg3[0x10];
                    int32_t rax_15;
                    
                    if ((*i ^ zmm6) == {0} ? 1 : 0)
                        rax_15 = memcmp(&(*i)[4], &arg3[0x10], arg4 - 0x10);
                    
                    if (!((*i ^ zmm6) == {0} ? 1 : 0) || rax_15)
                    {
                        uint64_t r13_5 = (r13_2 - arg4) & 0xf;
                        
                        while (i != rdi + r13_5)
                        {
                            i -= 0x10;
                            var_78 = i;
                            uint64_t rflags_9;
                            int32_t temp0_9[0x4];
                            temp0_9 = __pcmpestrm_xmmdq_memdq_immb(zmm6, *i, 0xc, 0x10, 0x10);
                            int32_t j = temp0_9[0];
                            
                            if (j)
                            {
                                do
                                {
                                    uint64_t rflags_10;
                                    int32_t temp0_10;
                                    temp0_10 = _bit_scan_reverse(j);
                                    uint32_t (* rdi_3)[0x8];
                                    
                                    if (!temp0_10)
                                    {
                                        rdi_3 = i;
                                    label_18001794e:
                                        
                                        if (!memcmp(&(*rdi_3)[4], &arg3[0x10], arg4 - 0x10))
                                        {
                                            result = rdi_3;
                                            goto label_180017a06;
                                        }
                                    }
                                    else
                                    {
                                        rdi_3 = temp0_10 + i;
                                        
                                        if ((zmm6 ^ *rdi_3) == {0} ? 1 : 0)
                                            goto label_18001794e;
                                    }
                                    j ^= 1 << temp0_10;
                                } while (j);
                                
                                rdi = var_b8;
                            }
                        }
                        
                        if (!r13_5)
                            result = arg2;
                        else
                        {
                            var_78 = rdi;
                            uint64_t rflags_11;
                            int32_t temp0_11[0x4];
                            temp0_11 = __pcmpestrm_xmmdq_memdq_immb(zmm6, *rdi, 0xc, 0x10, 0x10);
                            int32_t rdx_9 = temp0_11[0] & ((1 << r13_5) - 1);
                            
                            if (!rdx_9)
                                result = arg2;
                            else if (!sub_180017b50(&var_a8, rdx_9))
                                result = arg2;
                            else
                                result = var_78;
                        }
                    }
                    else
                        result = i;
                }
                else
                {
                    memcpy(&var_78, r10, arg4);
                    int32_t zmm2_1[0x4] = var_78;
                    int32_t (* r8_2)[0x4] = &(*arg2)[-4];
                    uint64_t rflags_1;
                    int32_t temp0_1[0x4];
                    temp0_1 = __pcmpestrm_xmmdq_memdq_immb(zmm2_1, *r8_2, 0xc, arg4, 0x10);
                    int32_t rax_5 = temp0_1[0] & ((1 << (0x11 - arg4)) - 1);
                    
                    if (!rax_5)
                    {
                        uint64_t r13_3 = r13_2 & 0xf;
                        int32_t r9_1 = ((1 << (0x11 - arg4)) - 1) ^ 0xffff;
                        void* rsi_1 = rdi + r13_3;
                        
                        if (r8_2 != rsi_1)
                        {
                            while (true)
                            {
                                r8_2 = &r8_2[-1];
                                uint64_t rflags_3;
                                int32_t temp0_3[0x4];
                                temp0_3 =
                                    __pcmpestrm_xmmdq_memdq_immb(zmm2_1, *r8_2, 0xc, arg4, 0x10);
                                int32_t r11_1 = temp0_3[0];
                                
                                if (r11_1)
                                {
                                    int32_t rdx_2 = r9_1 & r11_1;
                                    
                                    if (rdx_2)
                                    {
                                        int128_t zmm3_1 = *(&data_180037840 - arg4);
                                        
                                        while (true)
                                        {
                                            uint64_t rflags_4;
                                            int32_t temp0_4;
                                            temp0_4 = _bit_scan_reverse(rdx_2);
                                            uint32_t (* result_2)[0x8] = temp0_4 + r8_2;
                                            
                                            if (((zmm2_1 ^ *result_2) & zmm3_1) == {0} ? 1 : 0)
                                            {
                                                result = result_2;
                                                break;
                                            }
                                            
                                            rdx_2 ^= 1 << temp0_4;
                                            
                                            if (!rdx_2)
                                                goto label_1800177e9;
                                        }
                                        
                                        goto label_180017a06;
                                    }
                                    
                                label_1800177e9:
                                    int32_t r11_2 = r11_1 & ((1 << (0x11 - arg4)) - 1);
                                    
                                    if (r11_2)
                                    {
                                        uint64_t rflags_8;
                                        int32_t temp0_8;
                                        temp0_8 = _bit_scan_reverse(r11_2);
                                        result = r8_2 + temp0_8;
                                        goto label_180017a06;
                                    }
                                }
                                
                                if (r8_2 == rsi_1)
                                {
                                    rdi = var_b8;
                                    break;
                                }
                            }
                        }
                        
                        if (!r13_3)
                            result = arg2;
                        else
                        {
                            uint64_t rflags_5;
                            int32_t temp0_5[0x4];
                            temp0_5 = __pcmpestrm_xmmdq_memdq_immb(zmm2_1, *rdi, 0xc, arg4, 0x10);
                            int32_t rdx_4 = temp0_5[0] & ((1 << r13_3) - 1);
                            
                            if (!rdx_4)
                                result = arg2;
                            else
                            {
                                int32_t i_1 = r9_1 & rdx_4;
                                
                                if (i_1)
                                {
                                    int32_t zmm1_1[0x4] = *(&data_180037840 - arg4);
                                    
                                    do
                                    {
                                        uint64_t rflags_6;
                                        int32_t temp0_6;
                                        temp0_6 = _bit_scan_reverse(i_1);
                                        result = temp0_6 + rdi;
                                        
                                        if (((*result ^ zmm2_1) & zmm1_1) == {0} ? 1 : 0)
                                            goto label_180017a06;
                                        
                                        i_1 ^= 1 << temp0_6;
                                    } while (i_1);
                                }
                                
                                int32_t rdx_5 = rdx_4 & ((1 << (0x11 - arg4)) - 1);
                                
                                if (!rdx_5)
                                    result = arg2;
                                else
                                {
                                    uint64_t rflags_7;
                                    int32_t temp0_7;
                                    temp0_7 = _bit_scan_reverse(rdx_5);
                                    result = temp0_7 + rdi;
                                }
                            }
                        }
                    }
                    else
                    {
                        uint64_t rflags_2;
                        int32_t temp0_2;
                        temp0_2 = _bit_scan_reverse(rax_5);
                        result = temp0_2 + r8_2;
                    }
                }
            }
        }
    }
    else
        result = sub_180017a30(arg1, arg2, *arg3);
    
label_180017a06:
    __security_check_cookie(rax_1 ^ &var_d8);
    return result;
}

