
  int64_t sub_18002c290(int32_t arg1, int32_t arg2 @ mxcsr) __pure

{
    int32_t rdx_1 = arg1 >> 0x18 & 0x3f;
    int32_t rax_3 = rdx_1 & 2;
    int32_t rax_4 = -(rax_3);
    int32_t rax_8 = rdx_1 & 4;
    int32_t rax_9 = -(rax_8);
    int32_t rax_13 = rdx_1 & 8;
    int32_t rax_14 = -(rax_13);
    int32_t rcx_4 = ((arg1 - arg1) & 0x20) | ((rax_4 - rax_4) & 0x10) | ((rax_9 - rax_9) & 8)
        | ((rax_14 - rax_14) & 4);
    int32_t rax_17;
    rax_17 = TEST_BITD(rdx_1, 4);
    int32_t result = (arg2 & 0xffffffc0) | ((rcx_4 | rax_17 | ((rax_17 - rax_17) & 2)) & 0x3f);
    int32_t result_1 = result;
    return result;
}

