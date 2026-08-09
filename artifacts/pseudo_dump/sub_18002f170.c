
  int64_t sub_18002f170(int64_t* arg1)

{
    int32_t rcx = **arg1;
    
    if (rcx != 0xc0000005 && rcx != 0xc000001d)
        return 0;
    
    return 1;
}

