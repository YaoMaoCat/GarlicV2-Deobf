
  int64_t sub_180004fa0(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4)

{
    void* rax = *arg1;
    
    if (rax)
    {
        void* rcx;
        
        if (arg1[2] - rax < 0x1000)
            rcx = rax;
        else
        {
            rcx = *(rax - 8);
            
            if (rax - rcx - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx);
    }
    
    *arg1 = arg2;
    arg1[1] = arg2 + arg3;
    int64_t result = arg2 + arg4;
    arg1[2] = result;
    return result;
}

