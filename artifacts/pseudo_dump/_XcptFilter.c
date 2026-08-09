
  uint64_t _XcptFilter(int32_t arg1, int64_t arg2)

{
    void** rax = sub_18002334c();
    
    if (rax)
    {
        void* i_1 = *rax;
        void* i = i_1;
        
        if (i_1 != i_1 + 0xc0)
        {
            do
            {
                if (*i == arg1)
                {
                    if (i)
                    {
                        int64_t r8_2 = *(i + 8);
                        
                        if (r8_2)
                        {
                            if (r8_2 == 5)
                            {
                                *(i + 8) = 0;
                                return r8_2 - 4;
                            }
                            
                            if (r8_2 != 1)
                            {
                                int64_t rbp_1 = rax[1];
                                rax[1] = arg2;
                                
                                if (*(i + 4) != 8)
                                {
                                    *(i + 4);
                                    *(i + 8) = 0;
                                    sub_18002d680();
                                }
                                else
                                {
                                    void* j = i_1 + 0x30;
                                    
                                    for (void* rdx = j + 0x90; j != rdx; j += 0x10)
                                        *(j + 8) = 0;
                                    
                                    int32_t rdi_1 = rax[2];
                                    
                                    if (*i == 0xc000008d)
                                        rax[2] = 0x82;
                                    else if (*i == 0xc000008e)
                                        rax[2] = 0x83;
                                    else if (*i == 0xc000008f)
                                        rax[2] = 0x86;
                                    else if (*i == 0xc0000090)
                                        rax[2] = 0x81;
                                    else if (*i == 0xc0000091)
                                        rax[2] = 0x84;
                                    else if (*i == 0xc0000092)
                                        rax[2] = 0x8a;
                                    else if (*i == 0xc0000093)
                                        rax[2] = 0x85;
                                    else if (*i == 0xc00002b4)
                                        rax[2] = 0x8e;
                                    else if (*i == 0xc00002b5)
                                        rax[2] = 0x8d;
                                    
                                    sub_18002d680();
                                    rax[2] = rdi_1;
                                }
                                
                                rax[1] = rbp_1;
                            }
                            
                            return 0xffffffff;
                        }
                    }
                    
                    break;
                }
                
                i += 0x10;
            } while (i != i_1 + 0xc0);
        }
    }
    
    return 0;
}

