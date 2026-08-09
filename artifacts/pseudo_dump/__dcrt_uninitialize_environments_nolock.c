
🌐  int64_t __dcrt_uninitialize_environments_nolock()

{
    int64_t var_18 = -2;
    uninitialize_environment_internal<wchar_t>(&data_180047798);
    uninitialize_environment_internal<char>(&data_1800477a0);
    free_environment<wchar_t>(data_1800477b0);
    /* tailcall */
    return free_environment<wchar_t>(data_1800477a8);
}

