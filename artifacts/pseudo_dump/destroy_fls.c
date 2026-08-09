
🌐  void destroy_fls(int64_t* arg1)

{
    if (arg1)
    {
        destroy_ptd_array(arg1);
        _free_base(arg1);
    }
}

