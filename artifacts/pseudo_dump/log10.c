
  double log10(double arg1[0x2] @ zmm0, double arg2[0x2] @ zmm6)

{
    double var_38[0x2] = arg2;
    
    if (data_180047ff8)
    {
        uint64_t temp0_9[0x2] = __vpsrlq_xmmdq_xmmdq_immb(arg1, 0x34);
        double rax_4 = arg1[0];
        __vcvtdq2pd_xmmdq_xmmq(__vpsubq_xmmdq_xmmdq_memdq(temp0_9, data_18003ef70)[0]);
        __vcomisd_xmmq_memq((arg1 & data_18003ef40)[0], inf.0);
        
        if (rax_4 == 0x7ff0000000000000)
            return rax_4;
        
        if (rax_4 != -0x10000000000000)
            return _log10_special(arg1[0], rax_4 | 0x8000000000000, 3);
        
        uint128_t temp0_33 = __vmovsd_xmmdq_memq(-nan(ind).0);
        int64_t rax_8;
        int512_t zmm6_1;
        rax_8 = _log10_special(arg1[0], temp0_33, 2);
        zmm6_1 = var_38;
        return rax_8;
    }
    
    uint64_t zmm4[0x2] = arg1;
    uint64_t temp0[0x2] = _mm_srli_epi64(arg1, 0x34);
    double rax = arg1[0];
    uint64_t zmm3[0x2] = __psubq_xmmdq_memdq(temp0, data_18003ef70);
    uint64_t temp0_2[0x2] = __andpd_xmmxuq_memxuq(arg1, data_18003ef40);
    
    if (temp0_2[0] == inf.0)
    {
        if (rax == 0x7ff0000000000000)
            return rax;
        
        if (rax != -0x10000000000000)
            return rax | 0x8000000000000;
    }
    else
    {
        arg2 = _mm_cvtepi32_pd(zmm3[0]);
        uint64_t temp0_4[0x2] = _mm_xor_pd(temp0_2, temp0_2);
        arg1[0] - temp0_4[0];
        
        if (!(arg1[0] <= temp0_4[0]))
        {
            uint128_t zmm2 = arg1 & data_18003ef90;
            zmm4[0] = zmm4[0] - 1.0;
            
            if (arg2[0] == -1023.0)
            {
                zmm2 = (zmm2 | data_18003f020) - 1.0;
                temp0_4[0] = zmm2;
                zmm2 &= data_18003ef90;
                rax = zmm2;
                arg2 = _mm_cvtepi32_pd(__psubd_xmmdq_memdq(_mm_srli_epi64(temp0_4, 0x34), 
                    data_18003f0c0)[0]);
            }
            
            int64_t rax_2 = (rax & 0xff00000000000) + ((rax & 0x80000000000) << 1);
            uint128_t zmm1;
            uint64_t zmm5[0x2];
            
            if (!(__andpd_xmmxuq_memxuq(zmm4, data_18003f110)[0] < 0.0625))
            {
                uint64_t rax_3 = rax_2 >> 0x2c;
                zmm1 = (rax_2 | data_18003f030) - (zmm2 | data_18003f030);
                zmm1 = zmm1 * *(&data_1800401e0 + (rax_3 << 3));
                zmm2 = zmm1;
                arg1 = zmm1;
                zmm3 = 0x3fc5555555555555;
                zmm3[0] = zmm3[0] * zmm2;
                zmm1 = 0x3fd5555555555555 * zmm2;
                arg1[0] = arg1[0] * zmm2;
                zmm4 = arg1;
                zmm3[0] = zmm3[0] + 0.20000000000000001;
                zmm1 = zmm1 + 0.5;
                zmm4[0] = zmm4[0] * arg1[0];
                zmm3[0] = zmm3[0] * zmm2;
                zmm1 = zmm1 * arg1[0];
                zmm3[0] = zmm3[0] + 0.25;
                zmm1 = zmm1 + zmm2;
                zmm3[0] = zmm3[0] * zmm4[0];
                zmm1 = zmm1 + zmm3[0];
                zmm5 = 0x3e03ef3fde623e25;
                zmm1 = zmm1 * 0.43429448190325182;
                zmm5[0] = zmm5[0] * arg2[0];
                zmm5[0] = zmm5[0] - zmm1;
                arg1 = *(&data_18003f1c0 + (rax_3 << 3));
                zmm2 = *(&data_18003f9d0 + (rax_3 << 3));
                zmm4 = 0x3fd3441350000000;
                zmm4[0] = zmm4[0] * arg2[0];
                arg1[0] = arg1[0] + zmm4[0];
                zmm2 = zmm2 + zmm5[0];
                arg1[0] = arg1[0] + zmm2;
                return rax_3;
            }
            
            arg1[0] = arg1[0] - 1.0;
            zmm2 = 0x4000000000000000 + arg1[0];
            zmm1 = arg1 / zmm2;
            zmm4 = 0x3f89999999bac6d4;
            zmm5 = 0x3f3c8034c85dfff0;
            arg1[0] = arg1[0] * zmm1;
            zmm1 = zmm1 + zmm1;
            zmm2 = zmm1 * zmm1;
            zmm4[0] = zmm4[0] * zmm2;
            zmm5[0] = zmm5[0] * zmm2;
            zmm4[0] = zmm4[0] + 0.083333333333331788;
            zmm5[0] = zmm5[0] + 0.0022321399879194482;
            zmm2 = zmm2 * zmm1;
            zmm4[0] = zmm4[0] * zmm2;
            zmm2 = zmm2 * zmm2;
            zmm2 = zmm2 * zmm1;
            zmm5[0] = zmm5[0] * zmm2;
            zmm2 = 0x3ea8a93728719535;
            zmm4[0] = zmm4[0] + zmm5[0];
            zmm4[0] = zmm4[0] - arg1[0];
            arg2 = 0x3fdbcb7800000000;
            zmm3 = arg1 & data_18003f160;
            arg1[0] = arg1[0] - zmm3[0];
            zmm4[0] = zmm4[0] + arg1[0];
            arg1 = zmm3;
            zmm4[0] = zmm4[0] * zmm2;
            arg1[0] = arg1[0] * zmm2;
            zmm1 = zmm4 * arg2[0];
            zmm3[0] = zmm3[0] * arg2[0];
            arg1[0] = arg1[0] + zmm4[0];
            arg1[0] = arg1[0] + zmm1;
            arg1[0] = arg1[0] + zmm3[0];
            return rax_2;
        }
        
        if (!(arg1[0] != temp0_4[0]))
            return _log10_special(arg1[0], -0x10000000000000, 1);
    }
    
    return _log10_special(arg1[0], -0x8000000000000, 2);
}

