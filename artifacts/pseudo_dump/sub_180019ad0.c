
  SLIST_ENTRY* sub_180019ad0(SLIST_HEADER* arg1)

{
    SLIST_ENTRY* result = InterlockedFlushSList(arg1);
    
    if (result)
    {
        struct _SLIST_ENTRY* Next;
        
        do
        {
            Next = result->Next;
            j_sub_180021340(result);
            result = Next;
        } while (Next);
    }
    
    return result;
}

