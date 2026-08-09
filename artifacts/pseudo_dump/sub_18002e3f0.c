
  int64_t sub_18002e3f0(int64_t arg1, void* arg2)

{
    int32_t result = *(arg2 + 0x48) & 1;
    
    if (!result)
        return result;
    
    *(arg2 + 0x48) &= 0xfffffffe;
    return j_sub_180003a30(*(arg2 + 0x80));
}

