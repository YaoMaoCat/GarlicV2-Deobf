
  BOOL sub_18002640c()

{
    int32_t lpflOldProtect = 0;
    BOOL result;
    result = VirtualProtect(&data_18004c000, 0x100, PAGE_READONLY, &lpflOldProtect);
    return result;
}

