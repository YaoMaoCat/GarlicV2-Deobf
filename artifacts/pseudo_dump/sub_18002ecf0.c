
  uint64_t sub_18002ecf0(int64_t arg1, void* arg2)

{
    *(arg2 + 0x30) = arg1;
    
    if (*(arg2 + 0x58))
    {
        *(arg2 + 0x28) = **(arg2 + 0x30);
        
        if (**(arg2 + 0x28) == 0xe06d7363 && *(*(arg2 + 0x28) + 0x18) == 4 && (
            *(*(arg2 + 0x28) + 0x20) == 0x19930520 || *(*(arg2 + 0x28) + 0x20) == 0x19930521
            || *(*(arg2 + 0x28) + 0x20) == 0x19930522))
        {
            void* rax_7 = sub_180019c40();
            *(rax_7 + 0x20) = *(arg2 + 0x28);
            *(sub_180019c40() + 0x28) = *(*(arg2 + 0x30) + 8);
            sub_180020b48();
            /* no return */
        }
    }
    
    *(arg2 + 0x20) = 0;
    return *(arg2 + 0x20);
}

