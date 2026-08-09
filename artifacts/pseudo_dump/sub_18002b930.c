
  int64_t sub_18002b930(int64_t* arg1)

{
    int64_t arg_10 = 0;
    fegetenv(&arg_10);
    arg_10 |= 0x1f;
    *arg1 = arg_10;
    
    if (sub_18002b8c0(&arg_10))
        return 1;
    
    sub_18002c590();
    return 0;
}

