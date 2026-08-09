
  int64_t sub_180001740()

{
    void var_168;
    int64_t rax_1 = __security_cookie ^ &var_168;
    int64_t entry_rdx;
    sub_1800023a0("ProxyInitWorker: attaching to JVM as daemon", entry_rdx);
    int64_t* rcx = data_180047460;
    int32_t rbx = 0;
    int64_t var_130 = 0x10008;
    char const* const var_128 = "MinecraftProxyInit";
    int64_t var_120 = 0;
    int64_t* var_138 = nullptr;
    int32_t rax_3;
    int64_t rdx_1;
    rax_3 = (*(*rcx + 0x38))(rcx, &var_138, &var_130);
    
    if (rax_3 || !var_138)
        sub_1800023a0("ProxyInitWorker: AttachCurrentThreadAsDaemon FAILED", rdx_1);
    else
    {
        sub_1800023a0("ProxyInitWorker: attached; polling for MC ClassLoader", rdx_1);
        
        while (true)
        {
            if (sub_18000adb0(var_138))
            {
                int64_t* rdi_1 = &data_180046068;
                int64_t* rdx_3 = &data_180046068;
                
                if (data_180046080 > 0xf)
                    rdx_3 = data_180046068;
                
                sub_1800023a0("ProxyInitWorker: InstallHookBridge OK: %s", rdx_3);
                char rax_6;
                int64_t rdx_4;
                rax_6 = sub_18000b770(var_138);
                char const* const rcx_4;
                
                if (rax_6)
                {
                    int64_t* rbx_1 = &data_1800460c0;
                    int64_t* rdx_5 = &data_1800460c0;
                    
                    if (data_1800460d8 > 0xf)
                        rdx_5 = data_1800460c0;
                    
                    sub_1800023a0("ProxyInitWorker: InstallRelayHandler OK: %s", rdx_5);
                    
                    if (data_1800460d8 > 0xf)
                        rbx_1 = data_1800460c0;
                    
                    int64_t* var_148_1 = rbx_1;
                    
                    if (data_180046080 > 0xf)
                        rdi_1 = data_180046068;
                    
                    void var_118;
                    int512_t zmm2_1 =
                        sub_180001c70(&var_118, 0x100, "bridge=%s relay=%s (installed)", rdi_1);
                    int64_t* rcx_9 = var_138;
                    int64_t rax_10 = (*(*rcx_9 + 0x538))(rcx_9, &var_118);
                    data_180046040;
                    sub_180001710(var_138, data_180046030, zmm2_1, rax_10);
                    sub_180002210(var_138, "InitializeProxy/trace", zmm2_1);
                    int64_t* rcx_12 = var_138;
                    int64_t r8_2 = *rcx_12;
                    int64_t rdx_9 = (*(r8_2 + 0xb8))(rcx_12, rax_10, r8_2);
                    char rax_11;
                    rax_11 = sub_18000d7f0(var_138, rdx_9);
                    
                    if (rax_11)
                    {
                        sub_1800023a0("ProxyInitWorker: InstallConnectionHook OK", rdx_4);
                        char rax_12;
                        int64_t rdx_10;
                        rax_12 = sub_18000ea20(var_138);
                        
                        if (rax_12)
                        {
                            sub_1800023a0("ProxyInitWorker: InstallBServer OK ", rdx_10);
                            char rax_13;
                            int64_t rdx_11;
                            rax_13 = sub_18000e010(var_138);
                            
                            if (!rax_13)
                            {
                                char const* const rcx_17 =
                                    "ProxyInitWorker: Queued A Render thread blocking gate task";
                                
                                if (!sub_18000dac0(var_138))
                                    rcx_17 = "ProxyInitWorker: Failed to queue A Render thread "
                                    "blocking gate task";
                                
                                rdx_4 = sub_1800023a0(rcx_17, 
                                    "ProxyInitWorker: Failed to queue A Render thread blocking gate task");
                                rcx_4 = "ProxyInitWorker: done ";
                            }
                            else
                            {
                                rdx_4 = sub_1800023a0("ProxyInitWorker: mid-session ", rdx_11);
                                rcx_4 = "ProxyInitWorker: done ";
                            }
                        }
                        else
                        {
                            rdx_4 = sub_1800023a0(
                                "ProxyInitWorker: InstallBServer FAILED (B-side proxy unavailable)", 
                                rdx_10);
                            rcx_4 = "ProxyInitWorker: done ";
                        }
                    }
                    else
                        rcx_4 = "ProxyInitWorker: InstallConnectionHook FAILED";
                }
                else
                    rcx_4 = "ProxyInitWorker: InstallRelayHandler FAILED";
                
                sub_1800023a0(rcx_4, rdx_4);
                int64_t* rcx_5 = data_180047460;
                (*(*rcx_5 + 0x28))(rcx_5);
                break;
            }
            
            int64_t rdx_2 = Sleep(0x1f4);
            rbx += 1;
            
            if (rbx >= 0xf0)
            {
                sub_1800023a0("ProxyInitWorker: gave up waiting for MC ClassLoader", rdx_2);
                int64_t* rcx_2 = data_180047460;
                (*(*rcx_2 + 0x28))(rcx_2);
                break;
            }
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_168);
    return 0;
}

