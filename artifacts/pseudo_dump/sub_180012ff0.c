
  int64_t sub_180012ff0(int64_t arg1, int64_t arg2, char arg3)

{
    int64_t* rcx = data_180047468;
    int32_t arg_20 = 0;
    int64_t var_50 = 0;
    
    if ((*(*rcx + 0x198))(rcx, arg1, &arg_20, &var_50))
        return 0;
    
    int32_t rsi = 0;
    int64_t i = 0;
    
    if (arg_20 > 0)
    {
        while (!i)
        {
            int64_t* rcx_1 = data_180047468;
            int64_t rdx_1 = var_50;
            char* var_48;
            __builtin_memset(&var_48, 0, 0x18);
            int64_t r14_1 = rsi;
            int64_t var_40;
            int64_t var_38;
            
            if ((*(*rcx_1 + 0x1f8))(rcx_1, *(rdx_1 + (r14_1 << 3)), &var_40, &var_48, &var_38))
                i = 0;
            else
            {
                int64_t* rcx_2 = data_180047468;
                int64_t rdx_3 = var_50;
                int32_t var_58 = 0;
                (*(*rcx_2 + 0x208))(rcx_2, *(rdx_3 + (r14_1 << 3)), &var_58);
                char* rbx_1 = var_48;
                
                if (rbx_1 && !strcmp(rbx_1, arg2) && (var_58 >> 3 & 1) == arg3)
                {
                    i = *(var_50 + (r14_1 << 3));
                    sub_1800023a0("  findMethodByDesc(%s, static=%d): '%s'", arg2);
                    rbx_1 = var_48;
                }
                
                int64_t rdx_7 = var_40;
                
                if (rdx_7)
                {
                    int64_t* rcx_4 = data_180047468;
                    (*(*rcx_4 + 0x170))(rcx_4, rdx_7);
                    rbx_1 = var_48;
                }
                
                if (rbx_1)
                {
                    int64_t* rcx_5 = data_180047468;
                    (*(*rcx_5 + 0x170))(rcx_5, rbx_1);
                }
                
                int64_t rdx_9 = var_38;
                
                if (rdx_9)
                {
                    int64_t* rcx_6 = data_180047468;
                    (*(*rcx_6 + 0x170))(rcx_6, rdx_9);
                }
            }
            
            rsi += 1;
            
            if (rsi >= arg_20)
                break;
        }
    }
    
    int64_t* rcx_7 = data_180047468;
    int64_t r8_4 = *rcx_7;
    (*(r8_4 + 0x170))(rcx_7, var_50, r8_4);
    return i;
}

