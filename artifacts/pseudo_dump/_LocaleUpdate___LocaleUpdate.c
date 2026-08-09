
🌐  void** _LocaleUpdate::_LocaleUpdate(void** arg1, int128_t* arg2)

{
    arg1[3] = 0;
    
    if (arg2)
        *(arg1 + 8) = *arg2;
    else if (data_180047834)
    {
        void** rax_1 = __vcrt_getptd();
        *arg1 = rax_1;
        arg1[1] = rax_1[0x12];
        arg1[2] = rax_1[0x11];
        __acrt_update_locale_info(rax_1, &arg1[1]);
        sub_180021804(*arg1, &arg1[2]);
        void* rcx_4 = *arg1;
        int32_t rax_2 = *(rcx_4 + 0x3a8);
        
        if (!(rax_2 & 2))
        {
            *(rcx_4 + 0x3a8) = rax_2 | 2;
            arg1[3] = 1;
        }
    }
    else
        *(arg1 + 8) = *data_180046b28;
    
    return arg1;
}

