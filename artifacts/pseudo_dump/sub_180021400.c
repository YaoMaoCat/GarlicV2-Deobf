
  void* sub_180021400(char* arg1, void* arg2)

{
    int32_t rax_13 = data_180046858;
    
    if (rax_13 >= 5)
    {
        void* r10_1 = nullptr;
        uint64_t r8_2 = arg1 & 0x1f;
        char* r8_3 = arg1;
        
        if (r8_2)
            r10_1 = 0x20 - r8_2;
        
        if (arg2 < r10_1)
            r10_1 = arg2;
        
        void* rax_1 = r10_1 + arg1;
        
        if (arg1 != rax_1)
        {
            while (*r8_3)
            {
                r8_3 = &r8_3[1];
                
                if (r8_3 == rax_1)
                    break;
            }
        }
        
        void* rdx_1 = r8_3 - arg1;
        
        if (rdx_1 != r10_1)
            return rdx_1;
        
        char* rdx_2 = r8_3;
        void* rcx_1 = arg2 - r10_1;
        void* r10_4 = r8_3 - (rcx_1 & 0x1f) + rcx_1;
        
        if (r8_3 != r10_4)
        {
            do
            {
                uint8_t zmm1[0x20];
                zmm1[0] = {0};
                zmm1 = __vpcmpeqb_ymmqq_ymmqq_memqq(zmm1, *rdx_2);
                bool cond:1_1 = _mm256_movemask_epi8(zmm1);
                _mm256_zeroupper();
                
                if (cond:1_1)
                    break;
                
                rdx_2 = &rdx_2[0x20];
            } while (rdx_2 != r10_4);
        }
        
        void* rax_5 = arg1 + arg2;
        
        if (rdx_2 != rax_5)
        {
            while (*rdx_2)
            {
                rdx_2 = &rdx_2[1];
                
                if (rdx_2 == rax_5)
                    break;
            }
        }
        
        return rdx_2 - arg1;
    }
    
    char* rax_11;
    
    if (rax_13 < 1)
    {
        void* rcx_7 = arg1 + arg2;
        rax_11 = arg1;
        
        if (arg1 != rcx_7)
        {
            while (*rax_11)
            {
                rax_11 = &rax_11[1];
                
                if (rax_11 == rcx_7)
                    break;
            }
        }
    }
    else
    {
        void* r10_5 = nullptr;
        uint64_t rcx_2 = arg1 & 0xf;
        char* r8_4 = arg1;
        
        if (rcx_2)
            r10_5 = 0x10 - rcx_2;
        
        if (arg2 < r10_5)
            r10_5 = arg2;
        
        void* rax_8 = r10_5 + arg1;
        
        if (arg1 != rax_8)
        {
            while (*r8_4)
            {
                r8_4 = &r8_4[1];
                
                if (r8_4 == rax_8)
                    break;
            }
        }
        
        void* rax_10 = r8_4 - arg1;
        
        if (rax_10 != r10_5)
            return rax_10;
        
        void* rdx_3 = arg2 - r10_5;
        rax_11 = r8_4;
        void* r10_8 = r8_4 - (rdx_3 & 0xf) + rdx_3;
        
        if (r8_4 != r10_8)
        {
            do
            {
                if (_mm_movemask_epi8(__pcmpeqb_xmmdq_memdq({0}, *rax_11)))
                    break;
                
                rax_11 = &rax_11[0x10];
            } while (rax_11 != r10_8);
        }
        
        void* rcx_6 = arg1 + arg2;
        
        if (rax_11 != rcx_6)
        {
            while (*rax_11)
            {
                rax_11 = &rax_11[1];
                
                if (rax_11 == rcx_6)
                    return rax_11 - arg1;
            }
        }
    }
    
    return rax_11 - arg1;
}

