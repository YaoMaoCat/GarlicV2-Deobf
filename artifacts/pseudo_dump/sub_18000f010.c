
  int64_t sub_18000f010(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2)

{
    int64_t rax;
    int512_t zmm2;
    rax = sub_180013ac0(arg1, arg2, "io.netty.channel.nio.NioEventLoopGroup", 
        "Lio/netty/channel/nio/NioEventLoopGroup;", arg3);
    int64_t rax_1;
    int512_t zmm2_1;
    rax_1 = sub_180013ac0(arg1, arg2, "io.netty.bootstrap.ServerBootstrap", 
        "Lio/netty/bootstrap/ServerBootstrap;", zmm2);
    int64_t rax_2;
    int512_t zmm2_2;
    rax_2 = sub_180013ac0(arg1, arg2, "io.netty.channel.socket.nio.NioServerSocketChannel", 
        "Lio/netty/channel/socket/nio/NioServerSocketChannel;", zmm2_1);
    int64_t r8 = *arg1;
    int64_t result = (*(r8 + 0x30))(arg1, "java/net/InetSocketAddress", r8);
    
    if (!rax || !rax_1 || !rax_2 || !result)
        result = 0;
    else
    {
        int64_t rax_3;
        int64_t r9_1;
        rax_3 = (*(*arg1 + 0x108))(arg1, rax, "<init>", &data_180030c10);
        int64_t rax_4 = sub_18000bbf0(arg1, rax, zmm2_2, r9_1);
        int64_t rdx_4 = *arg1;
        
        if (!(*(rdx_4 + 0x720))(arg1, rdx_4))
        {
            int64_t rax_7;
            int64_t r9_2;
            rax_7 = (*(*arg1 + 0x108))(arg1, rax_1, "<init>", &data_180030c10);
            int64_t rax_8 = sub_18000bbf0(arg1, rax_1, zmm2_2, r9_2);
            (*(*arg1 + 0x108))(arg1, rax_1, "group", 
                "(Lio/netty/channel/EventLoopGroup;)Lio/netty/bootstrap/ServerBootstrap;");
            sub_180001cd0(arg1, rax_8, zmm2_2, rax_4);
            (*(*arg1 + 0x108))(arg1, rax_1, "channel", 
                "(Ljava/lang/Class;)Lio/netty/bootstrap/AbstractBootstrap;");
            int64_t r9_5 = sub_180001cd0(arg1, rax_8, zmm2_2, rax_2);
            data_180046248;
            int64_t rax_11 = sub_18000bbf0(arg1, data_180046240, zmm2_2, r9_5);
            (*(*arg1 + 0x108))(arg1, rax_1, "childHandler", 
                "(Lio/netty/channel/ChannelHandler;)Lio/netty/bootstrap/ServerBootstrap;");
            sub_180001cd0(arg1, rax_8, zmm2_2, rax_11);
            (*(*arg1 + 0xb8))(arg1, rax_11);
            int64_t rax_14 = (*(*arg1 + 0x538))(arg1, "0.0.0.0");
            (*(*arg1 + 0x108))(arg1, result, "<init>", "(Ljava/lang/String;I)V");
            int64_t rax_16 = sub_18000bbf0(arg1, result, zmm2_2, rax_14);
            int64_t r8_8 = *arg1;
            (*(r8_8 + 0xb8))(arg1, rax_14, r8_8);
            (*(*arg1 + 0x108))(arg1, rax_1, "bind", 
                "(Ljava/net/SocketAddress;)Lio/netty/channel/ChannelFuture;", 0x63dd);
            int64_t rax_18 = sub_180001cd0(arg1, rax_8, zmm2_2, rax_16);
            int64_t r8_10 = *arg1;
            (*(r8_10 + 0xb8))(arg1, rax_16, r8_10);
            
            if (!(*(*arg1 + 0x720))(arg1))
            {
                if (!rax_18)
                    goto label_18000f355;
                
                int64_t rax_21 = (*(*arg1 + 0xf8))(arg1, rax_18);
                int64_t rax_22;
                int64_t r9_10;
                rax_22 =
                    (*(*arg1 + 0x108))(arg1, rax_21, "sync", "()Lio/netty/channel/ChannelFuture;");
                sub_180001cd0(arg1, rax_18, zmm2_2, r9_10);
                int64_t rdx_25 = *arg1;
                
                if (!(*(rdx_25 + 0x720))(arg1, rdx_25))
                {
                    (*(*arg1 + 0xb8))(arg1, rax_21);
                    (*(*arg1 + 0xb8))(arg1, rax_18);
                label_18000f355:
                    (*(*arg1 + 0xb8))(arg1, rax_8);
                    sub_1800023a0("BServer: bound 0.0.0.0:25565 (all interfaces, LAN-wide)", 
                        (*(*arg1 + 0xb8))(arg1, rax_4));
                    result = 1;
                }
                else
                {
                    sub_180002210(arg1, "bind-sync", zmm2_2);
                    result = 0;
                }
            }
            else
            {
                sub_180002210(arg1, "bind", zmm2_2);
                result = 0;
            }
        }
        else
        {
            sub_180002210(arg1, "NioELG", zmm2_2);
            result = 0;
        }
    }
    
    return result;
}

