
🌐  int64_t uninitialize_allocated_io_buffers()

{
    _free_base(data_180047820);
    int64_t rcx_1 = data_180047828;
    data_180047820 = 0;
    _free_base(rcx_1);
    int64_t rcx_2 = data_180047ee0;
    data_180047828 = 0;
    _free_base(rcx_2);
    int64_t rcx_3 = data_180047ee8;
    data_180047ee0 = 0;
    _free_base(rcx_3);
    data_180047ee8 = 0;
    int64_t result;
    result = 1;
    return result;
}

