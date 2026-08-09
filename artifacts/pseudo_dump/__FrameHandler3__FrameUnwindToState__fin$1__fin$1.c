
🌐  void* __FrameHandler3::FrameUnwindToState::fin$1::fin$1()

{
    void* result = sub_180019c40();
    
    if (*(result + 0x30) > 0)
    {
        result = sub_180019c40();
        *(result + 0x30) -= 1;
    }
    
    return result;
}

