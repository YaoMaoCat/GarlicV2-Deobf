
🌐  int64_t* __acrt_uninitialize_winapi_thunks(char arg1)

{
    if (!arg1)
    {
        for (int64_t* i = &data_180047f00; i != &data_180047fb8; i = &i[1])
        {
            HMODULE hLibModule = *i;
            
            if (hLibModule)
            {
                if (hLibModule != -1)
                    FreeLibrary(hLibModule);
                
                *i = 0;
            }
        }
    }
    
    int64_t* result;
    result = 1;
    return result;
}

