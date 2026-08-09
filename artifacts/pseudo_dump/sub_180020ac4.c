
  void sub_180020ac4(int64_t* arg1, int64_t arg2)

{
    if (arg1 == arg2)
        return;
    
    int64_t* rbx_1 = arg1;
    
    do
    {
        if (*rbx_1)
            sub_18002d680();
        
        rbx_1 = &rbx_1[1];
    } while (rbx_1 != arg2);
}

