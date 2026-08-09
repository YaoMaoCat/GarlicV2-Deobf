
  int64_t sub_180026950(int64_t arg1, int64_t* arg2, int64_t* arg3, int64_t* arg4, int512_t arg5 @ zmm1)

{
    int64_t* arg_20 = arg4;
    sub_180020d3c(*arg2);
    int32_t* rdx = arg3[1];
    void* rcx_1 = **arg3;
    
    if (rcx_1)
    {
        int32_t rcx_2 = *(rcx_1 + 0x14);
        
        if (rcx_2 >> 0xd & 1)
        {
            if (((rcx_2 & 3) != 2 || !(rcx_2 & 0xc0)) && !TEST_BITD(rcx_2, 0xb))
                *rdx += 1;
            else if (*arg3[2] || *(**arg3 + 0x14) >> 1 & 1)
            {
                if (_fflush_nolock(**arg3, arg5) == 0xffffffff)
                    *arg3[3] = 0xffffffff;
                else
                {
                    int32_t* rax_9 = arg3[1];
                    *rax_9 += 1;
                }
            }
        }
    }
    
    return sub_180020d48(*arg4);
}

