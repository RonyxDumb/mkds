unsigned int ResetGlobalAA04(void)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x217aa04u) + 0) = (unsigned int)(0x0u);
    return 0x217aa04u;
}
