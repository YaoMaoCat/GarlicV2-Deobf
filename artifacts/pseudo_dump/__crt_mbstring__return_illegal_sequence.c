
  int64_t __crt_mbstring::return_illegal_sequence(int64_t* arg1, void* arg2)

{
    *arg1 = 0;
    *(arg2 + 0x30) = 1;
    *(arg2 + 0x2c) = 0x2a;
    return -1;
}

