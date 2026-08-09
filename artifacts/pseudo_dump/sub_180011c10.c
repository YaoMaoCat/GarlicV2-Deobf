
  uint64_t sub_180011c10(int64_t* arg1, int64_t arg2)

{
    void var_268;
    int64_t rax_1 = __security_cookie ^ &var_268;
    void* var_178;
    sub_180002e20(&var_178, 2, 3);
    sub_1800033a0();
    int64_t* var_198;
    sub_180003410(&var_198, &data_180046008, &var_178);
    int128_t var_208;
    int128_t* var_1a8 = &var_208;
    __builtin_memset(&var_208, 0, 0x20);
    int64_t rax_2 = sub_180016420(0x30);
    var_208 = rax_2;
    int64_t var_1f8 = 0x2d;
    int64_t var_1f0 = 0x2f;
    __builtin_strncpy(rax_2, "io/netty/channel/ChannelInboundHandlerAdapter", 0x2e);
    int128_t var_1e8;
    void var_158;
    sub_180004930(&var_158, sub_1800029d0(&var_1e8, &var_198), &var_208, 0x34);
    char const* const var_228 = &data_180030c10;
    int64_t var_220 = 3;
    var_1a8 = "<init>";
    int64_t var_1a0 = 6;
    char const* const var_218 = "io/netty/channel/ChannelInboundHandlerAdapter";
    int64_t var_210 = 0x2d;
    uint16_t rax_4 = sub_180006080(&var_158, &var_218, &var_1a8, &var_228);
    var_1a8 = 0xb72a;
    *(&var_1a8 + 2) = (rax_4 >> 8);
    *(&var_1a8 + 3) = rax_4;
    *(&var_1a8 + 4) = 0xb1;
    int32_t* rax_5 = sub_180016420(5);
    var_208 = rax_5;
    void* var_1f8_1 = rax_5 + 5;
    *rax_5 = var_1a8;
    rax_5[1] = *(&var_1a8 + 4);
    *(&var_208 + 8) = rax_5 + 5;
    __builtin_memset(&var_1e8, 0, 0x18);
    int32_t* rax_6 = sub_180016420(5);
    var_1e8 = rax_6;
    *(&var_1e8 + 8) = rax_6;
    void* var_1d8 = rax_6 + 5;
    *rax_6 = *rax_5;
    rax_6[1] = rax_5[1];
    *(&var_1e8 + 8) = rax_6 + 5;
    var_218 = &data_180030c10;
    int64_t var_210_1 = 3;
    var_228 = "<init>";
    int64_t var_220_1 = 6;
    int16_t var_238 = 1;
    sub_1800052c0(&var_158, &var_228, &var_218, 1, &var_1e8, 1);
    var_218 = "(Lio/netty/channel/ChannelHandlerContext;)V";
    int64_t var_210_2 = 0x2b;
    var_228 = "channelActive";
    int64_t var_220_2 = 0xd;
    sub_180005820(&var_158, &var_228, &var_218, 0x101);
    var_218 = "(Lio/netty/channel/ChannelHandlerContext;)V";
    int64_t var_210_3 = 0x2b;
    var_228 = "channelInactive";
    int64_t var_220_3 = 0xf;
    sub_180005820(&var_158, &var_228, &var_218, 0x101);
    var_218 = "(Lio/netty/channel/ChannelHandlerContext;Ljava/lang/Object;)V";
    int64_t var_210_4 = 0x3d;
    var_228 = "channelRead";
    int64_t var_220_4 = 0xb;
    sub_180005820(&var_158, &var_228, &var_218, 0x101);
    void* var_1c8;
    int512_t zmm2 = sub_180005940(&var_158, &var_1c8);
    void* r10 = var_1c8;
    int64_t* rdx_9 = &var_198;
    int64_t var_180;
    
    if (var_180 > 0xf)
        rdx_9 = var_198;
    
    int32_t* var_248;
    int32_t var_1c0;
    var_248 = var_1c0 - r10;
    int64_t rax_8 = (*(*arg1 + 0x28))(arg1, rdx_9, arg2, r10, var_248);
    int64_t rbx_1 = rax_8;
    
    if (rax_8)
    {
        char const* const var_98 = "channelActive";
        char const* const var_90_1 = "(Lio/netty/channel/ChannelHandlerContext;)V";
        int64_t (* var_88_1)() = sub_18000eb00;
        char const* const var_80_1 = "channelInactive";
        char const* const var_78_1 = "(Lio/netty/channel/ChannelHandlerContext;)V";
        int64_t (* var_70_1)(int64_t* arg1, int64_t arg2) = sub_18000eb10;
        char const* const var_68_1 = "channelRead";
        char const* const var_60_1 =
            "(Lio/netty/channel/ChannelHandlerContext;Ljava/lang/Object;)V";
        void* const var_58_1 = &data_18000ec20;
        
        if (!(*(*arg1 + 0x6b8))(arg1, rbx_1, &var_98, 3))
        {
            data_180046258 = (*(*arg1 + 0x108))(arg1, rbx_1, "<init>", &data_180030c10);
            data_180046250 = (*(*arg1 + 0xa8))(arg1, rbx_1);
            (*(*arg1 + 0xb8))(arg1, rbx_1);
            int64_t* rdx_15 = &var_198;
            
            if (var_180 > 0xf)
                rdx_15 = var_198;
            
            sub_1800023a0("BServer: defined BSideHandler as %s", rdx_15);
            rbx_1 = 1;
        }
        else
        {
            sub_180002210(arg1, "BServer/RegisterHandler", zmm2);
            (*(*arg1 + 0xb8))(arg1, rbx_1);
            rbx_1 = 0;
        }
    }
    else
        sub_180002210(arg1, "BServer/DefineHandler", zmm2);
    
    void* rax_17 = var_1c8;
    
    if (rax_17)
    {
        int64_t var_1b8;
        void* rcx_21;
        
        if (var_1b8 - rax_17 < 0x1000)
            rcx_21 = rax_17;
        else
        {
            rcx_21 = *(rax_17 - 8);
            
            if (rax_17 - rcx_21 - 8 > 0x1f)
                trap(0xd);
        }
        
        j_sub_180021340(rcx_21);
        __builtin_memset(&var_1c8, 0, 0x18);
    }
    
    int32_t* rcx_23;
    
    if (5 < 0x1000)
        rcx_23 = rax_5;
    else
    {
        rcx_23 = *(rax_5 - 8);
        
        if (rax_5 - rcx_23 - 8 > 0x1f)
            trap(0xd);
    }
    
    j_sub_180021340(rcx_23);
    sub_18000ab00(&var_158);
    
    if (var_180 > 0xf)
    {
        int64_t* rcx_26 = var_198;
        
        if (var_180 + 1 >= 0x1000)
        {
            int64_t* rax_20 = rcx_26[-1];
            
            if (rcx_26 - rax_20 - 8 > 0x1f)
                trap(0xd);
            
            rcx_26 = rax_20;
        }
        
        j_sub_180021340(rcx_26);
    }
    
    int64_t var_188 = 0;
    int64_t var_180_1 = 0xf;
    var_198 = 0;
    int64_t var_160;
    
    if (var_160 > 0xf)
    {
        void* rcx_29 = var_178;
        
        if (var_160 + 1 >= 0x1000)
        {
            void* rax_21 = *(rcx_29 - 8);
            
            if (rcx_29 - rax_21 - 8 > 0x1f)
                trap(0xd);
            
            rcx_29 = rax_21;
        }
        
        j_sub_180021340(rcx_29);
    }
    
    __security_check_cookie(rax_1 ^ &var_268);
    return rbx_1;
}

