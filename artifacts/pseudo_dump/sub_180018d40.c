
  int64_t sub_180018d40(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5, int64_t arg6, int32_t arg7, int64_t* arg8, char arg9)

{
    void var_e8;
    int64_t rax_1 = __security_cookie ^ &var_e8;
    int128_t zmm0 = data_180038940;
    uint128_t zmm1 = data_180038950;
    int64_t TargetFrame = *arg1;
    EXCEPTION_RECORD ExceptionRecord;
    ExceptionRecord.ExceptionCode = zmm0;
    ExceptionRecord.ExceptionFlags = *(&zmm0 + 4);
    ExceptionRecord.ExceptionRecord = *(&zmm0 + 8);
    zmm0 = data_180038960;
    ExceptionRecord.ExceptionInformation[0] = zmm0;
    ExceptionRecord.ExceptionInformation[1] = *(&zmm0 + 8);
    zmm0 = data_180038980;
    ExceptionRecord.ExceptionAddress = zmm1;
    ExceptionRecord.NumberParameters = *(&zmm1 + 8);
    zmm1 = data_180038970;
    ExceptionRecord.ExceptionInformation[2] = zmm1;
    ExceptionRecord.ExceptionInformation[3] = *(&zmm1 + 8);
    zmm1 = data_180038990;
    ExceptionRecord.ExceptionInformation[4] = zmm0;
    ExceptionRecord.ExceptionInformation[5] = *(&zmm0 + 8);
    zmm0 = data_1800389a0;
    ExceptionRecord.ExceptionInformation[6] = zmm1;
    ExceptionRecord.ExceptionInformation[7] = *(&zmm1 + 8);
    zmm1 = data_1800389b0;
    ExceptionRecord.ExceptionInformation[8] = zmm0;
    ExceptionRecord.ExceptionInformation[9] = *(&zmm0 + 8);
    zmm0 = data_1800389c0;
    ExceptionRecord.ExceptionInformation[0xa] = zmm1;
    ExceptionRecord.ExceptionInformation[0xb] = *(&zmm1 + 8);
    ExceptionRecord.ExceptionInformation[0xe] = 0;
    ExceptionRecord.ExceptionInformation[0xc] = zmm0;
    ExceptionRecord.ExceptionInformation[0xd] = *(&zmm0 + 8);
    ExceptionRecord.ExceptionInformation[0] = sub_18001c1c0;
    ExceptionRecord.ExceptionInformation[2] = arg5;
    ExceptionRecord.ExceptionInformation[1] = arg4;
    ExceptionRecord.ExceptionInformation[3] = arg7;
    ExceptionRecord.ExceptionInformation[5] = arg6;
    ExceptionRecord.ExceptionInformation[7] = arg9;
    UNWIND_HISTORY_TABLE* HistoryTable = arg8[8];
    CONTEXT* ContextRecord = arg8[5];
    ExceptionRecord.ExceptionInformation[4] = arg3;
    ExceptionRecord.ExceptionInformation[6] = arg2;
    int64_t TargetIp = *arg8;
    ExceptionRecord.ExceptionInformation[8] = 0x19930520;
    int64_t result =
        RtlUnwindEx(TargetFrame, TargetIp, &ExceptionRecord, nullptr, ContextRecord, HistoryTable);
    __security_check_cookie(rax_1 ^ &var_e8);
    return result;
}

