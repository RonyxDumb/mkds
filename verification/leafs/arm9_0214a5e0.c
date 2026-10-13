void G3X_SetHOffset(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x4000010u) + 0) = (unsigned int)(p0);
}
