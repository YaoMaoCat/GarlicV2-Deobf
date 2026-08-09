
  int64_t* sub_180004e90(int64_t* arg1, int64_t* arg2)

{
    if (arg1 != arg2)
    {
        void* rax_1 = *arg1;
        
        if (rax_1)
        {
            void* rcx;
            
            if (arg1[2] - rax_1 < 0x1000)
                rcx = rax_1;
            else
            {
                rcx = *(rax_1 - 8);
                
                if (rax_1 - rcx - 8 > 0x1f)
                    trap(0xd);
            }
            
            j_sub_180021340(rcx);
            __builtin_memset(arg1, 0, 0x18);
        }
        
        *arg1 = *arg2;
        arg1[1] = arg2[1];
        arg1[2] = arg2[2];
        __builtin_memset(arg2, 0, 0x18);
    }
    
    return arg1;
}

