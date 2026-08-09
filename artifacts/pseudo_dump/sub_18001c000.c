
  uint64_t sub_18001c000(int32_t* arg1, int64_t* arg2, void* arg3, int64_t* arg4, int512_t arg5 @ zmm1, char* arg6, int32_t arg7, int64_t arg8, char arg9)

{
    int32_t rax_4 = sub_18001bd90(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    *(sub_180019c40() + 0x78) = 0xfffffffe;
    return rax_4;
}

