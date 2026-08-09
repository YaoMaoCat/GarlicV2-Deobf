
  void* sub_18002edd1(int64_t arg1, void* arg2)

{
    sub_180019220(*(arg2 + 0x30));
    
    if (!*(arg2 + 0x20))
    {
        int32_t* rbx_1 = *(arg2 + 0xd8);
        
        if (*rbx_1 == 0xe06d7363 && rbx_1[6] == 4
            && (rbx_1[8] == 0x19930520 || rbx_1[8] == 0x19930521 || rbx_1[8] == 0x19930522))
        {
            int32_t rax_1;
            int64_t rdx;
            rax_1 = sub_1800199b0(*(rbx_1 + 0x28));
            
            if (rax_1)
            {
                rdx = 1;
                sub_180019930(rbx_1);
            }
        }
    }
    
    void* rax_2 = sub_180019c40();
    *(rax_2 + 0x20) = *(arg2 + 0x70);
    void* result = sub_180019c40();
    *(result + 0x28) = *(arg2 + 0x78);
    return result;
}

