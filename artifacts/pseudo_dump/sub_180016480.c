
  int64_t sub_180016480()

{
    int64_t result;
    
    if (sub_180016fc0())
    {
        TEB* gsbase;
        void* StackBase = gsbase->NtTib.Self->NtTib.StackBase;
        result = 0;
        bool z_1;
        
        if (0 == data_180047528)
        {
            data_180047528 = StackBase;
            z_1 = true;
        }
        else
        {
            result = data_180047528;
            z_1 = false;
        }
        
        if (!z_1)
        {
            bool z_2;
            
            do
            {
                if (StackBase == result)
                {
                    result = 1;
                    return result;
                }
                
                result = 0;
                
                if (0 == data_180047528)
                {
                    data_180047528 = StackBase;
                    z_2 = true;
                }
                else
                {
                    result = data_180047528;
                    z_2 = false;
                }
            } while (!z_2);
        }
    }
    
    result = 0;
    return result;
}

