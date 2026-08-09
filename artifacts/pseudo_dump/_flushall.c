
🌐  int64_t _flushall()

{
    int512_t entry_zmm1;
    /* tailcall */
    return common_flush_all(1, entry_zmm1);
}

