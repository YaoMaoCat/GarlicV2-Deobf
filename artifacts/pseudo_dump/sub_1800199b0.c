
  int64_t sub_1800199b0(int64_t arg1)

{
    for (int64_t* i = *(sub_180019c40() + 0x58); i; i = i[1])
    {
        if (*i == arg1)
            return 0;
    }
    
    return 1;
}

