
🌐  uint64_t __crt_seh_guarded_call<class <lambda_ad8af0d99a0adf03d037d7dffe354bb5>,class <lambda_c9ba49e555ba839a7b07aa3fbecb7617>& __ptr64,class <lambda_2f1ebd5d68526518146ae959c9e734c8>,int32_t>::operator()<class <lambda_ad8af0d99a0adf03d037d7dffe354bb5>,class <lambda_c9ba49e555ba839a7b07aa3fbecb7617>& __ptr64,class <lambda_2f1ebd5d68526518146ae959c9e734c8> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)

{
    int32_t* arg_20 = arg4;
    __acrt_lowio_unlock_fh(*arg2);
    int64_t rcx_1 = **arg3;
    void* rdx = arg3[1];
    int32_t rbx_1;
    
    if (!(*((&data_180047840)[rcx_1 >> 6] + (rcx_1 & 0x3f) * 0x48 + 0x38) & 1))
    {
        *(rdx + 0x30) = 1;
        *(rdx + 0x2c) = 9;
        rbx_1 = -1;
    }
    else
        rbx_1 = _close_nolock_internal(rcx_1, rdx);
    
    sub_1800292dc(*arg4);
    return rbx_1;
}

