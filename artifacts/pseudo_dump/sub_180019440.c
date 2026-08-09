
  int64_t sub_180019440(int64_t* arg1, int64_t* arg2)

{
    if (arg1[1])
    {
        int64_t r8_1 = *arg1;
        
        if (r8_1)
        {
            int64_t rax = -1;
            bool cond:1_1;
            
            do
            {
                cond:1_1 = *(r8_1 + rax + 1);
                rax += 1;
            } while (cond:1_1);
            char* rax_1 = j_sub_1800213a0(rax + 1);
            
            if (rax_1)
            {
                sub_180020d70(rax_1, rax + 1, *arg1);
                *arg2 = rax_1;
                arg2[1] = 1;
            }
            
            /* tailcall */
            return j_sub_180021340(0);
        }
    }
    
    int64_t result = *arg1;
    *arg2 = result;
    arg2[1] = 0;
    return result;
}

