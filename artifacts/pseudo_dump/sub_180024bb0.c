
🌐  int64_t __crt_seh_guarded_call<class <lambda_efdfa57d1f175319df784efa44bb7b81>,class <lambda_5f0a4c1567f8adc6734073e5d1e1b35c>& __ptr64,class <lambda_2e8a7d3640ea6ccb4c2413664c2db6fd>,void>::operator()<class <lambda_efdfa57d1f175319df784efa44bb7b81>,class <lambda_5f0a4c1567f8adc6734073e5d1e1b35c>& __ptr64,class <lambda_2e8a7d3640ea6ccb4c2413664c2db6fd> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)

{
    int32_t* arg_20 = arg4;
    sub_1800239bc(*arg2);
    int128_t* rax_2 = *(**arg3 + 0x88) + 0x18;
    int128_t* arg_10 = rax_2;
    char* rcx_2 = data_180047eb0;
    char* var_28 = rcx_2;
    
    if (!rcx_2)
        goto label_180024c68;
    
    int64_t i_2;
    
    if (!rax_2)
    {
        sub_18002de50(rcx_2, 0, 0x101);
    label_180024c68:
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
        i_2 = 2;
    }
    else
    {
        i_2 = 2;
        int64_t i_3 = 2;
        int64_t i;
        
        do
        {
            *rcx_2 = *rax_2;
            *(rcx_2 + 0x10) = rax_2[1];
            *(rcx_2 + 0x20) = rax_2[2];
            *(rcx_2 + 0x30) = rax_2[3];
            *(rcx_2 + 0x40) = rax_2[4];
            *(rcx_2 + 0x50) = rax_2[5];
            *(rcx_2 + 0x60) = rax_2[6];
            rcx_2 = &rcx_2[0x80];
            *(rcx_2 - 0x10) = rax_2[7];
            rax_2 = &rax_2[8];
            i = i_3;
            i_3 -= 1;
        } while (i != 1);
        rax_2 = *rax_2;
        *rcx_2 = rax_2;
    }
    
    int128_t* rax_6 = *(**arg3 + 0x88) + 0x119;
    int128_t* var_20 = rax_6;
    int128_t* rcx_4 = data_180047eb8;
    int128_t* var_18 = rcx_4;
    
    if (!rcx_4)
    {
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
    }
    else if (!rax_6)
    {
        sub_18002de50(rcx_4, 0, 0x100);
        *sub_18002131c() = 0x16;
        _invalid_parameter_noinfo();
    }
    else
    {
        int64_t i_1;
        
        do
        {
            *rcx_4 = *rax_6;
            rcx_4[1] = rax_6[1];
            rcx_4[2] = rax_6[2];
            rcx_4[3] = rax_6[3];
            rcx_4[4] = rax_6[4];
            rcx_4[5] = rax_6[5];
            rcx_4[6] = rax_6[6];
            rcx_4 = &rcx_4[8];
            rcx_4[-1] = rax_6[7];
            rax_6 = &rax_6[8];
            i_1 = i_2;
            i_2 -= 1;
        } while (i_1 != 1);
    }
    
    int32_t* rdx = **arg3[1];
    int32_t rax_9 = *rdx;
    *rdx -= 1;
    
    if (rax_9 == 1)
    {
        int64_t* rcx_6 = *arg3[1];
        
        if (*rcx_6 != &data_180046b40)
            _free_base(*rcx_6);
    }
    
    **arg3[1] = *(**arg3 + 0x88);
    int32_t* rax_15 = *(**arg3 + 0x88);
    *rax_15 += 1;
    return sub_180023a10(*arg4);
}

