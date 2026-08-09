
  uint64_t sub_18001f11c(void* arg1)

{
    int16_t** rdx = *(arg1 + 0x18);
    *(arg1 + 0x18) = &rdx[1];
    int16_t* rdi = *rdx;
    uint64_t result;
    
    if (_get_printf_count_output())
    {
        int32_t rcx = *(arg1 + 0x34);
        int32_t rcx_2;
        
        if (rcx > 5)
        {
            if (rcx != 6 && rcx != 7)
            {
                rcx_2 = rcx - 9;
                
                if (rcx == 9)
                    goto label_18001f1b7;
                
            label_18001f1a9:
                
                if (rcx_2 == 1)
                    goto label_18001f1ce;
                
                if (rcx_2 != 2)
                    goto label_18001f141;
                
                goto label_18001f1b7;
            }
            
        label_18001f1b7:
            *rdi = *(arg1 + 0x20);
            *(arg1 + 0x38) = 1;
            result = 1;
        }
        else
        {
            if (rcx == 5)
                goto label_18001f1b7;
            
            if (!rcx)
            {
            label_18001f1ce:
                *rdi = *(arg1 + 0x20);
                *(arg1 + 0x38) = 1;
                result = 1;
            }
            else if (rcx == 1)
            {
                result = *(arg1 + 0x20);
                *rdi = result;
                *(arg1 + 0x38) = 1;
                result = 1;
            }
            else
            {
                rcx_2 = rcx - 2;
                
                if (rcx != 2)
                    goto label_18001f1a9;
                
                *rdi = *(arg1 + 0x20);
                *(arg1 + 0x38) = 1;
                result = 1;
            }
        }
    }
    else
    {
    label_18001f141:
        void* rax_1 = *(arg1 + 8);
        *(rax_1 + 0x30) = 1;
        *(rax_1 + 0x2c) = 0x16;
        _invalid_parameter_internal(0, 0, 0, 0, 0, *(arg1 + 8));
        result = 0;
    }
    
    return result;
}

