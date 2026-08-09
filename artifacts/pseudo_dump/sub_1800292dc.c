
  int64_t sub_1800292dc(int32_t arg1)

{
    int64_t rdx_2 = arg1;
    /* tailcall */
    return LeaveCriticalSection((&data_180047840)[rdx_2 >> 6] + (rdx_2 & 0x3f) * 0x48);
}

