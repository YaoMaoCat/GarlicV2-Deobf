
  int64_t sub_18000d7f0(int64_t* arg1, int64_t arg2)

{
    void var_1a8;
    int64_t var_38 = __security_cookie ^ &var_1a8;
    int64_t* rbx = data_180047468;
    int64_t result;
    
    if (!rbx || !arg1)
        result = 0;
    else if (data_180046030)
    {
        int64_t rax_1 = *rbx;
        int32_t var_44_1 = 0x60;
        int64_t var_40_1 = 0;
        int32_t var_48 = 0x4200200;
        int32_t rax_2;
        int64_t rdx_1;
        rax_2 = (*(rax_1 + 0x468))(rbx, &var_48);
        
        if (!rax_2)
        {
            int128_t var_178[0x2];
            sub_18002de50(&var_178, 0, 0x128);
            int64_t (* var_158_1)(int64_t* arg1, char* arg2, int32_t arg3, char* arg4, 
                int32_t* arg5, int128_t** arg6) = sub_18000d360;
            int32_t rax_4;
            int64_t rdx_3;
            rax_4 = (*(*rbx + 0x3c8))(rbx, &var_178, 0x128);
            
            if (!rax_4)
            {
                int32_t rax_5;
                int64_t rdx_4;
                rax_5 = sub_18000dab0(rbx, 1, 0x36, 0);
                
                if (!rax_5)
                {
                    int64_t* rdi_1 = data_180047468;
                    int32_t var_188 = 0;
                    int64_t var_180 = 0;
                    
                    if (!(*(*rdi_1 + 0x268))(rdi_1, &var_188, &var_180))
                    {
                        uint64_t rdx_6 = var_188;
                        int32_t i = 0;
                        int32_t r13_1 = 0;
                        int32_t r15_1 = 0;
                        
                        if (rdx_6 > 0)
                        {
                            do
                            {
                                var_48 = 0;
                                int64_t i_1 = i;
                                
                                if (!
                                    (*(*rdi_1 + 0x178))(rdi_1, *(var_180 + (i_1 << 3)), &var_48, 0))
                                {
                                    char* rbx_1 = var_48;
                                    
                                    if (rbx_1)
                                    {
                                        if (!strcmp(rbx_1, "Lnet/minecraft/network/Connection;"))
                                        {
                                            r13_1 += 1;
                                            int32_t rax_12 =
                                                (*(*rdi_1 + 0x4b8))(rdi_1, 1, var_180 + (i_1 << 3));
                                            
                                            if (rax_12)
                                                sub_1800023a0(
                                                    "Connection hook: RetransformClasses failed err=%d", 
                                                    rax_12);
                                            else
                                                r15_1 += 1;
                                            
                                            rbx_1 = var_48;
                                        }
                                        
                                        if (rbx_1)
                                            (*(*rdi_1 + 0x170))(rdi_1, rbx_1);
                                    }
                                }
                                
                                rdx_6 = var_188;
                                i += 1;
                            } while (i < rdx_6);
                        }
                        
                        sub_1800023a0(
                            "RetransformIfLoaded: enumerated %d classes, found %d Connection, "
                        "retransformed %d", 
                            rdx_6);
                        int32_t rbx_2 = 0;
                        
                        if (var_188 > 0)
                        {
                            do
                            {
                                int64_t r8_5 = *arg1;
                                (*(r8_5 + 0xb8))(arg1, *(var_180 + (rbx_2 << 3)), r8_5);
                                rbx_2 += 1;
                            } while (rbx_2 < var_188);
                        }
                        
                        (*(*rdi_1 + 0x170))(rdi_1, var_180);
                    }
                    
                    result = 1;
                }
                else
                {
                    sub_180001d30("Connection hook: SetEventNotificationMode failed", rdx_4);
                    result = 0;
                }
            }
            else
            {
                sub_180001d30("Connection hook: SetEventCallbacks failed", rdx_3);
                result = 0;
            }
        }
        else
        {
            sub_180001d30("Connection hook: AddCapabilities failed", rdx_1);
            result = 0;
        }
    }
    else
    {
        sub_180001d30("Connection hook: called before HookBridge installed", arg2);
        result = 0;
    }
    
    __security_check_cookie(var_38 ^ &var_1a8);
    return result;
}

