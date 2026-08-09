
  int32_t sub_18002c590()

{
    int32_t mxcsr;
    int32_t rax = sub_18002cde0(mxcsr);
    
    if (!(rax & 0x3f))
        return 0;
    
    int32_t result_4 = (rax & 1) << 4;
    int32_t result_3 = result_4 | 8;
    
    if (!(rax & 4))
        result_3 = result_4;
    
    int32_t result_2 = result_3 | 4;
    
    if (!(rax & 8))
        result_2 = result_3;
    
    int32_t result_1 = result_2 | 2;
    
    if (!(rax & 0x10))
        result_1 = result_2;
    
    int32_t result = result_1 | 1;
    
    if (!(rax & 0x20))
        result = result_1;
    
    if (!(rax & 2))
        return result;
    
    return result | 0x80000;
}

