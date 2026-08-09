
  void* sub_18001e778(char* arg1)

{
    void* result;
    result = arg1[0x39];
    
    if (result == 0x46)
    {
        if (!(*arg1 & 8))
        {
            arg1[0x24] = 7;
            /* tailcall */
            return sub_18001e900(arg1);
        }
        
        result = 1;
    }
    else if (result != 0x4e)
    {
        if (*(arg1 + 0x34))
            goto label_18001e7aa;
        
        switch (result)
        {
            case 0x49:
            {
                char* r8_2 = *(arg1 + 0x10);
                result = *r8_2;
                
                if (result == 0x33 && r8_2[1] == 0x32)
                {
                    *(arg1 + 0x34) = 0xa;
                    *(arg1 + 0x10) = &r8_2[2];
                }
                else if (result != 0x36)
                {
                    result -= 0x58;
                    
                    if (result <= 0x20 && TEST_BITQ(0x120821001, result))
                        *(arg1 + 0x34) = 9;
                }
                else if (r8_2[1] == 0x34)
                {
                    *(arg1 + 0x34) = 0xb;
                    *(arg1 + 0x10) = &r8_2[2];
                }
                break;
            }
            case 0x4c:
            {
                *(arg1 + 0x34) = 8;
                break;
            }
            case 0x54:
            {
                *(arg1 + 0x34) = 0xd;
                break;
            }
            case 0x68:
            {
                char* rax_5 = *(arg1 + 0x10);
                
                if (*rax_5 != 0x68)
                    result = 2;
                else
                {
                    *(arg1 + 0x10) = &rax_5[1];
                    result = 1;
                }
                
                *(arg1 + 0x34) = result;
                break;
            }
            case 0x6a:
            {
                *(arg1 + 0x34) = 5;
                break;
            }
            case 0x6c:
            {
                char* rax_3 = *(arg1 + 0x10);
                
                if (*rax_3 != 0x6c)
                    result = 3;
                else
                {
                    *(arg1 + 0x10) = &rax_3[1];
                    result = 4;
                }
                
                *(arg1 + 0x34) = result;
                break;
            }
            case 0x74:
            {
                *(arg1 + 0x34) = 7;
                break;
            }
            case 0x77:
            {
                *(arg1 + 0x34) = 0xc;
                break;
            }
            case 0x7a:
            {
                *(arg1 + 0x34) = 6;
                break;
            }
        }
        
        result = 1;
    }
    else if (*arg1 & 8)
        result = 1;
    else
    {
        arg1[0x24] = 8;
    label_18001e7aa:
        void* rax_1 = *(arg1 + 8);
        *(rax_1 + 0x30) = 1;
        *(rax_1 + 0x2c) = 0x16;
        _invalid_parameter_internal(0, 0, 0, 0, 0, *(arg1 + 8));
        result = 0;
    }
    
    return result;
}

