
  int64_t sub_18001c7c0(int64_t* arg1, void* arg2, int32_t* arg3)

{
    int32_t* r9 = *arg1;
    *arg3 = 0;
    
    if (*r9 == 0xe06d7363)
    {
        if (r9[6] == 4 && r9[8] - 0x19930520 <= 2 && *(r9 + 0x28) == *(arg2 + 0x28))
            *arg3 = 1;
        
        if (*r9 == 0xe06d7363 && r9[6] == 4 && r9[8] - 0x19930520 <= 2 && !*(r9 + 0x30))
        {
            *(sub_180019c40() + 0x40) = 1;
            *arg3 = 1;
            return 1;
        }
    }
    
    return 0;
}

