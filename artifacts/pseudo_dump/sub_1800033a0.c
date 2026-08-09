
  int64_t sub_1800033a0()

{
    int32_t fPending;
    
    if (!InitOnceBeginInitialize(&data_1800474a0, 0, &fPending, nullptr))
        trap(0xd);
    
    if (fPending)
    {
        void* var_18_1 = &data_1800474a0;
        int32_t var_10_1 = 4;
        sub_180002cd0();
        
        if (!InitOnceComplete(&data_1800474a0, 0, nullptr))
        {
            sub_1800172c0();
            /* no return */
        }
    }
    
    return &data_180046008;
}

