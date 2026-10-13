unsigned int Os_Lock_GetOwnerId(unsigned int p0)
{
    return ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 4));
}
