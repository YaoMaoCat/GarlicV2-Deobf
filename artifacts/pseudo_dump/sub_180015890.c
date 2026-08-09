
  int64_t sub_180015890(int64_t* arg1, int64_t arg2, int512_t arg3 @ zmm2, int64_t arg4, int64_t arg5)

{
    int64_t result = (*(*arg1 + 0x488))(arg1, arg4);
    
    if (!result)
        return result;
    
    data_180046328;
    int64_t rax_1 = sub_180001cd0(arg1, arg2, arg3, result);
    int64_t rdx_2 = *arg1;
    
    if ((*(rdx_2 + 0x720))(arg1, rdx_2) || !rax_1)
        return (*(*arg1 + 0x88))(arg1);
    
    data_180046388;
    sub_180001d00(arg1, rax_1, arg3, arg5);
    
    if ((*(*arg1 + 0x720))(arg1))
        (*(*arg1 + 0x88))(arg1);
    
    (*(*arg1 + 0xb8))(arg1, rax_1);
❓    /* jump -> *(*arg1 + 0xb8) */
}

