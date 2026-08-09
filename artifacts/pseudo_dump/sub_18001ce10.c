
  uint64_t sub_18001ce10(int64_t arg1, int64_t* arg2, void* arg3)

{
    int32_t rbx = sub_18001a020(arg3, arg2);
    
    if (!arg2[9])
    {
        if (*(sub_180019c40() + 0x78) != 0xfffffffe)
        {
            rbx = *(sub_180019c40() + 0x78);
            *(sub_180019c40() + 0x78) = 0xfffffffe;
        }
        
        return rbx;
    }
    
    if (*(sub_180019c40() + 0x78) == 0xfffffffe)
        return arg2[9] - 2;
    
    abort();
    /* no return */
}

