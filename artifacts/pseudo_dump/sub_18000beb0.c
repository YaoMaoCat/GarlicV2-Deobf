
  void sub_18000beb0(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2)

{
    if (!arg2)
        return;
    
    int64_t rsi_1 = arg2;
    
    if (!data_180046090)
    {
        if (!arg1)
            /* tailcall */
            return sub_1800023a0("AttachObj: install failed", arg2);
        
        int64_t rax_1;
        rax_1 = sub_180001de0(arg1, data_180047468, arg3);
        
        if (!rax_1)
            /* tailcall */
            return sub_1800023a0("AttachObj: install failed", arg2);
        
        char rax_2;
        int512_t zmm2;
        rax_2 = sub_18000c550(arg1, rax_1);
        char rax_3;
        
        if (rax_2)
            rax_3 = sub_18000c2f0(arg1, rax_1, zmm2);
        
        if (!rax_2 || !rax_3)
            /* tailcall */
            return sub_1800023a0("AttachObj: install failed", (*(*arg1 + 0xb0))(arg1, rax_1));
        
        (*(*arg1 + 0xb0))(arg1, rax_1);
    }
    
    LOCATOR::FLocateDbgValidate(arg1, rsi_1);
}

