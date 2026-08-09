
  int64_t sub_18000b270(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4)

{
    sub_1800023a0("Native_onChannelActive fired: conn=%p ctx=%p", arg3);
    sub_18000df50(arg1, arg3);
    /* tailcall */
    return sub_1800023a0("Native_onChannelActive returning", sub_18000bd50(arg1, arg4));
}

