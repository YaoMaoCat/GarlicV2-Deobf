
  void sub_18000b2d0(int64_t* arg1, int64_t arg2, int64_t arg3)

{
    if (!arg3)
        return;
    
    void var_98;
    int64_t rax_2 = __security_cookie ^ &var_98;
    int32_t* rax = (*(*arg1 + 0x548))(arg1, arg3, 0);
    
    if (rax)
    {
        int64_t r8 = *arg1;
        int64_t rax_4 = (*(r8 + 0x30))(arg1, "java/lang/System", r8);
        int64_t rax_5 = (*(*arg1 + 0x480))(arg1, rax_4, &data_180031530, "Ljava/io/PrintStream;");
        int64_t r9_1 = *arg1;
        int64_t rax_6 = (*(r9_1 + 0x488))(arg1, rax_4, rax_5, r9_1);
        int64_t r8_2 = *arg1;
        int64_t rax_7 = (*(r8_2 + 0xf8))(arg1, rax_6, r8_2);
        int64_t var_68_1 = (*(*arg1 + 0x108))(arg1, rax_7, "println", "(Ljava/lang/String;)V");
        int128_t var_60;
        __builtin_memset(&var_60, 0, 0x20);
        int64_t rax_9 = sub_180016420(0x20);
        var_60 = rax_9;
        void* var_50_1 = 0x19;
        int64_t var_48_1 = 0x1f;
        __builtin_strncpy(rax_9, "[MinecraftProxy][native] ", 0x1a);
        void* rax_10 = strlen(rax);
        void* var_78;
        int512_t zmm2_1;
        
        if (rax_10 > var_48_1 - var_50_1)
        {
            var_78 = rax_10;
            zmm2_1 = sub_180002840(&var_60, rax_10, 0, rax, var_78);
        }
        else
        {
            void* var_50_2 = var_50_1 + rax_10;
            int128_t* rbx_1 = &var_60;
            
            if (var_48_1 > 0xf)
                rbx_1 = var_60;
            
            char* rbx_2 = rbx_1 + var_50_1;
            zmm2_1 = memcpy(rbx_2, rax, rax_10);
            *(rbx_2 + rax_10) = 0;
        }
        
        int128_t* rdx_8 = &var_60;
        
        if (var_48_1 > 0xf)
            rdx_8 = var_60;
        
        int64_t rax_13 = (*(*arg1 + 0x538))(arg1, rdx_8);
        sub_180001d00(arg1, rax_6, zmm2_1, rax_13);
        int64_t r9_4 = *arg1;
        (*(r9_4 + 0x550))(arg1, arg3, rax, r9_4, var_78);
        int64_t r8_6 = *arg1;
        (*(r8_6 + 0xb8))(arg1, rax_13, r8_6);
        (*(*arg1 + 0xb8))(arg1, rax_7);
        (*(*arg1 + 0xb8))(arg1, rax_6);
        (*(*arg1 + 0xb8))(arg1, rax_4);
        
        if (var_48_1 > 0xf)
        {
            void* rcx_18 = var_60;
            
            if (var_48_1 + 1 >= 0x1000)
            {
                void* rax_17 = *(rcx_18 - 8);
                
                if (rcx_18 - rax_17 - 8 > 0x1f)
                    trap(0xd);
                
                rcx_18 = rax_17;
            }
            
            j_sub_180021340(rcx_18);
        }
    }
    
    __security_check_cookie(rax_2 ^ &var_98);
}

