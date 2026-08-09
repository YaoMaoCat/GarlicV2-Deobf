
  int64_t sub_18000bd50(int64_t* arg1, int64_t arg2)

{
    int64_t result;
    int64_t rdx;
    int64_t r9;
    int512_t zmm2;
    result = sub_1800023a0("Attach: entering ctx=%p", arg2);
    
    if (!arg2)
        return result;
    
    if (!data_180046090)
    {
        int64_t rdx_1;
        rdx_1 = sub_1800023a0("Attach: g_relay invalid, installing", rdx);
        
        if (!data_180046090)
        {
            if (!arg1)
                /* tailcall */
                return sub_1800023a0("Attach: install failed", rdx_1);
            
            int64_t rax;
            rax = sub_180001de0(arg1, data_180047468, zmm2);
            
            if (!rax)
                /* tailcall */
                return sub_1800023a0("Attach: install failed", rdx_1);
            
            char rax_1;
            int512_t zmm2_1;
            rax_1 = sub_18000c550(arg1, rax);
            char rax_2;
            
            if (rax_1)
                rax_2 = sub_18000c2f0(arg1, rax, zmm2_1);
            
            if (!rax_1 || !rax_2)
                /* tailcall */
                return sub_1800023a0("Attach: install failed", (*(*arg1 + 0xb0))(arg1, rax));
            
            r9 = (*(*arg1 + 0xb0))(arg1, rax);
        }
    }
    
    data_1800460e8;
    int64_t rax_4;
    int64_t rdx_7;
    rax_4 = sub_180001cd0(arg1, arg2, zmm2, r9);
    
    if (rax_4)
    {
        int64_t rdx_8 = *arg1;
        char rax_5;
        rax_5 = (*(rdx_8 + 0x720))(arg1, rdx_8);
        
        if (!rax_5)
        {
            sub_1800023a0("Attach: got pipeline=%p", rax_4);
            LOCATOR::FLocateDbgValidate(arg1, rax_4);
❓            /* jump -> *(*arg1 + 0xb8) */
        }
    }
    
    sub_1800023a0("Attach: ctx.pipeline() FAILED", rdx_7);
    return (*(*arg1 + 0x88))(arg1);
}

