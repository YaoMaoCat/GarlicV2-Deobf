
  void sub_180002210(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2)

{
    if (!arg1 || !(*(*arg1 + 0x720))())
        return;
    
    int64_t rax_3 = (*(*arg1 + 0x78))(arg1);
    int64_t rdx = *arg1;
    (*(rdx + 0x88))(arg1, rdx);
    int64_t r8_1 = *arg1;
    int64_t rax_4 = (*(r8_1 + 0x30))(arg1, "java/lang/Throwable", r8_1);
    int64_t rax_5;
    int64_t r9_1;
    rax_5 = (*(*arg1 + 0x108))(arg1, rax_4, "toString", "()Ljava/lang/String;");
    int64_t rax_6 = sub_180001cd0(arg1, rax_3, arg3, r9_1);
    int512_t zmm2;
    
    if (!rax_6)
        zmm2 = sub_180001d30("[%s] %s", arg2);
    else
    {
        int64_t r9_2 = *arg1;
        int64_t rax_7 = (*(r9_2 + 0x548))(arg1, rax_6, 0, r9_2);
        zmm2 = sub_180001d30("[%s] %s", arg2);
        int64_t r9_3 = *arg1;
        (*(r9_3 + 0x550))(arg1, rax_6, rax_7, r9_3);
    }
    
    int64_t rax_9;
    int64_t r9_4;
    rax_9 = (*(*arg1 + 0x108))(arg1, rax_4, "printStackTrace", &data_180030c10);
    
    if (rax_9)
        sub_180001d00(arg1, rax_3, zmm2, r9_4);
    
    if ((*(*arg1 + 0x720))(arg1))
        (*(*arg1 + 0x88))(arg1);
    
    (*(*arg1 + 0xb8))(arg1, rax_3);
    (*(*arg1 + 0xb8))(arg1, rax_4);
    
    if (rax_6)
        (*(*arg1 + 0xb8))(arg1, rax_6);
}

