
  int64_t sub_18001f640(char* arg1)

{
    int64_t* rax = __dcrt_get_or_create_narrow_environment_nolock();
    int64_t* rdi = rax;
    
    if (rax && arg1)
    {
        uint64_t rbx_1 = -1;
        
        do
            rbx_1 += 1;
         while (arg1[rbx_1]);
        
        for (char* i = *rax; i; i = *rdi)
        {
            int64_t rcx = -1;
            
            do
                rcx += 1;
             while (i[rcx]);
            
            if (rcx > rbx_1 && i[rbx_1] == 0x3d && !sub_1800237d0(i, arg1, rbx_1))
                return *rdi + 1 + rbx_1;
            
            rdi = &rdi[1];
        }
    }
    
    return 0;
}

