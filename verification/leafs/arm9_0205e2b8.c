unsigned int ResetGlobalAR(void)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x217aa24u) + 0) = (unsigned int)(0x0u);
    return 0x217aa24u;
}
