
  void* sub_18002d2a0(int64_t arg1)

{
    void* result = _ValidateImageBase(&__dos_header);
    
    if (result)
    {
        result = sub_18002d250(&__dos_header, arg1 - &__dos_header);
        
        if (result)
            return ~*(result + 0x24) >> 0x1f;
    }
    
    return result;
}

