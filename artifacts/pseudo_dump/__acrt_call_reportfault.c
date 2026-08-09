
  int32_t __acrt_call_reportfault(int32_t arg1, int32_t arg2)

{
    void var_608;
    int64_t rax_1 = __security_cookie ^ &var_608;
    
    if (arg1 != 0xffffffff)
        sub_180016fd0();
    
    int32_t var_598;
    sub_18002de50(&var_598, 0, 0x98);
    void ContextRecord;
    sub_18002de50(&ContextRecord, 0, 0x4d0);
    uint64_t EstablisherFrame = 0;
    uint64_t ImageBase = 0;
    int64_t HandlerData = 0;
    EXCEPTION_POINTERS ExceptionInfo;
    ExceptionInfo.ExceptionRecord = &var_598;
    ExceptionInfo.ContextRecord = &ContextRecord;
    RtlCaptureContext(&ContextRecord);
    uint64_t ControlPc;
    IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry =
        RtlLookupFunctionEntry(ControlPc, &ImageBase, nullptr);
    
    if (FunctionEntry)
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, ImageBase, ControlPc, FunctionEntry, &ContextRecord, 
            &HandlerData, &EstablisherFrame, nullptr);
    
    void* const __return_addr_2 = __return_addr;
    var_598 = arg2;
    void arg_8;
    void* var_460 = &arg_8;
    void* const __return_addr_1 = __return_addr;
    int32_t r8;
    int32_t var_594 = r8;
    BOOL rax_4 = IsDebuggerPresent();
    SetUnhandledExceptionFilter(nullptr);
    int32_t result = UnhandledExceptionFilter(&ExceptionInfo);
    
    if (!result && !rax_4 && arg1 != 0xffffffff)
        sub_180016fd0();
    
    __security_check_cookie(rax_1 ^ &var_608);
    return result;
}

