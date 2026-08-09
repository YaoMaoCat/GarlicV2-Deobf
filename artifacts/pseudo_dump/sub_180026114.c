
  int64_t sub_180026114()

{
    int64_t rax = data_18004c0d0;
    
    if (rax != -1)
    {
        int64_t rax_1;
        
        if (!rax)
            rax_1 = sub_180025f60(rax + 0x1a, "AppPolicyGetProcessTerminationMethod", 
                &data_18003abd4, "AppPolicyGetProcessTerminationMethod");
        
        if (rax || rax_1)
            /* tailcall */
            return sub_18002d680();
    }
    
    return 0xc0000225;
}

