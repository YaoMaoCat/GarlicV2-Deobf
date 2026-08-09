
  int64_t sub_180022c74(uint16_t* arg1, int64_t* arg2, int64_t arg3, uint32_t* arg4, void* arg5)

{
    char* rdi = *arg2;
    int64_t i_1 = arg3;
    int64_t rax;
    
    if (!arg1)
    {
        int64_t result = 0;
        
        while (true)
        {
            int64_t r8_3;
            
            if (!*rdi)
                r8_3 = 1;
            else if (rdi[1])
            {
                rax = rdi[2];
                char temp0_1 = rax;
                rax = -(rax);
                r8_3 = -((arg3 - arg3)) + 3;
            }
            else
                r8_3 = 2;
            
            rax = sub_1800229c8(0, rdi, r8_3, arg4, arg2, arg5);
            
            if (rax == -1)
                break;
            
            if (!rax)
                return result;
            
            int64_t result_1 = result + 1;
            rdi = &rdi[rax];
            
            if (rax != 4)
                result_1 = result;
            
            result = result_1 + 1;
        }
        
        *(arg5 + 0x30) = 1;
        *(arg5 + 0x2c) = 0x2a;
        return -1;
    }
    
    uint16_t* rbx = arg1;
    
    if (arg3)
    {
        int64_t i;
        
        do
        {
            int64_t r8;
            
            if (!*rdi)
                r8 = 1;
            else if (rdi[1])
            {
                rax = rdi[2];
                char temp1_1 = rax;
                rax = -(rax);
                r8 = -((arg3 - arg3)) + 3;
            }
            else
                r8 = 2;
            
            int32_t arg_8 = 0;
            rax = sub_1800229c8(&arg_8, rdi, r8, arg4, arg2, arg5);
            
            if (rax == -1)
            {
                *arg2 = rdi;
                *(arg5 + 0x30) = 1;
                *(arg5 + 0x2c) = 0x2a;
                return -1;
            }
            
            if (!rax)
            {
                rdi = nullptr;
                *rbx = 0;
                break;
            }
            
            int32_t rcx_1 = arg_8;
            
            if (rcx_1 > 0xffff)
            {
                if (i_1 <= 1)
                    break;
                
                arg3 = 0xd800;
                arg_8 = rcx_1 - 0x10000;
                i_1 -= 1;
                *rbx = (rcx_1 - 0x10000) >> 0xa | 0xd800;
                rcx_1 = (rcx_1 - 0x10000) & 0x3ff;
                rbx = &rbx[1];
                rcx_1 |= 0xdc00;
            }
            
            *rbx = rcx_1;
            rdi = &rdi[rax];
            rbx = &rbx[1];
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
    }
    
    *arg2 = rdi;
    return (rbx - arg1) >> 1;
}

