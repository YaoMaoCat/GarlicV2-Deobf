
🌐  uint8_t __acrt_app_verifier_enabled()

{
    TEB* gsbase;
    return gsbase->NtTib.Self->ProcessEnvironmentBlock->NtGlobalFlag >> 8 & 1;
}

