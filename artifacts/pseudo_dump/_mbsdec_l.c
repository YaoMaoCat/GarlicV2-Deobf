
🌐  char* _mbsdec_l(int64_t arg1, void* arg2, int128_t* arg3)

{
    if (!arg1 || !arg2)
    {
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
    }
    else if (arg1 < arg2)
    {
        void* var_28;
        _LocaleUpdate::_LocaleUpdate(&var_28, arg3);
        char* result = arg2 - 1;
        void* var_18;
        
        if (*(var_18 + 8))
        {
            do
            {
                result -= 1;
                
                if (arg1 > result)
                    break;
            } while (*(*result + var_18 + 0x19) & 4);
            
            result = arg2 - ((arg2 - result) & 1) - 1;
        }
        
        char var_10;
        
        if (var_10)
        {
            void* rcx_5 = var_28;
            *(rcx_5 + 0x3a8) &= 0xfffffffd;
        }
        
        return result;
    }
    
    return nullptr;
}

