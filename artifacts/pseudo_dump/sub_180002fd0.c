
  int128_t* sub_180002fd0(int128_t* arg1)

{
    __chkstk(0x1458);
    void var_1498;
    int64_t rax_1 = __security_cookie ^ &var_1498;
    int128_t* var_1418 = arg1;
    int32_t var_1450 = 0;
    void var_13e8;
    int64_t rdx = sub_180003ac0(&var_13e8);
    void* var_1458 = &var_13e8;
    int64_t rax_3;
    int64_t rdx_1;
    rdx_1 = HIGHQ(3 * sub_180003530(&var_1458, rdx));
    rax_3 = LOWQ(3 * sub_180003530(&var_1458, rdx));
    
    if (rax_3 < 3 && !rax_3)
    {
        int64_t i;
        
        do
            rdx_1 = HIGHQ(3 * sub_180003530(&var_1458, rdx_1));
            i = LOWQ(3 * sub_180003530(&var_1458, rdx_1));
         while (!i);
    }
    
    int32_t r12_3 = ((rdx_1 >> 0x40) - 0x7fffffff) ^ 0x80000000;
    var_1458 = r12_3;
    *arg1 = {0};
    arg1[1] = 0;
    *(arg1 + 0x18) = 0xf;
    *arg1 = 0;
    int32_t var_1450_1 = 1;
    
    if (r12_3 > 0)
    {
        int32_t r15_1 = 0;
        int32_t var_1460_1 = 0;
        
        do
        {
            if (r15_1)
            {
                int64_t rcx_5 = arg1[1];
                rdx_1 = *(arg1 + 0x18);
                
                if (rdx_1 - rcx_5 < 1)
                    rdx_1 = sub_180002840(arg1, 1, 0, &data_1800313c0, 1);
                else
                {
                    arg1[1] = rcx_5 + 1;
                    
                    if (rdx_1 <= 0xf)
                        *(arg1 + rcx_5) = 0x2f;
                    else
                        *(*arg1 + rcx_5) = 0x2f;
                }
            }
            
            void* var_1468 = &var_13e8;
            uint64_t rax_11;
            int64_t rdx_2;
            rdx_2 = HIGHQ(2 * sub_180003530(&var_1468, rdx_1));
            rax_11 = LOWQ(2 * sub_180003530(&var_1468, rdx_1));
            int64_t var_1438_1 = 0x40;
            int64_t var_1430_1 = 0;
            int32_t r14_2 = (0x80000001 + (rdx_2 >> 0x40)) ^ 0x80000000;
            var_1468 = &var_13e8;
            uint64_t rax_14;
            int64_t rdx_3;
            rdx_3 = HIGHQ(0x60 * sub_180003530(&var_1468, rdx_2));
            rax_14 = LOWQ(0x60 * sub_180003530(&var_1468, rdx_2));
            
            if (rax_14 < 0x60 && !(rax_14 & 0xffffffffffffffc0))
            {
                do
                    rdx_3 = HIGHQ(0x60 * sub_180003530(&var_1468, rdx_3));
                    rax_14 = LOWQ(0x60 * sub_180003530(&var_1468, rdx_3));
                 while (!(rax_14 & 0xffffffffffffffc0));
            }
            
            int64_t var_1428_1 = 0x40;
            int64_t var_1420_1 = 0;
            int32_t* rbx_1 = (&data_180030d20)[rdx_3 >> 0x40];
            int128_t var_1410 = {0};
            void* var_1400_1 = nullptr;
            int64_t var_13f8_1 = 0;
            sub_180002740(&var_1410, rbx_1, strlen(rbx_1));
            int32_t* rbx_2 = &var_1410;
            int32_t* rcx_15 = var_1410;
            int64_t r8_2 = var_13f8_1;
            
            if (r8_2 > 0xf)
                rbx_2 = rcx_15;
            
            int32_t* rdi_1 = &var_1410;
            
            if (r8_2 > 0xf)
                rdi_1 = rcx_15;
            
            void* r9_1 = var_1400_1;
            void* rdi_2 = rdi_1 + r9_1;
            
            if (rbx_2 != rdi_2)
            {
                do
                {
                    *rbx_2 = tolower(*rbx_2);
                    rbx_2 += 1;
                } while (rbx_2 != rdi_2);
                
                r8_2 = var_13f8_1;
                r9_1 = var_1400_1;
                rcx_15 = var_1410;
            }
            
            int32_t* rdx_6 = &var_1410;
            
            if (r8_2 > 0xf)
                rdx_6 = rcx_15;
            
            int64_t rdx_7 = sub_1800026b0(arg1, rdx_6, r9_1);
            int32_t rdi_3 = 1;
            
            if (r14_2 > 1)
            {
                do
                {
                    var_1468 = &var_13e8;
                    uint64_t rax_19;
                    int64_t rdx_8;
                    rdx_8 = HIGHQ(0x60 * sub_180003530(&var_1468, rdx_7));
                    rax_19 = LOWQ(0x60 * sub_180003530(&var_1468, rdx_7));
                    
                    if (rax_19 < 0x60 && !(rax_19 & 0xffffffffffffffc0))
                    {
                        do
                            rdx_8 = HIGHQ(0x60 * sub_180003530(&var_1468, rdx_8));
                            rax_19 = LOWQ(0x60 * sub_180003530(&var_1468, rdx_8));
                         while (!(rax_19 & 0xffffffffffffffc0));
                    }
                    
                    int64_t var_1448_1 = 0x40;
                    int64_t var_1440_1 = 0;
                    char* rbx_3 = (&data_180030d20)[rdx_8 >> 0x40];
                    rdx_7 = sub_1800026b0(arg1, rbx_3, strlen(rbx_3));
                    rdi_3 += 1;
                } while (rdi_3 < r14_2);
                
                r15_1 = var_1460_1;
                r12_3 = var_1458;
            }
            
            rdx_1 = var_13f8_1;
            
            if (rdx_1 > 0xf)
            {
                void* rcx_24 = var_1410;
                
                if (rdx_1 + 1 >= 0x1000)
                {
                    void* rax_22 = *(rcx_24 - 8);
                    
                    if (rcx_24 - rax_22 - 8 > 0x1f)
                        trap(0xd);
                    
                    rcx_24 = rax_22;
                }
                
                rdx_1 = j_sub_180021340(rcx_24);
            }
            
            r15_1 += 1;
            var_1460_1 = r15_1;
        } while (r15_1 < r12_3);
    }
    
    __security_check_cookie(rax_1 ^ &var_1498);
    return arg1;
}

