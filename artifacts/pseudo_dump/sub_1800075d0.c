
  int64_t* sub_1800075d0(int64_t* arg1, int64_t* arg2)

{
    __builtin_memset(arg1, 0, 0x18);
    int64_t rdx = arg2[1];
    uint64_t rdx_1 = rdx - *arg2;
    
    if (rdx != *arg2)
    {
        if (rdx_1 > 0x7fffffffffffffff)
        {
            sub_1800052a0();
            /* no return */
        }
        
        sub_180007840(arg1, rdx_1);
        int32_t* rdx_2 = *arg2;
        int128_t* rdi_1 = *arg1;
        void* rbx_2 = arg2[1] - rdx_2;
        memcpy(rdi_1, rdx_2, rbx_2);
        arg1[1] = rbx_2 + rdi_1;
    }
    
    return arg1;
}

