
  void* sub_180018ff0(void* arg1, void* arg2)

{
    char* r9 = *(arg1 + 0x10);
    int32_t rbx = *(arg2 + 8);
    *(arg1 + 8) = r9;
    int32_t rdi = 0;
    uint64_t rcx_1 = *r9 & 0xf;
    char* r9_1 = r9 - *(rcx_1 + 0x180038880);
    *(arg1 + 0x18) = *(r9_1 - 4) >> *(rcx_1 + 0x180038890);
    *(arg1 + 8) = r9_1;
    uint64_t rcx_4 = *r9_1 & 0xf;
    char rcx_5 = *(rcx_4 + 0x180038890);
    char* r9_2 = r9_1 - *(rcx_4 + 0x180038880);
    int32_t rdx_3 = *(r9_2 - 4);
    *(arg1 + 8) = r9_2;
    *(arg1 + 0x1c) = rdx_3 >> rcx_5;
    uint64_t rcx_7 = *r9_2 & 0xf;
    char rcx_8 = *(rcx_7 + 0x180038890);
    int32_t* r9_3 = r9_2 - *(rcx_7 + 0x180038880);
    int32_t rdx_6 = r9_3[-1];
    char* r11 = &r9_3[1];
    *(arg1 + 8) = r9_3;
    *(arg1 + 0x20) = rdx_6 >> rcx_8;
    int32_t rcx_9 = *r9_3;
    *(arg1 + 8) = r11;
    *(arg1 + 0x24) = rcx_9;
    
    if (rbx)
    {
        do
        {
            uint64_t rcx_11 = *r11 & 0xf;
            rdi += 1;
            int64_t r10_1 = *(rcx_11 + 0x180038880);
            char rcx_12 = *(rcx_11 + 0x180038890);
            char* r8_2 = r11 - r10_1;
            int32_t rdx_8 = *(r8_2 - 4);
            *(arg1 + 8) = r8_2;
            *(arg1 + 0x18) = rdx_8 >> rcx_12;
            uint64_t rcx_14 = *r8_2 & 0xf;
            int64_t r9_4 = *(rcx_14 + 0x180038880);
            char rcx_15 = *(rcx_14 + 0x180038890);
            char* r8_5 = r11 - r9_4 - r10_1;
            int32_t rdx_10 = *(r8_5 - 4);
            *(arg1 + 8) = r8_5;
            *(arg1 + 0x1c) = rdx_10 >> rcx_15;
            uint64_t rcx_17 = *r8_5 & 0xf;
            char rcx_18 = *(rcx_17 + 0x180038890);
            int32_t* r11_3 = r11 - *(rcx_17 + 0x180038880) - r9_4 - r10_1;
            int32_t rdx_13 = r11_3[-1];
            *(arg1 + 8) = r11_3;
            *(arg1 + 0x20) = rdx_13 >> rcx_18;
            int32_t rcx_19 = *r11_3;
            *(arg1 + 8) = &r11_3[1];
            *(arg1 + 0x24) = rcx_19;
            uint64_t rcx_21 = r11_3[1] & 0xf;
            int64_t r10_2 = *(rcx_21 + 0x180038880);
            char rcx_22 = *(rcx_21 + 0x180038890);
            char* r8_7 = &r11_3[1] - r10_2;
            int32_t rdx_15 = *(r8_7 - 4);
            *(arg1 + 8) = r8_7;
            *(arg1 + 0x18) = rdx_15 >> rcx_22;
            uint64_t rcx_24 = *r8_7 & 0xf;
            int64_t r9_5 = *(rcx_24 + 0x180038880);
            char* r8_10 = &r11_3[1] - r9_5 - r10_2;
            uint32_t rdx_18 = *(r8_10 - 4) >> *(rcx_24 + 0x180038890);
            *(arg1 + 8) = r8_10;
            *(arg1 + 0x1c) = rdx_18;
            uint64_t rcx_27 = *r8_10 & 0xf;
            int32_t* r11_7 = &r11_3[1] - *(rcx_27 + 0x180038880) - r9_5 - r10_2;
            uint32_t rdx_21 = r11_7[-1] >> *(rcx_27 + 0x180038890);
            *(arg1 + 8) = r11_7;
            *(arg1 + 0x20) = rdx_21;
            int32_t rcx_29 = *r11_7;
            r11 = &r11_7[1];
            *(arg1 + 8) = r11;
            *(arg1 + 0x24) = rcx_29;
        } while (rdi != rbx);
    }
    
    return arg1;
}

