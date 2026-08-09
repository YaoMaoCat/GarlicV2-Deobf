
  void sub_180004470(int64_t arg1, int64_t arg2, void** arg3)

{
    void** rbx = arg3;
    
    if (*(arg3 + 0x19))
        return;
    
    do
    {
        sub_180004470(arg1, arg2, rbx[2]);
        void** rcx_1 = rbx;
        rbx = *rbx;
        j_sub_180021340(rcx_1);
    } while (!*(rbx + 0x19));
}

