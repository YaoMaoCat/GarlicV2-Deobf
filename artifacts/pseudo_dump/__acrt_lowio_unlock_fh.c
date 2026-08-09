
  int64_t __acrt_lowio_unlock_fh(int32_t arg1)

{
    int64_t rdx_2 = arg1;
    /* tailcall */
    return EnterCriticalSection((&data_180047840)[rdx_2 >> 6] + (rdx_2 & 0x3f) * 0x48);
}

