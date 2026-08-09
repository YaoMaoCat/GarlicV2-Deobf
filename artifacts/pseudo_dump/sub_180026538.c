
  void* sub_180026538(int64_t* arg1, int64_t arg2)

{
    int64_t* rbx_1;
    
    if (arg1 != arg2)
    {
        rbx_1 = arg1;
        
        do
        {
            if (*rbx_1 && !sub_18002d680())
                break;
            
            rbx_1 = &rbx_1[2];
        } while (rbx_1 != arg2);
    }
    
    void* result;
    
    if (arg1 == arg2 || rbx_1 == arg2)
        result = 1;
    else
    {
        if (rbx_1 != arg1)
        {
            int64_t* rbx_2 = &rbx_1[-1];
            
            do
            {
                if (rbx_2[-1] && *rbx_2)
                    sub_18002d680();
                
                rbx_2 -= 0x10;
            } while (&rbx_2[1] != arg1);
        }
        
        result = 0;
    }
    
    return result;
}

