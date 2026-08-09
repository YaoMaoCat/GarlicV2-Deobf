
🌐  uint64_t tolower(uint32_t arg1)

{
    if (data_180047834)
        arg1 = _tolower_l(arg1, nullptr);
    else if (arg1 - 0x41 <= 0x19)
        arg1 += 0x20;
    
    return arg1;
}

