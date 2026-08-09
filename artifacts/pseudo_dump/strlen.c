
🌐  void* strlen(char* arg1)

{
    char* rax = arg1;
    int64_t rcx = -(arg1);
    
    if (rax & 7)
    {
        do
        {
            char rdx = *rax;
            rax = &rax[1];
            
            if (!rdx)
                return &rax[rcx - 1];
        } while (rax & 7);
    }
    
    while (true)
    {
        int64_t rdx_1 = *rax;
        rax = &rax[8];
        
        if ((~rdx_1 ^ (0x7efefefefefefeff + rdx_1)) & 0x8101010101010100)
        {
            int64_t rdx_5 = *(rax - 8);
            
            if (!rdx_5)
                return &rax[rcx - 8];
            
            if (!*(&rdx_5 + 1))
                return &rax[rcx - 7];
            
            uint64_t rdx_6 = rdx_5 >> 0x10;
            
            if (!rdx_6)
                return &rax[rcx - 6];
            
            if (!*(&rdx_6 + 1))
                return &rax[rcx - 5];
            
            uint32_t rdx_7 = rdx_6 >> 0x10;
            
            if (!rdx_7)
                return &rax[rcx - 4];
            
            if (!*(&rdx_7 + 1))
                return &rax[rcx - 3];
            
            uint16_t rdx_8 = rdx_7 >> 0x10;
            
            if (!rdx_8)
                return &rax[rcx - 2];
            
            if (!*(&rdx_8 + 1))
                break;
        }
    }
    
    return &rax[rcx - 1];
}

