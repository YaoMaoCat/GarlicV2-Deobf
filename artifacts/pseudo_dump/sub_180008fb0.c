
  int64_t sub_180008fb0(int64_t* arg1, int128_t* arg2, int128_t* arg3, int32_t* arg4, uint16_t arg5)

{
    int128_t var_48 = *arg2;
    int16_t rax = sub_1800083b0(arg1, &var_48);
    var_48 = *arg3;
    int16_t rax_1 = sub_1800083b0(arg1, &var_48);
    
    if (rax && rax_1)
    {
        for (void* i = arg1[0x12]; i != arg1[0x13]; i += 0x20)
        {
            if (*(i + 2) == rax && *(i + 4) == rax_1)
            {
                *(&var_48 + 8) = 4;
                var_48 = "Code";
                int16_t rax_2 = sub_1800083b0(arg1, &var_48);
                int16_t r9 = rax_2;
                
                if (!rax_2)
                {
                    var_48 = "Code";
                    *(&var_48 + 8) = 4;
                    r9 = sub_180008120(arg1, &var_48);
                }
                
                sub_180004e90(i + 8, sub_180009110(arg1, &var_48, i + 8, r9, arg4, arg5));
                void* rax_6 = var_48;
                
                if (rax_6)
                {
                    int64_t var_38;
                    
                    if (var_38 - rax_6 >= 0x1000)
                    {
                        int64_t rcx_6 = *(rax_6 - 8);
                        
                        if (rax_6 - rcx_6 - 8 > 0x1f)
                            trap(0xd);
                        
                        j_sub_180021340(rcx_6);
                        int64_t rax_9;
                        rax_9 = 1;
                        return rax_9;
                    }
                    
                    j_sub_180021340(rax_6);
                }
                
                rax_6 = 1;
                return rax_6;
            }
        }
    }
    
    rax_1 = 0;
    return rax_1;
}

