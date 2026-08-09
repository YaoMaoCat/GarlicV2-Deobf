
  int64_t sub_18001c3d0(void* arg1)

{
    int32_t var_c8 = 0;
    int32_t arg_10 = 0;
    int64_t var_b0 = 0;
    int64_t var_a8 = 0;
    int64_t r13 = *(sub_180019c40() + 0x28);
    int64_t var_88 = r13;
    int64_t var_68 = r13;
    int64_t rax_2 = *(sub_180019c40() + 0x20);
    int64_t var_80 = rax_2;
    int64_t var_70 = rax_2;
    int32_t* rsi = *(arg1 + 0x50);
    int32_t* var_78 = rsi;
    int32_t* var_c0 = rsi;
    void* rbx = *(arg1 + 0x40);
    int64_t rax_3 = *(arg1 + 0x30);
    int64_t* r12 = *(arg1 + 0x28);
    int64_t var_60 = *(arg1 + 0x48);
    int64_t var_58 = *(arg1 + 0x68);
    int32_t arg_8 = *(arg1 + 0x78);
    int32_t rax_7 = *(arg1 + 0x38);
    int32_t arg_20 = rax_7;
    int32_t var_b8 = rax_7;
    __except_validate_context_record(rbx);
    *(sub_180019c40() + 0x20) = rsi;
    *(sub_180019c40() + 0x28) = rbx;
    void var_50;
    int64_t* rax_11;
    int512_t zmm0;
    rax_11 = _CreateFrameInfo(&var_50, *(*(sub_180019c40() + 0x20) + 0x28));
    int64_t* var_a0 = rax_11;
    
    if (*(arg1 + 0x58))
    {
        arg_10 = 1;
        void* rax_12;
        rax_12 = sub_180019c40();
        int64_t var_a8_1 = *(rax_12 + 0x70);
    }
    
    int64_t result_2 = _CallSettingFrame_LookupContinuationIndex(rax_3, r12, zmm0);
    int64_t result = result_2;
    int64_t result_3 = result_2;
    
    if (result_2 < 2)
    {
        result = (&var_60)[result_2];
        
        if (!result)
        {
            abort();
            /* no return */
        }
        
        int64_t result_1 = result;
    }
    
    _CallSettingFrame_NotifyContinuationAddr(result, r12);
    sub_180019220(rax_11);
    
    if (*rsi == 0xe06d7363 && rsi[6] == 4 && rsi[8] - 0x19930520 <= 2)
    {
        int32_t rax_15;
        int64_t rdx_5;
        rax_15 = sub_1800199b0(*(rsi + 0x28));
        
        if (rax_15)
        {
            rdx_5 = 1;
            sub_180019930(rsi);
        }
    }
    
    *(sub_180019c40() + 0x20) = rax_2;
    *(sub_180019c40() + 0x28) = r13;
    *(sub_180019c40() + 0x78) = rax_7;
    *(sub_180019c40() + 0x78) = 0xfffffffe;
    return result;
}

