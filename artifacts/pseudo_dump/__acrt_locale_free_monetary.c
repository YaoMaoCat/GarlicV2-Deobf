
🌐  void __acrt_locale_free_monetary(void* arg1)

{
    if (!arg1)
        return;
    
    int64_t rcx = *(arg1 + 0x18);
    
    if (rcx != data_1800470a8)
        _free_base(rcx);
    
    int64_t rcx_1 = *(arg1 + 0x20);
    
    if (rcx_1 != data_1800470b0)
        _free_base(rcx_1);
    
    int64_t rcx_2 = *(arg1 + 0x28);
    
    if (rcx_2 != data_1800470b8)
        _free_base(rcx_2);
    
    int64_t rcx_3 = *(arg1 + 0x30);
    
    if (rcx_3 != data_1800470c0)
        _free_base(rcx_3);
    
    int64_t rcx_4 = *(arg1 + 0x38);
    
    if (rcx_4 != data_1800470c8)
        _free_base(rcx_4);
    
    int64_t rcx_5 = *(arg1 + 0x40);
    
    if (rcx_5 != data_1800470d0)
        _free_base(rcx_5);
    
    int64_t rcx_6 = *(arg1 + 0x48);
    
    if (rcx_6 != data_1800470d8)
        _free_base(rcx_6);
    
    int64_t rcx_7 = *(arg1 + 0x68);
    
    if (rcx_7 != data_1800470f8)
        _free_base(rcx_7);
    
    int64_t rcx_8 = *(arg1 + 0x70);
    
    if (rcx_8 != data_180047100)
        _free_base(rcx_8);
    
    int64_t rcx_9 = *(arg1 + 0x78);
    
    if (rcx_9 != data_180047108)
        _free_base(rcx_9);
    
    int64_t rcx_10 = *(arg1 + 0x80);
    
    if (rcx_10 != data_180047110)
        _free_base(rcx_10);
    
    int64_t rcx_11 = *(arg1 + 0x88);
    
    if (rcx_11 != data_180047118)
        _free_base(rcx_11);
    
    int64_t rcx_12 = *(arg1 + 0x90);
    
    if (rcx_12 != data_180047120)
        _free_base(rcx_12);
}

