
  uint32_t sub_180019e00()

{
    uint32_t dwFlsIndex = FlsAlloc(sub_180019bc0);
    data_180046890 = dwFlsIndex;
    
    if (dwFlsIndex != 0xffffffff)
    {
        if (FlsSetValue(dwFlsIndex, &data_1800475b0))
        {
            data_180047628 = 0xfffffffe;
            dwFlsIndex = 1;
            return dwFlsIndex;
        }
        
        uint32_t dwFlsIndex_1 = data_180046890;
        
        if (dwFlsIndex_1 != 0xffffffff)
        {
            FlsFree(dwFlsIndex_1);
            data_180046890 = 0xffffffff;
        }
    }
    
    dwFlsIndex = 0;
    return dwFlsIndex;
}

