
  int64_t sub_1800014d0()

{
    int64_t entry_rdx;
    sub_1800023a0("BootstrapThread start; waiting for jvm.dll", entry_rdx);
    HMODULE hModule_1 = GetModuleHandleA("jvm.dll");
    HMODULE hModule = hModule_1;
    
    if (!hModule_1)
    {
        HMODULE i;
        
        do
        {
            Sleep(0x32);
            i = GetModuleHandleA("jvm.dll");
            hModule = i;
        } while (!i);
    }
    
    sub_1800023a0("jvm.dll loaded at %p", hModule);
    int64_t rax;
    int64_t rdx_1;
    rax = GetProcAddress(hModule, "JNI_GetCreatedJavaVMs");
    
    if (!rax)
    {
        sub_1800023a0("GetProcAddress(JNI_GetCreatedJavaVMs) FAILED", rdx_1);
        return 0;
    }
    
    int32_t rbx = 0;
    char const* const rcx_1;
    int64_t rdx_2;
    
    while (true)
    {
        int32_t arg_10 = 0;
        int32_t rax_2 = rax(&data_180047460, 1, &arg_10);
        
        if (!rax_2 && arg_10 >= 1)
            rdx_2 = data_180047460;
        
        if (rax_2 || arg_10 < 1 || !rdx_2)
        {
            data_180047460 = 0;
            Sleep(0x1f4);
            rbx += 1;
            
            if (rbx < 0x258)
                continue;
            else
            {
                rdx_2 = data_180047460;
                
                if (!rdx_2)
                {
                    rcx_1 = "BootstrapThread: JVM never appeared";
                    break;
                }
            }
        }
        
        sub_1800023a0("Got JavaVM=%p", rdx_2);
        int64_t* rcx_2 = data_180047460;
        int64_t var_28 = 0x10008;
        char const* const var_20_1 = "MinecraftProxyBoot";
        int64_t var_18_1 = 0;
        int64_t arg_18 = 0;
        int32_t rax_4;
        rax_4 = (*(*rcx_2 + 0x38))(rcx_2, &arg_18, &var_28);
        
        if (!rax_4)
        {
            rdx_2 = arg_18;
            
            if (rdx_2)
            {
                sub_1800023a0("BootstrapThread: attached, env=%p", rdx_2);
                int64_t* rcx_3 = data_180047460;
                int32_t rax_6;
                int64_t rdx_4;
                rax_6 = (*(*rcx_3 + 0x30))(rcx_3, &data_180047468, 0x30010200);
                
                if (rax_6)
                {
                    data_180047468 = 0;
                    sub_1800023a0("GetEnv(JVMTI) FAILED", rdx_4);
                    int64_t* rcx_4 = data_180047460;
                    (*(*rcx_4 + 0x28))(rcx_4);
                    return 0;
                }
                
                sub_1800023a0("InitializeProxy: spawning bootstrap worker", 
                    sub_1800023a0("Got jvmtiEnv=%p", data_180047468));
                HANDLE hObject = CreateThread(nullptr, 0, sub_180001740, nullptr, 
                    THREAD_CREATE_RUN_IMMEDIATELY, nullptr);
                
                if (hObject)
                    CloseHandle(hObject);
                
                int64_t* rcx_6 = data_180047460;
                (*(*rcx_6 + 0x28))(rcx_6);
                return 0;
            }
        }
        
        rcx_1 = "BootstrapThread: AttachCurrentThreadAsDaemon FAILED";
        break;
    }
    
    sub_1800023a0(rcx_1, rdx_2);
    return 0;
}

