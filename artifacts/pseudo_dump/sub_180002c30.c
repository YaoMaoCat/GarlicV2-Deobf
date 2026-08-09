
  int64_t* sub_180002c30(int64_t* arg1, int128_t* arg2)

{
    if (arg1 != arg2)
    {
        int64_t rcx = arg1[3];
        
        if (rcx > 0xf)
        {
            void* rax_1 = *arg1;
            void* r8_1;
            
            if (rcx + 1 < 0x1000)
                r8_1 = rax_1;
            else
            {
                r8_1 = *(rax_1 - 8);
                
                if (rax_1 - r8_1 - 8 > 0x1f)
                    trap(0xd);
            }
            
            j_sub_180021340(r8_1);
        }
        
        arg1[3] = 0xf;
        arg1[2] = 0;
        *arg1 = 0;
        *arg1 = *arg2;
        *(arg1 + 0x10) = arg2[1];
        arg2[1] = 0;
        *(arg2 + 0x18) = 0xf;
        *arg2 = 0;
    }
    
    return arg1;
}

