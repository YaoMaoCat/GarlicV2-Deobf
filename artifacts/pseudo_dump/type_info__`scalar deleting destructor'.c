
🌐  struct type_info::VTable** type_info::`scalar deleting destructor'(struct type_info::VTable** arg1, char arg2)

{
    *arg1 = &type_info::`vftable';
    
    if (arg2 & 1)
        j_sub_180021340(arg1);
    
    return arg1;
}

