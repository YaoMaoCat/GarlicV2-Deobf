
  int64_t sub_18001cfd0(int32_t* arg1)

{
    int32_t i = 0;
    int32_t result;
    
    if (*arg1 > 0)
    {
        do
        {
            int64_t rbp_1 = i * 0x14;
            void* rax_6;
            
            if (!*(_GetImageBase() + arg1[1] + rbp_1 + 4))
                rax_6 = nullptr;
            else
            {
                int64_t rdi_3 = *(_GetImageBase() + rbp_1 + arg1[1] + 4);
                rax_6 = _GetImageBase() + rdi_3;
            }
            
            if (!sub_180019aa0(rax_6 + 8, &class std::bad_exception `RTTI Type Descriptor'.spare))
            {
                result = 1;
                return result;
            }
            
            i += 1;
        } while (i < *arg1);
    }
    
    result = 0;
    return result;
}

