
  int64_t common_getenv<char>(char* arg1)

{
    if (arg1 && sub_180021400(arg1, 0x7fff) < 0x7fff)
    {
        sub_1800239bc(0xb);
        int64_t result = sub_18001f640(arg1);
        sub_180023a10(0xb);
        return result;
    }
    
    *sub_18002131c() = 0x16;
    _invalid_parameter_noinfo();
    return 0;
}

