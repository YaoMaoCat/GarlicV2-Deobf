
🌐  uint64_t __acrt_fenv_get_status(int32_t arg1 @ mxcsr) __pure

{
    int32_t rdx_1 = arg1 & 0x3f;
    int32_t r8_8 = (((rdx_1 >> 2 & 8) | (rdx_1 & 0x10)) >> 2 | (rdx_1 & 8)) >> 1
        | (((rdx_1 & 2) << 3 | (rdx_1 & 4)) * 2) | (rdx_1 & 1) << 4;
    return r8_8 << 0x18 | r8_8;
}

