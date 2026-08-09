
  uint64_t sub_18002c324(int16_t arg1)

{
    int16_t arg_8 = arg1;
    
    if (__dcrt_lowio_ensure_console_output_initialized())
    {
        int32_t arg_10 = 0;
        
        if (sub_18002cd1c(&arg_8, 1, &arg_10))
            return arg_8;
    }
    
    return 0xffff;
}

