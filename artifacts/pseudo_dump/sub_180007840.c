
  void* sub_180007840(int64_t* arg1, uint64_t arg2)

{
    void* rax;
    
    if (!arg2)
        rax = nullptr;
    else if (arg2 < 0x1000)
        rax = sub_180016420(arg2);
    else
    {
        if (arg2 + 0x27 <= arg2)
        {
            stdext::threads::_Throw_lock_error();
            /* no return */
        }
        
        int64_t rax_1 = sub_180016420(arg2 + 0x27);
        
        if (!rax_1)
            trap(0xd);
        
        rax = (rax_1 + 0x27) & 0xffffffffffffffe0;
        *(rax - 8) = rax_1;
    }
    
    *arg1 = rax;
    arg1[1] = rax;
    void* result = rax + arg2;
    arg1[2] = result;
    return result;
}

