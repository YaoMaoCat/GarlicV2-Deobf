
🌐  void* _recalloc_base(int64_t arg1, int64_t arg2, int64_t arg3)

{
    if (arg2 && -0x20 / arg2 < arg3)
    {
        *sub_18002131c() = 0xc;
        return nullptr;
    }
    
    int64_t rdi_1;
    
    if (!arg1)
        rdi_1 = 0;
    else
        rdi_1 = sub_18002a6a0(arg1);
    
    uint64_t rbx_1 = arg2 * arg3;
    void* result = _realloc_base(arg1, rbx_1);
    
    if (result && rdi_1 < rbx_1)
        sub_18002de50(result + rdi_1, 0, rbx_1 - rdi_1);
    
    return result;
}

