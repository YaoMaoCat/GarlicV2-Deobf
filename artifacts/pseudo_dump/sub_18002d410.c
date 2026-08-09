
  int64_t sub_18002d410(int32_t* arg1, int64_t arg2, void* arg3, int64_t* arg4)

{
    int32_t result = sub_1800183a0(arg1, arg2, arg3, arg4);
    
    if (arg1[1] & 0x66 || *arg1 != 0xe06d7363 || result != 1)
        return result;
    
    *(sub_180019c40() + 0x20) = arg1;
    *(sub_180019c40() + 0x28) = arg3;
    sub_180020b48();
    /* no return */
}

