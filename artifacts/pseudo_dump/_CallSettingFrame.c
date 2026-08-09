
🌐  int64_t _CallSettingFrame(int64_t arg1, int64_t* arg2, int512_t arg3 @ zmm0)

{
    int64_t arg_8 = arg1;
    int32_t r8;
    int32_t arg_18 = r8;
    int64_t rdx = *arg2;
    sub_180019b40();
    int64_t result = arg1(arg3, rdx);
    *arg2;
    sub_180019b40();
    return result;
}

