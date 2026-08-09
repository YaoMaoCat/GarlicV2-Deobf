
  void sub_180019be0()

{
    uint32_t dwFlsIndex = data_180046890;
    
    if (dwFlsIndex == 0xffffffff)
        return;
    
    int64_t rax_1 = FlsGetValue(dwFlsIndex);
    FlsSetValue(data_180046890, nullptr);
    
    if (rax_1 && rax_1 != &data_1800475b0)
        /* tailcall */
        return j_sub_180021340(rax_1);
}

