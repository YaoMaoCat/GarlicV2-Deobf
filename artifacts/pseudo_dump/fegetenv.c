
🌐  int64_t fegetenv(int32_t* arg1)

{
    int32_t mxcsr;
    *arg1 = sub_18002c020(mxcsr);
    arg1[1] = __acrt_fenv_get_status(mxcsr);
    return 0;
}

