
🌐  int64_t __acrt_errno_map_os_error_ptd(int32_t arg1, void* arg2)

{
    *(arg2 + 0x38) = 1;
    *(arg2 + 0x34) = arg1;
    int32_t result = sub_1800211dc(arg1);
    *(arg2 + 0x2c) = result;
    *(arg2 + 0x30) = 1;
    return result;
}

