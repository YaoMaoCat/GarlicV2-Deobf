
🌐  uint64_t __acrt_is_secure_process()

{
    TEB* gsbase;
    return gsbase->NtTib.Self->ProcessEnvironmentBlock->ProcessParameters->Flags >> 0x1f;
}

