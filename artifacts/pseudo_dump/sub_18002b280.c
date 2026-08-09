
  uint64_t sub_18002b280(int32_t arg1, int16_t* arg2, int32_t arg3, int64_t* arg4)

{
    int32_t rdi = 0;
    uint64_t r14 = arg3;
    int64_t r13 = arg1;
    
    if (arg3)
    {
        char var_78_1;
        uint64_t rax_2;
        int64_t rcx;
        int64_t r12_2;
        uint64_t r15_1;
        
        if (arg2)
        {
            r12_2 = r13 >> 6;
            r15_1 = (r13 & 0x3f) * 9;
            rcx = (&data_180047840)[r12_2];
            rax_2 = *(rcx + (r15_1 << 3) + 0x39);
            var_78_1 = rax_2;
            rax_2 -= 1;
        }
        
        if (!arg2 || (rax_2 <= 1 && !(~r14 & 1)))
        {
            arg4[7] = 1;
            *(arg4 + 0x34) = 0;
            arg4[6] = 1;
            *(arg4 + 0x2c) = 0x16;
            _invalid_parameter_internal(0, 0, 0, 0, 0, arg4);
            return 0xffffffff;
        }
        
        if (*(rcx + (r15_1 << 3) + 0x38) & 0x20)
            j_common_lseek_nolock<int64_t>(r13, 0, FILE_END, arg4);
        
        int64_t var_60_1 = 0;
        int64_t var_70;
        int64_t* rax_14;
        
        if (!_isatty(r13) || *((&data_180047840)[r12_2] + (r15_1 << 3) + 0x38) >= 0)
        {
        label_18002b472:
            int64_t rdx_2 = (&data_180047840)[r13 >> 6];
            uint64_t rcx_13 = (r13 & 0x3f) * 9;
            
            if (*(rdx_2 + (rcx_13 << 3) + 0x38) >= 0)
            {
                HANDLE hFile = *(rdx_2 + (rcx_13 << 3) + 0x28);
                var_70 = 0;
                int32_t var_68_1 = 0;
                
                if (!WriteFile(hFile, arg2, r14, (&var_70 + 4), nullptr))
                    var_70 = GetLastError();
                
                rdi = var_68_1;
                var_60_1 = var_70;
            }
            else
            {
                int32_t rcx_14 = var_78_1;
                
                if (!rcx_14)
                {
                    rax_14 = sub_18002adc8(&var_70, r13, arg2, r14);
                label_18002b455:
                    rdi = rax_14[1];
                    var_60_1 = *rax_14;
                }
                else
                {
                    if (rcx_14 == 1)
                    {
                        rax_14 = sub_18002afec(&var_70, r13, arg2, r14);
                        goto label_18002b455;
                    }
                    
                    if (rcx_14 == 2)
                    {
                        rax_14 = sub_18002aed0(&var_70, r13, arg2, r14);
                        goto label_18002b455;
                    }
                }
            }
        }
        else
        {
            if (!arg4[5])
                __crt_cached_ptd_host::update_locale_slow(arg4);
            
            if (!*(arg4[3] + 0x138) && !*((&data_180047840)[r12_2] + (r15_1 << 3) + 0x39))
                goto label_18002b472;
            
            enum CONSOLE_MODE mode[0x4];
            mode[0] = 0;
            
            if (!GetConsoleMode(*((&data_180047840)[r12_2] + (r15_1 << 3) + 0x28), &mode))
                goto label_18002b472;
            
            int32_t rcx_6 = var_78_1;
            
            if (!rcx_6)
            {
                rax_14 = sub_18002a934(&var_70, r13, arg2, r14, arg4);
                goto label_18002b455;
            }
            
            if (rcx_6 == 1 || rcx_6 == 2)
            {
                void* r12_3 = arg2 + r14;
                var_70 = 0;
                int16_t* r15_2 = arg2;
                
                if (arg2 < r12_3)
                {
                    int32_t var_6c;
                    int32_t r14_1 = var_6c;
                    
                    while (true)
                    {
                        int16_t rax_10 = *r15_2;
                        var_78_1 = rax_10;
                        int16_t rcx_9 = var_78_1;
                        
                        if (sub_18002c324(rax_10) == rcx_9)
                        {
                            r14_1 += 2;
                            int32_t var_6c_1 = r14_1;
                            
                            if (rcx_9 != 0xa)
                                goto label_18002b422;
                            
                            if (sub_18002c324(0xd) == 0xd)
                            {
                                r14_1 += 1;
                                int32_t var_6c_2 = r14_1;
                                rdi += 1;
                            label_18002b422:
                                r15_2 = &r15_2[1];
                                
                                if (r15_2 >= r12_3)
                                    break;
                                
                                continue;
                            }
                        }
                        
                        var_70 = GetLastError();
                        break;
                    }
                }
                
                var_60_1 = var_70;
            }
        }
        
        if (var_60_1 >> 0x20)
            return *(&var_60_1 + 4) - rdi;
        
        int32_t rax_21 = var_60_1;
        
        if (rax_21)
        {
            if (rax_21 != 5)
                __acrt_errno_map_os_error_ptd(var_60_1, arg4);
            else
            {
                arg4[6] = 1;
                *(arg4 + 0x2c) = 9;
                arg4[7] = 1;
                *(arg4 + 0x34) = rax_21;
            }
            
            return 0xffffffff;
        }
        
        if (!(*((&data_180047840)[r13 >> 6] + (r13 & 0x3f) * 0x48 + 0x38) & 0x40) || *arg2 != 0x1a)
        {
            *(arg4 + 0x34) = 0;
            arg4[6] = 1;
            *(arg4 + 0x2c) = 0x1c;
            arg4[7] = 1;
            return 0xffffffff;
        }
    }
    
    return 0;
}

