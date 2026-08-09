
  int64_t sub_180018e70(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5, int32_t arg6, int32_t arg7, void* arg8, int64_t* arg9, char arg10)

{
    void var_e8;
    int64_t rax_1 = __security_cookie ^ &var_e8;
    int128_t zmm0 = data_1800388a0;
    uint128_t zmm1 = data_1800388b0;
    EXCEPTION_RECORD ExceptionRecord;
    ExceptionRecord.ExceptionCode = zmm0;
    ExceptionRecord.ExceptionFlags = *(&zmm0 + 4);
    ExceptionRecord.ExceptionRecord = *(&zmm0 + 8);
    zmm0 = data_1800388c0;
    ExceptionRecord.ExceptionInformation[0] = zmm0;
    ExceptionRecord.ExceptionInformation[1] = *(&zmm0 + 8);
    zmm0 = data_1800388e0;
    ExceptionRecord.ExceptionInformation[0] = sub_18001c3d0;
    ExceptionRecord.ExceptionAddress = zmm1;
    ExceptionRecord.NumberParameters = *(&zmm1 + 8);
    zmm1 = data_1800388d0;
    ExceptionRecord.ExceptionInformation[2] = zmm1;
    ExceptionRecord.ExceptionInformation[3] = *(&zmm1 + 8);
    zmm1 = data_1800388f0;
    ExceptionRecord.ExceptionInformation[2] = arg5;
    ExceptionRecord.ExceptionInformation[4] = zmm0;
    ExceptionRecord.ExceptionInformation[5] = *(&zmm0 + 8);
    zmm0 = data_180038900;
    ExceptionRecord.ExceptionInformation[4] = arg3;
    ExceptionRecord.ExceptionInformation[3] = arg6;
    ExceptionRecord.ExceptionInformation[6] = zmm1;
    ExceptionRecord.ExceptionInformation[7] = *(&zmm1 + 8);
    zmm1 = data_180038910;
    int64_t rcx_1 = *(arg8 + 0x18) + arg9[1];
    int64_t r8_2 = *(arg8 + 0x20) + arg9[1];
    ExceptionRecord.ExceptionInformation[7] = arg10;
    ExceptionRecord.ExceptionInformation[8] = zmm0;
    ExceptionRecord.ExceptionInformation[9] = *(&zmm0 + 8);
    zmm0 = data_180038920;
    ExceptionRecord.ExceptionInformation[0xa] = zmm1;
    ExceptionRecord.ExceptionInformation[0xb] = *(&zmm1 + 8);
    ExceptionRecord.ExceptionInformation[0xb] = arg7;
    UNWIND_HISTORY_TABLE* HistoryTable = arg9[8];
    CONTEXT* ContextRecord = arg9[5];
    ExceptionRecord.ExceptionInformation[1] = arg4;
    ExceptionRecord.ExceptionInformation[5] = rcx_1;
    int64_t TargetFrame = *arg1;
    ExceptionRecord.ExceptionInformation[6] = arg2;
    int64_t TargetIp = *arg9;
    ExceptionRecord.ExceptionInformation[9] = r8_2;
    ExceptionRecord.ExceptionInformation[0xc] = zmm0;
    ExceptionRecord.ExceptionInformation[0xd] = *(&zmm0 + 8);
    ExceptionRecord.ExceptionInformation[0xe] = 0;
    ExceptionRecord.ExceptionInformation[8] = 0x19930520;
    int64_t result =
        RtlUnwindEx(TargetFrame, TargetIp, &ExceptionRecord, nullptr, ContextRecord, HistoryTable);
    __security_check_cookie(rax_1 ^ &var_e8);
    return result;
}

