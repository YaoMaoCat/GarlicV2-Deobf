
  uint64_t sub_18002ec30(int64_t arg1, void* arg2, int512_t arg3 @ zmm1)

{
    *(arg2 + 0x48) = arg1;
    void* rax = sub_180019c40();
    *(rax + 0x70) = *(arg2 + 0x80);
    int64_t* rdi = *(arg2 + 0x98);
    *(sub_180019c40() + 0x60) = rdi[1];
    *(sub_180019c40() + 0x68) = *(**(arg2 + 0x48) + 0x38);
    void* rax_4 = sub_180019c40();
    *(rax_4 + 0x78) = *(arg2 + 0xb8);
    sub_18001c000(**(arg2 + 0x48), *(arg2 + 0x88), *(arg2 + 0x90), rdi, arg3, *(arg2 + 0xa0), 0, 0, 
        1);
    *(sub_180019c40() + 0x70) = 0;
    *(arg2 + 0x40) = 1;
    *(arg2 + 0x44) = 1;
    return *(arg2 + 0x44);
}

