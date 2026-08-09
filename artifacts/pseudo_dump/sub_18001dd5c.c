
  uint64_t sub_18001dd5c(void* arg1, char arg2)

{
    int32_t r8 = *(arg1 + 0x34);
    int64_t rbp;
    rbp = arg2;
    int32_t rdx;
    uint64_t rsi_1;
    int64_t rdi_1;
    
    if (r8 <= 5)
    {
        if (r8 == 5)
            goto label_18001ddbe;
        
        if (!r8)
        {
        label_18001deaf:
            rdx = *(arg1 + 0x28);
            rdi_1 = 4;
            int32_t* rcx_3 = *(arg1 + 0x18);
            *(arg1 + 0x18) = &rcx_3[2];
            
            if (!(rdx >> 4 & 1))
                rsi_1 = *rcx_3;
            else
                rsi_1 = *rcx_3;
            
            goto label_18001dde6;
        }
        
        if (r8 == 1)
        {
            rdx = *(arg1 + 0x28);
            rdi_1 = 1;
            char* rcx_2 = *(arg1 + 0x18);
            *(arg1 + 0x18) = &rcx_2[8];
            
            if (!(1 & rdx >> 4))
                rsi_1 = *rcx_2;
            else
                rsi_1 = *rcx_2;
            
            goto label_18001dde6;
        }
        
        int32_t temp4_1 = r8 - 1;
        r8 -= 2;
        
        if (temp4_1 != 1)
            goto label_18001ddaa;
        
        rdx = *(arg1 + 0x28);
        rdi_1 = 2;
        int16_t* rcx_1 = *(arg1 + 0x18);
        *(arg1 + 0x18) = &rcx_1[4];
        
        if (!(rdx >> 4 & 1))
            rsi_1 = *rcx_1;
        else
            rsi_1 = *rcx_1;
        
        goto label_18001dde6;
    }
    
    uint64_t result;
    
    if (r8 == 6)
    {
    label_18001ddbe:
        rdx = *(arg1 + 0x28);
        rdi_1 = 8;
        uint64_t* rcx = *(arg1 + 0x18);
        *(arg1 + 0x18) = &rcx[1];
        rsi_1 = *rcx;
    label_18001dde6:
        
        if (rdx >> 4 & 1 && rsi_1 < 0)
        {
            rsi_1 = -(rsi_1);
            rdx |= 0x40;
            *(arg1 + 0x28) = rdx;
        }
        
        if (*(arg1 + 0x30) >= 0)
        {
            void* r8_1 = *(arg1 + 8);
            *(arg1 + 0x28) = rdx & 0xfffffff7;
            __crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>(arg1 + 0x50, 
                *(arg1 + 0x30), r8_1);
        }
        else
            *(arg1 + 0x30) = 1;
        
        if (!rsi_1)
            *(arg1 + 0x28) &= 0xffffffdf;
        
        *(arg1 + 0x4c) = 0;
        r8 = rbp;
        
        if (rdi_1 != 8)
            __crt_stdio_output::output_processor<uint32_t,16,char,class __crt_stdio_output::console_output_adapter<char>,class __crt_stdio_output::format_validation_base<char,class __crt_stdio_output::console_output_adapter<char> > >::type_case_integer_parse_into_buffer<uint32_t,16>(
                arg1, rsi_1, r8);
        else
            __crt_stdio_output::output_processor<uint64_t,16,char,class __crt_stdio_output::console_output_adapter<char>,class __crt_stdio_output::format_validation_base<char,class __crt_stdio_output::console_output_adapter<char> > >::type_case_integer_parse_into_buffer<uint64_t,16>(
                arg1, rsi_1, r8);
        
        if ((*(arg1 + 0x28) >> 7) & 1 && (!*(arg1 + 0x48) || **(arg1 + 0x40) != 0x30))
        {
            *(arg1 + 0x40) -= 1;
            **(arg1 + 0x40) = 0x30;
            *(arg1 + 0x48) += 1;
        }
        
        result = 1;
    }
    else
    {
        if (r8 == 7)
            goto label_18001ddbe;
        
        int32_t temp2_1 = r8 - 7;
        r8 -= 9;
        
        if (temp2_1 == 2)
            goto label_18001ddbe;
        
    label_18001ddaa:
        
        if (r8 == 1)
            goto label_18001deaf;
        
        if (r8 == 2)
            goto label_18001ddbe;
        
        void* rax_9 = *(arg1 + 8);
        *(rax_9 + 0x30) = 1;
        *(rax_9 + 0x2c) = 0x16;
        _invalid_parameter_internal(0, 0, 0, 0, 0, *(arg1 + 8));
        result = 0;
    }
    
    return result;
}

