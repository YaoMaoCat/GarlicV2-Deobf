
  BOOL InitializeCriticalSectionEx(CRITICAL_SECTION* lpCriticalSection, uint32_t dwSpinCount, uint32_t Flags)

{
    /* tailcall */
    return InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags);
}

