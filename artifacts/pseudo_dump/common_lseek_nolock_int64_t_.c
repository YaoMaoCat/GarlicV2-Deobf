
  int64_t common_lseek_nolock<int64_t>(int32_t arg1, int64_t arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3, void* arg4)

{
    int64_t rdi = arg1;
    HANDLE hFile = _get_osfhandle(rdi);
    
    if (hFile != -1)
    {
        int64_t newFilePointer[0x2];
        newFilePointer[0] = 0;
        
        if (SetFilePointerEx(hFile, arg2, &newFilePointer, arg3))
        {
            int64_t result = newFilePointer[0];
            
            if (result != -1)
            {
                uint64_t rdx_4 = (rdi & 0x3f) * 9;
                int64_t rcx_5 = (&data_180047840)[rdi >> 6];
                *(rcx_5 + (rdx_4 << 3) + 0x38) &= 0xfd;
                return result;
            }
        }
        else
            __acrt_errno_map_os_error_ptd(GetLastError(), arg4);
    }
    else
    {
        *(arg4 + 0x30) = 1;
        *(arg4 + 0x2c) = 9;
    }
    
    return -1;
}

