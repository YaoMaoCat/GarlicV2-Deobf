
  int64_t sub_180015f80(int64_t* arg1, int64_t arg2, int64_t arg3, int512_t arg4 @ zmm1, int512_t arg5 @ zmm2)

{
    void var_68;
    int64_t rax_1 = __security_cookie ^ &var_68;
    int64_t r8 = data_1800464d8;
    char rax_3;
    
    if (r8)
        rax_3 = (*(*arg1 + 0x100))(arg1, arg3, r8);
    
    int32_t result;
    
    if (!r8 || !rax_3)
    {
        int64_t r8_1 = data_1800464c8;
        
        if (r8_1 && data_1800464d0 && (*(*arg1 + 0x100))(arg1, arg3, r8_1))
        {
            int64_t rax_7;
            int64_t r9_1;
            rax_7 = (*(*arg1 + 0x2f8))(arg1, arg3, data_1800464d0);
            
            if (rax_7)
            {
                void var_48;
                char rax_11 = sub_180015e20(arg1, rax_7, &var_48, r9_1, arg5);
                int64_t r8_4 = *arg1;
                (*(r8_4 + 0xb8))(arg1, rax_7, r8_4);
                
                if (rax_11)
                    arg5 = sub_180015be0(arg1, arg2, &var_48, arg4, arg5);
            }
            else if ((*(*arg1 + 0x720))(arg1))
                (*(*arg1 + 0x88))(arg1);
        }
        
        data_180046320;
        sub_180001cd0(arg1, arg2, arg5, arg3);
        
        if ((*(*arg1 + 0x720))(arg1))
            arg5 = sub_180002210(arg1, "ForwardToB/writeOne", arg5);
        
        result = sub_180014630(arg1, arg2, arg3, sub_180013c60(arg1, arg2, arg3, arg5));
    }
    else
    {
        result = data_18004751c;
        data_18004751c += 1;
        uint64_t rdx_1 = result + 1;
        
        if (!result || !(rdx_1 & 0x3ff))
            result = sub_1800023a0(
                "ForwardToB: skipping ClientboundCustomPayloadPacket (mod channel, count=%d)", 
                rdx_1);
    }
    
    __security_check_cookie(rax_1 ^ &var_68);
    return result;
}

