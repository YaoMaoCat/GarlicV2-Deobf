
  int64_t sub_18002e820(int64_t arg1, void* arg2)

{
    int32_t result = *(arg2 + 0x20) & 1;
    
    if (!result)
        return result;
    
    *(arg2 + 0x20) &= 0xfffffffe;
    return sub_180004d40(*(arg2 + 0x88));
}

