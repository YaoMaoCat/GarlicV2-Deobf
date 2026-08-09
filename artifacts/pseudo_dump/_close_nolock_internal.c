
🌐  int64_t _close_nolock_internal(int32_t arg1, void* arg2)

{
    int64_t rdi = arg1;
    enum WIN32_ERROR rbx_2;
    
    if (_get_osfhandle(rdi) != -1)
    {
        void* rax_1 = data_180047840;
        int64_t rax_2;
        int64_t rax_3;
        
        if ((rdi == 1 && *(rax_1 + 0xc8) & rdi) || (rdi == 2 && *(rax_1 + 0x80) & 1))
        {
            rax_2 = _get_osfhandle(2);
            rax_3 = _get_osfhandle(1);
        }
        
        if (((rdi == 1 && *(rax_1 + 0xc8) & rdi) || (rdi == 2 && *(rax_1 + 0x80) & 1))
                && rax_3 == rax_2)
            rbx_2 = NO_ERROR;
        else if (CloseHandle(_get_osfhandle(rdi)))
            rbx_2 = NO_ERROR;
        else
            rbx_2 = GetLastError();
    }
    else
        rbx_2 = NO_ERROR;
    
    _free_osfhnd(rdi);
    *((&data_180047840)[rdi >> 6] + (rdi & 0x3f) * 0x48 + 0x38) = 0;
    
    if (!rbx_2)
        return 0;
    
    __acrt_errno_map_os_error_ptd(rbx_2, arg2);
    return 0xffffffff;
}

