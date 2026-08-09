
  BOOL sub_180002be0(int64_t* arg1)

{
    BOOL result = InitOnceComplete(*arg1, arg1[1], nullptr);
    
    if (result)
        return result;
    
    sub_1800172c0();
    /* no return */
}

