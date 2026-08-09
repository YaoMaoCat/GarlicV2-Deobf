
  int64_t sub_180004ce0(int64_t* arg1)

{
    void** rbx_1 = *(*arg1 + 8);
    
    while (!*(rbx_1 + 0x19))
    {
        sub_180004470(arg1, arg1, rbx_1[2]);
        void** rcx_1 = rbx_1;
        rbx_1 = *rbx_1;
        j_sub_180021340(rcx_1);
    }
    
    /* tailcall */
    return j_sub_180021340(*arg1);
}

