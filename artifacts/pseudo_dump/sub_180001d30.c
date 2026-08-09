
  int64_t sub_180001d30(int64_t arg1, int64_t arg2)

{
    int64_t arg_8 = arg1;
    int64_t arg_10 = arg2;
    int64_t r8;
    int64_t arg_18 = r8;
    int64_t r9;
    int64_t arg_20 = r9;
    void var_458;
    int64_t rax_1 = __security_cookie ^ &var_458;
    void text;
    __stdio_common_vsprintf(data_180047458 | 2, &text, 0x400, arg1, nullptr, &arg_10);
    MessageBoxA(nullptr, &text, "MinecraftProxy", MB_OK);
    int64_t result = sub_1800023a0("[DBG] %s", &text);
    __security_check_cookie(rax_1 ^ &var_458);
    return result;
}

