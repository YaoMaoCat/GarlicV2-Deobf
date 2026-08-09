
  int64_t sub_18002f1a0(int64_t* arg1, void* arg2)

{
    *(arg2 + 0x10) = arg1;
    int32_t rcx = **arg1;
    *(arg2 + 8) = rcx;
    
    if (rcx != 0xc0000005 && rcx != 0xc000001d)
        return 0;
    
    return 1;
}

