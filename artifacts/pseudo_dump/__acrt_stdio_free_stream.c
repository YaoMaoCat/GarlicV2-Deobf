
🌐  uint64_t __acrt_stdio_free_stream(void* arg1)

{
    *(arg1 + 0x18) = 0xffffffff;
    __builtin_memset(arg1, 0, 0x18);
    *(arg1 + 0x1c) = 0;
    *(arg1 + 0x28) = 0;
    return *(arg1 + 0x14);
}

