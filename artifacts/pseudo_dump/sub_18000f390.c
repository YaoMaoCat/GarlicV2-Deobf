
  int64_t sub_18000f390(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2)

{
    int64_t result = sub_180013ac0(arg1, arg2, "net.minecraft.network.Connection", 
        "Lnet/minecraft/network/Connection;", arg3);
    
    if (result)
    {
        int64_t r8_1 = *arg1;
        data_180046270 = (*(r8_1 + 0xa8))(arg1, result, r8_1);
        data_180046278 = sub_180012ff0(result, 
            "(Lio/netty/channel/ChannelPipeline;Lnet/minecraft/network/protocol/PacketFlow;)V", 1);
        data_180046280 = sub_180012ff0(result, "(Lnet/minecraft/network/protocol/Packet;)V", 0);
        data_180046288 = sub_180012e10(result, "Lio/netty/util/AttributeKey;", 1);
        int64_t rax_4;
        int512_t zmm2;
        rax_4 = sub_180012e10(result, "Lio/netty/channel/Channel;", 0);
        data_180046340 = rax_4;
        (*(*arg1 + 0xb8))(arg1, result);
        int64_t rax_6;
        int64_t rdx_3;
        rax_6 = sub_180013ac0(arg1, arg2, "net.minecraft.network.protocol.BundlerInfo", 
            "Lnet/minecraft/network/protocol/BundlerInfo;", zmm2);
        int512_t zmm2_1;
        
        if (!rax_6)
            zmm2_1 = sub_1800023a0("BServer: BundlerInfo not found (bundle attr not set ", rdx_3);
        else
        {
            int64_t r8_4 = *arg1;
            data_180046390 = (*(r8_4 + 0xa8))(arg1, rax_6, r8_4);
            int64_t rax_8;
            rax_8 = sub_180012e10(rax_6, "Lio/netty/util/AttributeKey;", 1);
            data_180046398 = rax_8;
            int64_t r8_6 = *arg1;
            (*(r8_6 + 0xb8))(arg1, rax_6, r8_6);
        }
        
        int64_t rax_9;
        int512_t zmm2_2;
        rax_9 = sub_180013ac0(arg1, arg2, "net.minecraft.network.ConnectionProtocol", 
            "Lnet/minecraft/network/ConnectionProtocol;", zmm2_1);
        
        if (rax_9)
        {
            int64_t rax_10 = (*(*arg1 + 0x480))(arg1, rax_9, "HANDSHAKING", 
                "Lnet/minecraft/network/ConnectionProtocol;");
            int64_t rax_12;
            
            if (rax_10)
                rax_12 = (*(*arg1 + 0x488))(arg1, rax_9, rax_10);
            
            int64_t rax_13;
            
            if (!rax_10 || !rax_12)
                rax_13 = 0;
            else
            {
                int64_t r8_8 = *arg1;
                rax_13 = (*(r8_8 + 0xa8))(arg1, rax_12, r8_8);
            }
            
            data_180046290 = rax_13;
            int64_t rax_15 = (*(*arg1 + 0x480))(arg1, rax_9, "LOGIN", 
                "Lnet/minecraft/network/ConnectionProtocol;");
            int64_t rax_17;
            
            if (rax_15)
                rax_17 = (*(*arg1 + 0x488))(arg1, rax_9, rax_15);
            
            int64_t rax_18;
            
            if (!rax_15 || !rax_17)
                rax_18 = 0;
            else
            {
                int64_t r8_10 = *arg1;
                rax_18 = (*(r8_10 + 0xa8))(arg1, rax_17, r8_10);
            }
            
            data_180046298 = rax_18;
            int64_t rax_20 = (*(*arg1 + 0x480))(arg1, rax_9, "PLAY", 
                "Lnet/minecraft/network/ConnectionProtocol;");
            int64_t rax_22;
            
            if (rax_20)
                rax_22 = (*(*arg1 + 0x488))(arg1, rax_9, rax_20);
            
            int64_t rax_23;
            
            if (!rax_20 || !rax_22)
                rax_23 = 0;
            else
            {
                int64_t r8_12 = *arg1;
                rax_23 = (*(r8_12 + 0xa8))(arg1, rax_22, r8_12);
            }
            
            data_1800462a0 = rax_23;
            int64_t rax_25 = (*(*arg1 + 0x480))(arg1, rax_9, "STATUS", 
                "Lnet/minecraft/network/ConnectionProtocol;");
            int64_t rax_27;
            
            if (rax_25)
                rax_27 = (*(*arg1 + 0x488))(arg1, rax_9, rax_25);
            
            int64_t rax_28;
            
            if (!rax_25 || !rax_27)
                rax_28 = 0;
            else
            {
                int64_t r8_14 = *arg1;
                rax_28 = (*(r8_14 + 0xa8))(arg1, rax_27, r8_14);
            }
            
            data_1800462a8 = rax_28;
            
            if ((*(*arg1 + 0x720))(arg1))
                (*(*arg1 + 0x88))(arg1);
            
            (*(*arg1 + 0xb8))(arg1, rax_9);
        }
        
        int512_t zmm2_3;
        result = sub_180013ac0(arg1, arg2, "net.minecraft.network.protocol.PacketFlow", 
            "Lnet/minecraft/network/protocol/PacketFlow;", zmm2_2);
        
        if (result)
        {
            int64_t rax_33 = (*(*arg1 + 0x480))(arg1, result, "SERVERBOUND", 
                "Lnet/minecraft/network/protocol/PacketFlow;");
            int64_t rax_34 = (*(*arg1 + 0x480))(arg1, result, "CLIENTBOUND", 
                "Lnet/minecraft/network/protocol/PacketFlow;");
            
            if (rax_33)
            {
                int64_t r9_1 = *arg1;
                int64_t rax_35 = (*(r9_1 + 0x488))(arg1, result, rax_33, r9_1);
                int64_t r8_16 = *arg1;
                data_180046300 = (*(r8_16 + 0xa8))(arg1, rax_35, r8_16);
            }
            
            if (rax_34)
            {
                int64_t rax_38 = (*(*arg1 + 0x488))(arg1, result, rax_34);
                int64_t r8_18 = *arg1;
                data_180046308 = (*(r8_18 + 0xa8))(arg1, rax_38, r8_18);
            }
            
            (*(*arg1 + 0xb8))(arg1, result);
            int512_t zmm2_4;
            result = sub_180013ac0(arg1, arg2, "io.netty.channel.Channel", 
                "Lio/netty/channel/Channel;", zmm2_3);
            
            if (result)
            {
                int64_t r8_19 = *arg1;
                data_180046310 = (*(r8_19 + 0xa8))(arg1, result, r8_19);
                data_180046318 = (*(*arg1 + 0x108))(arg1, result, "pipeline", 
                    "()Lio/netty/channel/ChannelPipeline;");
                data_180046320 = (*(*arg1 + 0x108))(arg1, result, "writeAndFlush", 
                    "(Ljava/lang/Object;)Lio/netty/channel/ChannelFuture;");
                data_180046328 = (*(*arg1 + 0x108))(arg1, result, "attr", 
                    "(Lio/netty/util/AttributeKey;)Lio/netty/util/Attribute;");
                data_180046330 = (*(*arg1 + 0x108))(arg1, result, "config", 
                    "()Lio/netty/channel/ChannelConfig;");
                data_180046338 =
                    (*(*arg1 + 0x108))(arg1, result, "close", "()Lio/netty/channel/ChannelFuture;");
                
                if ((*(*arg1 + 0x720))(arg1))
                    (*(*arg1 + 0x88))(arg1);
                
                (*(*arg1 + 0xb8))(arg1, result);
                int64_t rax_55;
                int512_t zmm2_5;
                rax_55 = sub_180013ac0(arg1, arg2, "io.netty.channel.ChannelConfig", 
                    "Lio/netty/channel/ChannelConfig;", zmm2_4);
                
                if (rax_55)
                {
                    data_180046348 = (*(*arg1 + 0x108))(arg1, rax_55, "setOption", 
                        "(Lio/netty/channel/ChannelOption;Ljava/lang/Object;)Z");
                    int64_t rdx_38 = *arg1;
                    
                    if ((*(rdx_38 + 0x720))(arg1, rdx_38))
                        (*(*arg1 + 0x88))(arg1);
                    
                    (*(*arg1 + 0xb8))(arg1, rax_55);
                }
                
                int64_t rax_60;
                int512_t zmm2_6;
                rax_60 = sub_180013ac0(arg1, arg2, "io.netty.channel.ChannelOption", 
                    "Lio/netty/channel/ChannelOption;", zmm2_5);
                
                if (rax_60)
                {
                    int64_t rax_61 = (*(*arg1 + 0x480))(arg1, rax_60, "TCP_NODELAY", 
                        "Lio/netty/channel/ChannelOption;");
                    
                    if (rax_61)
                    {
                        int64_t r9_2 = *arg1;
                        int64_t rax_62 = (*(r9_2 + 0x488))(arg1, rax_60, rax_61, r9_2);
                        
                        if (rax_62)
                        {
                            int64_t r8_21 = *arg1;
                            data_180046350 = (*(r8_21 + 0xa8))(arg1, rax_62, r8_21);
                        }
                    }
                    
                    if ((*(*arg1 + 0x720))(arg1))
                        (*(*arg1 + 0x88))(arg1);
                    
                    (*(*arg1 + 0xb8))(arg1, rax_60);
                }
                
                int64_t rax_69 = (*(*arg1 + 0x30))(arg1, "java/lang/Boolean");
                
                if (rax_69)
                {
                    int64_t rax_70 =
                        (*(*arg1 + 0x480))(arg1, rax_69, "TRUE", "Ljava/lang/Boolean;");
                    
                    if (rax_70)
                    {
                        int64_t r9_3 = *arg1;
                        int64_t rax_71 = (*(r9_3 + 0x488))(arg1, rax_69, rax_70, r9_3);
                        
                        if (rax_71)
                        {
                            int64_t r8_23 = *arg1;
                            data_180046358 = (*(r8_23 + 0xa8))(arg1, rax_71, r8_23);
                        }
                    }
                    
                    if ((*(*arg1 + 0x720))(arg1))
                        (*(*arg1 + 0x88))(arg1);
                    
                    (*(*arg1 + 0xb8))(arg1, rax_69);
                }
                
                int512_t zmm2_7;
                result = sub_180013ac0(arg1, arg2, "io.netty.channel.ChannelPipeline", 
                    "Lio/netty/channel/ChannelPipeline;", zmm2_6);
                
                if (result)
                {
                    int64_t r8_24 = *arg1;
                    data_180046360 = (*(r8_24 + 0xa8))(arg1, result, r8_24);
                    data_180046368 = (*(*arg1 + 0x108))(arg1, result, "addLast", 
                        "(Ljava/lang/String;Lio/netty/channel/ChannelHandler;"
                    ")Lio/netty/channel/ChannelPipeline;");
                    data_180046370 = (*(*arg1 + 0x108))(arg1, result, "remove", 
                        "(Ljava/lang/String;)Lio/netty/channel/ChannelHandler;");
                    data_180046378 = (*(*arg1 + 0x108))(arg1, result, &data_180032ce8, 
                        "(Ljava/lang/String;)Lio/netty/channel/ChannelHandler;");
                    (*(*arg1 + 0xb8))(arg1, result);
                    int512_t zmm2_8;
                    result = sub_180013ac0(arg1, arg2, "io.netty.util.Attribute", 
                        "Lio/netty/util/Attribute;", zmm2_7);
                    
                    if (result)
                    {
                        int64_t r8_25 = *arg1;
                        data_180046380 = (*(r8_25 + 0xa8))(arg1, result, r8_25);
                        data_180046388 = (*(*arg1 + 0x108))(arg1, result, &data_180032d40, 
                            "(Ljava/lang/Object;)V");
                        (*(*arg1 + 0xb8))(arg1, result);
                        int64_t rax_87;
                        int512_t zmm2_9;
                        rax_87 = sub_180013ac0(arg1, arg2, "com.mojang.authlib.GameProfile", 
                            "Lcom/mojang/authlib/GameProfile;", zmm2_8);
                        
                        if (rax_87)
                        {
                            int64_t r8_26 = *arg1;
                            data_1800463c0 = (*(r8_26 + 0xa8))(arg1, rax_87, r8_26);
                            data_1800463c8 = (*(*arg1 + 0x108))(arg1, rax_87, "<init>", 
                                "(Ljava/util/UUID;Ljava/lang/String;)V");
                            data_180046518 =
                                (*(*arg1 + 0x108))(arg1, rax_87, "getName", "()Ljava/lang/String;");
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_87);
                        }
                        
                        int64_t rax_96;
                        int512_t zmm2_10;
                        rax_96 = sub_180013ac0(arg1, arg2, "net.minecraft.client.Minecraft", 
                            "Lnet/minecraft/client/Minecraft;", zmm2_9);
                        
                        if (rax_96)
                        {
                            int64_t r8_27 = *arg1;
                            data_1800463d0 = (*(r8_27 + 0xa8))(arg1, rax_96, r8_27);
                            data_1800463d8 =
                                sub_180012ff0(rax_96, "()Lnet/minecraft/client/Minecraft;", 1);
                            data_1800463e0 = sub_180012ff0(rax_96, 
                                "()Lcom/mojang/authlib/properties/PropertyMap;", 0);
                            int64_t rax_100;
                            rax_100 = sub_180012ff0(rax_96, "()Lnet/minecraft/client/User;", 0);
                            data_180046588 = rax_100;
                            (*(*arg1 + 0xb8))(arg1, rax_96);
                        }
                        
                        int64_t rax_102;
                        int512_t zmm2_11;
                        rax_102 = sub_180013ac0(arg1, arg2, "net.minecraft.client.User", 
                            "Lnet/minecraft/client/User;", zmm2_10);
                        
                        if (rax_102)
                        {
                            int64_t r8_29 = *arg1;
                            data_180046578 = (*(r8_29 + 0xa8))(arg1, rax_102, r8_29);
                            data_180046580 = sub_180012ff0(rax_102, "()Ljava/util/UUID;", 0);
                            int64_t rax_105;
                            rax_105 =
                                sub_180012ff0(rax_102, "()Lcom/mojang/authlib/GameProfile;", 0);
                            data_180046510 = rax_105;
                            (*(*arg1 + 0xb8))(arg1, rax_102);
                        }
                        
                        int64_t rax_107;
                        int512_t zmm2_12;
                        rax_107 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.FriendlyByteBuf", 
                            "Lnet/minecraft/network/FriendlyByteBuf;", zmm2_11);
                        
                        if (rax_107)
                        {
                            int64_t r8_30 = *arg1;
                            data_1800463e8 = (*(r8_30 + 0xa8))(arg1, rax_107, r8_30);
                            data_1800463f0 = (*(*arg1 + 0x108))(arg1, rax_107, "<init>", 
                                "(Lio/netty/buffer/ByteBuf;)V");
                            data_1800463f8 = (*(*arg1 + 0x108))(arg1, rax_107, "writeByte", 
                                "(I)Lio/netty/buffer/ByteBuf;");
                            data_180046400 = (*(*arg1 + 0x108))(arg1, rax_107, "writeBoolean", 
                                "(Z)Lio/netty/buffer/ByteBuf;");
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            data_180046408 = sub_180012ff0(rax_107, 
                                "(I)Lnet/minecraft/network/FriendlyByteBuf;", 0);
                            data_180046410 = sub_180012ff0(rax_107, 
                                "(Ljava/util/UUID;)Lnet/minecraft/network/FriendlyByteBuf;", 0);
                            data_180046418 = sub_180012ff0(rax_107, 
                                "(Ljava/lang/String;I)Lnet/minecraft/network/FriendlyByteBuf;", 0);
                            int64_t rax_120;
                            rax_120 = sub_180012ff0(rax_107, 
                                "(Lcom/mojang/authlib/properties/PropertyMap;)V", 0);
                            data_180046420 = rax_120;
                            (*(*arg1 + 0xb8))(arg1, rax_107);
                        }
                        
                        int64_t rax_122;
                        int512_t zmm2_13;
                        rax_122 = sub_180013ac0(arg1, arg2, "io.netty.buffer.ByteBuf", 
                            "Lio/netty/buffer/ByteBuf;", zmm2_12);
                        
                        if (rax_122)
                        {
                            data_180046530 =
                                (*(*arg1 + 0x108))(arg1, rax_122, "readableBytes", &data_1800330e8);
                            data_180046538 =
                                (*(*arg1 + 0x108))(arg1, rax_122, "readerIndex", &data_1800330e8);
                            data_180046540 = (*(*arg1 + 0x108))(arg1, rax_122, "getBytes", 
                                "(I[B)Lio/netty/buffer/ByteBuf;");
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_122);
                        }
                        
                        int64_t rax_131;
                        int512_t zmm2_14;
                        rax_131 = sub_180013ac0(arg1, arg2, "io.netty.buffer.Unpooled", 
                            "Lio/netty/buffer/Unpooled;", zmm2_13);
                        
                        if (rax_131)
                        {
                            int64_t r8_31 = *arg1;
                            data_180046428 = (*(r8_31 + 0xa8))(arg1, rax_131, r8_31);
                            data_180046430 = (*(*arg1 + 0x388))(arg1, rax_131, "buffer", 
                                "()Lio/netty/buffer/ByteBuf;");
                            data_180046438 = (*(*arg1 + 0x388))(arg1, rax_131, "wrappedBuffer", 
                                "([B)Lio/netty/buffer/ByteBuf;");
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_131);
                        }
                        
                        int64_t rax_140;
                        int512_t zmm2_15;
                        rax_140 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundPlayerInfoUpdatePacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundPlayerInfoUpdatePacket;", 
                            zmm2_14);
                        int32_t var_98;
                        int128_t var_38;
                        
                        if (rax_140)
                        {
                            int64_t r8_32 = *arg1;
                            data_180046440 = (*(r8_32 + 0xa8))(arg1, rax_140, r8_32);
                            data_180046448 = (*(*arg1 + 0x108))(arg1, rax_140, "<init>", 
                                "(Lnet/minecraft/network/FriendlyByteBuf;)V");
                            data_180046450 = sub_180012ff0(rax_140, 
                                "(Lnet/minecraft/network/FriendlyByteBuf;)V", 0);
                            var_98 = 2;
                            var_38 = {0};
                            int32_t rax_144 =
                                sub_1800133e0(rax_140, "()Ljava/util/List;", 0, &var_38, 2);
                            data_180046458 = var_38;
                            data_180046460 = *(&var_38 + 8);
                            zmm2_15 = sub_1800023a0("  piu: %d ()List accessor(s) cached", rax_144);
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_140);
                        }
                        
                        int64_t rax_149;
                        int512_t zmm2_16;
                        rax_149 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundPlayerInfoUpdatePacket$Entry", 
                            "
                        "Lnet/minecraft/network/protocol/game/ClientboundPlayerInfoUpdatePacket$Entry;", 
                            zmm2_15);
                        
                        if (rax_149)
                        {
                            int64_t r8_33 = *arg1;
                            data_180046468 = (*(r8_33 + 0xa8))(arg1, rax_149, r8_33);
                            data_180046470 = sub_180012ff0(rax_149, "()Ljava/util/UUID;", 0);
                            data_180046478 =
                                sub_180012ff0(rax_149, "()Lnet/minecraft/world/level/GameType;", 0);
                            data_180046480 = sub_180012ff0(rax_149, &data_1800333b8, 0);
                            var_98 = 1;
                            data_180046488 =
                                sub_1800131d0(rax_149, &data_1800330e8, 0, &data_180032800, 1);
                            int64_t rax_155;
                            rax_155 = sub_180012ff0(rax_149, 
                                "()Lnet/minecraft/network/chat/Component;", 0);
                            data_180046490 = rax_155;
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_149);
                        }
                        
                        int64_t rax_160;
                        int512_t zmm2_17;
                        rax_160 = sub_180013ac0(arg1, arg2, "net.minecraft.world.level.GameType", 
                            "Lnet/minecraft/world/level/GameType;", zmm2_16);
                        
                        if (rax_160)
                        {
                            var_98 = 2;
                            int64_t rax_161;
                            rax_161 =
                                sub_1800131d0(rax_160, &data_1800330e8, 0, &data_180032818, 2);
                            data_180046498 = rax_161;
                            int64_t rdx_95 = *arg1;
                            
                            if ((*(rdx_95 + 0x720))(arg1, rdx_95))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_160);
                        }
                        
                        int64_t rcx_142 = data_1800463e8;
                        
                        if (rcx_142)
                        {
                            int64_t rax_165;
                            rax_165 = sub_180012ff0(rcx_142, 
                                "(Lnet/minecraft/network/chat/Component;"
                            ")Lnet/minecraft/network/FriendlyByteBuf;", 
                                0);
                            data_1800464a0 = rax_165;
                        }
                        
                        int64_t rax_167 = (*(*arg1 + 0x30))(arg1, "java/util/List");
                        
                        if (rax_167)
                        {
                            data_1800464a8 =
                                (*(*arg1 + 0x108))(arg1, rax_167, "size", &data_1800330e8, var_98);
                            data_1800464b0 = (*(*arg1 + 0x108))(arg1, rax_167, &data_180032ce8, 
                                "(I)Ljava/lang/Object;");
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_167);
                        }
                        
                        int64_t rax_174;
                        int512_t zmm2_18;
                        rax_174 = sub_180013ac0(arg1, arg2, "io.netty.buffer.ByteBuf", 
                            "Lio/netty/buffer/ByteBuf;", zmm2_17);
                        
                        if (rax_174)
                        {
                            data_1800464b8 =
                                (*(*arg1 + 0x108))(arg1, rax_174, "getByte", "(I)B", var_98);
                            int64_t rdx_102 = *arg1;
                            
                            if ((*(rdx_102 + 0x720))(arg1, rdx_102))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_174);
                        }
                        
                        int64_t rax_179;
                        int512_t zmm2_19;
                        rax_179 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundAddPlayerPacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundAddPlayerPacket;", 
                            zmm2_18);
                        
                        if (rax_179)
                        {
                            int64_t r8_34 = *arg1;
                            data_1800464c8 = (*(r8_34 + 0xa8))(arg1, rax_179, r8_34);
                            int64_t rax_181;
                            rax_181 = sub_180012e10(rax_179, "Ljava/util/UUID;", 0);
                            data_1800464d0 = rax_181;
                            int64_t r8_35 = *arg1;
                            (*(r8_35 + 0xb8))(arg1, rax_179, r8_35);
                        }
                        
                        int64_t rax_182;
                        int512_t zmm2_20;
                        rax_182 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundCustomPayloadPacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundCustomPayloadPacket;", 
                            zmm2_19);
                        
                        if (rax_182)
                        {
                            int64_t r8_36 = *arg1;
                            data_1800464d8 = (*(r8_36 + 0xa8))(arg1, rax_182, r8_36);
                            int64_t r8_37 = *arg1;
                            (*(r8_37 + 0xb8))(arg1, rax_182, r8_37);
                        }
                        
                        int64_t rax_184;
                        int512_t zmm2_21;
                        rax_184 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundSetPlayerTeamPacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundSetPlayerTeamPacket;", 
                            zmm2_20);
                        
                        if (rax_184)
                        {
                            int64_t r8_38 = *arg1;
                            data_1800464e0 = (*(r8_38 + 0xa8))(arg1, rax_184, r8_38);
                            data_1800464e8 = (*(*arg1 + 0x108))(arg1, rax_184, "<init>", 
                                "(Lnet/minecraft/network/FriendlyByteBuf;)V", var_98);
                            data_1800464f0 = sub_180012e10(rax_184, &data_1800336a4, 0);
                            data_1800464f8 = sub_180012e10(rax_184, "Ljava/lang/String;", 0);
                            int64_t rax_189;
                            rax_189 = sub_180012e10(rax_184, "Ljava/util/Collection;", 0);
                            data_180046500 = rax_189;
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_184);
                        }
                        
                        int64_t rax_195 = (*(*arg1 + 0x30))(arg1, "java/util/Collection");
                        
                        if (rax_195)
                        {
                            data_180046508 = (*(*arg1 + 0x108))(arg1, rax_195, "contains", 
                                "(Ljava/lang/Object;)Z", var_98);
                            int64_t rdx_115 = *arg1;
                            
                            if ((*(rdx_115 + 0x720))(arg1, rdx_115))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_195);
                        }
                        
                        int64_t rax_201 = (*(*arg1 + 0x30))(arg1, "java/util/UUID");
                        
                        if (rax_201)
                        {
                            data_180046590 = (*(*arg1 + 0x108))(arg1, rax_201, 
                                "getMostSignificantBits", &data_180033728, var_98);
                            data_180046598 = (*(*arg1 + 0x108))(arg1, rax_201, 
                                "getLeastSignificantBits", &data_180033728);
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_201);
                        }
                        
                        if ((*(*arg1 + 0x720))(arg1))
                            (*(*arg1 + 0x88))(arg1);
                        
                        int64_t rax_211;
                        int512_t zmm2_22;
                        rax_211 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.login.ClientboundGameProfilePacket", 
                            "Lnet/minecraft/network/protocol/login/ClientboundGameProfilePacket;", 
                            zmm2_21);
                        
                        if (rax_211)
                        {
                            int64_t r8_39 = *arg1;
                            data_1800465a0 = (*(r8_39 + 0xa8))(arg1, rax_211, r8_39);
                            int64_t rax_213;
                            rax_213 =
                                sub_180012ff0(rax_211, "(Lcom/mojang/authlib/GameProfile;)V", 0);
                            data_1800465a8 = rax_213;
                            int64_t r8_40 = *arg1;
                            (*(r8_40 + 0xb8))(arg1, rax_211, r8_40);
                        }
                        
                        int64_t rax_214;
                        int512_t zmm2_23;
                        rax_214 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.login.ServerboundHelloPacket", 
                            "Lnet/minecraft/network/protocol/login/ServerboundHelloPacket;", 
                            zmm2_22);
                        
                        if (rax_214)
                        {
                            int64_t r8_41 = *arg1;
                            data_1800465b0 = (*(r8_41 + 0xa8))(arg1, rax_214, r8_41);
                            int64_t rax_216;
                            rax_216 = sub_180012e10(rax_214, "Ljava/lang/String;", 0);
                            data_1800465b8 = rax_216;
                            int64_t r8_42 = *arg1;
                            (*(r8_42 + 0xb8))(arg1, rax_214, r8_42);
                        }
                        
                        int64_t rax_217;
                        int512_t zmm2_24;
                        rax_217 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.handshake.ClientIntentionPacket", 
                            "Lnet/minecraft/network/protocol/handshake/ClientIntentionPacket;", 
                            zmm2_23);
                        
                        if (rax_217)
                        {
                            int64_t r8_43 = *arg1;
                            data_1800465c0 = (*(r8_43 + 0xa8))(arg1, rax_217, r8_43);
                            int64_t rax_219;
                            rax_219 = sub_180012e10(rax_217, 
                                "Lnet/minecraft/network/ConnectionProtocol;", 0);
                            data_1800462f8 = rax_219;
                            int64_t r8_44 = *arg1;
                            (*(r8_44 + 0xb8))(arg1, rax_217, r8_44);
                        }
                        
                        int64_t rax_220;
                        int512_t zmm2_25;
                        rax_220 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.status.ServerboundStatusRequestPacket", 
                            "Lnet/minecraft/network/protocol/status/ServerboundStatusRequestPacket;", 
                            zmm2_24);
                        
                        if (rax_220)
                        {
                            int64_t r8_45 = *arg1;
                            data_1800462e0 = (*(r8_45 + 0xa8))(arg1, rax_220, r8_45);
                            int64_t r8_46 = *arg1;
                            (*(r8_46 + 0xb8))(arg1, rax_220, r8_46);
                        }
                        
                        int64_t rax_222;
                        int512_t zmm2_26;
                        rax_222 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.status.ServerboundPingRequestPacket", 
                            "Lnet/minecraft/network/protocol/status/ServerboundPingRequestPacket;", 
                            zmm2_25);
                        
                        if (rax_222)
                        {
                            int64_t r8_47 = *arg1;
                            data_1800462e8 = (*(r8_47 + 0xa8))(arg1, rax_222, r8_47);
                            int64_t rax_224;
                            rax_224 = sub_180012e10(rax_222, &data_180033a64, 0);
                            data_1800462f0 = rax_224;
                            int64_t r8_48 = *arg1;
                            (*(r8_48 + 0xb8))(arg1, rax_222, r8_48);
                        }
                        
                        int64_t rax_225;
                        int512_t zmm2_27;
                        rax_225 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.status.ClientboundPongResponsePacket", 
                            "Lnet/minecraft/network/protocol/status/ClientboundPongResponsePacket;", 
                            zmm2_26);
                        
                        if (rax_225)
                        {
                            int64_t r8_49 = *arg1;
                            data_1800462d0 = (*(r8_49 + 0xa8))(arg1, rax_225, r8_49);
                            int64_t rax_227;
                            rax_227 = sub_180012ff0(rax_225, "(J)V", 0);
                            data_1800462d8 = rax_227;
                            (*(*arg1 + 0xb8))(arg1, rax_225);
                        }
                        
                        int64_t rax_229;
                        int512_t zmm2_28;
                        rax_229 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.status.ClientboundStatusResponsePacket", 
                            "Lnet/minecraft/network/protocol/status/ClientboundStatusResponsePacket;", 
                            zmm2_27);
                        
                        if (rax_229)
                        {
                            int64_t r8_50 = *arg1;
                            data_1800462b0 = (*(r8_50 + 0xa8))(arg1, rax_229, r8_50);
                            int64_t rax_231;
                            rax_231 = sub_180012ff0(rax_229, 
                                "(Lnet/minecraft/network/protocol/status/ServerStatus;)V", 0);
                            data_1800462b8 = rax_231;
                            int64_t r8_51 = *arg1;
                            (*(r8_51 + 0xb8))(arg1, rax_229, r8_51);
                        }
                        
                        int64_t rax_232;
                        int512_t zmm2_29;
                        rax_232 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.status.ServerStatus", 
                            "Lnet/minecraft/network/protocol/status/ServerStatus;", zmm2_28);
                        
                        if (rax_232)
                        {
                            int64_t r8_52 = *arg1;
                            data_1800462c0 = (*(r8_52 + 0xa8))(arg1, rax_232, r8_52);
                            int64_t r8_53 = *arg1;
                            (*(r8_53 + 0xb8))(arg1, rax_232, r8_53);
                        }
                        
                        int64_t rax_234;
                        int512_t zmm2_30;
                        rax_234 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundPlayerPositionPacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundPlayerPositionPacket;", 
                            zmm2_29);
                        
                        if (rax_234)
                        {
                            int64_t r8_54 = *arg1;
                            data_1800465c8 = (*(r8_54 + 0xa8))(arg1, rax_234, r8_54);
                            int64_t rax_236;
                            rax_236 = sub_180012ff0(rax_234, "(DDDFFLjava/util/Set;I)V", 0);
                            data_1800465d0 = rax_236;
                            int64_t r8_55 = *arg1;
                            (*(r8_55 + 0xb8))(arg1, rax_234, r8_55);
                        }
                        
                        int64_t rax_238 = (*(*arg1 + 0x30))(arg1, "java/util/Set");
                        
                        if (rax_238)
                        {
                            int64_t r8_56 = *arg1;
                            data_1800465d8 = (*(r8_56 + 0xa8))(arg1, rax_238, r8_56);
                            data_1800465e0 = (*(*arg1 + 0x388))(arg1, rax_238, &data_180033d2c, 
                                "()Ljava/util/Set;", var_98);
                            (*(*arg1 + 0xb8))(arg1, rax_238);
                        }
                        
                        int64_t rax_242;
                        int512_t zmm2_31;
                        rax_242 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundKeepAlivePacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundKeepAlivePacket;", 
                            zmm2_30);
                        
                        if (rax_242)
                        {
                            int64_t r8_57 = *arg1;
                            data_1800465e8 = (*(r8_57 + 0xa8))(arg1, rax_242, r8_57);
                            int64_t rax_244;
                            rax_244 = sub_180012ff0(rax_242, "(J)V", 0);
                            data_1800465f0 = rax_244;
                            int64_t r8_58 = *arg1;
                            (*(r8_58 + 0xb8))(arg1, rax_242, r8_58);
                        }
                        
                        int64_t rax_245;
                        int64_t rdx_154;
                        int512_t zmm2_32;
                        rax_245 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundBundlePacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundBundlePacket;", 
                            zmm2_31);
                        
                        if (!rax_245)
                            sub_1800023a0("BServer: ClientboundBundlePacket not found ", rdx_154);
                        else
                        {
                            int64_t r8_59 = *arg1;
                            data_180046608 = (*(r8_59 + 0xa8))(arg1, rax_245, r8_59);
                            int64_t rax_247 = sub_180013ac0(arg1, arg2, 
                                "net.minecraft.network.protocol.BundlePacket", 
                                "Lnet/minecraft/network/protocol/BundlePacket;", zmm2_32);
                            
                            if (rax_247)
                            {
                                data_180046610 =
                                    sub_180012ff0(rax_247, "()Ljava/lang/Iterable;", 0);
                                int64_t r8_60 = *arg1;
                                (*(r8_60 + 0xb8))(arg1, rax_247, r8_60);
                            }
                            
                            (*(*arg1 + 0xb8))(arg1, rax_245);
                        }
                        
                        int64_t rax_251 = (*(*arg1 + 0x30))(arg1, "java/lang/Iterable");
                        
                        if (rax_251)
                        {
                            data_180046618 = (*(*arg1 + 0x108))(arg1, rax_251, "iterator", 
                                "()Ljava/util/Iterator;", var_98);
                            int64_t r8_61 = *arg1;
                            (*(r8_61 + 0xb8))(arg1, rax_251, r8_61);
                        }
                        
                        int64_t rax_254 = (*(*arg1 + 0x30))(arg1, "java/util/Iterator");
                        
                        if (rax_254)
                        {
                            data_180046620 = (*(*arg1 + 0x108))(arg1, rax_254, "hasNext", 
                                &data_1800333b8, var_98);
                            data_180046628 =
                                (*(*arg1 + 0x108))(arg1, rax_254, "next", "()Ljava/lang/Object;");
                            (*(*arg1 + 0xb8))(arg1, rax_254);
                        }
                        
                        if ((*(*arg1 + 0x720))(arg1))
                            (*(*arg1 + 0x88))(arg1);
                        
                        int64_t rax_262 = (*(*arg1 + 0x30))(arg1, "java/util/UUID");
                        
                        if (rax_262)
                        {
                            int64_t r8_62 = *arg1;
                            data_1800465f8 = (*(r8_62 + 0xa8))(arg1, rax_262, r8_62);
                            data_180046600 = (*(*arg1 + 0x388))(arg1, rax_262, "nameUUIDFromBytes", 
                                "([B)Ljava/util/UUID;", var_98);
                            (*(*arg1 + 0xb8))(arg1, rax_262);
                        }
                        
                        int64_t rax_266 = data_180046600;
                        data_180046288;
                        data_180046280;
                        int64_t rax_267 = data_1800465b8;
                        int64_t rax_268 = data_1800465a8;
                        int64_t rax_269 = data_1800463c8;
                        int64_t rax_270 = data_180046388;
                        int64_t rax_271 = data_180046368;
                        int64_t rax_272 = data_180046318;
                        int64_t rax_273 = data_180046300;
                        int64_t rax_274 = data_1800462a0;
                        int64_t rax_275 = data_180046298;
                        int64_t rax_276 = data_180046290;
                        var_98 = data_180046398;
                        int512_t zmm2_33 = sub_1800023a0(
                            "cacheJavaRefs: configureSer=%p send=%p attrProtoFid=%p bundlerFid=%p "
                        "protoHS=%p protoLOGIN=%p protoPLAY=%p flowSB=%p pipMid=%p addLast=%p "
                        "attrSet=%p gpCtor=%p lfpCtor=%p helloName=%p uuidFromBytes=%p", 
                            data_180046278);
                        
                        if ((*(*arg1 + 0x720))(arg1))
                            (*(*arg1 + 0x88))(arg1);
                        
                        int64_t rcx_246 = data_1800463d0;
                        
                        if (rcx_246)
                        {
                            int64_t rax_281 = sub_180012ff0(rcx_246, 
                                "()Lnet/minecraft/client/multiplayer/ClientPacketListener;", 0);
                            int64_t rcx_247 = data_1800463d0;
                            data_1800466e8 = rax_281;
                            int64_t rax_282 = sub_180012e10(rcx_247, 
                                "Lnet/minecraft/client/player/LocalPlayer;", 0);
                            int64_t rcx_248 = data_1800463d0;
                            data_180046718 = rax_282;
                            int64_t rax_283 = sub_180012e10(rcx_248, 
                                "Lnet/minecraft/client/multiplayer/MultiPlayerGameMode;", 0);
                            int64_t rcx_249 = data_1800463d0;
                            data_180046720 = rax_283;
                            int64_t rax_284;
                            rax_284 = sub_180012e10(rcx_249, 
                                "Lnet/minecraft/client/multiplayer/ClientLevel;", 0);
                            data_180046728 = rax_284;
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                        }
                        
                        int64_t rax_288;
                        int512_t zmm2_34;
                        rax_288 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.client.multiplayer.ClientPacketListener", 
                            "Lnet/minecraft/client/multiplayer/ClientPacketListener;", zmm2_33);
                        
                        if (rax_288)
                        {
                            int64_t r8_64 = *arg1;
                            data_1800466f0 = (*(r8_64 + 0xa8))(arg1, rax_288, r8_64);
                            data_1800466f8 =
                                sub_180012ff0(rax_288, "()Lnet/minecraft/network/Connection;", 0);
                            data_180046700 = sub_180012ff0(rax_288, "()Ljava/util/Set;", 0);
                            int64_t rax_292;
                            rax_292 =
                                sub_180012ff0(rax_288, "()Lnet/minecraft/core/RegistryAccess;", 0);
                            data_180046708 = rax_292;
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_288);
                        }
                        
                        int64_t rax_297;
                        int512_t zmm2_35;
                        rax_297 = sub_180013ac0(arg1, arg2, "net.minecraft.core.RegistryAccess", 
                            "Lnet/minecraft/core/RegistryAccess;", zmm2_34);
                        
                        if (rax_297)
                        {
                            int64_t rax_298;
                            rax_298 = sub_180012ff0(rax_297, 
                                "()Lnet/minecraft/core/RegistryAccess$Frozen;", 0);
                            data_180046710 = rax_298;
                            int64_t rdx_172 = *arg1;
                            
                            if ((*(rdx_172 + 0x720))(arg1, rdx_172))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_297);
                        }
                        
                        int64_t rax_302;
                        int512_t zmm2_36;
                        rax_302 = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.client.multiplayer.MultiPlayerGameMode", 
                            "Lnet/minecraft/client/multiplayer/MultiPlayerGameMode;", zmm2_35);
                        
                        if (rax_302)
                        {
                            int64_t rax_303;
                            rax_303 =
                                sub_180012ff0(rax_302, "()Lnet/minecraft/world/level/GameType;", 0);
                            data_180046730 = rax_303;
                            int64_t rdx_175 = *arg1;
                            
                            if ((*(rdx_175 + 0x720))(arg1, rdx_175))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_302);
                        }
                        
                        int64_t rax_307;
                        int512_t zmm2_37;
                        rax_307 = sub_180013ac0(arg1, arg2, "net.minecraft.world.level.Level", 
                            "Lnet/minecraft/world/level/Level;", zmm2_36);
                        
                        if (rax_307)
                        {
                            int64_t r8_65 = *arg1;
                            var_98 = 2;
                            data_180046738 = (*(r8_65 + 0xa8))(arg1, rax_307, r8_65);
                            var_38 = {0};
                            int32_t rax_309 = sub_1800133e0(rax_307, 
                                "()Lnet/minecraft/resources/ResourceKey;", 0, &var_38, 2);
                            data_180046740 = var_38;
                            data_180046748 = *(&var_38 + 8);
                            zmm2_37 = sub_1800023a0("  level: %d ()ResourceKey method(s)", rax_309);
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_307);
                        }
                        
                        int64_t rax_315 = (*(*arg1 + 0x30))(arg1, "java/lang/Object");
                        
                        if (rax_315)
                        {
                            data_180046750 = (*(*arg1 + 0x108))(arg1, rax_315, "toString", 
                                "()Ljava/lang/String;", var_98, rax_276, rax_275, rax_274, rax_273, 
                                rax_272, rax_271, rax_270, rax_269, rax_268, rax_267, rax_266);
                            int64_t rdx_182 = *arg1;
                            
                            if ((*(rdx_182 + 0x720))(arg1, rdx_182))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_315);
                        }
                        
                        int64_t rax_321 = (*(*arg1 + 0x30))(arg1, "java/util/Optional");
                        
                        if (rax_321)
                        {
                            int64_t r8_66 = *arg1;
                            data_180046768 = (*(r8_66 + 0xa8))(arg1, rax_321, r8_66);
                            data_180046770 = (*(*arg1 + 0x388))(arg1, rax_321, "empty", 
                                "()Ljava/util/Optional;", var_98, rax_276, rax_275, rax_274, 
                                rax_273, rax_272, rax_271, rax_270, rax_269, rax_268, rax_267, 
                                rax_266);
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            (*(*arg1 + 0xb8))(arg1, rax_321);
                        }
                        
                        result = sub_180013ac0(arg1, arg2, 
                            "net.minecraft.network.protocol.game.ClientboundLoginPacket", 
                            "Lnet/minecraft/network/protocol/game/ClientboundLoginPacket;", 
                            zmm2_37);
                        
                        if (result)
                        {
                            data_180046758 = (*(*arg1 + 0xa8))(arg1, result);
                            data_180046760 = (*(*arg1 + 0x108))(arg1, result, "<init>", 
                                "(IZLnet/minecraft/world/level/GameType;"
                            "Lnet/minecraft/world/level/GameType;Ljava/util/Set;"
                            "Lnet/minecraft/core/RegistryAccess$Frozen;"
                            "Lnet/minecraft/resources/ResourceKey;"
                            "Lnet/minecraft/resources/ResourceKey;JIIIZZZZLjava/util/Optional;I)V", 
                                var_98, rax_276, rax_275, rax_274, rax_273, rax_272, rax_271, 
                                rax_270, rax_269, rax_268, rax_267, rax_266);
                            
                            if ((*(*arg1 + 0x720))(arg1))
                                (*(*arg1 + 0x88))(arg1);
                            
                            char const* const rdx_190 = "MISSING";
                            
                            if (data_180046760)
                                rdx_190 = "resolved";
                            
                            sub_1800023a0("  login ctor %s", rdx_190);
                            (*(*arg1 + 0xb8))(arg1, result);
                        }
                        
                        if (data_180046278 && data_180046280 && data_180046300 && data_180046318
                            && data_180046368 && data_180046320 && data_180046328
                            && data_180046388)
                        {
                            result = 1;
                            return result;
                        }
                    }
                }
            }
        }
    }
    
    result = 0;
    return result;
}

