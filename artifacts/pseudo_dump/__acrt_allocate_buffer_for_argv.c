
🌐  int64_t __acrt_allocate_buffer_for_argv(int64_t arg1, int64_t arg2, int64_t arg3)

{
    if (arg1 < 0x1fffffffffffffff && arg2 < -1 / arg3)
    {
        int64_t rcx = arg1 << 3;
        int64_t r9_1 = arg2 * arg3;
        
        if (~rcx > r9_1)
        {
            int64_t result = _calloc_base(rcx + r9_1, 1);
            _free_base(0);
            return result;
        }
    }
    
    return 0;
}

