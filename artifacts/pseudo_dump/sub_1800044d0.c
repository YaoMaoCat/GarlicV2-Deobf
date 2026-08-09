
  void*** sub_1800044d0(int64_t* arg1, int64_t* arg2, int64_t* arg3)

{
    void* rax = *arg1;
    void*** result = arg2;
    arg2[1] = 0;
    arg2[2] = rax;
    void** rbx = *(rax + 8);
    *arg2 = rbx;
    
    if (!*(rbx + 0x19))
    {
        int64_t rbp_1 = arg3[2];
        int64_t r15_1 = arg3[3];
        
        do
        {
            *result = rbx;
            int64_t* rdx;
            
            if (r15_1 <= 0xf)
                rdx = arg3;
            else
                rdx = *arg3;
            
            char* rcx = &rbx[4];
            int64_t rsi_1 = rbx[6];
            
            if (rbx[7] > 0xf)
                rcx = *rcx;
            
            int64_t r8 = rsi_1;
            
            if (rbp_1 < rsi_1)
                r8 = rbp_1;
            
            int32_t rax_1 = memcmp(rcx, rdx, r8);
            
            if (!rax_1)
            {
                if (rsi_1 >= rbp_1)
                    rax_1 = rsi_1 > rbp_1;
                else
                    rax_1 = -1;
            }
            
            int32_t rax_3;
            
            if (!(rax_1 >> 0x1f))
            {
                result[2] = rbx;
                rax_3 = 1;
            }
            else
            {
                rax_3 = 0;
                rbx = &rbx[2];
            }
            
            rbx = *rbx;
            result[1] = rax_3;
        } while (!*(rbx + 0x19));
    }
    
    return result;
}

