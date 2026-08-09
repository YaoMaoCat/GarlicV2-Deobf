
🌐  int64_t* _CreateFrameInfo(int64_t* arg1, int64_t arg2)

{
    *arg1 = arg2;
    int64_t rcx;
    
    if (arg1 >= *(sub_180019c40() + 0x58))
        rcx = 0;
    else
        rcx = *(sub_180019c40() + 0x58);
    
    arg1[1] = rcx;
    *(sub_180019c40() + 0x58) = arg1;
    return arg1;
}

