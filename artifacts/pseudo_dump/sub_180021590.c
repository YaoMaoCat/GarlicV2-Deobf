
  int64_t sub_180021590(int16_t* arg1, uint64_t arg2)

{
    int32_t rax_22 = data_180046858;
    
    if (rax_22 >= 5)
    {
        int16_t* i_2;
        
        if (!(arg1 & 1))
        {
            int64_t r10_1 = 0;
            uint64_t rcx = arg1 & 0x1f;
            int16_t* rdx_2 = arg1;
            
            if (rcx)
                r10_1 = 0x20 - rcx;
            
            uint64_t r10_2 = r10_1 >> 1;
            
            if (arg2 < r10_2)
                r10_2 = arg2;
            
            void* rax_3 = &arg1[r10_2];
            
            if (arg1 != rax_3)
            {
                while (*rdx_2)
                {
                    rdx_2 = &rdx_2[1];
                    
                    if (rdx_2 == rax_3)
                        break;
                }
            }
            
            int64_t rdx_4 = (rdx_2 - arg1) >> 1;
            
            if (rdx_4 != r10_2)
                return rdx_4;
            
            int16_t* i = &arg1[rdx_4];
            uint64_t rcx_2 = arg2 - r10_2;
            
            for (; i != &arg1[rcx_2 - (rcx_2 & 0x1f) + rdx_4]; i = &i[0x10])
            {
                uint16_t zmm1[0x10];
                zmm1[0] = {0};
                zmm1 = __vpcmpeqw_ymmqq_ymmqq_memqq(zmm1, *i);
                bool cond:0_1 = _mm256_movemask_epi8(zmm1);
                _mm256_zeroupper();
                
                if (cond:0_1)
                    break;
            }
            
            void* rax_7 = &arg1[arg2];
            
            if (i != rax_7)
            {
                while (*i)
                {
                    i = &i[1];
                    
                    if (i == rax_7)
                        break;
                }
            }
            
            i_2 = i;
        }
        else
        {
            void* rax = &arg1[arg2];
            i_2 = arg1;
            
            if (arg1 != rax)
            {
                while (*i_2)
                {
                    i_2 = &i_2[1];
                    
                    if (i_2 == rax)
                        return (i_2 - arg1) >> 1;
                }
            }
        }
        
        return (i_2 - arg1) >> 1;
    }
    
    int16_t* rax_9;
    
    if (rax_22 < 1)
    {
        void* rcx_11 = &arg1[arg2];
        rax_9 = arg1;
        
        if (arg1 != rcx_11)
        {
            while (*rax_9)
            {
                rax_9 = &rax_9[1];
                
                if (rax_9 == rcx_11)
                    break;
            }
        }
    }
    else
    {
        if (!(arg1 & 1))
        {
            int64_t r10_3 = 0;
            uint64_t rcx_6 = arg1 & 0xf;
            
            if (rcx_6)
                r10_3 = 0x10 - rcx_6;
            
            int16_t* rax_13 = arg1;
            uint64_t r10_4 = r10_3 >> 1;
            
            if (arg2 < r10_4)
                r10_4 = arg2;
            
            void* rcx_7 = &arg1[r10_4];
            
            if (arg1 != rcx_7)
            {
                while (*rax_13)
                {
                    rax_13 = &rax_13[1];
                    
                    if (rax_13 == rcx_7)
                        break;
                }
            }
            
            int64_t rax_15 = (rax_13 - arg1) >> 1;
            
            if (rax_15 != r10_4)
                return rax_15;
            
            uint64_t rdx_7 = arg2 - r10_4;
            int16_t (* i_1)[0x8];
            
            for (i_1 = &arg1[rax_15]; i_1 != &arg1[rdx_7 - (rdx_7 & 0xf) + rax_15]; i_1 = &i_1[1])
            {
                if (_mm_movemask_epi8(__pcmpeqw_xmmdq_memdq({0}, *i_1)))
                    break;
            }
            
            void* rax_17 = &arg1[arg2];
            
            if (i_1 != rax_17)
            {
                while (*i_1)
                {
                    i_1 = &(*i_1)[1];
                    
                    if (i_1 == rax_17)
                        break;
                }
            }
            
            return (i_1 - arg1) >> 1;
        }
        
        void* rcx_5 = &arg1[arg2];
        rax_9 = arg1;
        
        if (arg1 != rcx_5)
        {
            while (*rax_9)
            {
                rax_9 = &rax_9[1];
                
                if (rax_9 == rcx_5)
                    return (rax_9 - arg1) >> 1;
            }
        }
    }
    
    return (rax_9 - arg1) >> 1;
}

