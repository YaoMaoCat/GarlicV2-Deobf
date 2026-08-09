
  uint64_t sub_1800133e0(int64_t arg1, int64_t arg2, char arg3, int64_t arg4, int32_t arg5)

{
    int64_t* rcx = data_180047468;
    int32_t var_58 = 0;
    int64_t var_48 = 0;
    
    if ((*(*rcx + 0x198))(rcx, arg1, &var_58, &var_48))
        return 0;
    
    int32_t rbx = 0;
    int32_t rsi = 0;
    
    if (var_58 > 0)
    {
        while (rbx < arg5)
        {
            int64_t* rcx_1 = data_180047468;
            int64_t rdx_1 = var_48;
            int64_t var_40 = 0;
            char* var_50 = nullptr;
            int64_t var_38 = 0;
            int64_t r14_1 = rsi;
            
            if (!(*(*rcx_1 + 0x1f8))(rcx_1, *(rdx_1 + (r14_1 << 3)), &var_40, &var_50, &var_38))
            {
                int64_t* rcx_2 = data_180047468;
                int64_t rdx_3 = var_48;
                int32_t var_54 = 0;
                (*(*rcx_2 + 0x208))(rcx_2, *(rdx_3 + (r14_1 << 3)), &var_54);
                char* rdi_1 = var_50;
                
                if (rdi_1 && !strcmp(rdi_1, arg2) && (var_54 >> 3 & 1) == arg3)
                {
                    int64_t rdx_6 = rbx;
                    rbx += 1;
                    *(arg4 + (rdx_6 << 3)) = *(var_48 + (r14_1 << 3));
                    sub_1800023a0("  findMethodsByDesc(%s)[%d]: '%s'", arg2);
                    rdi_1 = var_50;
                }
                
                int64_t rdx_8 = var_40;
                
                if (rdx_8)
                {
                    int64_t* rcx_5 = data_180047468;
                    (*(*rcx_5 + 0x170))(rcx_5, rdx_8);
                    rdi_1 = var_50;
                }
                
                if (rdi_1)
                {
                    int64_t* rcx_6 = data_180047468;
                    (*(*rcx_6 + 0x170))(rcx_6, rdi_1);
                }
                
                int64_t rdx_10 = var_38;
                
                if (rdx_10)
                {
                    int64_t* rcx_7 = data_180047468;
                    (*(*rcx_7 + 0x170))(rcx_7, rdx_10);
                }
            }
            
            rsi += 1;
            
            if (rsi >= var_58)
                break;
        }
    }
    
    int64_t* rcx_8 = data_180047468;
    (*(*rcx_8 + 0x170))(rcx_8, var_48);
    return rbx;
}

