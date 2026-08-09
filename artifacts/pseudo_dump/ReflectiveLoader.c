
  void* ReflectiveLoader(int64_t arg1)

{
    void* r12 = nullptr;
    void* r15 = nullptr;
    void* rsi = nullptr;
    void* r13 = nullptr;
    int16_t* rbp = &data_180001079;
    
    while (true)
    {
        if (*rbp == 0x5a4d)
        {
            int64_t rdx_1 = *(rbp + 0x3c);
            
            if (rdx_1 - 0x40 <= 0x3bf)
            {
                void* rdi_1 = rdx_1 + rbp;
                void* arg_18 = rdi_1;
                
                if (*(rdx_1 + rbp) == 0x4550)
                {
                    int16_t j_2 = 1;
                    TEB* gsbase;
                    struct _LDR_DATA_TABLE_ENTRY* Flink_2 =
                        gsbase->ProcessEnvironmentBlock->Ldr->InMemoryOrderModuleList.Flink;
                    
                    if (Flink_2)
                    {
                        int16_t j_1 = 3;
                        
                        do
                        {
                            WCHAR* Buffer = Flink_2->FullDllName.Buffer;
                            int32_t rax_1 = 0;
                            uint16_t Length = Flink_2->FullDllName.Length;
                            uint16_t j;
                            
                            do
                            {
                                uint32_t rcx_2 = *Buffer;
                                uint64_t rax_2 = RORD(rax_1, 0xd);
                                
                                if (rcx_2 >= 0x61)
                                    rax_2 -= 0x20;
                                
                                rax_1 = rax_2 + rcx_2;
                                Buffer += 1;
                                j = Length;
                                Length -= 1;
                            } while (j != 1);
                            
                            if (rax_1 == 0x6a4abc5b)
                            {
                                void* __offset(_LDR_DATA_TABLE_ENTRY, 0x10) Flink =
                                    Flink_2->InInitializationOrderModuleList.Flink;
                                uint64_t rdi_2 = *(*(&ADJ(Flink)->FullDllName + 4) + Flink + 0x88);
                                int32_t* r10_2 = *(rdi_2 + Flink + 0x20) + Flink;
                                int16_t* r11_1 = *(rdi_2 + Flink + 0x24) + Flink;
                                
                                do
                                {
                                    char* rdx_3 = *r10_2 + Flink;
                                    int32_t rcx_3 = 0;
                                    
                                    do
                                    {
                                        int32_t rax_4 = *rdx_3;
                                        rdx_3 = &rdx_3[1];
                                        rcx_3 = RORD(rcx_3, 0xd) + rax_4;
                                    } while (*rdx_3);
                                    
                                    if (rcx_3 == 0xec0e4e8e || rcx_3 == 0x7c0dfcaa
                                        || rcx_3 == 0x91afca54)
                                    {
                                        uint64_t rdx_4 = *r11_1;
                                        void* r8_2 = *(rdi_2 + Flink + 0x1c) + Flink;
                                        
                                        if (rcx_3 == 0xec0e4e8e)
                                            r12 = *(r8_2 + (rdx_4 << 2)) + Flink;
                                        else if (rcx_3 == 0x7c0dfcaa)
                                            r15 = *(r8_2 + (rdx_4 << 2)) + Flink;
                                        else if (rcx_3 == 0x91afca54)
                                            rsi = *(r8_2 + (rdx_4 << 2)) + Flink;
                                        
                                        j_1 -= 1;
                                    }
                                    
                                    r10_2 = &r10_2[1];
                                    r11_1 = &r11_1[1];
                                } while (j_1);
                                
                                j_2 = 1;
                                j_1 = 3;
                            }
                            else if (rax_1 == 0x3cfa685d)
                            {
                                void* __offset(_LDR_DATA_TABLE_ENTRY, 0x10) Flink_1 =
                                    Flink_2->InInitializationOrderModuleList.Flink;
                                uint64_t rbx_1 =
                                    *(*(&ADJ(Flink_1)->FullDllName + 4) + Flink_1 + 0x88);
                                int32_t* r8_4 = *(rbx_1 + Flink_1 + 0x20) + Flink_1;
                                int16_t* r9_2 = *(rbx_1 + Flink_1 + 0x24) + Flink_1;
                                
                                do
                                {
                                    char* rdx_6 = *r8_4 + Flink_1;
                                    int32_t rcx_5 = 0;
                                    
                                    do
                                    {
                                        int32_t rax_6 = *rdx_6;
                                        rdx_6 = &rdx_6[1];
                                        rcx_5 = RORD(rcx_5, 0xd) + rax_6;
                                    } while (*rdx_6);
                                    
                                    if (rcx_5 == 0x534c0ab8)
                                    {
                                        r13 = *(*(rbx_1 + Flink_1 + 0x1c) + Flink_1 + (*r9_2 << 2))
                                            + Flink_1;
                                        j_2 -= 1;
                                    }
                                    
                                    r8_4 = &r8_4[1];
                                    r9_2 = &r9_2[1];
                                } while (j_2);
                                
                                j_2 = 1;
                                j_1 = 3;
                            }
                            
                            if (r12 && r15 && rsi && r13)
                                break;
                            
                            Flink_2 = Flink_2->InLoadOrderLinks.Flink;
                        } while (Flink_2);
                        
                        rdi_1 = arg_18;
                    }
                    
                    char* rax_7 = rsi(0, *(rdi_1 + 0x50), 0x3000, 0x40);
                    uint64_t i_3 = *(rdi_1 + 0x54);
                    int16_t* r8_5 = rbp;
                    char* r9_3 = rax_7;
                    
                    if (i_3)
                    {
                        uint64_t i;
                        
                        do
                        {
                            char rcx_9 = *r8_5;
                            r8_5 += 1;
                            *r9_3 = rcx_9;
                            r9_3 = &r9_3[1];
                            i = i_3;
                            i_3 -= 1;
                        } while (i != 1);
                    }
                    
                    uint64_t i_1 = *(rdi_1 + 6);
                    void* r9_6 = *(rdi_1 + 0x14) + 0x18 + rdi_1;
                    
                    if (i_1)
                    {
                        do
                        {
                            i_1 -= 1;
                            char* rcx_11 = &rax_7[*(r9_6 + 0xc)];
                            uint64_t j_4 = *(r9_6 + 0x10);
                            char* rdx_10 = *(r9_6 + 0x14) + rbp;
                            
                            if (j_4)
                            {
                                uint64_t j_3;
                                
                                do
                                {
                                    char rax_8 = *rdx_10;
                                    rdx_10 = &rdx_10[1];
                                    *rcx_11 = rax_8;
                                    rcx_11 = &rcx_11[1];
                                    j_3 = j_4;
                                    j_4 -= 1;
                                } while (j_3 != 1);
                            }
                            
                            r9_6 += 0x28;
                        } while (i_1);
                    }
                    
                    int32_t* rbp_2 = &rax_7[*(rdi_1 + 0x90)];
                    
                    if (rbp_2[3])
                    {
                        do
                        {
                            void* rax_9 = r12(&rax_7[rbp_2[3]]);
                            int64_t* rdi_4 = &rax_7[rbp_2[4]];
                            int64_t* rbx_3 = &rax_7[*rbp_2];
                            
                            while (*rdi_4)
                            {
                                int64_t rdx_11;
                                
                                if (rbx_3)
                                    rdx_11 = *rbx_3;
                                
                                void* rax_13;
                                
                                if (!rbx_3 || rdx_11 >= 0)
                                    rax_13 = r15(rax_9, *rdi_4 + 2 + rax_7);
                                else
                                {
                                    uint64_t rcx_14 = *(*(rax_9 + 0x3c) + rax_9 + 0x88);
                                    rax_13 = *(*(rcx_14 + rax_9 + 0x1c) + rax_9
                                        + ((rdx_11 - *(rcx_14 + rax_9 + 0x10)) << 2)) + rax_9;
                                }
                                
                                *rdi_4 = rax_13;
                                rdi_4 = &rdi_4[1];
                                int64_t* rax_14 = &rbx_3[1];
                                
                                if (!rbx_3)
                                    rax_14 = rbx_3;
                                
                                rbx_3 = rax_14;
                            }
                            
                            rbp_2 = &rbp_2[5];
                        } while (rbp_2[3]);
                        
                        rdi_1 = arg_18;
                    }
                    
                    void* r9_8 = rax_7 - *(rdi_1 + 0x30);
                    
                    if (*(rdi_1 + 0xb4))
                    {
                        int32_t* r11_3 = &rax_7[*(rdi_1 + 0xb0)];
                        
                        while (r11_3[1])
                        {
                            int16_t* r10_3 = &r11_3[2];
                            int64_t rax_16 = r11_3[1] - 8;
                            int16_t* rcx_19 = &rax_7[*r11_3];
                            uint64_t i_2 = rax_16 >> 1;
                            
                            if (rax_16 >= 2)
                            {
                                do
                                {
                                    uint32_t rax_17 = *r10_3;
                                    i_2 -= 1;
                                    uint16_t rdx_17 = rax_17 >> 0xc;
                                    
                                    if (rdx_17 == 0xa)
                                    {
                                        uint64_t rax_18 = rax_17 & 0xfff;
                                        *(rcx_19 + rax_18) += r9_8;
                                    }
                                    else if (rdx_17 == 3)
                                    {
                                        uint64_t rax_19 = rax_17 & 0xfff;
                                        *(rcx_19 + rax_19) += r9_8;
                                    }
                                    else if (rdx_17 == 1)
                                    {
                                        uint64_t rax_20 = rax_17 & 0xfff;
                                        *(rcx_19 + rax_20) += r9_8 >> 0x10;
                                    }
                                    else if (rdx_17 == 2)
                                    {
                                        uint64_t rax_21 = rax_17 & 0xfff;
                                        *(rcx_19 + rax_21) += r9_8;
                                    }
                                    
                                    r10_3 = &r10_3[1];
                                } while (i_2);
                            }
                            
                            r11_3 += r11_3[1];
                        }
                    }
                    
                    void* result = &rax_7[*(rdi_1 + 0x28)];
                    r13(-1, 0, 0, r9_8);
                    
                    if (result(rax_7, 1, arg1))
                        return result;
                    
                    return nullptr;
                }
            }
        }
        
        rbp -= 1;
    }
}

