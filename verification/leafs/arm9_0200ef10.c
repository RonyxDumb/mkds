unsigned int Os_DisableMainExRegion(void)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x21701b8u) + 0) = (unsigned int)(0x0u);
    return 0x21701b8u;
}
