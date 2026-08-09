
🌐  void __chkstk(int64_t arg1 @ rax)

{
    void arg_8;
    void* r10 = &arg_8 - arg1;
    
    if (&arg_8 < arg1)
        r10 = nullptr;
    
    TEB* gsbase;
    void* StackLimit = gsbase->NtTib.StackLimit;
    
    if (r10 >= StackLimit)
        return;
    
    r10 &= 0xf000;
    
    do
    {
        StackLimit -= 0x1000;
        *StackLimit = 0;
    } while (r10 != StackLimit);
}

