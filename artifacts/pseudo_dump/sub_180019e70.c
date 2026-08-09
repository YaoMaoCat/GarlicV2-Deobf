
  int64_t sub_180019e70()

{
    uint32_t dwFlsIndex = data_180046890;
    
    if (dwFlsIndex != 0xffffffff)
    {
        FlsFree(dwFlsIndex);
        data_180046890 = 0xffffffff;
    }
    
    int64_t result;
    result = 1;
    return result;
}

