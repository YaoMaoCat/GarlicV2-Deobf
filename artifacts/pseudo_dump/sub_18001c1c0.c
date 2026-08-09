
  int64_t sub_18001c1c0(void* arg1)

{
    int32_t var_a8 = 0;
    int32_t arg_8 = 0;
    int64_t var_a0 = 0;
    int64_t arg_18 = 0;
    int64_t r13 = *(sub_180019c40() + 0x28);
    int64_t var_80 = r13;
    int64_t var_50 = r13;
    int64_t rax_2 = *(sub_180019c40() + 0x20);
    int64_t var_78 = rax_2;
    int64_t var_58 = rax_2;
    int32_t* rsi = *(arg1 + 0x50);
    int32_t* var_70 = rsi;
    int32_t* arg_10 = rsi;
    void* rax_3 = *(arg1 + 0x48);
    void* var_68 = rax_3;
    void* rbx = *(arg1 + 0x40);
    int64_t rax_4 = *(arg1 + 0x30);
    int64_t* r14 = *(arg1 + 0x28);
    int64_t* var_60 = r14;
    __except_validate_context_record(rbx);
    *(sub_180019c40() + 0x20) = rsi;
    *(sub_180019c40() + 0x28) = rbx;
    void var_48;
    int64_t* rax_8;
    int512_t zmm0;
    rax_8 = _CreateFrameInfo(&var_48, *(*(sub_180019c40() + 0x20) + 0x28));
    int64_t* var_98 = rax_8;
    
    if (*(arg1 + 0x58))
    {
        arg_8 = 1;
        void* rax_9;
        rax_9 = sub_180019c40();
        arg_18 = *(rax_9 + 0x70);
    }
    
    int64_t result = _CallSettingFrame(rax_4, r14, zmm0);
    int64_t result_1 = result;
    sub_180019220(rax_8);
    
    if (*rsi == 0xe06d7363 && rsi[6] == 4 && rsi[8] - 0x19930520 <= 2)
    {
        int32_t rax_12;
        int64_t rdx_4;
        rax_12 = sub_1800199b0(*(rsi + 0x28));
        
        if (rax_12)
        {
            rdx_4 = 1;
            sub_180019930(rsi);
        }
    }
    
    *(sub_180019c40() + 0x20) = rax_2;
    *(sub_180019c40() + 0x28) = r13;
    *(*(rax_3 + 0x1c) + *r14) = -2;
    return result;
}

