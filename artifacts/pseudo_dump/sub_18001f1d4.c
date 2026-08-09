
  int64_t sub_18001f1d4(void* arg1)

{
    int64_t* rdx = *(arg1 + 0x18);
    *(arg1 + 0x18) = &rdx[1];
    wchar16 const* const rcx = *rdx;
    int32_t r8 = *(arg1 + 0x30);
    int32_t rdx_1 = *(arg1 + 0x34);
    char r9 = *(arg1 + 0x39);
    
    if (r8 == 0xffffffff)
        r8 = 0x7fffffff;
    
    *(arg1 + 0x40) = rcx;
    int32_t result;
    
    if (rdx_1 == 2)
    {
    label_18001f24d:
        
        if (!rcx)
        {
            rcx = "(null)";
            *(arg1 + 0x40) = "(null)";
        }
        
        result = sub_180021400(rcx, r8);
    }
    else
    {
        if (rdx_1 != 3 && rdx_1 != 0xc)
        {
            if (*(arg1 + 0x34) == 0xd)
                goto label_18001f24d;
            
            if (!((r9 - 0x63) & 0xef))
                goto label_18001f24d;
        }
        
        if (!rcx)
        {
            rcx = u"(null)";
            *(arg1 + 0x40) = u"(null)";
        }
        
        *(arg1 + 0x4c) = 1;
        result = sub_180021590(rcx, r8);
    }
    
    *(arg1 + 0x48) = result;
    result = 1;
    return result;
}

