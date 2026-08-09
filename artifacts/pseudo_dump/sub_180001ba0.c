
  int64_t sub_180001ba0(HMODULE arg1, int32_t arg2, int64_t* arg3)

{
    if (arg2 == 1)
    {
        if (!sub_180001ac0(arg3))
        {
            sub_1800019f0("[auth] GarlicProxy internal verification failed");
            return 0;
        }
        
        sub_1800019f0("[auth] GarlicProxy internal verification passed");
        sub_1800019f0("[raw] DllMain entry");
        DisableThreadLibraryCalls(arg1);
        sub_1800019f0("[raw] DisableThreadLibraryCalls done");
        HANDLE hObject = CreateThread(nullptr, 0, sub_1800014d0, nullptr, 
            THREAD_CREATE_RUN_IMMEDIATELY, nullptr);
        
        if (hObject)
            CloseHandle(hObject);
        
        sub_1800023a0("=== DllMain PROCESS_ATTACH ===", sub_1800019f0("[raw] CreateThread done"));
        sub_1800019f0("[raw] first LogTo returned");
    }
    
    return 1;
}

