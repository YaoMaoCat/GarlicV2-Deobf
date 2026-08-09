
  void* sub_180019220(int64_t arg1)

{
    if (arg1 == *(sub_180019c40() + 0x58))
    {
        void* i_1 = *(sub_180019c40() + 0x58);
        
        if (i_1)
        {
            void* i;
            
            do
            {
                i = *(i_1 + 8);
                
                if (arg1 == i_1)
                {
                    void* result = sub_180019c40();
                    *(result + 0x58) = i;
                    return result;
                }
                
                i_1 = i;
            } while (i);
        }
    }
    
    abort();
    /* no return */
}

