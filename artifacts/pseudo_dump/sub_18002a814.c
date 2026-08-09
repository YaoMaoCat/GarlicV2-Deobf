
🌐  uint64_t __crt_seh_guarded_call<class <lambda_a37b2b86f63e897a80ea819b0eb08c01>,class <lambda_38ce7e780aa69e748d6df282ebc68efe>& __ptr64,class <lambda_99fb1378e971ab6e7edea83e3a7a83a2>,int32_t>::operator()<class <lambda_a37b2b86f63e897a80ea819b0eb08c01>,class <lambda_38ce7e780aa69e748d6df282ebc68efe>& __ptr64,class <lambda_99fb1378e971ab6e7edea83e3a7a83a2> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)

{
    int32_t* arg_20 = arg4;
    __acrt_lowio_unlock_fh(*arg2);
    int64_t rcx_1 = **arg3;
    int32_t rbx_1;
    
    if (!(*((&data_180047840)[rcx_1 >> 6] + (rcx_1 & 0x3f) * 0x48 + 0x38) & 1))
    {
        *sub_18002131c() = 9;
        rbx_1 = -1;
    }
    else
    {
        rbx_1 = 0;
        
        if (!FlushFileBuffers(_get_osfhandle(rcx_1)))
        {
            *sub_1800212f8() = GetLastError();
            *sub_18002131c() = 9;
            rbx_1 = -1;
        }
    }
    
    sub_1800292dc(*arg4);
    return rbx_1;
}

