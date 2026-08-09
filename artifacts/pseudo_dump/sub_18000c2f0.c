
  int64_t sub_18000c2f0(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2)

{
    int64_t rax;
    int64_t rdx;
    rax = sub_1800020f0(arg1, arg2, "io.netty.channel.ChannelHandlerContext", arg3);
    char const* const rcx;
    
    if (rax)
    {
        data_1800460e0 = (*(*arg1 + 0xa8))(arg1, rax);
        data_1800460e8 =
            (*(*arg1 + 0x108))(arg1, rax, "pipeline", "()Lio/netty/channel/ChannelPipeline;");
        data_1800460f0 = (*(*arg1 + 0x108))(arg1, rax, "fireChannelRead", 
            "(Ljava/lang/Object;)Lio/netty/channel/ChannelHandlerContext;");
        data_1800460f8 = (*(*arg1 + 0x108))(arg1, rax, "write", 
            "(Ljava/lang/Object;Lio/netty/channel/ChannelPromise;)Lio/netty/channel/ChannelFuture;");
        data_180046100 = (*(*arg1 + 0x108))(arg1, rax, "writeAndFlush", 
            "(Ljava/lang/Object;)Lio/netty/channel/ChannelFuture;");
        (*(*arg1 + 0xb8))(arg1, rax);
        int64_t rax_12;
        rax_12 = sub_1800020f0(arg1, arg2, "io.netty.channel.ChannelPipeline", arg3);
        
        if (rax_12)
        {
            data_180046108 = (*(*arg1 + 0xa8))(arg1, rax_12);
            data_180046110 = (*(*arg1 + 0x108))(arg1, rax_12, "addFirst", 
                "(Ljava/lang/String;Lio/netty/channel/ChannelHandler;)Lio/netty/channel/ChannelPipeline;");
            data_180046118 = (*(*arg1 + 0x108))(arg1, rax_12, "addBefore", 
                "(Ljava/lang/String;Ljava/lang/String;Lio/netty/channel/ChannelHandler;"
            ")Lio/netty/channel/ChannelPipeline;");
            (*(*arg1 + 0xb8))(arg1, rax_12);
            int64_t rax_20;
            rax_20 = sub_1800020f0(arg1, arg2, "io.netty.channel.ChannelPromise", arg3);
            
            if (rax_20)
            {
                data_180046120 = (*(*arg1 + 0xa8))(arg1, rax_20);
                data_180046128 = (*(*arg1 + 0x108))(arg1, rax_20, "setSuccess", 
                    "()Lio/netty/channel/ChannelPromise;");
                int64_t rax_26;
                rax_26 = (*(*arg1 + 0xb8))(arg1, rax_20);
                
                if (data_1800460e8 && data_1800460f0 && data_1800460f8 && data_180046110
                    && data_180046118 && data_180046128)
                {
                    rax_26 = 1;
                    return rax_26;
                }
                
                rcx = "Relay: one or more netty method IDs missing";
            }
            else
                rcx = "Relay: couldn't load ChannelPromise";
        }
        else
            rcx = "Relay: couldn't load ChannelPipeline";
    }
    else
        rcx = "Relay: couldn't load ChannelHandlerContext";
    
    sub_180001d30(rcx, rdx);
    int64_t rax_27;
    rax_27 = 0;
    return rax_27;
}

