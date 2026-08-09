
🌐  uint64_t _tolower_l(uint32_t arg1, int128_t* arg2)

{
    uint32_t r8 = -1;
    
    if (arg1 != 0xffffffff)
    {
        void* var_28;
        _LocaleUpdate::_LocaleUpdate(&var_28, arg2);
        int64_t* var_20;
        char var_10;
        
        if (arg1 >= 0x100)
        {
            int64_t* rdx_1 = var_20;
            char arg_a = 0;
            uint64_t rcx_2;
            
            if (rdx_1[1] > 1)
                rcx_2 = arg1 >> 8;
            
            char arg_8;
            int32_t rcx_3;
            char arg_9;
            
            if (rdx_1[1] <= 1 || *(*rdx_1 + (rcx_2 << 1)) >= 0)
            {
                rcx_3 = 1;
                *sub_18002131c() = 0x2a;
                rdx_1 = var_20;
                arg_8 = arg1;
                arg_9 = 0;
            }
            else
            {
                arg_8 = rcx_2;
                rcx_3 = 2;
                arg_9 = arg1;
            }
            int16_t arg_18 = 0;
            char arg_1a = 0;
            int32_t rax_8 = __acrt_LCMapStringA(&var_20, rdx_1[0x27], 0x100, &arg_8, rcx_3, 
                &arg_18, 3, *(rdx_1 + 0xc), 1);
            
            if (rax_8)
            {
                r8 = arg_18;
                
                if (rax_8 != 1)
                    r8 = r8 << 8 | *(&arg_18 + 1);
            }
            else
                r8 = arg1;
            
            if (var_10)
            {
                void* rcx_5 = var_28;
                *(rcx_5 + 0x3a8) &= 0xfffffffd;
            }
        }
        else
        {
            r8 = *(var_20[0x22] + arg1);
            
            if (var_10)
            {
                void* rax_2 = var_28;
                *(rax_2 + 0x3a8) &= 0xfffffffd;
            }
        }
    }
    
    return r8;
}

