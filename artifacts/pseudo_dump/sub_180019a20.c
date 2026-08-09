
  int64_t sub_180019a20(int64_t* arg1)

{
    int32_t* rdi = *arg1;
    int32_t rax = *rdi;
    
    if (rax == 0xe0434352 || rax == 0xe0434f4d)
    {
        if (*(sub_180019c40() + 0x30) > 0)
        {
            void* rax_2 = sub_180019c40();
            *(rax_2 + 0x30) -= 1;
        }
    }
    else if (rax == 0xe06d7363)
    {
        *(sub_180019c40() + 0x20) = rdi;
        *(sub_180019c40() + 0x28) = arg1[1];
        sub_180020b48();
        /* no return */
    }
    
    return 0;
}

