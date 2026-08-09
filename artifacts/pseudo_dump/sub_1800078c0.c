
  int64_t sub_1800078c0(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4)

{
    void* r10 = *arg1;
    
    if (r10)
    {
        void* rcx;
        
        if (((arg1[2] - r10) >> 1) * 2 < 0x1000)
            rcx = r10;
        else
        {
            rcx = *(r10 - 8);
            
            if (r10 - rcx - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx);
    }
    
    *arg1 = arg2;
    arg1[1] = arg2 + (arg3 << 1);
    int64_t result = arg2 + (arg4 << 1);
    arg1[2] = result;
    return result;
}

