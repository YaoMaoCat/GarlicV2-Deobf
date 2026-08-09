
  int64_t sub_18001ba30(void* arg1, char* arg2, int32_t* arg3)

{
    int64_t rbx = *(arg1 + 8);
    
    if (rbx && _GetImageBase() != -(rbx))
    {
        int64_t rbx_1 = *(arg1 + 8);
        void* rax_4;
        
        if (!rbx_1)
            rax_4 = nullptr;
        else
            rax_4 = _GetImageBase() + rbx_1;
        
        if (*(rax_4 + 0x10) && (!(*(arg1 + 4) & 0x80) || !(*arg2 & 0x10)))
        {
            int64_t rsi = *(arg1 + 8);
            int64_t rbx_2;
            
            if (!rsi)
                rbx_2 = 0;
            else
                rbx_2 = _GetImageBase() + rsi;
            
            int64_t rax_6 = _GetThrowImageBase();
            uint32_t i;
            uint32_t rdx;
            
            if (rbx_2 != *(arg2 + 4) + rax_6)
            {
                int64_t rbx_3 = *(arg1 + 8);
                void* rsi_1;
                
                if (!rbx_3)
                    rsi_1 = nullptr;
                else
                    rsi_1 = _GetImageBase() + rbx_3;
                
                char* rax_9 = rsi_1 + 0x10;
                void* r8_2 = *(arg2 + 4) + 0x10 + _GetThrowImageBase() - rax_9;
                
                do
                {
                    rdx = *rax_9;
                    i = *(rax_9 + r8_2);
                    
                    if (rdx != i)
                        break;
                    
                    rax_9 = &rax_9[1];
                } while (i);
            }
            
            if ((rbx_2 == *(arg2 + 4) + rax_6 || !(rdx - i)) && (!(*arg2 & 2) || *(arg1 + 4) & 8))
            {
                char rax_11 = *arg3;
                
                if ((!(rax_11 & 1) || *(arg1 + 4) & 1) && (!(rax_11 & 4) || *(arg1 + 4) & 4)
                        && (!(rax_11 & 2) || *(arg1 + 4) & 2))
                    return 1;
            }
            
            return 0;
        }
    }
    
    return 1;
}

