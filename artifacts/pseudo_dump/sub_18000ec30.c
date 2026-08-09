
  int64_t sub_18000ec30()

{
    char result;
    int64_t rdx;
    result = sub_18000e2f0(0);
    
    if (result)
        return result;
    
    sub_1800023a0("[MAIN-GATE] blocking A Render thread until B reaches PLAY", rdx);
    /* tailcall */
    return sub_1800023a0("[MAIN-GATE] B reached PLAY; resuming A Render thread", 
        sub_18000e2f0(0xffffffff));
}

