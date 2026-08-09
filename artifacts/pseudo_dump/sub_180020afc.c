
  int64_t sub_180020afc(int64_t* arg1, int64_t arg2)

{
    int64_t* rbx = arg1;
    
    if (arg1 != arg2)
    {
        do
        {
            if (*rbx)
            {
                int32_t result = sub_18002d680();
                
                if (result)
                    return result;
            }
            
            rbx = &rbx[1];
        } while (rbx != arg2);
    }
    
    return 0;
}

