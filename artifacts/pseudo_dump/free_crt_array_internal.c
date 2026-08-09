
🌐  void free_crt_array_internal(int64_t* arg1, int64_t arg2)

{
    void* rdi = &arg1[arg2];
    int64_t* rbx = arg1;
    
    if (arg1 == rdi)
        return;
    
    do
    {
        _free_base(*rbx);
        rbx = &rbx[1];
    } while (rbx != rdi);
}

