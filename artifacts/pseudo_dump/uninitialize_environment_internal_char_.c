
  void uninitialize_environment_internal<char>(int64_t* arg1)

{
    int64_t* rcx = *arg1;
    
    if (rcx != data_1800477a8)
        free_environment<wchar_t>(rcx);
}

