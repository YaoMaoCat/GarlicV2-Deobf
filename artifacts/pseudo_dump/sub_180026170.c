
  int64_t sub_180026170()

{
    int64_t rax = data_18004c000;
    
    if (rax != -1)
    {
        int64_t rax_1;
        
        if (!rax)
            rax_1 = sub_180025f60(0, "AreFileApisANSI", &data_18003ab58, &data_18003ab5c);
        
        if (rax || rax_1)
            /* tailcall */
            return sub_18002d680();
    }
    
    return 1;
}

