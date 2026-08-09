
  void sub_180003f30(void* arg1, int64_t arg2)

{
    if (arg1 == arg2)
        return;
    
    void* rbx_1 = arg1;
    
    do
    {
        void* rax = *(rbx_1 + 8);
        
        if (rax)
        {
            void* rcx;
            
            if (*(rbx_1 + 0x18) - rax < 0x1000)
                rcx = rax;
            else
            {
                rcx = *(rax - 8);
                
                if (rax - rcx - 8 > 0x1f)
                    trap(0xd);
            }
            
            j_sub_180021340(rcx);
            __builtin_memset(rbx_1 + 8, 0, 0x18);
        }
        
        rbx_1 += 0x20;
    } while (rbx_1 != arg2);
}

