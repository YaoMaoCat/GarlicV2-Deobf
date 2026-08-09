
🌐  void _free_base(int64_t arg1)

{
    if (arg1 && !HeapFree(data_180047fb8, HEAP_NONE, arg1))
        *sub_18002131c() = sub_1800211dc(GetLastError());
}

