
  int64_t sub_1800265b8(int64_t arg1, void* arg2)

{
    void* rbx = arg2;
    
    if (arg1 != arg2)
    {
        do
        {
            if (*(rbx - 8))
                sub_18002d680();
            
            rbx -= 0x10;
        } while (rbx != arg1);
    }
    
    int64_t result;
    result = 1;
    return result;
}

