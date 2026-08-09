
  int64_t LOCATOR::FLocateDbgValidate(int64_t* arg1, int64_t arg2)

{
    void var_a8;
    int64_t rax_1 = __security_cookie ^ &var_a8;
    int64_t r9 = data_1800474c0;
    data_1800474c0 += 1;
    void var_78;
    int512_t zmm2 = sub_180001c70(&var_78, 0x40, "proxy_relay_%llu", r9 + 1);
    int64_t rax_3;
    int64_t r9_2;
    rax_3 = (*(*arg1 + 0x538))(arg1, &var_78);
    data_180046098;
    int64_t rax_4;
    int64_t rdx_2;
    rax_4 = sub_18000bbf0(arg1, data_180046090, zmm2, r9_2);
    char rax_5;
    
    if (rax_4)
    {
        int64_t rdx_3 = *arg1;
        rax_5 = (*(rdx_3 + 0x720))(arg1, rdx_3);
    }
    
    int64_t result;
    
    if (!rax_4 || rax_5)
    {
        sub_1800023a0("Attach: NewObject(RelayHandler) FAILED", rdx_2);
        (*(*arg1 + 0x88))(arg1);
        result = (*(*arg1 + 0xb8))(arg1, rax_3);
    }
    else
    {
        int64_t r8_1 = *arg1;
        int64_t rax_6 = (*(r8_1 + 0x538))(arg1, "packet_handler", r8_1);
        data_180046118;
        int64_t var_80_1 = rax_4;
        int64_t var_88_1 = rax_3;
        int64_t rsi_1 = sub_180001cd0(arg1, arg2, zmm2, rax_6);
        char const* const rdx_10;
        
        if (!(*(*arg1 + 0x720))(arg1))
            rdx_10 = "before-packet_handler";
        else
        {
            int512_t zmm2_1 = sub_1800023a0(
                "Attach: addBefore(packet_handler,...) THREW, falling back to addFirst", 
                (*(*arg1 + 0x88))(arg1));
            data_180046110;
            int64_t var_88_2 = rax_4;
            int64_t rax_10 = sub_180001cd0(arg1, arg2, zmm2_1, rax_3);
            int64_t rdx_7 = *arg1;
            rsi_1 = rax_10;
            
            if (!(*(rdx_7 + 0x720))(arg1, rdx_7))
                rdx_10 = "HEAD-fallback";
            else
            {
                int64_t rdx_8 = *arg1;
                sub_1800023a0("Attach: addFirst ALSO threw ", (*(rdx_8 + 0x88))(arg1, rdx_8));
                rdx_10 = "FAILED";
            }
        }
        
        if (data_1800460d8 > 0xf)
            data_1800460c0;
        
        sub_1800023a0("Attach: %s as %s (class %s)", rdx_10);
        
        if (rsi_1)
            (*(*arg1 + 0xb8))(arg1, rsi_1);
        
        (*(*arg1 + 0xb8))(arg1, rax_6);
        (*(*arg1 + 0xb8))(arg1, rax_4);
        result = (*(*arg1 + 0xb8))(arg1, rax_3);
    }
    
    __security_check_cookie(rax_1 ^ &var_a8);
    return result;
}

