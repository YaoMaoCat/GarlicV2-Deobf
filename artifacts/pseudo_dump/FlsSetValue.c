
  BOOL FlsSetValue(uint32_t dwFlsIndex, void* lpFlsData)

{
    /* tailcall */
    return FlsSetValue(dwFlsIndex, lpFlsData);
}

