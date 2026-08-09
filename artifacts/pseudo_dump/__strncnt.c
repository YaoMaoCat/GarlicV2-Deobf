
🌐  char* __strncnt(char* arg1, int64_t arg2)

{
    char* result = nullptr;
    
    if (*arg1)
    {
        while (result != arg2)
        {
            result = &result[1];
            
            if (!*(result + arg1))
                break;
        }
    }
    
    return result;
}

