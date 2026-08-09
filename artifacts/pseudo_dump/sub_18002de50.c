
  double [0x4] sub_18002de50(int128_t* arg1, char arg2, void* arg3)

{
    double (* rax_2)[0x4] = arg1;
    uint64_t rdx = arg2;
    int64_t r11 = 0x101010101010101 * rdx;
    double result[0x4];
    result[0] = r11;
    
    if (arg3 > 0xf)
    {
        result[0] = _mm_unpacklo_epi64(result[0], result[0]);
        
        if (arg3 <= 0x20)
        {
            *arg1 = result[0];
            *(arg1 + arg3 - 0x10) = result[0];
            return result;
        }
        
        if (data_180046858 < 3)
        {
            if (arg3 > data_180046860 && *data_18004756c & 2)
                /* tailcall */
                return sub_18002de40(arg1, rdx, arg3, arg1);
            
            int128_t* rcx_4 = arg1 - ((arg1 & 0xf) - 0x10);
            int64_t i = arg3 + (arg1 & 0xf) - 0x10;
            
            if (i > 0x80)
            {
                do
                {
                    *rcx_4 = result[0];
                    rcx_4[1] = result[0];
                    rcx_4[2] = result[0];
                    rcx_4[3] = result[0];
                    rcx_4[4] = result[0];
                    rcx_4[5] = result[0];
                    rcx_4[6] = result[0];
                    rcx_4[7] = result[0];
                    rcx_4 = &rcx_4[8];
                    i -= 0x80;
                } while (i >= 0x80);
            }
            
            int64_t r9_14 = (i + 0xf) & 0xfffffffffffffff0;
            
            switch (jump_table_180040ca8[r9_14 >> 4])
            {
                case 0x2e19b:
                {
                    *(rcx_4 + r9_14 - 0x80) = result[0];
                label_18002e1a2:
                    *(rcx_4 + r9_14 - 0x70) = result[0];
                label_18002e1a9:
                    *(rcx_4 + r9_14 - 0x60) = result[0];
                label_18002e1b0:
                    *(rcx_4 + r9_14 - 0x50) = result[0];
                label_18002e1b7:
                    *(rcx_4 + r9_14 - 0x40) = result[0];
                label_18002e1be:
                    *(rcx_4 + r9_14 - 0x30) = result[0];
                    *(rcx_4 + r9_14 - 0x20) = result[0];
                    *(rcx_4 + i - 0x10) = result[0];
                    break;
                }
                case 0x2e1a2:
                {
                    goto label_18002e1a2;
                }
                case 0x2e1a9:
                {
                    goto label_18002e1a9;
                }
                case 0x2e1b0:
                {
                    goto label_18002e1b0;
                }
                case 0x2e1b7:
                {
                    goto label_18002e1b7;
                }
                case 0x2e1be:
                {
                    goto label_18002e1be;
                }
                case 0x2e1c5:
                {
                    *(rcx_4 + r9_14 - 0x20) = result[0];
                    *(rcx_4 + i - 0x10) = result[0];
                    break;
                }
                case 0x2e1cc:
                {
                    *(rcx_4 + i - 0x10) = result[0];
                    break;
                }
            }
            
            *rax_2 = result[0];
            return result;
        }
        
        if (arg3 > data_180046860 && arg3 <= data_180046868 && *data_18004756c & 2)
            /* tailcall */
            return sub_18002de40(arg1, rdx, arg3, arg1);
        
        result = _mm256_insertf128_ps(result, result[0], 1);
        int256_t* rcx_2 = arg1 - ((arg1 & 0x1f) - 0x20);
        void* i_1 = arg3 + (arg1 & 0x1f) - 0x20;
        
        if (i_1 > 0x100)
        {
            if (i_1 > data_180046868)
            {
                do
                {
                    *rcx_2 = result;
                    rcx_2[1] = result;
                    rcx_2[2] = result;
                    rcx_2[3] = result;
                    rcx_2[4] = result;
                    rcx_2[5] = result;
                    rcx_2[6] = result;
                    rcx_2[7] = result;
                    rcx_2 = &rcx_2[8];
                    i_1 -= 0x100;
                } while (i_1 >= 0x100);
                
                void* r9_9 = (i_1 + 0x1f) & 0xffffffffffffffe0;
                
                switch (r9_9 >> 5)
                {
                    case 1:
                    {
                        *(rcx_2 + i_1 - 0x20) = result;
                        break;
                    }
                    case 2:
                    {
                        *(rcx_2 + r9_9 - 0x40) = result;
                        *(rcx_2 + i_1 - 0x20) = result;
                        break;
                    }
                    case 3:
                    {
                        goto label_18002e0d6;
                    }
                    case 4:
                    {
                        goto label_18002e0cf;
                    }
                    case 5:
                    {
                        goto label_18002e0c5;
                    }
                    case 6:
                    {
                        goto label_18002e0bb;
                    }
                    case 7:
                    {
                        goto label_18002e0b1;
                    }
                    case 8:
                    {
                        *(rcx_2 + r9_9 - 0x100) = result;
                    label_18002e0b1:
                        *(rcx_2 + r9_9 - 0xe0) = result;
                    label_18002e0bb:
                        *(rcx_2 + r9_9 - 0xc0) = result;
                    label_18002e0c5:
                        *(rcx_2 + r9_9 - 0xa0) = result;
                    label_18002e0cf:
                        *(rcx_2 + r9_9 - 0x80) = result;
                    label_18002e0d6:
                        *(rcx_2 + r9_9 - 0x60) = result;
                        *(rcx_2 + r9_9 - 0x40) = result;
                        *(rcx_2 + i_1 - 0x20) = result;
                        break;
                    }
                }
                
                *rax_2 = result;
                _mm256_zeroupper();
                return result;
            }
            
            do
            {
                *rcx_2 = result;
                rcx_2[1] = result;
                rcx_2[2] = result;
                rcx_2[3] = result;
                rcx_2[4] = result;
                rcx_2[5] = result;
                rcx_2[6] = result;
                rcx_2[7] = result;
                rcx_2 = &rcx_2[8];
                i_1 -= 0x100;
            } while (i_1 >= 0x100);
        }
        
        void* r9_7 = (i_1 + 0x1f) & 0xffffffffffffffe0;
        
        switch (r9_7 >> 5)
        {
            case 1:
            {
                *(rcx_2 + i_1 - 0x20) = result;
                break;
            }
            case 2:
            {
                *(rcx_2 + r9_7 - 0x40) = result;
                *(rcx_2 + i_1 - 0x20) = result;
                break;
            }
            case 3:
            {
                goto label_18002e016;
            }
            case 4:
            {
                goto label_18002e00f;
            }
            case 5:
            {
                goto label_18002e005;
            }
            case 6:
            {
                goto label_18002dffb;
            }
            case 7:
            {
                goto label_18002dff1;
            }
            case 8:
            {
                *(rcx_2 + r9_7 - 0x100) = result;
            label_18002dff1:
                *(rcx_2 + r9_7 - 0xe0) = result;
            label_18002dffb:
                *(rcx_2 + r9_7 - 0xc0) = result;
            label_18002e005:
                *(rcx_2 + r9_7 - 0xa0) = result;
            label_18002e00f:
                *(rcx_2 + r9_7 - 0x80) = result;
            label_18002e016:
                *(rcx_2 + r9_7 - 0x60) = result;
                *(rcx_2 + r9_7 - 0x40) = result;
                *(rcx_2 + i_1 - 0x20) = result;
                break;
            }
        }
        
        *rax_2 = result;
        _mm256_zeroupper();
        return result;
    }
    
    void* rcx = arg1 + arg3;
    
    switch (arg3)
    {
        case nullptr:
        {
            return result;
            break;
        }
        case 1:
        {
            *(rcx - 1) = r11;
            return result;
            break;
        }
        case 2:
        {
            *(rcx - 2) = r11;
            return result;
            break;
        }
        case 3:
        {
            goto label_18002de99;
        }
        case 4:
        {
            *(rcx - 4) = r11;
            return result;
            break;
        }
        case 5:
        {
            goto label_18002dec4;
        }
        case 6:
        {
            goto label_18002dea7;
        }
        case 7:
        {
            goto label_18002de95;
        }
        case 8:
        {
            *(rcx - 8) = r11;
            return result;
            break;
        }
        case 9:
        {
            *(rcx - 9) = r11;
            *(rcx - 1) = r11;
            return result;
            break;
        }
        case 0xa:
        {
            *(rcx - 0xa) = r11;
            *(rcx - 2) = r11;
            return result;
            break;
        }
        case 0xb:
        {
            *(rcx - 0xb) = r11;
            *(rcx - 3) = r11;
            *(rcx - 1) = r11;
            return result;
            break;
        }
        case 0xc:
        {
            *(rcx - 0xc) = r11;
            *(rcx - 4) = r11;
            return result;
            break;
        }
        case 0xd:
        {
            *(rcx - 0xd) = r11;
        label_18002dec4:
            *(rcx - 5) = r11;
            *(rcx - 1) = r11;
            return result;
            break;
        }
        case 0xe:
        {
            *(rcx - 0xe) = r11;
        label_18002dea7:
            *(rcx - 6) = r11;
            *(rcx - 2) = r11;
            return result;
            break;
        }
        case 0xf:
        {
            *(rcx - 0xf) = r11;
        label_18002de95:
            *(rcx - 7) = r11;
        label_18002de99:
            *(rcx - 3) = r11;
            *(rcx - 1) = r11;
            return result;
            break;
        }
    }
}

