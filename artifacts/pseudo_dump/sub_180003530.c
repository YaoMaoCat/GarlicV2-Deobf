
  int64_t sub_180003530(int64_t* arg1, int64_t arg2)

{
    int32_t* rbx = *arg1;
    int64_t i = 0x138;
    int32_t rax = *rbx;
    
    if (rax == 0x138)
    {
        do
        {
            int64_t r8_1 = *(rbx + (i << 3) - 0x9b0);
            int64_t rdx_3 = ((r8_1 ^ *(rbx + (i << 3) - 0x9b8)) & 0xffffffff80000000) ^ r8_1;
            int64_t rcx_3 =
                ((arg1 - arg1) & 0xb5026f5aa96619e9) ^ *(rbx + (i << 3) - 0x4d8) ^ rdx_3 >> 1;
            int64_t rdx_5 = *(rbx + (i << 3) - 0x9a8);
            *(rbx + (i << 3) + 8) = rcx_3;
            int64_t r8_4 = ((r8_1 ^ rdx_5) & 0xffffffff80000000) ^ rdx_5;
            int64_t rcx_7 =
                ((rcx_3 - rcx_3) & 0xb5026f5aa96619e9) ^ *(rbx + (i << 3) - 0x4d0) ^ r8_4 >> 1;
            int64_t r8_6 = *(rbx + (i << 3) - 0x9a0);
            *(rbx + (i << 3) + 0x10) = rcx_7;
            int64_t rdx_8 = ((rdx_5 ^ r8_6) & 0xffffffff80000000) ^ r8_6;
            int64_t rcx_11 =
                ((rcx_7 - rcx_7) & 0xb5026f5aa96619e9) ^ *(rbx + (i << 3) - 0x4c8) ^ rdx_8 >> 1;
            int64_t rdx_10 = *(rbx + (i << 3) - 0x998);
            *(rbx + (i << 3) + 0x18) = rcx_11;
            int64_t r8_9 = ((r8_6 ^ rdx_10) & 0xffffffff80000000) ^ rdx_10;
            int64_t rcx_15 =
                ((rcx_11 - rcx_11) & 0xb5026f5aa96619e9) ^ *(rbx + (i << 3) - 0x4c0) ^ r8_9 >> 1;
            int64_t r8_11 = *(rbx + (i << 3) - 0x990);
            *(rbx + (i << 3) + 0x20) = rcx_15;
            int64_t rdx_13 = ((rdx_10 ^ r8_11) & 0xffffffff80000000) ^ r8_11;
            int64_t rax_6 = *(rbx + (i << 3) - 0x988);
            int64_t rcx_19 =
                ((rcx_15 - rcx_15) & 0xb5026f5aa96619e9) ^ *(rbx + (i << 3) - 0x4b8) ^ rdx_13 >> 1;
            int64_t r8_14 = ((r8_11 ^ rax_6) & 0xffffffff80000000) ^ rax_6;
            *(rbx + (i << 3) + 0x28) = rcx_19;
            arg1 =
                ((rcx_19 - rcx_19) & 0xb5026f5aa96619e9) ^ *(rbx + (i << 3) - 0x4b0) ^ r8_14 >> 1;
            *(rbx + (i << 3) + 0x30) = arg1;
            i += 6;
        } while (i < 0x270);
    }
    else if (rax >= 0x270)
        sub_180003720(rbx, arg2);
    
    uint64_t rax_8 = *rbx;
    int64_t rcx_24 = *(rbx + (rax_8 << 3) + 8);
    *rbx = rax_8 + 1;
    int64_t rdx_18 = (rcx_24 >> 0x1d & 0x555555555) ^ rcx_24;
    int64_t rax_13 = (rdx_18 & 0x38eb3ffff6d3) << 0x11 ^ rdx_18;
    int64_t rcx_28 = (rax_13 & 0xffffffffffffbf77) << 0x25 ^ rax_13;
    return rcx_28 >> 0x2b ^ rcx_28;
}

