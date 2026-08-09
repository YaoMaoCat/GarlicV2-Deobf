
  int32_t* memcpy(int128_t* arg1, int32_t* arg2, void* arg3)

{
    int32_t* result = arg1;
    
    if (arg3 > 0xf)
    {
        int256_t zmm1;
        int256_t zmm2;
        
        if (arg3 <= 0x20)
        {
            zmm1 = *arg2;
            zmm2 = *(arg2 + arg3 - 0x10);
            *arg1 = zmm1;
            *(arg1 + arg3 - 0x10) = zmm2;
            return result;
        }
        
        int128_t* r9_7 = arg2 + arg3;
        
        if (arg1 <= arg2)
            r9_7 = arg1;
        
        int256_t zmm0;
        
        if (arg1 < r9_7)
        {
            zmm2 = *arg2;
            int64_t rdx = arg2 - arg1;
            int64_t rcx_17 = arg1 + arg3;
            zmm0 = *(rcx_17 + rdx - 0x10);
            int128_t* rcx_18 = rcx_17 - 0x10;
            void* r8_11 = arg3 - 0x10;
            
            if (rcx_18 & 0xf)
            {
                int128_t* r9_21 = rcx_18;
                rcx_18 &= 0xfffffffffffffff0;
                zmm1 = zmm0;
                zmm0 = *(rcx_18 + rdx);
                *r9_21 = zmm1;
                r8_11 = rcx_18 - result;
            }
            
            uint64_t r9_23 = r8_11 >> 7;
            
            if (r9_23)
            {
                *rcx_18 = zmm0;
                
                while (true)
                {
                    zmm0 = *(rcx_18 + rdx - 0x10);
                    zmm1 = *(rcx_18 + rdx - 0x20);
                    rcx_18 -= 0x80;
                    rcx_18[7] = zmm0;
                    rcx_18[6] = zmm1;
                    zmm0 = *(rcx_18 + rdx + 0x50);
                    zmm1 = *(rcx_18 + rdx + 0x40);
                    uint64_t temp0_1 = r9_23;
                    r9_23 -= 1;
                    rcx_18[5] = zmm0;
                    rcx_18[4] = zmm1;
                    zmm0 = *(rcx_18 + rdx + 0x30);
                    zmm1 = *(rcx_18 + rdx + 0x20);
                    rcx_18[3] = zmm0;
                    rcx_18[2] = zmm1;
                    zmm0 = *(rcx_18 + rdx + 0x10);
                    zmm1 = *(rcx_18 + rdx);
                    
                    if (temp0_1 == 1)
                        break;
                    
                    rcx_18[1] = zmm0;
                    *rcx_18 = zmm1;
                }
                
                rcx_18[1] = zmm0;
                r8_11 &= 0x7f;
                zmm0 = zmm1;
            }
            
            uint64_t i_1 = r8_11 >> 4;
            
            if (i_1)
            {
                uint64_t i;
                
                do
                {
                    *rcx_18 = zmm0;
                    rcx_18 -= 0x10;
                    zmm0 = *(rcx_18 + rdx);
                    i = i_1;
                    i_1 -= 1;
                } while (i != 1);
            }
            
            if (r8_11 & 0xf)
                *result = zmm2;
            
            *rcx_18 = zmm0;
            return result;
        }
        
        int256_t zmm3;
        int256_t zmm4;
        int256_t zmm5;
        
        if (data_180046858 < 3)
        {
            if (arg3 > 0x800 && *data_18004756c & 2)
                /* tailcall */
                return memcpy_repmovs(arg1, arg2, arg3);
            
            zmm0 = *arg2;
            zmm5 = *(arg2 + arg3 - 0x10);
            
            if (arg3 > 0x80)
            {
                void* r9_18 = (arg1 & 0xf) - 0x10;
                arg1 -= r9_18;
                arg2 -= r9_18;
                arg3 += r9_18;
                
                if (arg3 > 0x80)
                {
                    do
                    {
                        zmm1 = *arg2;
                        zmm2 = *(arg2 + 0x10);
                        zmm3 = *(arg2 + 0x20);
                        zmm4 = *(arg2 + 0x30);
                        *arg1 = zmm1;
                        arg1[1] = zmm2;
                        arg1[2] = zmm3;
                        arg1[3] = zmm4;
                        zmm1 = *(arg2 + 0x40);
                        zmm2 = *(arg2 + 0x50);
                        zmm3 = *(arg2 + 0x60);
                        zmm4 = *(arg2 + 0x70);
                        arg1[4] = zmm1;
                        arg1[5] = zmm2;
                        arg1[6] = zmm3;
                        arg1[7] = zmm4;
                        arg1 = &arg1[8];
                        arg2 = &arg2[0x20];
                        arg3 -= 0x80;
                    } while (arg3 >= 0x80);
                }
            }
            
            void* r9_20 = (arg3 + 0xf) & 0xfffffffffffffff0;
            
            switch (jump_table_180040bf8[r9_20 >> 4])
            {
                case 0x2dbe9:
                {
                    zmm1 = *(arg2 + r9_20 - 0x80);
                    *(arg1 + r9_20 - 0x80) = zmm1;
                label_18002dbf7:
                    zmm1 = *(arg2 + r9_20 - 0x70);
                    *(arg1 + r9_20 - 0x70) = zmm1;
                label_18002dc05:
                    zmm1 = *(arg2 + r9_20 - 0x60);
                    *(arg1 + r9_20 - 0x60) = zmm1;
                label_18002dc13:
                    zmm1 = *(arg2 + r9_20 - 0x50);
                    *(arg1 + r9_20 - 0x50) = zmm1;
                label_18002dc21:
                    zmm1 = *(arg2 + r9_20 - 0x40);
                    *(arg1 + r9_20 - 0x40) = zmm1;
                label_18002dc2f:
                    zmm1 = *(arg2 + r9_20 - 0x30);
                    *(arg1 + r9_20 - 0x30) = zmm1;
                label_18002dc3d:
                    zmm1 = *(arg2 + r9_20 - 0x20);
                    *(arg1 + r9_20 - 0x20) = zmm1;
                    *(arg1 + arg3 - 0x10) = zmm5;
                    break;
                }
                case 0x2dbf7:
                {
                    goto label_18002dbf7;
                }
                case 0x2dc05:
                {
                    goto label_18002dc05;
                }
                case 0x2dc13:
                {
                    goto label_18002dc13;
                }
                case 0x2dc21:
                {
                    goto label_18002dc21;
                }
                case 0x2dc2f:
                {
                    goto label_18002dc2f;
                }
                case 0x2dc3d:
                {
                    goto label_18002dc3d;
                }
                case 0x2dc4b:
                {
                    *(arg1 + arg3 - 0x10) = zmm5;
                    break;
                }
            }
            
            *result = zmm0;
            return result;
        }
        
        if (arg3 > 0x2000 && arg3 <= 0x180000)
        {
            int32_t* r9_8 = &arg1[4];
            
            if (arg1 > arg2)
                r9_8 = arg2;
            
            if (r9_8 <= arg2 && *data_18004756c & 2)
                /* tailcall */
                return memcpy_repmovs(arg1, arg2, arg3);
        }
        
        zmm0 = *arg2;
        zmm5 = *(arg2 + arg3 - 0x20);
        
        if (arg3 > 0x100)
        {
            void* r9_11 = (arg1 & 0x1f) - 0x20;
            arg1 -= r9_11;
            arg2 -= r9_11;
            arg3 += r9_11;
            
            if (arg3 > 0x100)
            {
                if (arg3 > 0x180000)
                {
                    do
                    {
                        zmm2 = *(arg2 + 0x20);
                        zmm3 = *(arg2 + 0x40);
                        zmm4 = *(arg2 + 0x60);
                        *arg1 = *arg2;
                        *(arg1 + 0x20) = zmm2;
                        *(arg1 + 0x40) = zmm3;
                        *(arg1 + 0x60) = zmm4;
                        zmm2 = *(arg2 + 0xa0);
                        zmm3 = *(arg2 + 0xc0);
                        zmm4 = *(arg2 + 0xe0);
                        *(arg1 + 0x80) = *(arg2 + 0x80);
                        *(arg1 + 0xa0) = zmm2;
                        *(arg1 + 0xc0) = zmm3;
                        *(arg1 + 0xe0) = zmm4;
                        arg1 = &arg1[0x10];
                        arg2 = &arg2[0x40];
                        arg3 -= 0x100;
                    } while (arg3 >= 0x100);
                    
                    void* r9_15 = (arg3 + 0x1f) & 0xffffffffffffffe0;
                    
                    switch (r9_15 >> 5)
                    {
                        case 1:
                        {
                            *(arg1 + arg3 - 0x20) = zmm5;
                            break;
                        }
                        case 2:
                        {
                            *(arg1 + r9_15 - 0x40) = *(arg2 + r9_15 - 0x40);
                            *(arg1 + arg3 - 0x20) = zmm5;
                            break;
                        }
                        case 3:
                        {
                            goto label_18002dada;
                        }
                        case 4:
                        {
                            goto label_18002dacc;
                        }
                        case 5:
                        {
                            goto label_18002dabb;
                        }
                        case 6:
                        {
                            goto label_18002daa7;
                        }
                        case 7:
                        {
                            goto label_18002da93;
                        }
                        case 8:
                        {
                            *(arg1 + r9_15 - 0x100) = *(arg2 + r9_15 - 0x100);
                        label_18002da93:
                            *(arg1 + r9_15 - 0xe0) = *(arg2 + r9_15 - 0xe0);
                        label_18002daa7:
                            *(arg1 + r9_15 - 0xc0) = *(arg2 + r9_15 - 0xc0);
                        label_18002dabb:
                            *(arg1 + r9_15 - 0xa0) = *(arg2 + r9_15 - 0xa0);
                        label_18002dacc:
                            *(arg1 + r9_15 - 0x80) = *(arg2 + r9_15 - 0x80);
                        label_18002dada:
                            *(arg1 + r9_15 - 0x60) = *(arg2 + r9_15 - 0x60);
                            *(arg1 + r9_15 - 0x40) = *(arg2 + r9_15 - 0x40);
                            *(arg1 + arg3 - 0x20) = zmm5;
                            break;
                        }
                    }
                    
                    *result = zmm0;
                    _mm256_zeroupper();
                    return result;
                }
                
                do
                {
                    zmm2 = *(arg2 + 0x20);
                    zmm3 = *(arg2 + 0x40);
                    zmm4 = *(arg2 + 0x60);
                    *arg1 = *arg2;
                    *(arg1 + 0x20) = zmm2;
                    *(arg1 + 0x40) = zmm3;
                    *(arg1 + 0x60) = zmm4;
                    zmm2 = *(arg2 + 0xa0);
                    zmm3 = *(arg2 + 0xc0);
                    zmm4 = *(arg2 + 0xe0);
                    *(arg1 + 0x80) = *(arg2 + 0x80);
                    *(arg1 + 0xa0) = zmm2;
                    *(arg1 + 0xc0) = zmm3;
                    *(arg1 + 0xe0) = zmm4;
                    arg1 = &arg1[0x10];
                    arg2 = &arg2[0x40];
                    arg3 -= 0x100;
                } while (arg3 >= 0x100);
            }
        }
        
        void* r9_13 = (arg3 + 0x1f) & 0xffffffffffffffe0;
        
        switch (r9_13 >> 5)
        {
            case 1:
            {
                *(arg1 + arg3 - 0x20) = zmm5;
                break;
            }
            case 2:
            {
                *(arg1 + r9_13 - 0x40) = *(arg2 + r9_13 - 0x40);
                *(arg1 + arg3 - 0x20) = zmm5;
                break;
            }
            case 3:
            {
                goto label_18002d9aa;
            }
            case 4:
            {
                goto label_18002d99c;
            }
            case 5:
            {
                goto label_18002d98b;
            }
            case 6:
            {
                goto label_18002d977;
            }
            case 7:
            {
                goto label_18002d963;
            }
            case 8:
            {
                *(arg1 + r9_13 - 0x100) = *(arg2 + r9_13 - 0x100);
            label_18002d963:
                *(arg1 + r9_13 - 0xe0) = *(arg2 + r9_13 - 0xe0);
            label_18002d977:
                *(arg1 + r9_13 - 0xc0) = *(arg2 + r9_13 - 0xc0);
            label_18002d98b:
                *(arg1 + r9_13 - 0xa0) = *(arg2 + r9_13 - 0xa0);
            label_18002d99c:
                *(arg1 + r9_13 - 0x80) = *(arg2 + r9_13 - 0x80);
            label_18002d9aa:
                *(arg1 + r9_13 - 0x60) = *(arg2 + r9_13 - 0x60);
                *(arg1 + r9_13 - 0x40) = *(arg2 + r9_13 - 0x40);
                *(arg1 + arg3 - 0x20) = zmm5;
                break;
            }
        }
        
        *result = zmm0;
        _mm256_zeroupper();
        return result;
    }
    
    switch (arg3)
    {
        case nullptr:
        {
            return result;
            break;
        }
        case 1:
        {
            *result = *arg2;
            return result;
            break;
        }
        case 2:
        {
            *result = *arg2;
            return result;
            break;
        }
        case 3:
        {
            char r8_4 = *(arg2 + 2);
            *result = *arg2;
            *(result + 2) = r8_4;
            return result;
            break;
        }
        case 4:
        {
            *result = *arg2;
            return result;
            break;
        }
        case 5:
        {
            char r8_10 = arg2[1];
            *result = *arg2;
            result[1] = r8_10;
            return result;
            break;
        }
        case 6:
        {
            int16_t r8_9 = arg2[1];
            *result = *arg2;
            result[1] = r8_9;
            return result;
            break;
        }
        case 7:
        {
            int16_t r8_2 = arg2[1];
            char r9_4 = *(arg2 + 6);
            *result = *arg2;
            result[1] = r8_2;
            *(result + 6) = r9_4;
            return result;
            break;
        }
        case 8:
        {
            *result = *arg2;
            return result;
            break;
        }
        case 9:
        {
            char rcx_8 = arg2[2];
            *result = *arg2;
            result[2] = rcx_8;
            return result;
            break;
        }
        case 0xa:
        {
            int16_t rcx_7 = arg2[2];
            *result = *arg2;
            result[2] = rcx_7;
            return result;
            break;
        }
        case 0xb:
        {
            int16_t rcx_1 = arg2[2];
            char r9_3 = *(arg2 + 0xa);
            *result = *arg2;
            result[2] = rcx_1;
            *(result + 0xa) = r9_3;
            return result;
            break;
        }
        case 0xc:
        {
            int32_t rcx_9 = arg2[2];
            *result = *arg2;
            result[2] = rcx_9;
            return result;
            break;
        }
        case 0xd:
        {
            int32_t rcx_6 = arg2[2];
            char r9_6 = arg2[3];
            *result = *arg2;
            result[2] = rcx_6;
            result[3] = r9_6;
            return result;
            break;
        }
        case 0xe:
        {
            int32_t rcx_4 = arg2[2];
            int16_t r9_5 = arg2[3];
            *result = *arg2;
            result[2] = rcx_4;
            result[3] = r9_5;
            return result;
            break;
        }
        case 0xf:
        {
            int32_t rcx = arg2[2];
            int16_t r9_2 = arg2[3];
            char r10 = *(arg2 + 0xe);
            *result = *arg2;
            result[2] = rcx;
            result[3] = r9_2;
            *(result + 0xe) = r10;
            return result;
            break;
        }
    }
}

