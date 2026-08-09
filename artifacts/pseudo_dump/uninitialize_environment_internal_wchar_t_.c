
  void uninitialize_environment_internal<wchar_t>(int64_t* arg1)

{
    int64_t* rcx = *arg1;
    
    if (rcx != data_1800477b0)
        free_environment<wchar_t>(rcx);
}

