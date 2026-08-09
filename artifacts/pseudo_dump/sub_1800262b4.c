
  int64_t sub_1800262b4(int16_t* arg1, uint32_t arg2, wchar16* arg3, int32_t arg4, PWSTR arg5, int32_t arg6, int64_t arg7, int64_t arg8, int64_t arg9)

{
    int64_t r10 = data_18004c090;
    
    if (r10 != -1)
    {
        int64_t rax_1;
        
        if (!r10)
            rax_1 = sub_180025f60(r10 + 0x12, "LCMapStringEx", &data_18003aba0, "LCMapStringEx");
        
        if (r10 || rax_1)
        {
            int64_t var_18_1 = arg9;
            int64_t var_20_1 = arg8;
            int64_t var_28_1 = arg7;
            int32_t var_30 = arg6;
            PWSTR var_38 = arg5;
            return sub_18002d680();
        }
    }
    
    return LCMapStringW(sub_1800263a8(arg1, 0), arg2, arg3, arg4, arg5, arg6);
}

