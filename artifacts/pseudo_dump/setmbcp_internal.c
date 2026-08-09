
🌐  uint64_t setmbcp_internal(uint32_t arg1, char arg2, void* arg3, int64_t* arg4)

{
    int64_t* arg_20 = arg4;
    void* arg_18 = arg3;
    int64_t r14;
    r14 = arg2;
    update_thread_multibyte_data_internal(arg3, arg4);
    uint32_t rax = getSystemCP(arg1);
    
    if (rax == *(*(arg_18 + 0x88) + 4))
        return 0;
    
    int128_t* rax_2 = _malloc_base(0x228);
    
    if (!rax_2)
    {
        _free_base(0);
        return 0xffffffff;
    }
    
    void var_248;
    int128_t* rcx_3 = &var_248;
    int64_t i_2 = 4;
    int64_t i_3 = 4;
    int128_t* rax_4 = *(arg_18 + 0x88);
    int128_t zmm0_1;
    int128_t zmm1;
    int64_t i;
    
    do
    {
        zmm1 = rax_4[1];
        *rcx_3 = *rax_4;
        zmm0_1 = rax_4[2];
        rcx_3[1] = zmm1;
        zmm1 = rax_4[3];
        rcx_3[2] = zmm0_1;
        zmm0_1 = rax_4[4];
        rcx_3[3] = zmm1;
        zmm1 = rax_4[5];
        rcx_3[4] = zmm0_1;
        zmm0_1 = rax_4[6];
        rcx_3[5] = zmm1;
        zmm1 = rax_4[7];
        rax_4 = &rax_4[8];
        rcx_3[6] = zmm0_1;
        rcx_3 = &rcx_3[8];
        rcx_3[-1] = zmm1;
        i = i_3;
        i_3 -= 1;
    } while (i != 1);
    zmm1 = rax_4[1];
    int64_t rax_5 = rax_4[2];
    *rcx_3 = *rax_4;
    rcx_3[1] = zmm1;
    rcx_3[2] = rax_5;
    int128_t* rcx_4 = rax_2;
    int128_t* rax_6 = &var_248;
    int64_t i_1;
    
    do
    {
        zmm1 = rax_6[1];
        *rcx_4 = *rax_6;
        zmm0_1 = rax_6[2];
        rcx_4[1] = zmm1;
        zmm1 = rax_6[3];
        rcx_4[2] = zmm0_1;
        zmm0_1 = rax_6[4];
        rcx_4[3] = zmm1;
        zmm1 = rax_6[5];
        rcx_4[4] = zmm0_1;
        zmm0_1 = rax_6[6];
        rcx_4[5] = zmm1;
        zmm1 = rax_6[7];
        rax_6 = &rax_6[8];
        rcx_4[6] = zmm0_1;
        rcx_4 = &rcx_4[8];
        rcx_4[-1] = zmm1;
        i_1 = i_2;
        i_2 -= 1;
    } while (i_1 != 1);
    zmm1 = rax_6[1];
    int64_t rax_7 = rax_6[2];
    *rcx_4 = *rax_6;
    rcx_4[1] = zmm1;
    rcx_4[2] = rax_7;
    *rax_2 &= i_2;
    int32_t rax_8 = sub_180025434(rax, rax_2);
    
    if (rax_8 == 0xffffffff)
    {
        *sub_18002131c() = 0x16;
        _free_base(rax_2);
        return 0xffffffff;
    }
    
    if (!r14)
        Concurrency::details::WinRT::Initialize();
    
    int32_t* rcx_7 = *(arg_18 + 0x88);
    int32_t rax_11 = *rcx_7;
    *rcx_7 -= 1;
    
    if (rax_11 == 1)
    {
        int64_t rcx_8 = *(arg_18 + 0x88);
        
        if (rcx_8 != &data_180046b40)
            _free_base(rcx_8);
    }
    
    *rax_2 = 1;
    *(arg_18 + 0x88) = rax_2;
    
    if (!(data_180047080 & *(arg_18 + 0x3a8)))
    {
        void** var_258 = &arg_18;
        int64_t* var_250_1 = &arg_20;
        int32_t var_264 = 5;
        int32_t var_260 = 5;
        void var_268;
        __crt_seh_guarded_call<class <lambda_efdfa57d1f175319df784efa44bb7b81>,class <lambda_5f0a4c1567f8adc6734073e5d1e1b35c>& __ptr64,class <lambda_2e8a7d3640ea6ccb4c2413664c2db6fd>,void>::operator()<class <lambda_efdfa57d1f175319df784efa44bb7b81>,class <lambda_5f0a4c1567f8adc6734073e5d1e1b35c>& __ptr64,class <lambda_2e8a7d3640ea6ccb4c2413664c2db6fd> >(
            &var_268, &var_260, &var_258, &var_264);
        
        if (r14)
            data_180046b30 = *arg_20;
    }
    
    _free_base(0);
    return rax_8;
}

