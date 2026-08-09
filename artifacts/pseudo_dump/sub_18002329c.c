
  void sub_18002329c()

{
    int64_t var_18 = -2;
    uint32_t dwFlsIndex = data_1800469c8;
    int64_t* rbx;
    
    if (dwFlsIndex != 0xffffffff)
    {
        rbx = FlsGetValue(dwFlsIndex);
        dwFlsIndex = data_1800469c8;
    }
    else
        rbx = nullptr;
    
    if (!rbx)
        return;
    
    FlsSetValue(dwFlsIndex, nullptr);
    destroy_ptd_array(rbx);
    _free_base(rbx);
}

