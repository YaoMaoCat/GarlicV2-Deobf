
  uint64_t sub_18000dac0(int64_t* arg1)

{
    if (!arg1 || !data_180047468)
    {
        int64_t rax;
        rax = 0;
        return rax;
    }
    
    if (sub_18000e2f0(0))
        return 1;
    
    int64_t rax_2;
    int64_t rdx_1;
    int512_t entry_zmm2;
    rax_2 = sub_180001de0(arg1, data_180047468, entry_zmm2);
    
    if (!rax_2)
    {
        sub_1800023a0("[MAIN-GATE] Minecraft ClassLoader unavailable", rdx_1);
        int64_t rax_3;
        rax_3 = 0;
        return rax_3;
    }
    
    char rax_4;
    int512_t zmm2;
    rax_4 = sub_180012620(arg1, rax_2);
    
    if (!rax_4)
    {
        (*(*arg1 + 0xb0))(arg1, rax_2);
        int64_t rax_6;
        rax_6 = 0;
        return rax_6;
    }
    
    int64_t rax_7 = sub_1800020f0(arg1, rax_2, "net.minecraft.client.Minecraft", zmm2);
    int64_t r8 = *arg1;
    int64_t rdx_5 = (*(r8 + 0xb0))(arg1, rax_2, r8);
    
    if (!rax_7)
    {
        sub_1800023a0("[MAIN-GATE] Minecraft class unavailable", rdx_5);
        int64_t rax_8;
        rax_8 = 0;
        return rax_8;
    }
    
    int64_t rax_9;
    int512_t zmm2_1;
    rax_9 = sub_180012ff0(rax_7, "()Lnet/minecraft/client/Minecraft;", 1);
    int64_t rax_10 = (*(*arg1 + 0x108))(arg1, rax_7, "execute", "(Ljava/lang/Runnable;)V");
    int64_t rdx_7 = *arg1;
    char rax_11;
    int64_t rdx_8;
    int64_t r9;
    rax_11 = (*(rdx_7 + 0x720))(arg1, rdx_7);
    
    if (rax_11)
    {
        int64_t rdx_9 = *arg1;
        rdx_8 = (*(rdx_9 + 0x88))(arg1, rdx_9);
    }
    
    uint64_t rax_17;
    
    if (!rax_9 || !rax_10)
    {
        sub_1800023a0("[MAIN-GATE] Minecraft getInstance/execute lookup failed", rdx_8);
        (*(*arg1 + 0xb8))(arg1, rax_7);
        rax_17 = 0;
    }
    else
    {
        int64_t rax_12;
        int64_t r9_1;
        rax_12 = sub_18000e9f0(arg1, rax_7, zmm2_1, r9);
        data_180046268;
        int64_t rax_13 = sub_18000bbf0(arg1, data_180046260, zmm2_1, r9_1);
        
        if (rax_12 && rax_13)
        {
            int64_t rdx_12 = *arg1;
            
            if (!(*(rdx_12 + 0x720))(arg1, rdx_12))
            {
                sub_180001d00(arg1, rax_12, zmm2_1, rax_13);
                char rax_16 = (*(*arg1 + 0x720))(arg1);
                int64_t r15;
                r15 = !rax_16;
                
                if (rax_16)
                {
                    int64_t rdx_14 = *arg1;
                    (*(rdx_14 + 0x88))(arg1, rdx_14);
                }
                
                char const* const rdx_15 = "queue failed";
                
                if (!rax_16)
                    rdx_15 = "queued";
                
                sub_1800023a0("[MAIN-GATE] task %s on A Render thread", rdx_15);
                int64_t r8_5 = *arg1;
                (*(r8_5 + 0xb8))(arg1, rax_13, r8_5);
                int64_t r8_6 = *arg1;
                (*(r8_6 + 0xb8))(arg1, rax_12, r8_6);
                int64_t r8_7 = *arg1;
                (*(r8_7 + 0xb8))(arg1, rax_7, r8_7);
                return r15;
            }
        }
        
        char rax_19;
        int64_t rdx_19;
        rax_19 = (*(*arg1 + 0x720))(arg1);
        
        if (rax_19)
            rdx_19 = (*(*arg1 + 0x88))(arg1);
        
        sub_1800023a0("[MAIN-GATE] failed to create Minecraft gate task", rdx_19);
        
        if (rax_13)
            (*(*arg1 + 0xb8))(arg1, rax_13);
        
        if (rax_12)
            (*(*arg1 + 0xb8))(arg1, rax_12);
        
        (*(*arg1 + 0xb8))(arg1, rax_7);
        rax_17 = 0;
    }
    
    return rax_17;
}

