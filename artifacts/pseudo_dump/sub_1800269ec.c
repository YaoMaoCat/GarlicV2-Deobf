
  int64_t __crt_seh_guarded_call<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752>,void>::operator()<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4, int512_t arg5 @ zmm1)

{
    int32_t* arg_20 = arg4;
    sub_1800239bc(*arg2);
    int64_t* rbx = data_1800477f0;
    void* r14 = &rbx[data_1800477e8];
    
    while (true)
    {
        int64_t* var_40_1 = rbx;
        
        if (rbx == r14)
            break;
        
        void* rcx_1 = *rbx;
        void* var_58 = rcx_1;
        int32_t* rdx = *arg3;
        
        if (rcx_1)
        {
            int32_t rcx_2 = *(rcx_1 + 0x14);
            
            if (rcx_2 >> 0xd & 1)
            {
                if ((rcx_2 & 3) != 2)
                {
                    if (TEST_BITD(rcx_2, 0xb))
                        goto label_180026a64;
                    
                    *rdx += 1;
                }
                else if (rcx_2 & 0xc0 || TEST_BITD(rcx_2, 0xb))
                {
                label_180026a64:
                    int64_t rdx_1 = arg3[2];
                    int64_t rcx_3 = arg3[1];
                    int64_t rax_4 = *arg3;
                    void** var_38 = &var_58;
                    int64_t var_30_1 = rax_4;
                    int64_t var_28_1 = rcx_3;
                    int64_t var_20_1 = rdx_1;
                    void* rax_5 = var_58;
                    void* var_50 = rax_5;
                    void* var_48 = rax_5;
                    void arg_10;
                    arg5 = sub_180026950(&arg_10, &var_48, &var_38, &var_50, arg5);
                }
                else
                    *rdx += 1;
            }
        }
        
        rbx = &rbx[1];
    }
    
    return sub_180023a10(*arg4);
}

