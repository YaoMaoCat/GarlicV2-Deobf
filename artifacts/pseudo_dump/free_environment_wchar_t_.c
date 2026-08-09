
  void free_environment<wchar_t>(int64_t* arg1)

{
    if (!arg1)
        return;
    
    int64_t i = *arg1;
    int64_t* rdi_1 = arg1;
    
    for (; i; i = *rdi_1)
    {
        _free_base(i);
        rdi_1 = &rdi_1[1];
    }
    
    _free_base(arg1);
}

