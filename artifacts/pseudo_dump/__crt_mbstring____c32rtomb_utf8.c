
  int64_t __crt_mbstring::__c32rtomb_utf8(char* arg1, uint32_t arg2, int64_t* arg3, void* arg4)

{
    char* r10 = arg1;
    
    if (!arg1)
        *arg3 = 0;
    else if (arg2)
    {
        if (arg2 & 0xffffff80)
        {
            char* i_2;
            
            if (!(arg2 & 0xfffff800))
            {
                i_2 = 1;
                arg1 = 0xc0;
            }
            else if (arg2 & 0xffff0000)
            {
                if (arg2 & 0xffe00000 || arg2 > 0x10ffff)
                    /* tailcall */
                    return __crt_mbstring::return_illegal_sequence(arg3, arg4);
                
                i_2 = 3;
                arg1 = 0xf0;
            }
            else
            {
                if (arg2 - 0xd800 <= 0x7ff)
                    /* tailcall */
                    return __crt_mbstring::return_illegal_sequence(arg3, arg4);
                
                i_2 = 2;
                arg1 = 0xe0;
            }
            
            char* i_1 = i_2;
            char* i;
            
            do
            {
                int32_t rax_1;
                rax_1 = arg2;
                arg2 u>>= 6;
                rax_1 &= 0x3f;
                rax_1 |= 0x80;
                *(i_1 + r10) = rax_1;
                i = i_1;
                i_1 -= 1;
            } while (i != 1);
            arg1 |= arg2;
            *r10 = arg1;
            /* tailcall */
            return __crt_mbstring::reset_and_return(&i_2[1], arg3);
        }
        
        *arg1 = arg2;
    }
    else
    {
        *arg1 = 0;
        *arg3 = 0;
    }
    
    return 1;
}

