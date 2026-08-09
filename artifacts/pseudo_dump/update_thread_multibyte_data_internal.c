
  int32_t* update_thread_multibyte_data_internal(void* arg1, int64_t* arg2)

{
    int32_t* result;
    
    if (!(*(arg1 + 0x3a8) & data_180047080) || !*(arg1 + 0x90))
    {
        sub_1800239bc(5);
        result = *(arg1 + 0x88);
        
        if (result != *arg2)
        {
            if (result)
            {
                int32_t rax_1 = *result;
                *result -= 1;
                
                if (rax_1 == 1 && result != &data_180046b40)
                    _free_base(result);
            }
            
            int32_t* result_1 = *arg2;
            *(arg1 + 0x88) = result_1;
            *result_1 += 1;
            result = result_1;
        }
        
        sub_180023a10(5);
    }
    else
        result = *(arg1 + 0x88);
    
    if (result)
        return result;
    
    abort();
    /* no return */
}

