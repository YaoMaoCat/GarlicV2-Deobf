
  int64_t sub_180019300(int32_t* arg1, int64_t arg2, void* arg3, int64_t* arg4)

{
    int64_t rbx = arg4[1];
    int64_t arg_8 = arg2;
    *(sub_180019c40() + 0x60) = rbx;
    *(sub_180019c40() + 0x68) = *(arg1 + 0x38);
    void* rax_2 = sub_180019c40();
    char var_30 = 0;
    int64_t var_38 = 0;
    int32_t var_40 = 0;
    return sub_18001bff0(arg1, &arg_8, arg3, arg4, *arg4[7] + *(rax_2 + 0x60));
}

