
🌐  int64_t uninitialize_environment()

{
    __dcrt_uninitialize_environments_nolock();
    int64_t result;
    result = 1;
    return result;
}

