
  bool sub_180022990(char* arg1)

{
    bool rdx = *arg1;
    
    if (rdx >= 0)
        return rdx;
    
    if ((rdx & 0xe0) == 0xc0)
        return 2;
    
    if ((rdx & 0xf0) == 0xe0)
        return 3;
    
    if ((rdx & 0xf8) == 0xf0)
        return 4;
    
    return 0xffffffff;
}

