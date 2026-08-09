
  int64_t sub_180018370(int32_t arg1)

{
    for (int32_t* i = &data_1800379d0; i != &data_180037ec0; i = &i[4])
    {
        if (*i == arg1)
            return *(i + 8);
    }
    
    return "unknown error";
}

