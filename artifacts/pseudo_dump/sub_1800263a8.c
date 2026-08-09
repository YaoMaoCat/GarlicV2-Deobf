
  uint64_t sub_1800263a8(int16_t* arg1, int32_t arg2)

{
    int64_t rax = data_18004c0a0;
    
    if (rax != -1)
    {
        int64_t rax_1;
        
        if (!rax)
            rax_1 =
                sub_180025f60(rax + 0x14, "LocaleNameToLCID", &data_18003abb8, "LocaleNameToLCID");
        
        if (rax || rax_1)
            return sub_18002d680();
    }
    
    return sub_18002a76c(arg1);
}

