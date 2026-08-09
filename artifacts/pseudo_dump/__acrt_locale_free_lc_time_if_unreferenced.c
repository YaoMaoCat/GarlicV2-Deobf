
🌐  void __acrt_locale_free_lc_time_if_unreferenced(int64_t* arg1)

{
    if (arg1 && arg1 != &data_180039e20 && !*(arg1 + 0x15c))
    {
        __acrt_locale_free_time(arg1);
        _free_base(arg1);
    }
}

