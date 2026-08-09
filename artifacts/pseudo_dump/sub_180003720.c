
  char sub_180003720(int32_t* arg1, int64_t arg2)

{
    int64_t i = 0;
    int64_t i_1 = 0x9c;
    
    do
    {
        int64_t r9_1 = *(arg1 + (i << 3) + 0x9d0);
        int64_t r8_4 = ((r9_1 ^ *(arg1 + (i << 3) + 0x9c8)) & 0xffffffff80000000) ^ r9_1;
        int64_t rdx_3 =
            ((arg2 - arg2) & 0xb5026f5aa96619e9) ^ *(arg1 + (i << 3) + 0xea8) ^ r8_4 >> 1;
        int64_t r8_6 = *(arg1 + (i << 3) + 0x9d8);
        *(arg1 + (i << 3) + 8) = rdx_3;
        int64_t r9_4 = ((r9_1 ^ r8_6) & 0xffffffff80000000) ^ r8_6;
        int64_t rdx_7 =
            ((rdx_3 - rdx_3) & 0xb5026f5aa96619e9) ^ *(arg1 + (i << 3) + 0xeb0) ^ r9_4 >> 1;
        int64_t r9_6 = *(arg1 + (i << 3) + 0x9e0);
        *(arg1 + (i << 3) + 0x10) = rdx_7;
        int64_t r8_9 = ((r8_6 ^ r9_6) & 0xffffffff80000000) ^ r9_6;
        int64_t rdx_11 =
            ((rdx_7 - rdx_7) & 0xb5026f5aa96619e9) ^ *(arg1 + (i << 3) + 0xeb8) ^ r8_9 >> 1;
        int64_t r8_11 = *(arg1 + (i << 3) + 0x9e8);
        *(arg1 + (i << 3) + 0x18) = rdx_11;
        int64_t r9_9 = ((r9_6 ^ r8_11) & 0xffffffff80000000) ^ r8_11;
        int64_t rdx_15 =
            ((rdx_11 - rdx_11) & 0xb5026f5aa96619e9) ^ *(arg1 + (i << 3) + 0xec0) ^ r9_9 >> 1;
        int64_t r9_11 = *(arg1 + (i << 3) + 0x9f0);
        *(arg1 + (i << 3) + 0x20) = rdx_15;
        int64_t r8_14 = ((r8_11 ^ r9_11) & 0xffffffff80000000) ^ r9_11;
        int64_t rax_6 = *(arg1 + (i << 3) + 0x9f8);
        int64_t rdx_19 =
            ((rdx_15 - rdx_15) & 0xb5026f5aa96619e9) ^ *(arg1 + (i << 3) + 0xec8) ^ r8_14 >> 1;
        int64_t r9_14 = ((r9_11 ^ rax_6) & 0xffffffff80000000) ^ rax_6;
        *(arg1 + (i << 3) + 0x28) = rdx_19;
        arg2 = ((rdx_19 - rdx_19) & 0xb5026f5aa96619e9) ^ *(arg1 + (i << 3) + 0xed0) ^ r9_14 >> 1;
        *(arg1 + (i << 3) + 0x30) = arg2;
        i += 6;
    } while (i < 0x9c);
    
    do
    {
        int64_t r9_16 = *(arg1 + (i_1 << 3) + 0x9d0);
        int64_t r8_19 = ((r9_16 ^ *(arg1 + (i_1 << 3) + 0x9c8)) & 0xffffffff80000000) ^ r9_16;
        int64_t rdx_26 =
            ((arg2 - arg2) & 0xb5026f5aa96619e9) ^ *(arg1 + (i_1 << 3) - 0x4d8) ^ r8_19 >> 1;
        int64_t r8_21 = *(arg1 + (i_1 << 3) + 0x9d8);
        *(arg1 + (i_1 << 3) + 8) = rdx_26;
        int64_t r9_19 = ((r9_16 ^ r8_21) & 0xffffffff80000000) ^ r8_21;
        int64_t rdx_30 =
            ((rdx_26 - rdx_26) & 0xb5026f5aa96619e9) ^ *(arg1 + (i_1 << 3) - 0x4d0) ^ r9_19 >> 1;
        int64_t r9_21 = *(arg1 + (i_1 << 3) + 0x9e0);
        *(arg1 + (i_1 << 3) + 0x10) = rdx_30;
        int64_t r8_24 = ((r8_21 ^ r9_21) & 0xffffffff80000000) ^ r9_21;
        int64_t rdx_34 =
            ((rdx_30 - rdx_30) & 0xb5026f5aa96619e9) ^ *(arg1 + (i_1 << 3) - 0x4c8) ^ r8_24 >> 1;
        int64_t r8_26 = *(arg1 + (i_1 << 3) + 0x9e8);
        *(arg1 + (i_1 << 3) + 0x18) = rdx_34;
        int64_t r9_24 = ((r9_21 ^ r8_26) & 0xffffffff80000000) ^ r8_26;
        int64_t rax_12 = *(arg1 + (i_1 << 3) + 0x9f0);
        int64_t rdx_38 =
            ((rdx_34 - rdx_34) & 0xb5026f5aa96619e9) ^ *(arg1 + (i_1 << 3) - 0x4c0) ^ r9_24 >> 1;
        int64_t r8_29 = ((r8_26 ^ rax_12) & 0xffffffff80000000) ^ rax_12;
        *(arg1 + (i_1 << 3) + 0x20) = rdx_38;
        arg2 = ((rdx_38 - rdx_38) & 0xb5026f5aa96619e9) ^ *(arg1 + (i_1 << 3) - 0x4b8) ^ r8_29 >> 1;
        *(arg1 + (i_1 << 3) + 0x28) = arg2;
        i_1 += 5;
    } while (i_1 < 0x137);
    
    int64_t rax_14 = *(arg1 + 8);
    *arg1 = 0;
    int64_t r8_34 = ((rax_14 ^ *(arg1 + 0x1380)) & 0xffffffff80000000) ^ rax_14;
    char rax_15 = r8_34 & 1;
    *(arg1 + 0x9c0) = ((arg2 - arg2) & 0xb5026f5aa96619e9) ^ *(arg1 + 0x4e0) ^ r8_34 >> 1;
    return -(rax_15);
}

