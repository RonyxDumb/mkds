unsigned int OS_GetTickLo(void)
{
    return ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x4000100u) + 0));
}
