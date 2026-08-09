
  int64_t sub_1800020f0(int64_t* arg1, int64_t arg2, int64_t arg3, int512_t arg4 @ zmm2)

{
    if (!arg1 || !arg2 || !arg3)
        return 0;
    
    int64_t rax_1 = (*(*arg1 + 0xf8))();
    int64_t rax_2 =
        (*(*arg1 + 0x108))(arg1, rax_1, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");
    int64_t r8 = *arg1;
    
    if (!rax_2)
    {
        (*(r8 + 0x88))(arg1);
        int64_t r8_1 = *arg1;
        (*(r8_1 + 0xb8))(arg1, rax_1, r8_1);
        return 0;
    }
    
    int64_t rax_4 = (*(r8 + 0x538))(arg1, arg3, r8);
    int64_t result_1 = sub_180001cd0(arg1, arg2, arg4, rax_4);
    int64_t rdx_4 = *arg1;
    int64_t result = result_1;
    
    if ((*(rdx_4 + 0x720))(arg1, rdx_4))
    {
        int64_t rdx_5 = *arg1;
        (*(rdx_5 + 0x88))(arg1, rdx_5);
        result = 0;
    }
    
    int64_t r8_3 = *arg1;
    (*(r8_3 + 0xb8))(arg1, rax_4, r8_3);
    int64_t r8_4 = *arg1;
    (*(r8_4 + 0xb8))(arg1, rax_1, r8_4);
    return result;
}

