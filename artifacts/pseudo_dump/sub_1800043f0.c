
  void sub_1800043f0(int64_t arg1, int64_t arg2, void** arg3)

{
    void** rbx = arg3;
    
    if (*(arg3 + 0x19))
        return;
    
    do
    {
        sub_1800043f0(arg1, arg2, rbx[2]);
        void** rdi_1 = rbx;
        rbx = *rbx;
        j_sub_180003a30(&rdi_1[4]);
        j_sub_180021340(rdi_1);
    } while (!*(rbx + 0x19));
}

